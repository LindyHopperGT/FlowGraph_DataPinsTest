// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_InstancedStructOutputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_InstancedStructOutputs)

UFlowNode_InstancedStructOutputs::UFlowNode_InstancedStructOutputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_InstancedStructOutputs::ExecuteInput(const FName& PinName)
{
	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_InstancedStruct UFlowNode_InstancedStructOutputs::TrySupplyDataPinAsInstancedStruct_Implementation(const FName& PinName) const
{
	// NOTE (gtaylor) you don't need to override this function when using the auto-pin binding metadata features 
	// (like this class does).  I'm only overriding it so I can set breakpoints and print results (for testing).

	FFlowDataPinResult_InstancedStruct InstancedStructResult = Super::TrySupplyDataPinAsInstancedStruct_Implementation(PinName);

	if (InstancedStructResult.Result == EFlowDataPinResolveResult::Success)
	{
		if (const UScriptStruct* ScriptStruct = InstancedStructResult.Value.GetScriptStruct())
		{
			if (ScriptStruct == FFlowTestInstancedStruct::StaticStruct())
			{
				const int32 IntPayload = InstancedStructResult.Value.Get<FFlowTestInstancedStruct>().IntProperty;
				LogNote(FString::Printf(TEXT("%s supplied %d for pin %s"), *GetName(), IntPayload, *PinName.ToString()));
			}
		}
	}

	return InstancedStructResult;
}

