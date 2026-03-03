#include "Nodes/FlowNode_DataPinsTester_GameplayTag.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_GameplayTag)

UFlowNode_DataPinsTester_GameplayTag::UFlowNode_DataPinsTester_GameplayTag(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	GameplayTag_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
	GameplayTagContainer_Wrapped_Output.MultiType = EFlowDataMultiType::Single;

	GameplayTag_Wrapped_Input.bIsInputPin = true;
	GameplayTag_Wrapped_Input.MultiType = EFlowDataMultiType::Array;

	GameplayTagContainer_Wrapped_Input.bIsInputPin = true;
#endif
}

void UFlowNode_DataPinsTester_GameplayTag::ExecuteInput(const FName& PinName)
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

	// Test FGameplayTag single input
	{
		FGameplayTag Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTag_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_GameplayTag>(INPIN_Name, Value);
		LogResults<FGameplayTag>(INPIN_Name, ResultEnum, TArray<FGameplayTag>{Value}, [](const FGameplayTag& Val) { return Val.ToString(); });
	}

	// Test FGameplayTagContainer single input
	{
		FGameplayTagContainer Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTagContainer_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_GameplayTagContainer>(INPIN_Name, Value);
		LogResults<FGameplayTagContainer>(INPIN_Name, ResultEnum, TArray<FGameplayTagContainer>{Value}, [](const FGameplayTagContainer& Val) { return Val.ToString(); });
	}

	// Test FGameplayTag array input
	{
		TArray<FGameplayTag> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTag_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_GameplayTag>(INPIN_Name, Values);
		LogResults<FGameplayTag>(INPIN_Name, ResultEnum, Values, [](const FGameplayTag& Val) { return Val.ToString(); });
	}

	// Test wrapped FGameplayTag input
	{
		TArray<FGameplayTag> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTag_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_GameplayTag>(INPIN_Name, Values);
		LogResults<FGameplayTag>(INPIN_Name, ResultEnum, Values, [](const FGameplayTag& Val) { return Val.ToString(); });
	}

	// Test wrapped FGameplayTagContainer input
	{
		FGameplayTagContainer Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTagContainer_Wrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_GameplayTagContainer>(INPIN_Name, Value);
		LogResults<FGameplayTagContainer>(INPIN_Name, ResultEnum, TArray<FGameplayTagContainer>{Value}, [](const FGameplayTagContainer& Val) { return Val.ToString(); });
	}

	// Extract wrapped FGameplayTagContainer input again as TArray<FGameplayTag>
	{
		TArray<FGameplayTag> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTagContainer_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_GameplayTag>(INPIN_Name, Values);
		LogResults<FGameplayTag>(INPIN_Name, ResultEnum, Values, [](const FGameplayTag& Val) { return Val.ToString(); });
	}

	// #FlowDataPinLegacy
	{
		FGameplayTag Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTag_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_GameplayTag>(INPIN_Name, Value);
		LogResults<FGameplayTag>(INPIN_Name, ResultEnum, { Value }, [](const FGameplayTag& Val) { return Val.ToString(); });
	}

	{
		FGameplayTagContainer Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, GameplayTagContainer_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_GameplayTagContainer>(INPIN_Name, Value);
		LogResults<FGameplayTagContainer>(INPIN_Name, ResultEnum, { Value }, [](const FGameplayTagContainer& Val) { return Val.ToStringSimple(); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_GameplayTag::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}