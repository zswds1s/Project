// Fill out your copyright notice in the Description page of Project Settings.


#include "RaytracedAssetFactory.h"
#include "ToolMenus.h"
#include "Misc/PackageName.h"
#include "Styling/AppStyle.h"
#include "Factories/SlateBrushAssetFactory.h"
#include "Slate/SlateBrushAsset.h"
#include "Developer/AssetTools/Private/AssetTools.h"
#include "IContentBrowserSingleton.h"
#include "ContentBrowserModule.h"
#include "Interfaces/ITextureEditorModule.h"
#include "EditorSupportDelegates.h"
#include "MaterialCompiler.h"
#include "MaterialHLSLGenerator.h"
#include "MaterialGraph/MaterialGraphNode.h"
#include "Editor/MaterialEditor/Public/IMaterialEditor.h"
#include "EditorModeManager.h"
#include "Editor/MaterialEditor/Public/MaterialEditorModule.h"
#include "Editor/MaterialEditor/Private/MaterialEditor.h"
#include "Editor/MaterialEditor/Private/SMaterialEditorViewport.h"
#include "AssetEditorModeManager.h"
#include "MaterialEditorUtilities.h"
#include "CanvasItem.h"
#include "CanvasTypes.h"
#include "SimpleElementShaders.h"
#include "BatchedElements.h"
#include "Editor/TextureEditor/Private/TextureEditorToolkit.h"
#include "Toolkits/SimpleAssetEditor.h"
#include "EditorViewportTabContent.h"
#include "ScreenRendering.h"
#include "CommonRenderResources.h"
#include "UObject/SavePackage.h"
#include "Engine/StaticMesh.h"


#define LOCTEXT_NAMESPACE "RaytracedAssetsTypeActions"


UMaterialExpressionRTAO::UMaterialExpressionRTAO(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		FText NAME_RTAO;
		FConstructorStatics() : NAME_RTAO(FText::FromString(TEXT("RTAO"))) {}
	};
	static FConstructorStatics ConstructorStatics;
	MenuCategories.Add(ConstructorStatics.NAME_RTAO);
#endif // WITH_EDITORONLY_DATA

	this->bCollapsed = true;
	this->bRealtimePreview = false;
	this->bShowInputs = false;
	this->bHidePreviewWindow = true;
}

UMaterialExpression* UMaterialExpressionRTAO::GetOrCreateScreenPosition()
{
	if (!ScreenPosition)
	{
		UClass* Class = LoadClass<UMaterialExpression>(nullptr, TEXT("/Script/Engine.MaterialExpressionScreenPosition"));
		ScreenPosition = NewObject<UMaterialExpression>(this, Class, NAME_None, RF_Transient);
	}
	return ScreenPosition;
}

UMaterialExpressionTextureSample* UMaterialExpressionRTAO::GetOrCreateRaytracedAO()
{
	if (!RaytracedAO)
	{
		RaytracedAO = NewObject<UMaterialExpressionTextureSample>(this, NAME_None, RF_Transient);
		RaytracedAO->Texture = Asset;
		RaytracedAO->bCollapsed = true;
		RaytracedAO->bRealtimePreview = false;
		RaytracedAO->bShowInputs = false;
		RaytracedAO->bHidePreviewWindow = true;
		RaytracedAO->AutomaticViewMipBias = false;
		RaytracedAO->AutoSetSampleType();
		this->Outputs = TArray<FExpressionOutput>{RaytracedAO->Outputs[0]};
		this->Outputs[0].Mask = 1;
		this->Outputs[0].MaskR = 1;
		this->Outputs[0].MaskG = 0;
		this->Outputs[0].MaskB = 0;
		this->Outputs[0].MaskA = 0;
		this->Outputs[0].OutputName = TEXT("AO");
	}
	return RaytracedAO;
}

void UMaterialExpressionRTAO::PostLoad()
{
	Super::PostLoad();

	if (Asset)
	{
		Asset->SamplesPerPixel = this->SamplesPerPixel;
		Asset->Intensity = this->Intensity;
		Asset->MaxRayDistance = this->MaxRayDistance;
		Asset->MaxNormalBias = this->MaxNormalBias;
		Asset->bDenoise = this->bDenoise;
		Asset->bProjectionMatrixUnadjusted = this->bProjectionMatrixUnadjusted;
	}

	this->bShowInputs = true;
	this->bShowOutputs = true;
	this->bShowOutputNameOnPin = true;

	GetOrCreateScreenPosition();
	GetOrCreateRaytracedAO();
}

#if WITH_EDITOR
void UMaterialExpressionRTAO::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);
}

