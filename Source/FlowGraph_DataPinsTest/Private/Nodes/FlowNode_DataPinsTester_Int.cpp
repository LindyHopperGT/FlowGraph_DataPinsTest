// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Int.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Int)

UFlowNode_DataPinsTester_Int::UFlowNode_DataPinsTester_Int()
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Int32_Wrapped_Output.bIsInputPin = false;
	Int32_Wrapped_Output.MultiType = EFlowDataMultiType::Array;

	Int64_Wrapped_Output.bIsInputPin = false;
	Int64_Wrapped_Output.MultiType = EFlowDataMultiType::Array;

	Int64_Wrapped_Input.bIsInputPin = true;
	Int64_Wrapped_Input.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_Int::ExecuteInput(const FName& PinName)
{
	if (!bIsResolver)
	{
		constexpr bool bFinish = true;
		TriggerFirstOutput(bFinish);
		return;
	}

	using namespace FlowPinType;

	FName INPIN_Name;
	EFlowDataPinResolveResult ResultEnum = EFlowDataPinResolveResult::Invalid;

	// Test int32 single input
	{
		int32 Value = 0;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int32_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Int>(INPIN_Name, Value);
		LogResults<int32>(INPIN_Name, ResultEnum, TArray<int32>{Value}, [](const int32& Val) { return FString::FromInt(Val); });
	}

	// Test int64 single input
	{
		int64 Value = 0;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int64_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Int64>(INPIN_Name, Value);
		LogResults<int64>(INPIN_Name, ResultEnum, TArray<int64>{Value}, [](const int64& Val) { return FString::Printf(TEXT("%lld"), Val); });
	}

	// Test int32 array input
	{
		TArray<int32> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int32_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Int>(INPIN_Name, Values);
		LogResults<int32>(INPIN_Name, ResultEnum, Values, [](const int32& Val) { return FString::FromInt(Val); });
	}

	// Test wrapped int64 input
	{
		TArray<int64> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int64_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Int64>(INPIN_Name, Values);
		LogResults<int64>(INPIN_Name, ResultEnum, Values, [](const int64& Val) { return FString::Printf(TEXT("%lld"), Val); });
	}

	// #FlowDataPinLegacy
	{
		int32 Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int32_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Int>(INPIN_Name, Value);
		LogResults<int32>(INPIN_Name, ResultEnum, { Value }, [](const int32& Val) { return FString::FromInt(Val); });
	}

	{
		int64 Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Int64_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Int64>(INPIN_Name, Value);
		LogResults<int64>(INPIN_Name, ResultEnum, { Value }, [](const int64& Val) { return FString::Printf(TEXT("%lld"), Val); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Int::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}