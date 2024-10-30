// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"
#include "FlowTestInstancedStruct.h"

#include "FlowNode_InstancedStructOutputs.generated.h"

UCLASS(BlueprintType, DisplayName = "InstancedStruct Outputs")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_InstancedStructOutputs : public UFlowNode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct"))
	FInstancedStruct UntypedInstancedStruct;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct", BaseStruct = "/Script/FlowGraph_DataPinsTest.FlowTestInstancedStruct"))
	FInstancedStruct TypedInstancedStruct;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct"))
	TInstancedStruct<FFlowTestInstancedStruct> TemplatedInstancedStruct;

public:

	UFlowNode_InstancedStructOutputs(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult_InstancedStruct TrySupplyDataPinAsInstancedStruct_Implementation(const FName& PinName) const override;
	// --
};
