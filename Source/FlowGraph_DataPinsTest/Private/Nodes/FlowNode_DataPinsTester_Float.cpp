// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Float.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Float)

UFlowNode_DataPinsTester_Float::UFlowNode_DataPinsTester_Float()
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Float_Wrapped_Output.bIsInputPin = false;
	Float_Wrapped_Output.MultiType = EFlowDataMultiType::Array;

	Float_Wrapped_Input.bIsInputPin = true;
	Float_Wrapped_Input.MultiType = EFlowDataMultiType::Array;

	Double_Wrapped_Input.bIsInputPin = true;
	Double_Wrapped_Input.MultiType = EFlowDataMultiType::Single;
#endif
}

void UFlowNode_DataPinsTester_Float::ExecuteInput(const FName& PinName)
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

	// Test float single input
	{
		float Value = 0.0f;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Float_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Float>(INPIN_Name, Value);
		LogResults<float>(INPIN_Name, ResultEnum, TArray<float>{Value}, [](const float& Val) { return FString::SanitizeFloat(Val); });
	}

	// Test double single input
	{
		double Value = 0.0;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Double_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Double>(INPIN_Name, Value);
		LogResults<double>(INPIN_Name, ResultEnum, TArray<double>{Value}, [](const double& Val) { return FString::SanitizeFloat(Val); });
	}

	// Test float array input
	{
		TArray<float> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Float_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Float>(INPIN_Name, Values);
		LogResults<float>(INPIN_Name, ResultEnum, Values, [](const float& Val) { return FString::SanitizeFloat(Val); });
	}

	// Test double array input
	{
		TArray<double> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Double_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Double>(INPIN_Name, Values);
		LogResults<double>(INPIN_Name, ResultEnum, Values, [](const double& Val) { return FString::SanitizeFloat(Val); });
	}

	// Test wrapped float input
	{
		TArray<float> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Float_Wrapped_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Float>(INPIN_Name, Values);
		LogResults<float>(INPIN_Name, ResultEnum, Values, [](const float& Val) { return FString::SanitizeFloat(Val); });
	}

	// Test wrapped double input
	{
		double Value = 0.0;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Double_Wrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Double>(INPIN_Name, Value);
		LogResults<double>(INPIN_Name, ResultEnum, TArray<double>{Value}, [](const double& Val) { return FString::SanitizeFloat(Val); });
	}

	// #FlowDataPinLegacy
	{
		float Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Float_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Float>(INPIN_Name, Value);
		LogResults<float>(INPIN_Name, ResultEnum, { Value }, [](const float& Val) { return FString::SanitizeFloat(Val); });
	}

	{
		double Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Double_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Double>(INPIN_Name, Value);
		LogResults<double>(INPIN_Name, ResultEnum, { Value }, [](const double& Val) { return FString::SanitizeFloat(Val); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_Float::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}