// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_WrappedStringOutput.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_WrappedStringOutput)

UFlowNode_WrappedStringOutput::UFlowNode_WrappedStringOutput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_WrappedStringOutput::ExecuteInput(const FName& PinName)
{
	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_String UFlowNode_WrappedStringOutput::TrySupplyDataPinAsString_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_String Result = Super::TrySupplyDataPinAsString_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value, *PinName.ToString()));

	return Result;
}
