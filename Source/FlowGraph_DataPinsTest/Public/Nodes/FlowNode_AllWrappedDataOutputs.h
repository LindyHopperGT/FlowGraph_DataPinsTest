// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_AllWrappedDataOutputs.generated.h"

UCLASS(BlueprintType, DisplayName = "AllWrappedDataOutputs")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_AllWrappedDataOutputs : public UFlowNode
{
	GENERATED_BODY()

public:
	// This these output properties will cause output pins to be generated using each properties' DisplayName.
	// The value set for this property will be used as the source for the pin when supplying the value to other 
	// connected flow nodes.

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Bool Output")
	FFlowDataPinOutputProperty_Bool BoolOutputProperty = false;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int32 Output")
	FFlowDataPinOutputProperty_Int32 Int32OutputProperty = 0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int64 Output")
	FFlowDataPinOutputProperty_Int64 Int64OutputProperty = 0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Float32 Output")
	FFlowDataPinOutputProperty_Float Float32OutputProperty = 0.0f;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Float64 Output")
	FFlowDataPinOutputProperty_Double Float64OutputProperty = 0.0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Name Output")
	FFlowDataPinOutputProperty_Name NameOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "String Output")
	FFlowDataPinOutputProperty_String StringOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Text Output")
	FFlowDataPinOutputProperty_Text TextOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Enum Output")
	FFlowDataPinOutputProperty_Enum EnumOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Vector Output")
	FFlowDataPinOutputProperty_Vector VectorOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Transform Output")
	FFlowDataPinOutputProperty_Transform TransformOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTag Output")
	FFlowDataPinOutputProperty_GameplayTag GameplayTagOutputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTagContainer Output")
	FFlowDataPinOutputProperty_GameplayTagContainer GameplayTagContainerOutputProperty;

public:
	UFlowNode_AllWrappedDataOutputs(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --

	// Must implement TrySupplyDataAs... for every EFlowPinType
	FLOW_ASSERT_ENUM_MAX(EFlowPinType, 16);

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
