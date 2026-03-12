// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Bool.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Bool")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Bool : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Bool"))
	bool Bool_Single_Output = true;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (FlowPinType = "Bool"))
	bool Bool_Single_Minimal_Output = true;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin = "Renamed Bool Output", FlowPinType = "Bool"))
	bool Bool_Single_Renamed_Output = true;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Bool"))
	TArray<bool> Bool_Array_Output = { true, false, true };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Bool Bool_Wrapped_Output = FFlowDataPinValue_Bool({ false, true, false });

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Bool"))
	bool Bool_Single_Input = false;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Bool"))
	TArray<bool> Bool_Array_Input = { false, false, false };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin = "Renamed Bool Array Input", FlowPinType = "Bool"))
	TArray<bool> Bool_Renamed_Array_Input = { false, false, false };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Bool Bool_Wrapped_Input = FFlowDataPinValue_Bool(false);

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Bool Bool_LegacyWrapped_Output = FFlowDataPinOutputProperty_Bool(true);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Bool Bool_LegacyWrapped_Input = FFlowDataPinInputProperty_Bool(false);
	// --

public:
	UFlowNode_DataPinsTester_Bool();

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
	// --
};
