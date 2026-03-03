
#pragma once

#include "AddOns/FlowNodeAddOn.h"

#include "FlowNodeAddOn_TestAddOnDataPins.generated.h"

/**
 * Flow Node AddOn to test AddOn DataPins
 */
UCLASS(MinimalApi, NotBlueprintable, meta = (DisplayName = "Test AddOn DataPins"))
class UFlowNodeAddOn_TestAddOnDataPins : public UFlowNodeAddOn
{

	GENERATED_BODY()
public:
	UFlowNodeAddOn_TestAddOnDataPins();

	// Begin UFlowNodeAddOn
	virtual EFlowAddOnAcceptResult AcceptFlowNodeAddOnParent_Implementation(const UFlowNodeBase* ParentTemplate, const TArray<UFlowNodeAddOn*>& AdditionalAddOnsToAssumeAreChildren) const override;
	// End UFlowNodeAddOn

	// Begin UMKTFlowNode Interface
	virtual void ExecuteInput(const FName& PinName) override;
	// End UMKTFlowNode Interface

	// Begin UFlowNode
	virtual void UpdateNodeConfigText_Implementation() override;
	// End UFlowNode

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Int"))
	int32 IntInput = 1;

	UPROPERTY(EditAnywhere, Category = DataPins)
	int32 Multiplier = 1;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Int"))
	int32 ModifiedIntOutput = 1;
};
