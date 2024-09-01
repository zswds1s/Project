// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Internationalization/Text.h"
#include "UObject/Object.h"
#include "UObject/ObjectMacros.h"
#include <memory>

#include "CinewareAssetInstance.generated.h"

UENUM(BlueprintType)
enum ECinewareDataType
{
	CW_INT,
	CW_FLOAT,
	CW_BOOL,
	CW_STRING,
	CW_VECTOR3,
	CW_COLOR,
	CW_ENUM,
	CW_UNDEF
};

USTRUCT(BlueprintType)
struct FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainer() = default;
	FCinewareDataContainer(const FString Name, const TEnumAsByte <ECinewareDataType> Type = CW_UNDEF, int DescId=-1) 
		: Name(Name), Type(Type), DescId(DescId)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FString Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	TEnumAsByte<ECinewareDataType> Type;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	int Sort;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	int DescId;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerInt : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerInt() = default;
	FCinewareDataContainerInt(const FString Name, const int Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_INT, DescId), Value(Value)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	int32 Value;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerFloat : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerFloat() = default;
	FCinewareDataContainerFloat(const FString Name, const float Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_FLOAT, DescId), Value(Value)
	{
		IsAbstracted = false;
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	float Value;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	bool IsAbstracted;
	EAxis::Type Axis;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerBool : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerBool() = default;
	FCinewareDataContainerBool(const FString Name, const bool Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_BOOL, DescId), Value(Value)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	bool Value;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerString : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerString() = default;
	FCinewareDataContainerString(const FString Name, const FString Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_STRING, DescId), Value(Value)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FString Value;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerVec3 : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerVec3() = default;
	FCinewareDataContainerVec3(const FString Name, const FVector Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_VECTOR3, DescId), Value(Value)
	{
		IsAbstraction = false;
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FVector Value;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	bool IsAbstraction;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FString XId;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FString YId;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FString ZId;
};


USTRUCT(BlueprintType)
struct FCinewareDataContainerColor : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerColor() = default;
	FCinewareDataContainerColor(const FString Name, const FLinearColor Value, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_COLOR, DescId), Value(Value)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	FLinearColor Value;
};

USTRUCT(BlueprintType)
struct FCinewareDataContainerEnum : public FCinewareDataContainer
{
	GENERATED_USTRUCT_BODY()

	FCinewareDataContainerEnum() = default;
	FCinewareDataContainerEnum(const FString Name, const int Value,
		const TArray<FString> Collection, const TArray<int32> Ids, const int DescId=-1) 
		: FCinewareDataContainer(Name, CW_ENUM, DescId), Value(Value), Collection(Collection), Ids(Ids)
	{
	}

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	int32 Value;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	TArray<FString> Collection;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Data")
	TArray<int32> Ids;
};

/**
 * Implements an asset that can be used to store arbitrary text, such as notes
 * or documentation.
 */
