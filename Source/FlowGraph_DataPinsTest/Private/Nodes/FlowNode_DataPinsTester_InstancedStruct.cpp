// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_InstancedStruct.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"
#include "FlowTestInstancedStruct.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_InstancedStruct)

UFlowNode_DataPinsTester_InstancedStruct::UFlowNode_DataPinsTester_InstancedStruct(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	InstancedStruct_Wrapped_Input.bIsInputPin = true;
	InstancedStruct_Wrapped_Input.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_InstancedStruct::ExecuteInput(const FName& PinName)
{
	if (!bIsResolver)
	{
		constexpr bool bFinish = true;
		TriggerFirstOutput(bFinish);
		return;
	}

	using namespace FlowPinType;

	// Reusable lambda for FInstancedStruct formatting
	static const TFunction<FString(const FInstancedStruct&)> InstancedStructFormatter = [](const FInstancedStruct& Val)
		{
			if (Val.GetScriptStruct() == FFlowTestInstancedStruct::StaticStruct())
			{
				const FFlowTestInstancedStruct& TestStruct = Val.Get<FFlowTestInstancedStruct>();
				return FString::Printf(TEXT("%s::IntProperty (%s)"), *Val.GetScriptStruct()->GetName(), *FString::FromInt(TestStruct.IntProperty));
			}
			if (Val.GetScriptStruct())
			{
				return Val.GetScriptStruct()->GetName();
			}
			return FString(TEXT("None"));
		};

	FName INPIN_Name;
	EFlowDataPinResolveResult ResultEnum = EFlowDataPinResolveResult::Invalid;

	// Test Untyped FInstancedStruct single input
	{
		FInstancedStruct Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_Untyped_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_InstancedStruct>(INPIN_Name, Value);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, TArray<FInstancedStruct>{Value}, InstancedStructFormatter);
	}

	// Test Typed FInstancedStruct single input
	{
		FInstancedStruct Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_Typed_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_InstancedStruct>(INPIN_Name, Value);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, TArray<FInstancedStruct>{Value}, InstancedStructFormatter);
	}

	// Test Templatized FInstancedStruct single input
	{
		FInstancedStruct Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_Templatized_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_InstancedStruct>(INPIN_Name, Value);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, TArray<FInstancedStruct>{Value}, InstancedStructFormatter);
	}

	// Test FInstancedStruct array input
	{
		TArray<FInstancedStruct> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_InstancedStruct>(INPIN_Name, Values);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, Values, InstancedStructFormatter);
	}

	// Test wrapped FInstancedStruct input
	{
		TArray<FInstancedStruct> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_InstancedStruct>(INPIN_Name, Values);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, Values, InstancedStructFormatter);
	}

	// #FlowDataPinLegacy
	{
		FInstancedStruct Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedStruct_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_InstancedStruct>(INPIN_Name, Value);
		LogResults<FInstancedStruct>(INPIN_Name, ResultEnum, { Value }, InstancedStructFormatter);
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_InstancedStruct::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}