void UMaterialExpressionRTAO::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FProperty* PropertyThatChanged = PropertyChangedEvent.MemberProperty;
	const FString PropertyName = PropertyThatChanged ? PropertyThatChanged->GetName() : TEXT("");

	bool bDirty = false;
	if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, Asset))
	{
		if (UStaticMesh* StaticMesh = Cast<UStaticMesh>(Asset->Asset))
			StaticMesh->WaitForPendingInitOrStreaming();

		GetOrCreateRaytracedAO()->Texture = Asset;
		if (GraphNode)
			FMaterialEditorUtilities::UpdateMaterialAfterGraphChange(this->GraphNode->GetGraph());

		if(Asset)
		{
			Asset->SamplesPerPixel = SamplesPerPixel;
			Asset->Intensity = Intensity;
			Asset->MaxRayDistance = MaxRayDistance;
			Asset->MaxNormalBias = MaxNormalBias;
			Asset->bDenoise = bDenoise;
			Asset->bProjectionMatrixUnadjusted = bProjectionMatrixUnadjusted;
		}
		bDirty = true;
	}

	if (Asset)
	{
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, SamplesPerPixel))
		{
			Asset->SamplesPerPixel = SamplesPerPixel;
			bDirty = true;
		}

		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, Intensity))
		{
			Asset->Intensity = Intensity;
			bDirty = true;
		}

		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, MaxRayDistance))
		{
			Asset->MaxRayDistance = MaxRayDistance;
			bDirty = true;
		}

		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, MaxNormalBias))
		{
			Asset->MaxNormalBias = MaxNormalBias;
			bDirty = true;
		}

		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, bDenoise))
		{
			Asset->bDenoise = bDenoise;
			bDirty = true;
		}

		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTAO, bProjectionMatrixUnadjusted))
		{
			Asset->bProjectionMatrixUnadjusted = bProjectionMatrixUnadjusted;
			bDirty = true;
		}
	}

	if (bDirty&&Asset)
	{
		Asset->SamplesPerPixel = this->SamplesPerPixel;
		Asset->Intensity = this->Intensity;
		Asset->MaxRayDistance = this->MaxRayDistance;
		Asset->MaxNormalBias = this->MaxNormalBias;
		Asset->bDenoise = this->bDenoise;
		Asset->bProjectionMatrixUnadjusted = this->bProjectionMatrixUnadjusted;

		if (UPackage* Package = Asset->GetOutermost())
		{
			Package->SetDirtyFlag(true);

			FString PackageFileName = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());

			FSavePackageArgs SaveArgs;
			SaveArgs.TopLevelFlags = RF_Standalone;
			SaveArgs.SaveFlags = SAVE_None;
			SaveArgs.Error = GError;
			SaveArgs.bForceByteSwapping = false;
			SaveArgs.bWarnOfLongFilename = true;
			//SaveArgs.TargetPlatform = nullptr;

			bool bSuccess = UPackage::SavePackage(
				Package,
				Asset,
				*PackageFileName,
				SaveArgs
			);

			ensure(bSuccess);
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UMaterialExpressionRTAO::GetCaption(TArray<FString>& OutCaptions) const
{
	OutCaptions.Add(TEXT("RTAO"));
}
#endif

UObject* UMaterialExpressionRTAO::GetReferencedTexture() const
{
	return Asset;
}

int32 UMaterialExpressionRTAO::Compile(class FMaterialCompiler* Compiler, int32 OutputIndex)
{
	GetOrCreateRaytracedAO()->GetInput(0)->Connect(0, GetOrCreateScreenPosition());
	GetOrCreateRaytracedAO()->GetInput(0)->Compile(Compiler);
	return GetOrCreateRaytracedAO()->Compile(Compiler, OutputIndex);
}

TArray<FExpressionOutput>& UMaterialExpressionRTAO::GetOutputs()
{
	GetOrCreateRaytracedAO();
	return Super::GetOutputs();
}

uint32 UMaterialExpressionRTAO::GetOutputType(int32 OutputIndex)
{
	return MCT_Float4;
}

bool UMaterialExpressionRTAO::IsResultMaterialAttributes(int32 OutputIndex)
{
	return false;
}

URaytracedAmbientOcclusionFactoryNew::URaytracedAmbientOcclusionFactoryNew(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
	SupportedClass = URaytracedAmbientOcclusion::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
	bEditorImport = false;

	Width = 340;
	Height = 180;
}


UObject* URaytracedAmbientOcclusionFactoryNew::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	URaytracedAmbientOcclusion* Result = NewObject<URaytracedAmbientOcclusion>(InParent, Class, Name, Flags);
	return(Result);
}

void FAssetTypeActions_RaytracedAmbientOcclusion::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{

}

void FAssetTypeActions_RaytracedAmbientOcclusion::GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const
{

}

