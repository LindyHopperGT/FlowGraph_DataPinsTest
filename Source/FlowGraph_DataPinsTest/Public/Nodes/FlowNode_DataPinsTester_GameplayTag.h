#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"
#include "FlowNode_DataPinsTester_GameplayTag.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Gameplay Tag")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_GameplayTag : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTag"))
	FGameplayTag GameplayTag_Single_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTagContainer"))
	FGameplayTagContainer GameplayTagContainer_Single_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "GameplayTag"))
	TArray<FGameplayTag> GameplayTag_Array_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_GameplayTag GameplayTag_Wrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_GameplayTagContainer GameplayTagContainer_Wrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "GameplayTag"))
	FGameplayTag GameplayTag_Single_Input;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "GameplayTagContainer"))
	FGameplayTagContainer GameplayTagContainer_Single_Input;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "GameplayTag"))
	TArray<FGameplayTag> GameplayTag_Array_Input;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_GameplayTag GameplayTag_Wrapped_Input;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_GameplayTagContainer GameplayTagContainer_Wrapped_Input;

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_GameplayTag GameplayTag_LegacyWrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_GameplayTagContainer GameplayTagContainer_LegacyWrapped_Output;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_GameplayTag GameplayTag_LegacyWrapped_Input;

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_GameplayTagContainer GameplayTagContainer_LegacyWrapped_Input;
	// --

public:
	UFlowNode_DataPinsTester_GameplayTag(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin_Implementation(FName PinName) const override;
};