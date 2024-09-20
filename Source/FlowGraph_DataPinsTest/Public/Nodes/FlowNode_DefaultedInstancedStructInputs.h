// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"
#include "FlowTestInstancedStruct.h"

#include "FlowNode_DefaultedInstancedStructInputs.generated.h"

UCLASS(BlueprintType, DisplayName = "InstancedStruct Defaulted Inputs")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DefaultedInstancedStructInputs : public UFlowNode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct"))
	FInstancedStruct UntypedInstancedStruct;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct", BaseStruct = "/Script/FlowGraph_DataPinsTest.FlowTestInstancedStruct"))
	FInstancedStruct TypedInstancedStruct;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct"))
	TInstancedStruct<FFlowTestInstancedStruct> TemplatedInstancedStruct;

public:

	UFlowNode_DefaultedInstancedStructInputs(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	bool TryGetIntPayloadFromInstancedStructResult(const FName& INPIN_InstancedStructInput, int32& OutIntPayload) const;
};
