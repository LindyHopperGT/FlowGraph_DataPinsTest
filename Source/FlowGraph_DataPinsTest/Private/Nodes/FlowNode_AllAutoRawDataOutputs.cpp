// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AllAutoRawDataOutputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AllAutoRawDataOutputs)

UFlowNode_AllAutoRawDataOutputs::UFlowNode_AllAutoRawDataOutputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_AllAutoRawDataOutputs::ExecuteInput(const FName& PinName)
{
	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_Bool UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsBool_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_BoolOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, BoolOutput);

	FFlowDataPinResult_Bool Result;
	if (PinName == OUTPIN_BoolOutput)
	{
		Result = FFlowDataPinResult_Bool(BoolOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsBool_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), Result.Value ? TEXT("true") : TEXT("false"), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Int UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsInt_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_Int8Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int8Output);
	static const FName OUTPIN_Int16Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int16Output);
	static const FName OUTPIN_Int32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int32Output);
	static const FName OUTPIN_Int64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int64Output);
	static const FName OUTPIN_Uint8Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint8Output);
	static const FName OUTPIN_Uint16Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint16Output);
	static const FName OUTPIN_Uint32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint32Output);
	static const FName OUTPIN_Uint64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint64Output);

	FFlowDataPinResult_Int Result;

	if (PinName == OUTPIN_Int8Output)
	{
		Result = FFlowDataPinResult_Int(Int8Output);
	}
	else if (PinName == OUTPIN_Int16Output)
	{
		Result = FFlowDataPinResult_Int(Int16Output);
	}
	else if (PinName == OUTPIN_Int32Output)
	{
		Result = FFlowDataPinResult_Int(Int32Output);
	}
	else if (PinName == OUTPIN_Int64Output)
	{
		Result = FFlowDataPinResult_Int(Int64Output);
	}
	else if (PinName == OUTPIN_Uint8Output)
	{
		Result = FFlowDataPinResult_Int(Uint8Output);
	}
	else if (PinName == OUTPIN_Uint16Output)
	{
		Result = FFlowDataPinResult_Int(Uint16Output);
	}
	else if (PinName == OUTPIN_Uint32Output)
	{
		Result = FFlowDataPinResult_Int(Uint32Output);
	}
	else if (PinName == OUTPIN_Uint64Output)
	{
		Result = FFlowDataPinResult_Int(Uint64Output);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsInt_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %ld for pin %s"), *GetName(), Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Float UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsFloat_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_Float32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Float32Output);
	static const FName OUTPIN_Float64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Float64Output);

	FFlowDataPinResult_Float Result;

	if (PinName == OUTPIN_Float32Output)
	{
		Result = FFlowDataPinResult_Float(Float32Output);
	}
	else if (PinName == OUTPIN_Float64Output)
	{
		Result = FFlowDataPinResult_Float(Float64Output);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsFloat_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %.0f for pin %s"), *GetName(), Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Name UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsName_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_NameOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, NameOutput);

	FFlowDataPinResult_Name Result;
	if (PinName == OUTPIN_NameOutput)
	{
		Result = FFlowDataPinResult_Name(NameOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsName_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_String UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsString_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_StringOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, StringOutput);

	FFlowDataPinResult_String Result;
	if (PinName == OUTPIN_StringOutput)
	{
		Result = FFlowDataPinResult_String(StringOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsString_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Text UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsText_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_TextOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, TextOutput);

	FFlowDataPinResult_Text Result;
	if (PinName == OUTPIN_TextOutput)
	{
		Result = FFlowDataPinResult_Text(TextOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsText_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Enum UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsEnum_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_EnumOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, EnumOutput);

	FFlowDataPinResult_Enum Result;
	if (PinName == OUTPIN_EnumOutput)
	{
		// Enums always have to be so complicated...
		Result = FFlowDataPinResult_Enum::BuildResultFromNativeEnumValue(EnumOutput);

		// Also test the round-trip back to enum while we're here:
		const EFlowNodeState RoundTrip = Result.GetNativeEnumValue<EFlowNodeState, EFlowNodeState::Invalid>();
		check(RoundTrip == EnumOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsEnum_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Vector UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsVector_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_VectorOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, VectorOutput);

	FFlowDataPinResult_Vector Result;
	if (PinName == OUTPIN_VectorOutput)
	{
		Result = FFlowDataPinResult_Vector(VectorOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsVector_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Transform UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsTransform_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_TransformOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, TransformOutput);

	FFlowDataPinResult_Transform Result;
	if (PinName == OUTPIN_TransformOutput)
	{
		Result = FFlowDataPinResult_Transform(TransformOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsTransform_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_GameplayTag UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsGameplayTag_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_GameplayTagOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, GameplayTagOutput);

	FFlowDataPinResult_GameplayTag Result;
	if (PinName == OUTPIN_GameplayTagOutput)
	{
		Result = FFlowDataPinResult_GameplayTag(GameplayTagOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsGameplayTag_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_GameplayTagContainer UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsGameplayTagContainer_Implementation(const FName& PinName) const
{
	static const FName OUTPIN_GameplayTagContainerOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, GameplayTagContainerOutput);

	FFlowDataPinResult_GameplayTagContainer Result;
	if (PinName == OUTPIN_GameplayTagContainerOutput)
	{
		Result = FFlowDataPinResult_GameplayTagContainer(GameplayTagContainerOutput);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsGameplayTagContainer_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToStringSimple(), *PinName.ToString()));

	return Result;
}
