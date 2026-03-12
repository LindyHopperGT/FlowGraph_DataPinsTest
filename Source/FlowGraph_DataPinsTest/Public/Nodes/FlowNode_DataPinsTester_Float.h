// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Float.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Float")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Float : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	float Float_Single_Output = 1.123f;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Double"))
	double Double_Single_Output = 2.123;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	TArray<float> Float_Array_Output = { 3.123f, 4.123f };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Double"))
	TArray<double> Double_Array_Output = { 5.123, 6.123 };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Float Float_Wrapped_Output = FFlowDataPinValue_Float({ 10.123f, 11.123f });

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Float"))
	float Float_Single_Input = -13.456f;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Double"))
	double Double_Single_Input = -14.456;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Float"))
	TArray<float> Float_Array_Input = { -15.456f, -16.456f };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Double"))
	TArray<double> Double_Array_Input = { -17.456, -18.456 };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Float"))
	FFlowDataPinValue_Float Float_Wrapped_Input = FFlowDataPinValue_Float({ -10.123f, -11.123f });

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Double Double_Wrapped_Input = FFlowDataPinValue_Double(-12.123);

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Float Float_LegacyWrapped_Output = FFlowDataPinOutputProperty_Float(21.123f);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Double Double_LegacyWrapped_Output = FFlowDataPinOutputProperty_Double(22.123);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Float Float_LegacyWrapped_Input = FFlowDataPinInputProperty_Float(-21.123f);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Double Double_LegacyWrapped_Input = FFlowDataPinInputProperty_Double(22.123);
	// --

public:
	UFlowNode_DataPinsTester_Float();

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
};