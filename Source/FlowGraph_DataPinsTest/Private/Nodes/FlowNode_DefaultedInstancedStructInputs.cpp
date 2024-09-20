// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_DefaultedInstancedStructInputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_DefaultedInstancedStructInputs)

UFlowNode_DefaultedInstancedStructInputs::UFlowNode_DefaultedInstancedStructInputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_DefaultedInstancedStructInputs::ExecuteInput(const FName& PinName)
{
	static const FName INPIN_UntypedInput = GET_MEMBER_NAME_CHECKED(UFlowNode_DefaultedInstancedStructInputs, UntypedInstancedStruct);
	static const FName INPIN_TypedInput = GET_MEMBER_NAME_CHECKED(UFlowNode_DefaultedInstancedStructInputs, TypedInstancedStruct);
	static const FName INPIN_TemplatedInput = GET_MEMBER_NAME_CHECKED(UFlowNode_DefaultedInstancedStructInputs, TemplatedInstancedStruct);

	int32 IntPayload = 0;
	if (TryGetIntPayloadFromInstancedStructResult(INPIN_UntypedInput, IntPayload))
	{
		LogNote(FString::Printf(TEXT("%s received InstancedStruct<FFlowTestInstancedStruct> with IntProperty %d from pin %s"), *GetName(), IntPayload, *PinName.ToString()));
	}

	if (TryGetIntPayloadFromInstancedStructResult(INPIN_TypedInput, IntPayload))
	{
		LogNote(FString::Printf(TEXT("%s received InstancedStruct<FFlowTestInstancedStruct> with IntProperty %d from pin %s"), *GetName(), IntPayload, *PinName.ToString()));
	}

	if (TryGetIntPayloadFromInstancedStructResult(INPIN_TemplatedInput, IntPayload))
	{
		LogNote(FString::Printf(TEXT("%s received InstancedStruct<FFlowTestInstancedStruct> with IntProperty %d from pin %s"), *GetName(), IntPayload, *PinName.ToString()));
	}

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

bool UFlowNode_DefaultedInstancedStructInputs::TryGetIntPayloadFromInstancedStructResult(const FName& INPIN_InstancedStructInput, int32& OutIntPayload) const
{
	const FFlowDataPinResult_InstancedStruct InstancedStructResult = TryResolveDataPinAsInstancedStruct(INPIN_InstancedStructInput);

	if (const UScriptStruct* ScriptStruct = InstancedStructResult.Value.GetScriptStruct())
	{
		if (ScriptStruct == FFlowTestInstancedStruct::StaticStruct())
		{
			OutIntPayload = InstancedStructResult.Value.Get<FFlowTestInstancedStruct>().IntProperty;

			return true;
		}
	}

	return false;
}
