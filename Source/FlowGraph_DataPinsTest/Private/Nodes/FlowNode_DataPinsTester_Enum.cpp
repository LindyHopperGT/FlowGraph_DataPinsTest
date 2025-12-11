// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Enum.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Enum)

UFlowNode_DataPinsTester_Enum::UFlowNode_DataPinsTester_Enum(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Enum_Wrapped_Input.bIsInputPin = true;
	Enum_Wrapped_Input.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_Enum::ExecuteInput(const FName& PinName)
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

	// Test enum single input
	{
		EFlowNodeState Value = EFlowNodeState::Invalid;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Enum_Single_Input);
		ResultEnum = TryResolveDataPinValue<EFlowNodeState>(INPIN_Name, Value);
		LogResults<EFlowNodeState>(INPIN_Name, ResultEnum, TArray<EFlowNodeState>{Value}, [](const EFlowNodeState& Val) { return UEnum::GetDisplayValueAsText(Val).ToString(); });
	}

	// Test enum array input
	{
		TArray<EFlowNodeState> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Enum_Array_Input);
		ResultEnum = TryResolveDataPinValues<EFlowNodeState>(INPIN_Name, Values);
		LogResults<EFlowNodeState>(INPIN_Name, ResultEnum, Values, [](const EFlowNodeState& Val) { return UEnum::GetDisplayValueAsText(Val).ToString(); });
	}

	// Test wrapped enum input
	{
		TArray<EFlowNodeState> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Enum_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<EFlowNodeState>(INPIN_Name, Values);
		LogResults<EFlowNodeState>(INPIN_Name, ResultEnum, Values, [](const EFlowNodeState& Val) { return UEnum::GetDisplayValueAsText(Val).ToString(); });
	}

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Enum::TrySupplyDataPin_Implementation(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin_Implementation(PinName);
	return DataPinResult;
}