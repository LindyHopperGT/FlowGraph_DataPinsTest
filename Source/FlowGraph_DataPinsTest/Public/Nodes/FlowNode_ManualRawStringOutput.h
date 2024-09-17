// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_ManualRawStringOutput.generated.h"

UCLASS(BlueprintType, DisplayName = "Raw String Output (manual)")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_ManualRawStringOutput : public UFlowNode
{
	GENERATED_BODY()

public:

	// This string output property will not generate a matching pin, that is being done by-hand for this case.
	UPROPERTY(EditAnywhere, Category = DataPins)
	FString StringOutput;

	static FName OUTPIN_StringOutput;

public:
	UFlowNode_ManualRawStringOutput(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult_String TrySupplyDataPinAsString_Implementation(const FName& PinName) const override;
	// --
};
