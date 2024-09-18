// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinProperties.h"

#include "FlowNode_AllWrappedDataInputs.generated.h"

UCLASS(BlueprintType, DisplayName = "AllWrappedDataInputs")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_AllWrappedDataInputs : public UFlowNode
{
	GENERATED_BODY()

public:
	// This input properties will cause input pins to be generated using the property's DisplayName.
	// The value set for this property will be used as the default for the pin, if the pin is not connected 
	// (otherwise, the connected flownode will supply the value).

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Bool Input")
	FFlowDataPinInputProperty_Bool BoolInputProperty = false;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int Input")
	FFlowDataPinInputProperty_Int32 Int32InputProperty = 0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int64 Input")
	FFlowDataPinInputProperty_Int64 Int64InputProperty = 0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Float Input")
	FFlowDataPinInputProperty_Float FloatInputProperty = 0.0f;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Double Input")
	FFlowDataPinInputProperty_Double DoubleInputProperty = 0.0;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Name Input")
	FFlowDataPinInputProperty_Name NameInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "String Input")
	FFlowDataPinInputProperty_String StringInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Text Input")
	FFlowDataPinInputProperty_Text TextInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Enum Input")
	FFlowDataPinInputProperty_Enum EnumInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Vector Input")
	FFlowDataPinInputProperty_Vector VectorInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Transform Input")
	FFlowDataPinInputProperty_Transform TransformInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTag Input")
	FFlowDataPinInputProperty_GameplayTag GameplayTagInputProperty;

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "GameplayTagContainer Input")
	FFlowDataPinInputProperty_GameplayTagContainer GameplayTagContainerInputProperty;

public:
	UFlowNode_AllWrappedDataInputs(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;
	// --
};
