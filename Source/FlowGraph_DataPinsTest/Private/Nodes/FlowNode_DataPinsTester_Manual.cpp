// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DataPinsTester_Manual.h"
#include "Types/FlowDataPinResults.h"
#include "Types/FlowPinTypeTemplates.h"
#include "Types/FlowArray.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DataPinsTester_Manual)

FName UFlowNode_DataPinsTester_Manual::OUTPIN_StringOutput;

UFlowNode_DataPinsTester_Manual::UFlowNode_DataPinsTester_Manual(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Flow|Test";

	// NOTE (gtaylor) For this flownode, we're creating these pins manually, to test that code pathway
	OUTPIN_StringOutput = GET_MEMBER_NAME_CHECKED(ThisClass, StringOutput);
	OutputPins.Add(FFlowPin(OUTPIN_StringOutput, FFlowPinType_String::GetPinTypeNameStatic()));
#endif
}

void UFlowNode_DataPinsTester_Manual::ExecuteInput(const FName& PinName)
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

	// Test FString single input
	{
		FString Value;
		INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, StringInput);
		ResultEnum = TryResolveDataPinValue<FFlowPinType_String>(INPIN_Name, Value);
		LogResults<FString>(INPIN_Name, ResultEnum, TArray<FString>{Value}, [](const FString& Val) { return Val; });
	}

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}


FFlowDataPinResult UFlowNode_DataPinsTester_Manual::TrySupplyDataPin_Implementation(FName PinName) const
{
	FFlowDataPinResult Result;

	// NOTE (gtaylor) For this flownode, we're mapping the pin manually, to test that code pathway
	if (PinName == OUTPIN_StringOutput)
	{
		Result = FFlowDataPinResult(FFlowDataPinValue_String(StringOutput));

		check(Result.Result == EFlowDataPinResolveResult::Success);
	}
	else
	{
		Result = Super::TrySupplyDataPin_Implementation(PinName);
	}

	return Result;
}

