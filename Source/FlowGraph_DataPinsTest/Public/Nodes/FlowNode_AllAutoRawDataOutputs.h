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

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Bool"))
	bool BoolOutput = false;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int8 Int8Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int16 Int16Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int32 Int32Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int64 Int64Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint8 Uint8Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint16 Uint16Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint32 Uint32Output = 0;

	// (note - result is cast to signed Int64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	uint64 Uint64Output = 0;

	// (note - result is cast to Float64)
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	float Float32Output = 0.0f;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Float"))
	double Float64Output = 0.0;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Name"))
	FName NameOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "String"))
	FString StringOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Text"))
	FText TextOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Enum"))
	EFlowNodeState EnumOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Vector"))
	FVector VectorOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Transform"))
	FTransform TransformOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTag"))
	FGameplayTag GameplayTagOutput;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTagContainer"))
	FGameplayTagContainer GameplayTagContainerOutput;

	static FName OUTPIN_BoolOutput;
	static FName OUTPIN_Int8Output;
	static FName OUTPIN_Int16Output;
	static FName OUTPIN_Int32Output;
	static FName OUTPIN_Int64Output;
	static FName OUTPIN_Uint8Output;
	static FName OUTPIN_Uint16Output;
	static FName OUTPIN_Uint32Output;
	static FName OUTPIN_Uint64Output;
	static FName OUTPIN_Float32Output;
	static FName OUTPIN_Float64Output;
	static FName OUTPIN_NameOutput;
	static FName OUTPIN_StringOutput;
	static FName OUTPIN_TextOutput;
	static FName OUTPIN_EnumOutput;
	static FName OUTPIN_VectorOutput;
	static FName OUTPIN_TransformOutput;
	static FName OUTPIN_GameplayTagOutput;
	static FName OUTPIN_GameplayTagContainerOutput;

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
