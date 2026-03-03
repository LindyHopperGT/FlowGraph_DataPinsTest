// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Struct.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Struct)

UFlowNode_DataPinsTester_Struct::UFlowNode_DataPinsTester_Struct(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Vector_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
	Rotator_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
	Transform_Wrapped_Output.MultiType = EFlowDataMultiType::Single;

	Transform_Wrapped_Input.bIsInputPin = true;
	Transform_Wrapped_Input.MultiType = EFlowDataMultiType::Array;
#endif
}

void UFlowNode_DataPinsTester_Struct::ExecuteInput(const FName& PinName)
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

	// Test FVector single input
	{
		FVector Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Vector_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Vector>(INPIN_Name, Value);
		LogResults<FVector>(INPIN_Name, ResultEnum, TArray<FVector>{Value}, [](const FVector& Val) { return Val.ToString(); });
	}

	// Test FRotator single input
	{
		FRotator Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Rotator_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Rotator>(INPIN_Name, Value);
		LogResults<FRotator>(INPIN_Name, ResultEnum, TArray<FRotator>{Value}, [](const FRotator& Val) { return Val.ToString(); });
	}

	// Test FTransform single input
	{
		FTransform Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Transform_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Transform>(INPIN_Name, Value);
		LogResults<FTransform>(INPIN_Name, ResultEnum, TArray<FTransform>{Value}, [](const FTransform& Val) { return Val.ToString(); });
	}

	// Test FVector array input
	{
		TArray<FVector> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Vector_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Vector>(INPIN_Name, Values);
		LogResults<FVector>(INPIN_Name, ResultEnum, Values, [](const FVector& Val) { return Val.ToString(); });
	}

	// Test FRotator array input
	{
		TArray<FRotator> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Rotator_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Rotator>(INPIN_Name, Values);
		LogResults<FRotator>(INPIN_Name, ResultEnum, Values, [](const FRotator& Val) { return Val.ToString(); });
	}

	// Test FTransform array input
	{
		TArray<FTransform> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Transform_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Transform>(INPIN_Name, Values);
		LogResults<FTransform>(INPIN_Name, ResultEnum, Values, [](const FTransform& Val) { return Val.ToString(); });
	}

	// Test wrapped FTransform input
	{
		TArray<FTransform> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Transform_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Transform>(INPIN_Name, Values);
		LogResults<FTransform>(INPIN_Name, ResultEnum, Values, [](const FTransform& Val) { return Val.ToString(); });
	}

	// #FlowDataPinLegacy
	{
		FVector Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Vector_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Vector>(INPIN_Name, Value);
		LogResults<FVector>(INPIN_Name, ResultEnum, { Value }, [](const FVector& Val) { return Val.ToString(); });
	}

	{
		FRotator Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Rotator_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Rotator>(INPIN_Name, Value);
		LogResults<FRotator>(INPIN_Name, ResultEnum, { Value }, [](const FRotator& Val) { return Val.ToString(); });
	}

	{
		FTransform Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Transform_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Transform>(INPIN_Name, Value);
		LogResults<FTransform>(INPIN_Name, ResultEnum, { Value }, [](const FTransform& Val) { return Val.ToString(); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Struct::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}