#include "CinewareAssetInstance.h"

constexpr int CW_INVALID_IDX = -1;

bool UCinewareAssetInstance::GetInt(const FString& Name, int DescId, FCinewareDataContainerInt& OutContainer)
{
	int Index = ContainsIntKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerInt();
		return false;
	}

	OutContainer = CinewareInteger[Index];
	return true;
}

bool UCinewareAssetInstance::GetBool(const FString& Name, int DescId, FCinewareDataContainerBool& OutContainer)
{
	int Index = ContainsBoolKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerBool();
		return false;
	}

	OutContainer = CinewareBool[Index];
	return true;
}

bool UCinewareAssetInstance::GetFloat(const FString& Name, int DescId, FCinewareDataContainerFloat& OutContainer)
{
	int Index = ContainsFloatKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerFloat();
		return false;
	}

	OutContainer = CinewareFloat[Index];
	return true;
}

bool UCinewareAssetInstance::GetString(const FString& Name, int DescId, FCinewareDataContainerString& OutContainer)
{
	int Index = ContainsStringKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerString();
		return false;
	}

	OutContainer = CinewareString[Index];
	return true;
}

bool UCinewareAssetInstance::GetVector3(const FString& Name, int DescId, FCinewareDataContainerVec3& OutContainer)
{
	int Index = ContainsVector3Key(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerVec3();
		return false;
	}

	OutContainer = CinewareVector3[Index];
	return true;
}

bool UCinewareAssetInstance::GetColor(const FString& Name, int DescId, FCinewareDataContainerColor& OutContainer)
{
	int Index = ContainsColorKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerColor();
		return false;
	}

	OutContainer = CinewareColor[Index];
	return true;
}

bool UCinewareAssetInstance::GetEnum(const FString& Name, int DescId, FCinewareDataContainerEnum& OutContainer)
{
	int Index = ContainsEnumKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		OutContainer = FCinewareDataContainerEnum();
		return false;
	}

	OutContainer = CinewareEnum[Index];
	return true;
}

bool UCinewareAssetInstance::SetInt(const FString& Name, int DescId, const int Value)
{
	int Index = ContainsIntKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareInteger[Index].Value = Value;
	return true;
}

bool UCinewareAssetInstance::SetBool(const FString& Name, int DescId, const bool Value)
{
	int Index = ContainsBoolKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareBool[Index].Value = Value;
	return true;
}

bool UCinewareAssetInstance::SetFloat(const FString& Name, int DescId, const float Value)
{
	int Index = ContainsFloatKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareFloat[Index].Value = Value;
	return true;
}

bool UCinewareAssetInstance::SetString(const FString& Name, int DescId, const FString Value)
{
	int Index = ContainsStringKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareString[Index].Value = Value;
	return true;
}

