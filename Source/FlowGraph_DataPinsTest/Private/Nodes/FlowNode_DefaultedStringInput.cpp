// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DefaultedStringInput.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DefaultedStringInput)

FName UFlowNode_DefaultedStringInput::INPIN_StringInput = FName("String Input");

UFlowNode_DefaultedStringInput::UFlowNode_DefaultedStringInput(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_DefaultedStringInput::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	const FFlowDataPinResult_String StringResult = TryResolveDataPinAsString(INPIN_StringInput);

	LogNote(FString::Printf(TEXT("%s received %s from pin %s"), *GetName(), *StringResult.Value, *PinName.ToString()));

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}
