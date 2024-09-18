// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AutoRawStringOutput.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AutoRawStringOutput)

UFlowNode_AutoRawStringOutput::UFlowNode_AutoRawStringOutput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_AutoRawStringOutput::ExecuteInput(const FName& PinName)
{
	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_String UFlowNode_AutoRawStringOutput::TrySupplyDataPinAsString_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_String Result = Super::TrySupplyDataPinAsString_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value, *PinName.ToString()));

	return Result;
}