bool UCinewareAssetInstance::SetVector3(const FString& Name, int DescId, const FVector Value)
{
	int Index = ContainsVector3Key(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	auto vec = CinewareVector3[Index];
	vec.Value = Value;

	if (vec.IsAbstraction)
	{
		SetFloat(vec.XId, DescId, Value.X);
		SetFloat(vec.YId, DescId, Value.Y);
		SetFloat(vec.ZId, DescId, Value.Z);
	}

	CinewareVector3[Index] = vec;
	return true;
}

bool UCinewareAssetInstance::SetColor(const FString& Name, int DescId, const FLinearColor Value)
{
	int Index = ContainsColorKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareColor[Index].Value = Value;
	return true;
}

bool UCinewareAssetInstance::SetEnumByOrder(const FString& Name, int DescId, const int Value)
{
	int Index = ContainsEnumKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	CinewareEnum[Index].Value = CinewareEnum[Index].Ids[Value];
	return true;
}

bool UCinewareAssetInstance::SetEnumByLabel(const FString& Name, int DescId, const FString Value)
{
	int Index = ContainsEnumKey(Name, DescId);
	if (Index == CW_INVALID_IDX)
	{
		return false;
	}

	int NewValue = -1;
	if (CinewareEnum[Index].Collection.Find(Value, NewValue))
	{
		CinewareEnum[Index].Value = CinewareEnum[Index].Ids[NewValue];
		return true;
	}

	return false;
}

bool UCinewareAssetInstance::GetNextInput(FCinewareDataContainer*& OutContainer)
{
	return FindNextSortedElement(OutContainer, true);
}

void UCinewareAssetInstance::SetSourcefilePath(FString SrcFilePath)
{
	SourceFilePath = SrcFilePath;
}

FString UCinewareAssetInstance::GetSourceFilePath()
{
	return SourceFilePath;
}

void UCinewareAssetInstance::SetSourcefilePathAbs(FString SrcFilePath)
{
	SourceFilePathAbs = SrcFilePath;
}

FString UCinewareAssetInstance::GetSourceFilePathAbs()
{
	return SourceFilePathAbs;
}

bool UCinewareAssetInstance::GetNextInt(FCinewareDataContainerInt& OutContainer)
{
	if (CurrentIntIt >= CinewareInteger.Num())
	{
		return false;
	}

	OutContainer = CinewareInteger[CurrentIntIt];
	CurrentIntIt++;

	HasNextInt = CurrentIntIt < CinewareInteger.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextString(FCinewareDataContainerString& OutContainer)
{
	if (CurrentStringIt >= CinewareString.Num())
	{
		return false;
	}

	OutContainer = CinewareString[CurrentStringIt];
	CurrentStringIt++;

	HasNextString = CurrentStringIt < CinewareString.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextFloat(FCinewareDataContainerFloat& OutContainer)
{
	if (CurrentFloatIt >= CinewareFloat.Num())
	{
		return false;
	}

	OutContainer = CinewareFloat[CurrentFloatIt];
	CurrentFloatIt++;

	HasNextFloat = CurrentFloatIt < CinewareFloat.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextBool(FCinewareDataContainerBool& OutContainer)
{
	if (CurrentBoolIt >= CinewareBool.Num())
	{
		return false;
	}

	OutContainer = CinewareBool[CurrentBoolIt];
	CurrentBoolIt++;

	HasNextBool = CurrentBoolIt < CinewareBool.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextVector3(FCinewareDataContainerVec3& OutContainer)
{
	if (CurrentVector3It >= CinewareVector3.Num())
	{
		return false;
	}

	OutContainer = CinewareVector3[CurrentVector3It];
	CurrentVector3It++;

	HasNextVector3 = CurrentVector3It < CinewareVector3.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextColor(FCinewareDataContainerColor& OutContainer)
{
	if (CurrentColorIt >= CinewareColor.Num())
	{
		return false;
	}

	OutContainer = CinewareColor[CurrentColorIt];
	CurrentColorIt++;

	HasNextColor = CurrentColorIt < CinewareColor.Num();
	return true;
}

bool UCinewareAssetInstance::GetNextEnum(FCinewareDataContainerEnum& OutContainer)
{
	if (CurrentEnumIt >= CinewareEnum.Num())
	{
		return false;
	}

	OutContainer = CinewareEnum[CurrentEnumIt];
	CurrentEnumIt++;

	HasNextEnum = CurrentEnumIt < CinewareEnum.Num();
	return true;
}

template <typename T>
bool Reset(const int Index, TArray<T>& Values, const TArray<T>& Defaults)
{
	if (Index == CW_INVALID_IDX)
		return false;

	Values[Index] = Defaults[Index];
	return true;
}

bool UCinewareAssetInstance::ResetInt(const FString& Name, int DescId)
{
	return Reset(ContainsIntKey(Name, DescId), CinewareInteger, CinewareIntegerDefault);
}

bool UCinewareAssetInstance::ResetFloat(const FString& Name, int DescId)
{
	return Reset(ContainsFloatKey(Name, DescId), CinewareFloat, CinewareFloatDefault);
}

bool UCinewareAssetInstance::ResetBool(const FString& Name, int DescId)
{
	return Reset(ContainsBoolKey(Name, DescId), CinewareBool, CinewareBoolDefault);
}

bool UCinewareAssetInstance::ResetString(const FString& Name, int DescId)
{
	return Reset(ContainsStringKey(Name, DescId), CinewareString, CinewareStringDefault);
}

bool UCinewareAssetInstance::ResetVector3(const FString& Name, int DescId)
{
	return Reset(ContainsVector3Key(Name, DescId), CinewareVector3, CinewareVector3Default);
}

bool UCinewareAssetInstance::ResetColor(const FString& Name, int DescId)
{
	return Reset(ContainsColorKey(Name, DescId), CinewareColor, CinewareColorDefault);
}

bool UCinewareAssetInstance::ResetEnum(const FString& Name, int DescId)
{
	return Reset(ContainsEnumKey(Name, DescId), CinewareEnum, CinewareEnumDefault);
}

template <typename T>
bool IsDefault(const int Index, const TArray<T>& Values, const TArray<T>& Defaults)
{
	if (Index == CW_INVALID_IDX)
		return false;

	return Values[Index].Value == Defaults[Index].Value;
}

bool UCinewareAssetInstance::IsIntDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsIntKey(Name, DescId), CinewareInteger, CinewareIntegerDefault);
}

bool UCinewareAssetInstance::IsFloatDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsFloatKey(Name, DescId), CinewareFloat, CinewareFloatDefault);
}

bool UCinewareAssetInstance::IsBoolDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsBoolKey(Name, DescId), CinewareBool, CinewareBoolDefault);
}

