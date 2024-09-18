// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_DefaultedStringInput.generated.h"

UCLASS(BlueprintType, DisplayName = "String Input (defaulted)")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DefaultedStringInput : public UFlowNode
{
	GENERATED_BODY()

public:

	// This string input property will cause a string input pin to be generated using the property's DisplayName.
	// The value set for this property will be used as the default for the pin, if the pin is not connected 
	// (otherwise, the connected flownode will supply the value).
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin))
	FString StringInput;

public:

	UFlowNode_DefaultedStringInput(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --
};
