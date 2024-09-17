// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AllAutoRawDataOutputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AllAutoRawDataOutputs)

FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_BoolOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Int8Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Int16Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Int32Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Int64Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Uint8Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Uint16Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Uint32Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Uint64Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Float32Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_Float64Output;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_NameOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_StringOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_TextOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_EnumOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_VectorOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_TransformOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_GameplayTagOutput;
FName UFlowNode_AllAutoRawDataOutputs::OUTPIN_GameplayTagContainerOutput;

UFlowNode_AllAutoRawDataOutputs::UFlowNode_AllAutoRawDataOutputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	if (OUTPIN_BoolOutput.IsNone())
	{
		OUTPIN_BoolOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, BoolOutput);
		OUTPIN_Int8Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int8Output);
		OUTPIN_Int16Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int16Output);
		OUTPIN_Int32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int32Output);
		OUTPIN_Int64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Int64Output);
		OUTPIN_Uint8Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint8Output);
		OUTPIN_Uint16Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint16Output);
		OUTPIN_Uint32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint32Output);
		OUTPIN_Uint64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Uint64Output);
		OUTPIN_Float32Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Float32Output);
		OUTPIN_Float64Output = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, Float64Output);
		OUTPIN_NameOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, NameOutput);
		OUTPIN_StringOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, StringOutput);
		OUTPIN_TextOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, TextOutput);
		OUTPIN_EnumOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, EnumOutput);
		OUTPIN_VectorOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, VectorOutput);
		OUTPIN_TransformOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, TransformOutput);
		OUTPIN_GameplayTagOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, GameplayTagOutput);
		OUTPIN_GameplayTagContainerOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllAutoRawDataOutputs, GameplayTagContainerOutput);
	}
}

void UFlowNode_AllAutoRawDataOutputs::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_Bool UFlowNode_AllAutoRawDataOutputs::TrySupplyDataPinAsBool_Implementation(const FName& PinName) const
{
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
