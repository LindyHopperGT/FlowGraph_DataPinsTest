// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_ManualRawStringOutput.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_ManualRawStringOutput)

FName UFlowNode_ManualRawStringOutput::OUTPIN_StringOutput;

UFlowNode_ManualRawStringOutput::UFlowNode_ManualRawStringOutput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif

	// NOTE (gtaylor) For this flownode, we're creating the pin manually, to test that code pathway
	OUTPIN_StringOutput = GET_MEMBER_NAME_CHECKED(UFlowNode_ManualRawStringOutput, StringOutput);
	OutputPins.Add(FFlowPin(OUTPIN_StringOutput, EFlowPinType::String));
}

void UFlowNode_ManualRawStringOutput::ExecuteInput(const FName& PinName)
{
	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_String UFlowNode_ManualRawStringOutput::TrySupplyDataPinAsString_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_String Result;

	// NOTE (gtaylor) For this flownode, we're mapping the pin manually, to test that code pathway
	if (PinName == OUTPIN_StringOutput)
	{
		Result = FFlowDataPinResult_String(StringOutput);

		check(Result.Result == EFlowDataPinResolveResult::Success);
	}
	else
	{
		Result = Super::TrySupplyDataPinAsString_Implementation(PinName);
	}

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value, *PinName.ToString()));

	return Result;
}

