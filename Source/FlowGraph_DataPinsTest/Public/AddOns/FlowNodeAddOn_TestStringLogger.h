
#pragma once

#include "AddOns/FlowNodeAddOn.h"

#include "FlowNodeAddOn_TestStringLogger.generated.h"

/**
 * Flow Node AddOn to test string logging
 */
UCLASS(MinimalApi, NotBlueprintable, meta = (DisplayName = "Test String Logger"))
class UFlowNodeAddOn_TestStringLogger : public UFlowNodeAddOn
{

	GENERATED_BODY()
public:
	UFlowNodeAddOn_TestStringLogger();

	// Begin UFlowNodeAddOn
	virtual EFlowAddOnAcceptResult AcceptFlowNodeAddOnParent_Implementation(const UFlowNodeBase* ParentTemplate, const TArray<UFlowNodeAddOn*>& AdditionalAddOnsToAssumeAreChildren) const override;
	// End UFlowNodeAddOn

	// Begin UMKTFlowNode Interface
	virtual void ExecuteInput(const FName& PinName) override;
	// End UMKTFlowNode Interface

	// Begin UFlowNode
	virtual void UpdateNodeConfigText_Implementation() override;
	// End UFlowNode

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Configuration)
	FText TextToLog;
};