bool UCinewareAssetInstance::IsStringDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsStringKey(Name, DescId), CinewareString, CinewareStringDefault);
}

bool UCinewareAssetInstance::IsVector3Default(const FString& Name, int DescId) const
{
	return IsDefault(ContainsVector3Key(Name, DescId), CinewareVector3, CinewareVector3Default);
}

bool UCinewareAssetInstance::IsColorDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsColorKey(Name, DescId), CinewareColor, CinewareColorDefault);
}

bool UCinewareAssetInstance::IsEnumDefault(const FString& Name, int DescId) const
{
	return IsDefault(ContainsEnumKey(Name, DescId), CinewareEnum, CinewareEnumDefault);
}

void UCinewareAssetInstance::SetToDefaultValues()
{
	CinewareInteger.Empty();
	CinewareFloat.Empty();
	CinewareBool.Empty();
	CinewareString.Empty();
	CinewareVector3.Empty();
	CinewareColor.Empty();
	CinewareEnum.Empty();

	for (size_t i = 0; i < CinewareIntegerDefault.Num(); ++i)
	{
		CinewareInteger.Add(CinewareIntegerDefault[i]);
	}
	for (size_t i = 0; i < CinewareFloatDefault.Num(); ++i)
	{
		CinewareFloat.Add(CinewareFloatDefault[i]);
	}
	for (size_t i = 0; i < CinewareBoolDefault.Num(); ++i)
	{
		CinewareBool.Add(CinewareBoolDefault[i]);
	}
	for (size_t i = 0; i < CinewareStringDefault.Num(); ++i)
	{
		CinewareString.Add(CinewareStringDefault[i]);
	}
	for (size_t i = 0; i < CinewareVector3Default.Num(); ++i)
	{
		CinewareVector3.Add(CinewareVector3Default[i]);
	}
	for (size_t i = 0; i < CinewareColorDefault.Num(); ++i)
	{
		CinewareColor.Add(CinewareColorDefault[i]);
	}
	for (size_t i = 0; i < CinewareEnumDefault.Num(); ++i)
	{
		CinewareEnum.Add(CinewareEnumDefault[i]);
	}

	BeginIteration();
}

