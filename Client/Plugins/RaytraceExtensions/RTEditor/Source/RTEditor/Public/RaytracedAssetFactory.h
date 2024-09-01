// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "RTAssets/Public/RaytracedAO.h"
#include "RTAssets/Public/RaytracedBevel.h"
#include "AssetTypeActions_Base.h"
#if ENGINE_MINOR_VERSION > 1
#include "AssetDefinitionDefault.h"
#endif
#include "Runtime/Engine/Classes/Materials/MaterialExpressionTextureSampleParameter.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionScreenPosition.h"
#include "Runtime/Engine/Classes/Materials/MaterialExpressionTransform.h"
#include "EdGraphUtilities.h"
#include "EdGraph/EdGraphNode.h"
#include "SNodePanel.h"
#include "TutorialMetaData.h"
#include "TickableEditorObject.h"
#include "ThumbnailRendering/ThumbnailManager.h"
#include "ThumbnailRendering/TextureThumbnailRenderer.h"
#include "UObject/ObjectSaveContext.h"
#include "RaytracedAssetFactory.generated.h"


/**
 *
 */
UCLASS(collapsecategories, hidecategories=(Object, ParameterCustomization, MaterialExpressionTextureSample, MaterialExpressionTextureBase), MinimalAPI)
class UMaterialExpressionRTAO : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset, meta = (DisplayName = "预设", DisplayPriority = 0, DisplayThumbnail = "false"))
	TObjectPtr<class URaytracedAmbientOcclusion> Asset;

	void PostLoad() override;
#if WITH_EDITOR
	void PreSave(FObjectPreSaveContext SaveContext)override;
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
#endif
	bool CanReferenceTexture() const override { return true; }
	UObject* GetReferencedTexture() const override;

	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex);
	virtual TArray<FExpressionOutput>& GetOutputs();
	virtual uint32 GetOutputType(int32 OutputIndex) override;
	virtual bool IsResultMaterialAttributes(int32 OutputIndex) override;
protected:
	UMaterialExpression* GetOrCreateScreenPosition();
	UMaterialExpressionTextureSample* GetOrCreateRaytracedAO();
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Asset", meta = (DisplayName = "像素采样(SPP)", UIMin = "1", UIMax = "64"))
	int32 SamplesPerPixel = 8;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "强度", UIMin = "0.01"))
	float Intensity = 5;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "反射距离", UIMin = "1.0", tooltip = "unit : cm"))
	float MaxRayDistance = 500.f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "法线偏移", UIMin = "0.01", UIMax = "100", tooltip = "射线起点按法线方向偏移距离(cm)"))
	float MaxNormalBias = 0.1f;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "降噪"))
	bool bDenoise = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Asset")
	bool bProjectionMatrixUnadjusted = false;
protected:
	UPROPERTY(Transient)
	UMaterialExpression* ScreenPosition = nullptr;

	UPROPERTY(Transient)
	UMaterialExpressionTextureSample* RaytracedAO = nullptr;
};

UCLASS()
class RTEDITOR_API URaytracedAmbientOcclusionFactoryNew : public UFactory
{
	GENERATED_UCLASS_BODY()

	/** Width of the texture render target */
	UPROPERTY(meta=(ToolTip="Width of the texture render target"))
	int32 Width;

	/** Height of the texture render target */
	UPROPERTY(meta=(ToolTip="Height of the texture render target"))
	int32 Height;

	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface	
};

class RTEDITOR_API FAssetTypeActions_RaytracedAmbientOcclusion : public FAssetTypeActions_Base
{
public:
	FText GetName() const override { return FText::FromString("RTAO"); }
	FColor GetTypeColor() const override { return FColor(192, 64, 64); }
	UClass* GetSupportedClass() const override { return URaytracedAmbientOcclusion::StaticClass(); }
	void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;
	bool CanFilter() override { return true; }
	uint32 GetCategories() override { return EAssetTypeCategories::Textures; }
	bool IsImportedAsset() const override { return true; }
	void GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const override;
	void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
};





UCLASS(collapsecategories, hidecategories=(Object, ParameterCustomization, MaterialExpressionTextureSample, MaterialExpressionTextureBase), MinimalAPI)
class UMaterialExpressionRTBevel : public UMaterialExpression
{
	GENERATED_UCLASS_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Asset, meta = (DisplayName = "预设", DisplayPriority = 0, DisplayThumbnail = "false"))
	TObjectPtr<class URaytracedBevelNormal> Asset;

	void PostLoad() override;
#if WITH_EDITOR
	void PreSave(FObjectPreSaveContext SaveContext)override;
	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	virtual void GetCaption(TArray<FString>& OutCaptions) const override;
#endif
	bool CanReferenceTexture() const override { return true; }
	UObject* GetReferencedTexture() const override;

	virtual int32 Compile(class FMaterialCompiler* Compiler, int32 OutputIndex);
	virtual TArray<FExpressionOutput>& GetOutputs();
	virtual uint32 GetOutputType(int32 OutputIndex) override;
	virtual bool IsResultMaterialAttributes(int32 OutputIndex) override;
protected:
	UMaterialExpression* GetOrCreateScreenPosition();
	UMaterialExpressionTextureSample* GetOrCreateBevelNormal();
	UMaterialExpressionTransform* GetOrCreateTransformVector();
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "最大角度", UIMin = "0", UIMax = "180"))
	float MaxAngle = 90.0;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "半径", UIMin = "0.0"))
	float Radius = 1;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "像素采样(SPP)", UIMin = "1", UIMax = "64"))
	int32 NumSamples = 4;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "降噪"))
	bool bDenoise = true;

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = "Asset", meta = (DisplayName = "采样"))
	TEnumAsByte<enum TextureFilter> BevelFilter = TextureFilter::TF_Nearest;

protected:
	UPROPERTY(Transient)
	UMaterialExpression* ScreenPosition = nullptr;

	UPROPERTY(Transient)
	UMaterialExpressionTextureSample* BevelNormal = nullptr;

	UPROPERTY(Transient)
	UMaterialExpressionTransform* TransformVector = nullptr;
};

UCLASS()
class RTEDITOR_API URaytracedBevelNormallFactoryNew : public UFactory
{
	GENERATED_UCLASS_BODY()

	/** Width of the texture render target */
	UPROPERTY(meta=(ToolTip="Width of the texture render target"))
	int32 Width;

	/** Height of the texture render target */
	UPROPERTY(meta=(ToolTip="Height of the texture render target"))
	int32 Height;

	//~ Begin UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	//~ Begin UFactory Interface	
};

class RTEDITOR_API FAssetTypeActions_RaytracedBevelNormal : public FAssetTypeActions_Base
{
public:
	FText GetName() const override { return FText::FromString("RTBevel"); }
	FColor GetTypeColor() const override { return FColor(192, 64, 64); }
	UClass* GetSupportedClass() const override { return URaytracedBevelNormal::StaticClass(); }
	void GetActions(const TArray<UObject*>& InObjects, struct FToolMenuSection& Section) override;
	bool CanFilter() override { return true; }
	uint32 GetCategories() override { return EAssetTypeCategories::Textures; }
	bool IsImportedAsset() const override { return true; }
	void GetResolvedSourceFilePaths(const TArray<UObject*>& TypeAssets, TArray<FString>& OutSourceFilePaths) const override;
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
};