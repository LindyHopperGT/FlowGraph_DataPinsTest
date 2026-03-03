// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_String.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_String)

UFlowNode_DataPinsTester_String::UFlowNode_DataPinsTester_String(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	Name_Wrapped_Output.bIsInputPin = false;
	Name_Wrapped_Output.MultiType = EFlowDataMultiType::Array;
	String_Wrapped_Output.bIsInputPin = false;
	String_Wrapped_Output.MultiType = EFlowDataMultiType::Single;
	Text_Wrapped_Output.bIsInputPin = false;
	Text_Wrapped_Output.MultiType = EFlowDataMultiType::Single;

	String_Wrapped_Input.bIsInputPin = true;
	String_Wrapped_Input.MultiType = EFlowDataMultiType::Single;
#endif
}

void UFlowNode_DataPinsTester_String::ExecuteInput(const FName& PinName)
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

	// Test FName single input
	{
		FName Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Name_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Name>(INPIN_Name, Value);
		LogResults<FName>(INPIN_Name, ResultEnum, TArray<FName>{Value}, [](const FName& Val) { return Val.ToString(); });
	}

	// Test FString single input
	{
		FString Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, String_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_String>(INPIN_Name, Value);
		LogResults<FString>(INPIN_Name, ResultEnum, TArray<FString>{Value}, [](const FString& Val) { return Val; });
	}

	// Test FText single input
	{
		FText Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Text_Single_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Text>(INPIN_Name, Value);
		LogResults<FText>(INPIN_Name, ResultEnum, TArray<FText>{Value}, [](const FText& Val) { return Val.ToString(); });
	}

	// Test FName array input
	{
		TArray<FName> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Name_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Name>(INPIN_Name, Values);
		LogResults<FName>(INPIN_Name, ResultEnum, Values, [](const FName& Val) { return Val.ToString(); });
	}

	// Test FString array input
	{
		TArray<FString> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, String_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_String>(INPIN_Name, Values);
		LogResults<FString>(INPIN_Name, ResultEnum, Values, [](const FString& Val) { return Val; });
	}

	// Test FText array input
	{
		TArray<FText> Values;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Text_Array_Input);
		ResultEnum = TryResolveDataPinValues<FFlowPinType_Text>(INPIN_Name, Values);
		LogResults<FText>(INPIN_Name, ResultEnum, Values, [](const FText& Val) { return Val.ToString(); });
	}

	// Test wrapped FString input
	{
		FString Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, String_Wrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_String>(INPIN_Name, Value);
		LogResults<FString>(INPIN_Name, ResultEnum, TArray<FString>{Value}, [](const FString& Val) { return Val; });
	}

	// #FlowDataPinLegacy
	{
		FName Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Name_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Name>(INPIN_Name, Value);
		LogResults<FName>(INPIN_Name, ResultEnum, { Value }, [](const FName& Val) { return Val.ToString(); });
	}

	{
		FString Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, String_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_String>(INPIN_Name, Value);
		LogResults<FString>(INPIN_Name, ResultEnum, { Value }, [](const FString& Val) { return Val; });
	}

	{
		FText Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, Text_LegacyWrapped_Input);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_Text>(INPIN_Name, Value);
		LogResults<FText>(INPIN_Name, ResultEnum, { Value }, [](const FText& Val) { return Val.ToString(); });
	}
	// --

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult UFlowNode_DataPinsTester_String::TrySupplyDataPin(FName PinName) const
{
	FFlowDataPinResult DataPinResult = Super::TrySupplyDataPin(PinName);
	return DataPinResult;
}