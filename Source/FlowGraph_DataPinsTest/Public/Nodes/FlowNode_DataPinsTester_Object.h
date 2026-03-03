// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Object.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Object")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Object : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Object"))
	TObjectPtr<UObject> Object_Single_Output = nullptr;

	UPROPERTY(EditAnywhere, Instanced, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Object"))
	TObjectPtr<UObject> InstancedObject_Single_Output = nullptr;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Class"))
	TSubclassOf<UObject> Class_Single_Output = nullptr;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Object"))
	TArray<TObjectPtr<UObject>> Object_Array_Output;

	UPROPERTY(EditAnywhere, Instanced, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Object"))
	TArray<TObjectPtr<UObject>> InstancedObject_Array_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Class"))
	TArray<TSubclassOf<UObject>> Class_Array_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Object Object_Wrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Class Class_Wrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Object"))
	TObjectPtr<UObject> Object_Single_Input = nullptr;

	UPROPERTY(EditAnywhere, Instanced, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Object"))
	TObjectPtr<UObject> InstancedObject_Single_Input = nullptr;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Class"))
	TSubclassOf<UObject> Class_Single_Input = nullptr;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Object"))
	TArray<TObjectPtr<UObject>> Object_Array_Input;

	UPROPERTY(EditAnywhere, Instanced, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Object"))
	TArray<TObjectPtr<UObject>> InstancedObject_Array_Input;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Class"))
	TArray<TSubclassOf<UObject>> Class_Array_Input;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Class Class_Wrapped_Input;

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Object Object_LegacyWrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Class Class_LegacyWrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Object Object_LegacyWrapped_Input;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Class Class_LegacyWrapped_Input;
	// --

public:
	UFlowNode_DataPinsTester_Object(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
};