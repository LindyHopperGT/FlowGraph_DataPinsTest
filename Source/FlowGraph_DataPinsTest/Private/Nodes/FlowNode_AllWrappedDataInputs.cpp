// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AllWrappedDataInputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AllWrappedDataInputs)

// NOTE (gtaylor) Need to come up with a version of GetDisplayNameFromProperty that works at runtime, or otherwise
// make these names not need to be explicitly cached
FName UFlowNode_AllWrappedDataInputs::INPIN_BoolInput = FName("Bool Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_IntInput = FName("Int Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_Int64Input = FName("Int64 Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_FloatInput = FName("Float Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_DoubleInput = FName("Double Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_NameInput = FName("Name Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_StringInput = FName("String Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_TextInput = FName("Text Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_EnumInput = FName("Enum Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_VectorInput = FName("Transform Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_TransformInput = FName("Transform Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_GameplayTagInput = FName("GameplayTag Input");
FName UFlowNode_AllWrappedDataInputs::INPIN_GameplayTagContainerInput = FName("GameplayTagContainer Input");

UFlowNode_AllWrappedDataInputs::UFlowNode_AllWrappedDataInputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_AllWrappedDataInputs::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	const FFlowDataPinResult_Bool BoolResult = TryResolveDataPinAsBool(INPIN_BoolInput);
	if (BoolResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), BoolResult.Value ? TEXT("true") : TEXT("false"), *INPIN_BoolInput.ToString()));
	}

	const FFlowDataPinResult_Int IntResult = TryResolveDataPinAsInt(INPIN_IntInput);
	if (IntResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %ld for pin %s"), *GetName(), IntResult.Value, *INPIN_IntInput.ToString()));
	}

	const FFlowDataPinResult_Int Int64Result = TryResolveDataPinAsInt(INPIN_Int64Input);
	if (IntResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %ld for pin %s"), *GetName(), Int64Result.Value, *INPIN_Int64Input.ToString()));
	}

	const FFlowDataPinResult_Float FloatResult = TryResolveDataPinAsFloat(INPIN_FloatInput);
	if (FloatResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %.0g for pin %s"), *GetName(), FloatResult.Value, *INPIN_FloatInput.ToString()));
	}

	const FFlowDataPinResult_Float DoubleResult = TryResolveDataPinAsFloat(INPIN_DoubleInput);
	if (DoubleResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %.0g for pin %s"), *GetName(), DoubleResult.Value, *INPIN_DoubleInput.ToString()));
	}

	const FFlowDataPinResult_Name NameResult = TryResolveDataPinAsName(INPIN_NameInput);
	if (NameResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *NameResult.Value.ToString(), *INPIN_NameInput.ToString()));
	}

	const FFlowDataPinResult_String StringResult = TryResolveDataPinAsString(INPIN_StringInput);
	if (StringResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *StringResult.Value, *INPIN_StringInput.ToString()));
	}

	const FFlowDataPinResult_Text TextResult = TryResolveDataPinAsText(INPIN_TextInput);
	if (TextResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *TextResult.Value.ToString(), *INPIN_TextInput.ToString()));
	}

	const FFlowDataPinResult_Enum EnumResult = TryResolveDataPinAsEnum(INPIN_EnumInput);
	if (EnumResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *EnumResult.Value.ToString(), *INPIN_EnumInput.ToString()));
	}

	const FFlowDataPinResult_Vector VectorResult = TryResolveDataPinAsVector(INPIN_VectorInput);
	if (VectorResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *VectorResult.Value.ToString(), *INPIN_VectorInput.ToString()));
	}

	const FFlowDataPinResult_Transform TransformResult = TryResolveDataPinAsTransform(INPIN_TransformInput);
	if (TransformResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *TransformResult.Value.ToString(), *INPIN_TransformInput.ToString()));
	}

	const FFlowDataPinResult_GameplayTag GameplayTagResult = TryResolveDataPinAsGameplayTag(INPIN_GameplayTagInput);
	if (GameplayTagResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *GameplayTagResult.Value.ToString(), *INPIN_GameplayTagInput.ToString()));
	}

	const FFlowDataPinResult_GameplayTagContainer GameplayTagContainerResult = TryResolveDataPinAsGameplayTagContainer(INPIN_GameplayTagContainerInput);
	if (GameplayTagContainerResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *GameplayTagContainerResult.Value.ToString(), *INPIN_GameplayTagContainerInput.ToString()));
	}

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}