void UCinewareAssetInstance::BeginIteration()
{
	CurrentInputIteration = 0;

	CurrentIntIt = 0;
	CurrentFloatIt = 0;
	CurrentBoolIt = 0;
	CurrentStringIt = 0;
	CurrentVector3It = 0;
	CurrentColorIt = 0;
	CurrentEnumIt = 0;

	HasNextInt = CurrentIntIt < CinewareInteger.Num();
	HasNextFloat = CurrentFloatIt < CinewareFloat.Num();
	HasNextString = CurrentStringIt < CinewareString.Num();
	HasNextBool = CurrentBoolIt < CinewareBool.Num();
	HasNextVector3 = CurrentVector3It < CinewareVector3.Num();
	HasNextColor = CurrentColorIt < CinewareColor.Num();
	HasNextEnum = CurrentEnumIt < CinewareEnum.Num();
}

bool UCinewareAssetInstance::GetNextInputType(TEnumAsByte<ECinewareDataType>& OutType)
{
	FCinewareDataContainer* out = nullptr;
	if (!FindNextSortedElement(out))
	{
		OutType = CW_UNDEF;
		return false;
	}

	OutType = out->Type;
	return true;
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerInt container)
{
	container.Sort = CurrentSortCtr++;
	CinewareInteger.Add(container);
	CinewareIntegerDefault.Add(container);
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerFloat container)
{
	container.Sort = CurrentSortCtr++;
	CinewareFloat.Add(container);
	CinewareFloatDefault.Add(container);
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerFloat container, FString VectorId)
{
	container.Sort = CurrentSortCtr++;
	CinewareFloat.Add(container);
	CinewareFloatDefault.Add(container);

	if (!container.IsAbstracted)
	{
		return;
	}

	if (ContainsVector3Key(VectorId, container.DescId) == CW_INVALID_IDX)
	{
		RegisterProperty(FCinewareDataContainerVec3(VectorId, FVector::ZeroVector, container.DescId));
	}

	FCinewareDataContainerVec3 OutData;
	if (GetVector3(VectorId, container.DescId, OutData))
	{
		OutData.IsAbstraction = true;
		switch (container.Axis)
		{
		case EAxis::X:
			OutData.XId = container.Name;
			OutData.Value.X = container.Value;
			OutData.DescId = container.DescId;
			break;
		case EAxis::Y:
			OutData.YId = container.Name;
			OutData.Value.Y = container.Value;
			OutData.DescId = container.DescId;
			break;
		case EAxis::Z:
			OutData.ZId = container.Name;
			OutData.Value.Z = container.Value;
			OutData.DescId = container.DescId;
			break;
		}

		RegisterProperty(OutData);
	}
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerBool container)
{
	int Index = ContainsBoolKey(container.Name, container.DescId);

	if (Index == CW_INVALID_IDX)
	{
		container.Sort = CurrentSortCtr++;
		CinewareBool.Add(container);
		CinewareBoolDefault.Add(container);
	}
	else
	{
		CinewareBool[Index] = container;
		CinewareBoolDefault[Index] = container;
	}
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerString container)
{
	int Index = ContainsStringKey(container.Name, container.DescId);

	if (Index == CW_INVALID_IDX)
	{
		container.Sort = CurrentSortCtr++;
		CinewareString.Add(container);
		CinewareStringDefault.Add(container);
	}
	else
	{
		CinewareString[Index] = container;
		CinewareStringDefault[Index] = container;
	}
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerVec3 container)
{
	int Index = ContainsVector3Key(container.Name, container.DescId);

	if (Index == CW_INVALID_IDX)
	{
		container.Sort = CurrentSortCtr++;
		CinewareVector3.Add(container);
		CinewareVector3Default.Add(container);
	}
	else
	{
		CinewareVector3[Index] = container;
		CinewareVector3Default[Index] = container;
	}
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerColor container)
{
	int Index = ContainsColorKey(container.Name, container.DescId);

	if (Index == CW_INVALID_IDX)
	{
		container.Sort = CurrentSortCtr++;
		CinewareColor.Add(container);
		CinewareColorDefault.Add(container);
	}
	else
	{
		CinewareColor[Index] = container;
		CinewareColorDefault[Index] = container;
	}
}