void FAssetTypeActions_RaytracedAmbientOcclusion::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto Texture = Cast<URaytracedAmbientOcclusion>(*ObjIt);
		if (Texture != NULL)
		{
			ITextureEditorModule* TextureEditorModule = &FModuleManager::LoadModuleChecked<ITextureEditorModule>("TextureEditor");
			TSharedRef<FTextureEditorToolkit>Toolkit = StaticCastSharedRef<FTextureEditorToolkit>(TextureEditorModule->CreateTextureEditor(Mode, EditWithinLevelEditor, Texture));
		}
	}
}


UMaterialExpressionRTBevel::UMaterialExpressionRTBevel(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{
#if WITH_EDITORONLY_DATA
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{
		FText NAME_Bevel;
		FConstructorStatics() : NAME_Bevel(FText::FromString(TEXT("RTBevel"))) {}
	};
	static FConstructorStatics ConstructorStatics;
	MenuCategories.Add(ConstructorStatics.NAME_Bevel);
#endif // WITH_EDITORONLY_DATA

	this->bCollapsed = true;
	this->bRealtimePreview = false;
	this->bShowInputs = false;
	this->bHidePreviewWindow = true;
}

UMaterialExpression* UMaterialExpressionRTBevel::GetOrCreateScreenPosition()
{
	if (!ScreenPosition)
	{
		UClass* Class = LoadClass<UMaterialExpression>(nullptr, TEXT("/Script/Engine.MaterialExpressionScreenPosition"));
		ScreenPosition = NewObject<UMaterialExpression>(this, Class, NAME_None, RF_Transient);
	}
	return ScreenPosition;
}

UMaterialExpressionTextureSample* UMaterialExpressionRTBevel::GetOrCreateBevelNormal()
{
	if (!BevelNormal)
	{
		BevelNormal = NewObject<UMaterialExpressionTextureSample>(this, NAME_None, RF_Transient);
		BevelNormal->Texture = Asset;
		BevelNormal->bCollapsed = true;
		BevelNormal->bRealtimePreview = false;
		BevelNormal->bShowInputs = false;
		BevelNormal->bHidePreviewWindow = true;
		BevelNormal->AutomaticViewMipBias = false;
		BevelNormal->AutoSetSampleType();
	}
	return BevelNormal;
}

UMaterialExpressionTransform* UMaterialExpressionRTBevel::GetOrCreateTransformVector()
{
	if (!TransformVector)
	{
		TransformVector = NewObject<UMaterialExpressionTransform>(this, NAME_None, RF_Transient);
		TransformVector->TransformSourceType = TEnumAsByte<EMaterialVectorCoordTransformSource>(EMaterialVectorCoordTransformSource::TRANSFORMSOURCE_World);
		TransformVector->TransformType = TEnumAsByte<EMaterialVectorCoordTransform>(EMaterialVectorCoordTransform::TRANSFORM_Tangent);
		TransformVector->Outputs[0].OutputName = TEXT("Normal");
		TransformVector->bShowOutputs = true;
	}
	return TransformVector;
}

void UMaterialExpressionRTBevel::PostLoad()
{
	Super::PostLoad();

	if (Asset)
	{
		Asset->MaxAngle = this->MaxAngle;
		Asset->Radius = this->Radius;
		Asset->NumSamples = this->NumSamples;
		Asset->bDenoise = this->bDenoise;
		Asset->BevelFilter = this->BevelFilter;
	}

	this->bShowInputs = true;
	this->bShowOutputs = true;
	this->bShowOutputNameOnPin = true;

	GetOrCreateScreenPosition();
	GetOrCreateBevelNormal();
	GetOrCreateTransformVector();
}

#if WITH_EDITOR
void UMaterialExpressionRTBevel::PreSave(FObjectPreSaveContext SaveContext)
{
	Super::PreSave(SaveContext);
}

void UMaterialExpressionRTBevel::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FProperty* PropertyThatChanged = PropertyChangedEvent.MemberProperty;
	const FString PropertyName = PropertyThatChanged ? PropertyThatChanged->GetName() : TEXT("");

	bool bDirty = false;
	if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, Asset))
	{
		GetOrCreateBevelNormal()->Texture = Asset;
		if (GraphNode)
			FMaterialEditorUtilities::UpdateMaterialAfterGraphChange(this->GraphNode->GetGraph());

		if (Asset)
		{
			Asset->MaxAngle = MaxAngle;
			Asset->Radius = Radius;
			Asset->NumSamples = NumSamples;
			Asset->bDenoise = bDenoise;
			Asset->BevelFilter = BevelFilter;
			Asset->bProjectionMatrixUnadjusted = false;
		}

		bDirty = true;
	}

	if (Asset)
	{
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, MaxAngle))
		{
			Asset->MaxAngle = MaxAngle;
			bDirty = true;
			//Asset->MarkPackageDirty();
		}
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, Radius))
		{
			Asset->Radius = Radius;
			bDirty = true;
			//Asset->MarkPackageDirty();
		}
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, NumSamples))
		{
			Asset->NumSamples = NumSamples;
			bDirty = true;
			//Asset->MarkPackageDirty();
		}
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, bDenoise))
		{
			Asset->bDenoise = bDenoise;
			bDirty = true;
			//Asset->MarkPackageDirty();
		}
		if (PropertyName == GET_MEMBER_NAME_STRING_CHECKED(UMaterialExpressionRTBevel, BevelFilter))
		{
			Asset->BevelFilter = BevelFilter;
			Asset->OnBevelFilterChanged();
			if (this->GraphNode)
			{
				if (this->GraphNode->GetGraph())
				{
					GraphNode->GetGraph()->NotifyGraphChanged();
					FMaterialEditorUtilities::UpdateMaterialAfterGraphChange(GraphNode->GetGraph());
				}
			}
			bDirty = true;
			//Asset->MarkPackageDirty();
		}
	}

	if (bDirty&&Asset)
	{
		Asset->MaxAngle = this->MaxAngle;
		Asset->Radius = this->Radius;
		Asset->NumSamples = this->NumSamples;
		Asset->bDenoise = this->bDenoise;
		Asset->BevelFilter = this->BevelFilter;

		if (UPackage* Package = Asset->GetOutermost())
		{
			Package->SetDirtyFlag(true);

			FString PackageFileName = FPackageName::LongPackageNameToFilename(Package->GetName(), FPackageName::GetAssetPackageExtension());

			FSavePackageArgs SaveArgs;
			SaveArgs.TopLevelFlags = RF_Standalone;
			SaveArgs.SaveFlags = SAVE_None;
			SaveArgs.Error = GError;
			SaveArgs.bForceByteSwapping = false;
			SaveArgs.bWarnOfLongFilename = true;
			//SaveArgs.TargetPlatform = nullptr;

			bool bSuccess = UPackage::SavePackage(
				Package,
				Asset,
				*PackageFileName,
				SaveArgs
			);

			ensure(bSuccess);
		}
	}
	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UMaterialExpressionRTBevel::GetCaption(TArray<FString>& OutCaptions) const
{
	OutCaptions.Add(TEXT("RTBevel"));
}
#endif

