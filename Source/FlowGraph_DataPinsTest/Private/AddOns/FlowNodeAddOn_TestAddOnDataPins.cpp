
#include "AddOns/FlowNodeAddOn_TestAddOnDataPins.h"
#include "Nodes/Developer/FlowNode_Log.h"

//#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNodeAddOn_TestAddOnDataPins)

UFlowNodeAddOn_TestAddOnDataPins::UFlowNodeAddOn_TestAddOnDataPins() : Super()
{
# if WITH_EDITOR
	Category = TEXT("Flow|Test");
	NodeDisplayStyle = FlowNodeStyle::AddOn;
#endif
}

EFlowAddOnAcceptResult UFlowNodeAddOn_TestAddOnDataPins::AcceptFlowNodeAddOnParent_Implementation(const UFlowNodeBase* ParentTemplate, const TArray<UFlowNodeAddOn*>& AdditionalAddOnsToAssumeAreChildren) const
{
	if (ParentTemplate->IsA<UFlowNode_Log>())
	{
		return EFlowAddOnAcceptResult::TentativeAccept;
	}

	return EFlowAddOnAcceptResult::Reject;
}

void UFlowNodeAddOn_TestAddOnDataPins::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	check(IsSupportedInputPinName(PinName));
	check(FlowNode);

	// Get the value from the input pin
	int32 Value = 0;
	static FName INPIN_Name = GET_MEMBER_NAME_CHECKED(ThisClass, IntInput);
	const EFlowDataPinResolveResult ResultEnum = TryResolveDataPinValue<FFlowPinType_Int>(INPIN_Name, Value);
	check(FlowPinType::IsSuccess(ResultEnum));

	// Set the output data pin value to the multiplied value from the input pin
	ModifiedIntOutput = Multiplier * Value;	

	UE_LOG(LogFlow, Warning, TEXT("%d = %d * %d"), ModifiedIntOutput, Multiplier, Value);
}

void UFlowNodeAddOn_TestAddOnDataPins::UpdateNodeConfigText_Implementation()
{
#if WITH_EDITOR
	FTextBuilder TextBuilder;
	TextBuilder.AppendLine(
		FString::Printf(
			TEXT("OnExecute: ModifiedIntOutput = IntInput * %d"),
			Multiplier));

	SetNodeConfigText(TextBuilder.ToText());
#endif // WITH_EDITOR
}

