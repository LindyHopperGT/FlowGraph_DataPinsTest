// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Object.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Object)

UFlowNode_DataPinsTester_Object::UFlowNode_DataPinsTester_Object(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Class_Wrapped_Input.bIsInputPin = true;
	Class_Wrapped_Input.MultiType = EFlowDataMultiType::Array;

	Object_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
	Class_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_Object::ExecuteInput(const FName& PinName)
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

	// Test UObject single input
	{
		TObjectPtr<UObject> Value = nullptr;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Object_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Object>(INPIN_Name, Value);
		LogResults<TObjectPtr<UObject>>(INPIN_Name, ResultEnum, TArray<TObjectPtr<UObject>>{Value}, [](const TObjectPtr<UObject> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test Instanced UObject single input
	{
		TObjectPtr<UObject> Value = nullptr;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedObject_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Object>(INPIN_Name, Value);
		LogResults<TObjectPtr<UObject>>(INPIN_Name, ResultEnum, TArray<TObjectPtr<UObject>>{Value}, [](const TObjectPtr<UObject> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test UClass single input
	{
		TObjectPtr<UClass> Value = nullptr;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Class_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Class>(INPIN_Name, Value);
		LogResults<TObjectPtr<UClass>>(INPIN_Name, ResultEnum, TArray<TObjectPtr<UClass>>{Value}, [](const TObjectPtr<UClass> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test UObject array input
	{
		TArray<TObjectPtr<UObject>> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Object_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Object>(INPIN_Name, Values);
		LogResults<TObjectPtr<UObject>>(INPIN_Name, ResultEnum, Values, [](const TObjectPtr<UObject> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test Instanced UObject array input
	{
		TArray<TObjectPtr<UObject>> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, InstancedObject_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Object>(INPIN_Name, Values);
		LogResults<TObjectPtr<UObject>>(INPIN_Name, ResultEnum, Values, [](const TObjectPtr<UObject> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test UClass array input
	{
		TArray<TObjectPtr<UClass>> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Class_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Class>(INPIN_Name, Values);
		LogResults<TObjectPtr<UClass>>(INPIN_Name, ResultEnum, Values, [](const TObjectPtr<UClass> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// Test wrapped UClass input
	{
		TArray<TObjectPtr<UClass>> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Class_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Class>(INPIN_Name, Values);
		LogResults<TObjectPtr<UClass>>(INPIN_Name, ResultEnum, Values, [](const TObjectPtr<UClass> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	// #FlowDataPinLegacy
	{
		TObjectPtr<UObject> Value = nullptr;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Object_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Object>(INPIN_Name, Value);
		LogResults<TObjectPtr<UObject>>(INPIN_Name, ResultEnum, { Value }, [](const TObjectPtr<UObject> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}

	{
		TObjectPtr<UClass> Value = nullptr;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Class_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Class>(INPIN_Name, Value);
		LogResults<TObjectPtr<UClass>>(INPIN_Name, ResultEnum, { Value }, [](const TObjectPtr<UClass> Val) { return Val ? Val->GetName() : TEXT("None"); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Object::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}