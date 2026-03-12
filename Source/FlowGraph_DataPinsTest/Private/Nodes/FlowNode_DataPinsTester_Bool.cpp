// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Bool.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Bool)

UFlowNode_DataPinsTester_Bool::UFlowNode_DataPinsTester_Bool()
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Bool_Wrapped_Input.bIsInputPin = true;
	Bool_Wrapped_Input.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_Bool::ExecuteInput(const FName& PinName)
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

	// Test bool single input
	{
		bool Value = false;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Bool_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Bool>(INPIN_Name, Value);
		LogResults<bool>(INPIN_Name, ResultEnum, TArray<bool>{Value}, [](const bool& Val) { return Val ? TEXT("true") : TEXT("false"); });
	}

	// Test bool array input
	{
		TArray<bool> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Bool_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Bool>(INPIN_Name, Values);
		LogResults<bool>(INPIN_Name, ResultEnum, Values, [](const bool& Val) { return Val ? TEXT("true") : TEXT("false"); });
	}

	// Test renamed bool array input
	{
		TArray<bool> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Bool_Renamed_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Bool>(INPIN_Name, Values);
		LogResults<bool>(INPIN_Name, ResultEnum, Values, [](const bool& Val) { return Val ? TEXT("true") : TEXT("false"); });
	}

	// Test wrapped bool input
	{
		TArray<bool> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Bool_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Bool>(INPIN_Name, Values);
		LogResults<bool>(INPIN_Name, ResultEnum, Values, [](const bool& Val) { return Val ? TEXT("true") : TEXT("false"); });
	}

	// #FlowDataPinLegacy
	{
		bool Value = false;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Bool_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Bool>(INPIN_Name, Value);
		LogResults<bool>(INPIN_Name, ResultEnum, { Value }, [](const bool& Val) { return Val ? TEXT("true") : TEXT("false"); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Bool::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}