UObject* UMaterialExpressionRTBevel::GetReferencedTexture() const
{
	return Asset;
}

int32 UMaterialExpressionRTBevel::Compile(class FMaterialCompiler* Compiler, int32 OutputIndex)
{
	GetOrCreateBevelNormal()->GetInput(0)->Connect(0, GetOrCreateScreenPosition());
	GetOrCreateBevelNormal()->GetInput(0)->Compile(Compiler);
	GetOrCreateTransformVector()->GetInput(0)->Connect(0, GetOrCreateBevelNormal());
	int32 VecInputIdx = GetOrCreateTransformVector()->GetInput(0)->Compile(Compiler);
	const auto TransformSourceBasis = MCB_World;
	const auto TransformDestBasis = MCB_Tangent;
	return Compiler->TransformVector(TransformSourceBasis, TransformDestBasis, VecInputIdx);
}

TArray<FExpressionOutput>& UMaterialExpressionRTBevel::GetOutputs()
{
	return GetOrCreateTransformVector()->Outputs;
}

uint32 UMaterialExpressionRTBevel::GetOutputType(int32 OutputIndex)
{
	return GetOrCreateTransformVector()->GetOutputType(OutputIndex);
}

bool UMaterialExpressionRTBevel::IsResultMaterialAttributes(int32 OutputIndex)
{
	return false;
}

URaytracedBevelNormallFactoryNew::URaytracedBevelNormallFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = URaytracedBevelNormal::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
	bEditorImport = false;

	Width = 340;
	Height = 180;
}


UObject* URaytracedBevelNormallFactoryNew::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	URaytracedBevelNormal* Result = NewObject<URaytracedBevelNormal>(InParent, Class, Name, Flags);
	return(Result);
}


void FAssetTypeActions_RaytracedBevelNormal::GetActions(const TArray<UObject*>& InObjects, FToolMenuSection& Section)
{

}

void FAssetTypeActions_RaytracedBevelNormal::GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const
{

}

void FAssetTypeActions_RaytracedBevelNormal::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor /*= TSharedPtr<IToolkitHost>()*/)
{
	EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid() ? EToolkitMode::WorldCentric : EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto Texture = Cast<URaytracedBevelNormal>(*ObjIt);
		if (Texture != NULL)
		{
			ITextureEditorModule* TextureEditorModule = &FModuleManager::LoadModuleChecked<ITextureEditorModule>("TextureEditor");
			TSharedRef<FTextureEditorToolkit>Toolkit = StaticCastSharedRef<FTextureEditorToolkit>(TextureEditorModule->CreateTextureEditor(Mode, EditWithinLevelEditor, Texture));
		}
	}
}

#undef LOCTEXT_NAMESPACE