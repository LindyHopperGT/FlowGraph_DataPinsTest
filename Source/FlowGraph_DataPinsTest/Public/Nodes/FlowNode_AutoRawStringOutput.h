// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_AutoRawStringOutput.generated.h"

UCLASS(BlueprintType, DisplayName = "Raw String Output (auto)")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_AutoRawStringOutput : public UFlowNode
{
	GENERATED_BODY()

public:

	// This string output property will cause a string output pin to be generated using the property's DisplayName.
	// The value set for this property will be used as the source for the pin when supplying the value to other 
	// connected flow nodes.
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "String Output", meta = (SourceForOutputFlowPin, FlowPinType = "String"))
	FString StringOutputProperty;

public:

	UFlowNode_AutoRawStringOutput(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult_String TrySupplyDataPinAsString_Implementation(const FName& PinName) const override;
	// --
};