UCLASS(BlueprintType, hidecategories=(Object))
class CINEWAREASSETINSTANCE_API UCinewareAssetInstance
	: public UObject
{
	GENERATED_BODY()

public:
	/// Getters

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetInt(const FString& Name, int DescId, FCinewareDataContainerInt& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetFloat(const FString& Name, int DescId, FCinewareDataContainerFloat& OutContainer);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetBool(const FString& Name, int DescId, FCinewareDataContainerBool& OutContainer);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetString(const FString& Name, int DescId, FCinewareDataContainerString& OutContainer);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetVector3(const FString& Name, int DescId, FCinewareDataContainerVec3& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetColor(const FString& Name, int DescId, FCinewareDataContainerColor& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	bool GetEnum(const FString& Name, int DescId, FCinewareDataContainerEnum& OutContainer);
	

	/// Setters
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetInt(const FString& Name, int DescId, const int Value);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetFloat(const FString& Name, int DescId, const float Value);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetBool(const FString& Name, int DescId, const bool Value);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetString(const FString& Name, int DescId, const FString Value);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetVector3(const FString& Name, int DescId, const FVector Value);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetColor(const FString& Name, int DescId, const FLinearColor Value);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetEnumByOrder(const FString& Name, int DescId, const int Value);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Setter")
	bool SetEnumByLabel(const FString& Name, int DescId, const FString Value);

	/// Browsing

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	void BeginIteration();

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextInputType(TEnumAsByte<ECinewareDataType>& OutType);


	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextInt(FCinewareDataContainerInt& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextString(FCinewareDataContainerString& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextFloat(FCinewareDataContainerFloat& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextBool(FCinewareDataContainerBool& OutContainer);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextVector3(FCinewareDataContainerVec3& OutContainer);
	
	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextColor(FCinewareDataContainerColor& OutContainer);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Browsing")
	bool GetNextEnum(FCinewareDataContainerEnum& OutContainer);


	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	void SetToDefaultValues();

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetInt(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetFloat(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetBool(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetString(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetVector3(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetColor(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool ResetEnum(const FString& Name, int DescId);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsIntDefault(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsFloatDefault(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsBoolDefault(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsStringDefault(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsVector3Default(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsColorDefault(const FString& Name, int DescId)  const;

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Reset")
	bool IsEnumDefault(const FString& Name, int DescId)  const;

	// Blueprint Properties

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextInt = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextString = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextBool = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextFloat = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextVector3 = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextColor = false;
	
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Cineware | Asset Browsing")
	bool HasNextEnum = false;

	// Register
	
	void RegisterProperty(FCinewareDataContainerInt Container);
	void RegisterProperty(FCinewareDataContainerFloat Container);
	void RegisterProperty(FCinewareDataContainerFloat Container, FString VectorId);
	void RegisterProperty(FCinewareDataContainerBool Container);
	void RegisterProperty(FCinewareDataContainerString Container);
	void RegisterProperty(FCinewareDataContainerVec3 Container);
	void RegisterProperty(FCinewareDataContainerColor Container);
	void RegisterProperty(FCinewareDataContainerEnum Container);

	// To remove override properties that has been removed from c4d scene
	TMap<ECinewareDataType, TArray<TPair<FString,int>>> GetAllEntryKeys();
	void RemoveEntry(FString key, int DescId, ECinewareDataType DataType);

	void ClearEntries();
	
	bool GetNextInput(FCinewareDataContainer*& OutContainer);

	void SetSourcefilePath(FString SrcFilePath);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	FString GetSourceFilePath();

	void SetSourcefilePathAbs(FString SrcFilePath);

	UFUNCTION(BlueprintCallable, Category = "Cineware | Asset Getter")
	FString GetSourceFilePathAbs();

	UPROPERTY()
	TMap<FString, bool> GeometryCacheChecks;

private:

	int ContainsIntKey(const FString& Key, const int DescId = -1) const;
	int ContainsFloatKey(const FString& Key, const int DescId = -1) const;
	int ContainsBoolKey(const FString& Key, const int DescId = -1) const;
	int ContainsStringKey(const FString& Key, const int DescId = -1) const;
	int ContainsVector3Key(const FString& Key, const int DescId = -1) const;
	int ContainsColorKey(const FString& Key, const int DescId = -1) const;
	int ContainsEnumKey(const FString& Key, const int DescId = -1) const;

	bool FindNextSortedElement(FCinewareDataContainer*& OutContainer, bool Increment = false);

	UPROPERTY()
	TArray<FCinewareDataContainerInt> CinewareInteger;
	UPROPERTY()
	TArray<FCinewareDataContainerFloat> CinewareFloat;
	UPROPERTY()
	TArray<FCinewareDataContainerBool> CinewareBool;
	UPROPERTY()
	TArray<FCinewareDataContainerString> CinewareString;
	UPROPERTY()
	TArray<FCinewareDataContainerVec3> CinewareVector3;
	UPROPERTY()
	TArray<FCinewareDataContainerColor> CinewareColor;
	UPROPERTY()
	TArray<FCinewareDataContainerEnum> CinewareEnum;

	UPROPERTY()
	TArray<FCinewareDataContainerInt> CinewareIntegerDefault;
	UPROPERTY()
	TArray<FCinewareDataContainerFloat> CinewareFloatDefault;
	UPROPERTY()
	TArray<FCinewareDataContainerBool> CinewareBoolDefault;
	UPROPERTY()
	TArray<FCinewareDataContainerString> CinewareStringDefault;
	UPROPERTY()
	TArray<FCinewareDataContainerVec3> CinewareVector3Default;
	UPROPERTY()
	TArray<FCinewareDataContainerColor> CinewareColorDefault;
	UPROPERTY()
	TArray<FCinewareDataContainerEnum> CinewareEnumDefault;

	UPROPERTY()
	FString SourceFilePath;
	UPROPERTY()
	FString SourceFilePathAbs;
	
	int CurrentSortCtr = 0;
	int CurrentInputIteration = 0;
	int CurrentIntIt = 0;
	int CurrentFloatIt = 0;
	int CurrentBoolIt = 0;
	int CurrentStringIt = 0;
	int CurrentVector3It = 0;
	int CurrentColorIt = 0;
	int CurrentEnumIt = 0;
};