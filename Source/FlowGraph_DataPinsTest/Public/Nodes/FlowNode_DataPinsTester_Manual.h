#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "FlowNode_DataPinsTester_Manual.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Manual")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Manual : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:

	// This string output property will not generate a matching pin, that is being done by-hand for this case.
	UPROPERTY(EditAnywhere, Category = DataPins)
	FString StringOutput;

	// A single input string to use in testing
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "String"))
	FString StringInput;

	static FName OUTPIN_StringOutput;

public:
	UFlowNode_DataPinsTester_Manual(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
	// --
};