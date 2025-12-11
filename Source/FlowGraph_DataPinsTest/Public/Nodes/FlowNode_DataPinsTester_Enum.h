// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Enum.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Enum")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Enum : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Enum"))
	EFlowNodeState Enum_Single_Output = EFlowNodeState::Completed;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Enum"))
	TArray<EFlowNodeState> Enum_Array_Output = { EFlowNodeState::Aborted, EFlowNodeState::Active };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Enum Enum_Wrapped_Output = FFlowDataPinValue_Enum(StaticEnum<EFlowNodeState>(), { "Active", "Completed" });

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Enum"))
	EFlowNodeState Enum_Single_Input = EFlowNodeState::Invalid;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Enum"))
	TArray<EFlowNodeState> Enum_Array_Input = { EFlowNodeState::Invalid, EFlowNodeState::Invalid };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Enum Enum_Wrapped_Input = FFlowDataPinValue_Enum(StaticEnum<EFlowNodeState>(), { "Invalid", "Invalid" });

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Enum Enum_LegacyWrapped_Output = FFlowDataPinOutputProperty_Enum("Active", StaticEnum<EFlowNodeState>());

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Enum Enum_LegacyWrapped_Input = FFlowDataPinInputProperty_Enum("Invalid", StaticEnum<EFlowNodeState>());
	// --

public:
	UFlowNode_DataPinsTester_Enum(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin_Implementation(FName PinName) const override;
};