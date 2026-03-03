
#include "AddOns/FlowNodeAddOn_TestStringLogger.h"
#include "Nodes/Developer/FlowNode_Log.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNodeAddOn_TestStringLogger)

UFlowNodeAddOn_TestStringLogger::UFlowNodeAddOn_TestStringLogger() : Super()
{
# if WITH_EDITOR
	Category = TEXT("Flow|Test");
	NodeDisplayStyle = FlowNodeStyle::AddOn;
#endif
}

EFlowAddOnAcceptResult UFlowNodeAddOn_TestStringLogger::AcceptFlowNodeAddOnParent_Implementation(const UFlowNodeBase* ParentTemplate, const TArray<UFlowNodeAddOn*>& AdditionalAddOnsToAssumeAreChildren) const
{
	if (ParentTemplate->IsA<UFlowNode_Log>())
	{
		return EFlowAddOnAcceptResult::TentativeAccept;
	}

	return EFlowAddOnAcceptResult::Reject;
}

void UFlowNodeAddOn_TestStringLogger::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	check(IsSupportedInputPinName(PinName));
	check(FlowNode);

	const UFlowNode_Log* LogNode = CastChecked<UFlowNode_Log>(FlowNode);
	switch (LogNode->GetVerbosity())
	{
	case EFlowLogVerbosity::Error:
		UE_LOG(LogFlow, Error, TEXT("%s"), *TextToLog.ToString());
		break;
	case EFlowLogVerbosity::Warning:
		UE_LOG(LogFlow, Warning, TEXT("%s"), *TextToLog.ToString());
		break;
	case EFlowLogVerbosity::Display:
		UE_LOG(LogFlow, Display, TEXT("%s"), *TextToLog.ToString());
		break;
	case EFlowLogVerbosity::Log:
		UE_LOG(LogFlow, Log, TEXT("%s"), *TextToLog.ToString());
		break;
	case EFlowLogVerbosity::Verbose:
		UE_LOG(LogFlow, Verbose, TEXT("%s"), *TextToLog.ToString());
		break;
	case EFlowLogVerbosity::VeryVerbose:
		UE_LOG(LogFlow, VeryVerbose, TEXT("%s"), *TextToLog.ToString());
		break;
	default:;
	}
}

void UFlowNodeAddOn_TestStringLogger::UpdateNodeConfigText_Implementation()
{
#if WITH_EDITOR
	FTextBuilder TextBuilder;
	TextBuilder.AppendLine(
		FString::Printf(
			TEXT("%s"),
			*TextToLog.ToString()));

	SetNodeConfigText(TextBuilder.ToText());
#endif // WITH_EDITOR
}
