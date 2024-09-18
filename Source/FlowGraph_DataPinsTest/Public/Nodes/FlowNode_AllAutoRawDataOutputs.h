// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_AllAutoRawDataOutputs.generated.h"

UCLASS(BlueprintType, DisplayName = "AllAutoRawDataOutputs")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_AllAutoRawDataOutputs : public UFlowNode
{
	GENERATED_BODY()

public:
	// This these output properties will cause output pins to be generated using each properties' DisplayName.
	// The value set for this property will be used as the source for the pin when supplying the value to other 
	// connected flow nodes.

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Bool Output", meta = (SourceForOutputFlowPin, FlowPinType = "Bool"))
	bool BoolOutput = false;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "int8 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int8 Int8Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int16 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int16 Int16Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int32 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int32 Int32Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int64 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int64 Int64Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Uint8 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint8 Uint8Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Uint16 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint16 Uint16Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Uint32 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint32 Uint32Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Uint64 Output", meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint64 Uint64Output = 0;

	// (note - result is cast to Float64)
	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Float Output", meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	float Float32Output = 0.0f;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Double Output", meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	double Float64Output = 0.0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Name Output", meta = (SourceForOutputFlowPin, FlowPinType = "Name"))
	FName NameOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "String Output", meta = (SourceForOutputFlowPin, FlowPinType = "String"))
	FString StringOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Text Output", meta = (SourceForOutputFlowPin, FlowPinType = "Text"))
	FText TextOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Enum Output", meta = (SourceForOutputFlowPin, FlowPinType = "Enum"))
	EFlowNodeState EnumOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Vector Output", meta = (SourceForOutputFlowPin, FlowPinType = "Vector"))
	FVector VectorOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Transform Output", meta = (SourceForOutputFlowPin, FlowPinType = "Transform"))
	FTransform TransformOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTag Output", meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTag"))
	FGameplayTag GameplayTagOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTagContainer Output", meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTagContainer"))
	FGameplayTagContainer GameplayTagContainerOutput;

public:
	UFlowNode_AllAutoRawDataOutputs(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// Must implement TrySupplyDataAs... for every EFlowPinType
	FLOW_ASSERT_ENUM_MAX(EFlowPinType, 12);

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult_Bool TrySupplyDataPinAsBool_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Int TrySupplyDataPinAsInt_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Float TrySupplyDataPinAsFloat_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Name TrySupplyDataPinAsName_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_String TrySupplyDataPinAsString_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Text TrySupplyDataPinAsText_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Enum TrySupplyDataPinAsEnum_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Vector TrySupplyDataPinAsVector_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_Transform TrySupplyDataPinAsTransform_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_GameplayTag TrySupplyDataPinAsGameplayTag_Implementation(const FName& PinName) const override;
	virtual FFlowDataPinResult_GameplayTagContainer TrySupplyDataPinAsGameplayTagContainer_Implementation(const FName& PinName) const override;
	// --
};