void UCinewareAssetInstance::RegisterProperty(FCinewareDataContainerEnum container)
{
	int Index = ContainsEnumKey(container.Name, container.DescId);

	if (Index == CW_INVALID_IDX)
	{
		container.Sort = CurrentSortCtr++;
		CinewareEnum.Add(container);
		CinewareEnumDefault.Add(container);
	}
	else
	{
		CinewareEnum[Index] = container;
		CinewareEnumDefault[Index] = container;
	}
}

void UCinewareAssetInstance::ClearEntries()
{
	CinewareInteger.Empty();
	CinewareFloat.Empty();
	CinewareBool.Empty();
	CinewareString.Empty();
	CinewareVector3.Empty();
	CinewareColor.Empty();
	CinewareEnum.Empty();

	CinewareIntegerDefault.Empty();
	CinewareFloatDefault.Empty();
	CinewareBoolDefault.Empty();
	CinewareStringDefault.Empty();
	CinewareVector3Default.Empty();
	CinewareColorDefault.Empty();
	CinewareEnumDefault.Empty();
}

int UCinewareAssetInstance::ContainsIntKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareInteger.Num(); ++Index)
	{
		if (CinewareInteger[Index].Name == key && CinewareInteger[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsFloatKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareFloat.Num(); ++Index)
	{
		if (CinewareFloat[Index].Name == key && CinewareFloat[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsBoolKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareBool.Num(); ++Index)
	{
		if (CinewareBool[Index].Name == key && CinewareBool[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsStringKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareString.Num(); ++Index)
	{
		if (CinewareString[Index].Name == key && CinewareString[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsVector3Key(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareVector3.Num(); ++Index)
	{
		if (CinewareVector3[Index].Name == key && CinewareVector3[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsColorKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareColor.Num(); ++Index)
	{
		if (CinewareColor[Index].Name == key && CinewareColor[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

int UCinewareAssetInstance::ContainsEnumKey(const FString& key, const int DescId) const
{
	for (int Index = 0; Index < CinewareEnum.Num(); ++Index)
	{
		if (CinewareEnum[Index].Name == key && CinewareEnum[Index].DescId == DescId)
		{
			return Index;
		}
	}

	return CW_INVALID_IDX;
}

bool UCinewareAssetInstance::FindNextSortedElement(FCinewareDataContainer*& OutContainer, bool increment)
{
	TArray<FCinewareDataContainer*> Front{};

	if (CurrentIntIt < CinewareInteger.Num())
	{
		Front.Add(&CinewareInteger[CurrentIntIt]);
	}

	if (CurrentFloatIt < CinewareFloat.Num())
	{
		Front.Add(&CinewareFloat[CurrentFloatIt]);
	}

	if (CurrentBoolIt < CinewareBool.Num())
	{
		Front.Add(&CinewareBool[CurrentBoolIt]);
	}

	if (CurrentStringIt < CinewareString.Num())
	{
		Front.Add(&CinewareString[CurrentStringIt]);
	}

	if (CurrentVector3It < CinewareVector3.Num())
	{
		Front.Add(&CinewareVector3[CurrentVector3It]);
	}

	if (CurrentColorIt < CinewareColor.Num())
	{
		Front.Add(&CinewareColor[CurrentColorIt]);
	}

	if (CurrentEnumIt < CinewareEnum.Num())
	{
		Front.Add(&CinewareEnum[CurrentEnumIt]);
	}

	if (Front.Num() == 0)
	{
		return false;
	}

	Front.Sort([](const FCinewareDataContainer& a, const FCinewareDataContainer& b) { return a.Sort < b.Sort; });

	OutContainer = Front[0];

	if (increment)
	{
		switch (OutContainer->Type)
		{
		case CW_INT:
			CurrentIntIt++;
			break;

		case CW_FLOAT:
			CurrentFloatIt++;
			break;

		case CW_BOOL:
			CurrentBoolIt++;
			break;

		case CW_STRING:
			CurrentStringIt++;
			break;

		case CW_VECTOR3:
			CurrentVector3It++;
			break;

		case CW_COLOR:
			CurrentColorIt++;
			break;

		case CW_ENUM:
			CurrentEnumIt++;
			break;

		default:
			break;
		}
	}

	return true;
}

TMap<ECinewareDataType, TArray<TPair<FString, int>>> UCinewareAssetInstance::GetAllEntryKeys()
{
	TMap<ECinewareDataType, TArray<TPair<FString, int>>> EntryKeysTemp;
	EntryKeysTemp.Emplace(ECinewareDataType::CW_INT, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_FLOAT, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_BOOL, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_STRING, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_VECTOR3, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_COLOR, TArray<TPair<FString, int>>());
	EntryKeysTemp.Emplace(ECinewareDataType::CW_ENUM, TArray<TPair<FString, int>>());

	for (int Index = 0; Index < CinewareInteger.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_INT].Add(MakeTuple(CinewareInteger[Index].Name, CinewareInteger[Index].DescId));
	}

	for (int Index = 0; Index < CinewareFloat.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_FLOAT].Add(MakeTuple(CinewareFloat[Index].Name, CinewareFloat[Index].DescId));
	}

	for (int Index = 0; Index < CinewareBool.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_BOOL].Add(MakeTuple(CinewareBool[Index].Name, CinewareBool[Index].DescId));
	}

	for (int Index = 0; Index < CinewareString.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_STRING].Add(MakeTuple(CinewareString[Index].Name, CinewareString[Index].DescId));
	}

	for (int Index = 0; Index < CinewareVector3.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_VECTOR3].Add(MakeTuple(CinewareVector3[Index].Name, CinewareVector3[Index].DescId));
	}

	for (int Index = 0; Index < CinewareEnum.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_ENUM].Add(MakeTuple(CinewareEnum[Index].Name, CinewareEnum[Index].DescId));
	}

	for (int Index = 0; Index < CinewareColor.Num(); ++Index)
	{
		EntryKeysTemp[ECinewareDataType::CW_COLOR].Add(MakeTuple(CinewareColor[Index].Name, CinewareColor[Index].DescId));
	}

#ifdef __MAC
	return EntryKeysTemp;
#else
	return std::move(EntryKeysTemp);
#endif // __MAC
}

void UCinewareAssetInstance::RemoveEntry(FString key, int DescId, ECinewareDataType DataType)
{
	int Index;

	switch (DataType)
	{
	case CW_INT:
		Index = ContainsIntKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareInteger.RemoveAt(Index);
		break;

	case CW_FLOAT:
		Index = ContainsFloatKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareFloat.RemoveAt(Index);
		break;

	case CW_BOOL:
		Index = ContainsBoolKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareBool.RemoveAt(Index);
		break;

	case CW_STRING:
		Index = ContainsStringKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareString.RemoveAt(Index);
		break;

	case CW_VECTOR3:
		Index = ContainsVector3Key(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareVector3.RemoveAt(Index);
		break;

	case CW_COLOR:
		Index = ContainsColorKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareColor.RemoveAt(Index);
		break;

	case CW_ENUM:
		Index = ContainsEnumKey(key, DescId);
		if (Index != CW_INVALID_IDX)
			CinewareEnum.RemoveAt(Index);
		break;

	default:
		break;
	}
}