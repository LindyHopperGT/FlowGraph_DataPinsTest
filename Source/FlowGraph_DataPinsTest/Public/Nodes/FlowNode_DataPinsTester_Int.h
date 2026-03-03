// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Int.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Int")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Int : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int32 Int32_Single_Output = 1;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int64"))
	int64 Int64_Single_Output = 2;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	TArray<int32> Int32_Array_Output = { 4, 5 };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Int Int32_Wrapped_Output = FFlowDataPinValue_Int({ 11, 12 });

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Int64 Int64_Wrapped_Output = FFlowDataPinValue_Int64(-13);

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Int"))
	int32 Int32_Single_Input = -14;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Int64"))
	int64 Int64_Single_Input = -15;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Int"))
	TArray<int32> Int32_Array_Input = { -16, -17 };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Int64 Int64_Wrapped_Input = FFlowDataPinValue_Int64({ -22, -23 });

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Int32 Int_LegacyWrapped_Output = FFlowDataPinOutputProperty_Int32(-24);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Int64 Int64_LegacyWrapped_Output = FFlowDataPinOutputProperty_Int64(25);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Int32 Int32_LegacyWrapped_Input = FFlowDataPinInputProperty_Int32(-26);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Int64 Int64_LegacyWrapped_Input = FFlowDataPinInputProperty_Int64(-27);
	// --

public:
	UFlowNode_DataPinsTester_Int(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
};
