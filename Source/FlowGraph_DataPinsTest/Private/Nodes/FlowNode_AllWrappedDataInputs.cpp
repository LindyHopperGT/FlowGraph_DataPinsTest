// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AllWrappedDataInputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AllWrappedDataInputs)

UFlowNode_AllWrappedDataInputs::UFlowNode_AllWrappedDataInputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
#if WITH_EDITOR
	Category = "Test";
#endif
}

void UFlowNode_AllWrappedDataInputs::ExecuteInput(const FName& PinName)
{
	static const FName INPIN_BoolInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, BoolInputProperty);
	const FFlowDataPinResult_Bool BoolResult = TryResolveDataPinAsBool(INPIN_BoolInput);
	if (BoolResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), BoolResult.Value ? TEXT("true") : TEXT("false"), *INPIN_BoolInput.ToString()));
	}

	static const FName INPIN_IntInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, Int32InputProperty);
	const FFlowDataPinResult_Int IntResult = TryResolveDataPinAsInt(INPIN_IntInput);
	if (IntResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %ld for pin %s"), *GetName(), IntResult.Value, *INPIN_IntInput.ToString()));
	}

	static const FName INPIN_Int64Input = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, Int64InputProperty);
	const FFlowDataPinResult_Int Int64Result = TryResolveDataPinAsInt(INPIN_Int64Input);
	if (IntResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %ld for pin %s"), *GetName(), Int64Result.Value, *INPIN_Int64Input.ToString()));
	}

	static const FName INPIN_FloatInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, FloatInputProperty);
	const FFlowDataPinResult_Float FloatResult = TryResolveDataPinAsFloat(INPIN_FloatInput);
	if (FloatResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %.0g for pin %s"), *GetName(), FloatResult.Value, *INPIN_FloatInput.ToString()));
	}

	static const FName INPIN_DoubleInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, DoubleInputProperty);
	const FFlowDataPinResult_Float DoubleResult = TryResolveDataPinAsFloat(INPIN_DoubleInput);
	if (DoubleResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %.0g for pin %s"), *GetName(), DoubleResult.Value, *INPIN_DoubleInput.ToString()));
	}

	static const FName INPIN_NameInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, NameInputProperty);
	const FFlowDataPinResult_Name NameResult = TryResolveDataPinAsName(INPIN_NameInput);
	if (NameResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *NameResult.Value.ToString(), *INPIN_NameInput.ToString()));
	}

	static const FName INPIN_StringInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, StringInputProperty);
	const FFlowDataPinResult_String StringResult = TryResolveDataPinAsString(INPIN_StringInput);
	if (StringResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *StringResult.Value, *INPIN_StringInput.ToString()));
	}

	static const FName INPIN_TextInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, TextInputProperty);
	const FFlowDataPinResult_Text TextResult = TryResolveDataPinAsText(INPIN_TextInput);
	if (TextResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *TextResult.Value.ToString(), *INPIN_TextInput.ToString()));
	}

	static const FName INPIN_EnumInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, EnumInputProperty);
	const FFlowDataPinResult_Enum EnumResult = TryResolveDataPinAsEnum(INPIN_EnumInput);
	if (EnumResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *EnumResult.Value.ToString(), *INPIN_EnumInput.ToString()));
	}

	static const FName INPIN_VectorInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, VectorInputProperty);
	const FFlowDataPinResult_Vector VectorResult = TryResolveDataPinAsVector(INPIN_VectorInput);
	if (VectorResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *VectorResult.Value.ToString(), *INPIN_VectorInput.ToString()));
	}

	static const FName INPIN_TransformInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, TransformInputProperty);
	const FFlowDataPinResult_Transform TransformResult = TryResolveDataPinAsTransform(INPIN_TransformInput);
	if (TransformResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *TransformResult.Value.ToString(), *INPIN_TransformInput.ToString()));
	}

	static const FName INPIN_GameplayTagInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, GameplayTagInputProperty);
	const FFlowDataPinResult_GameplayTag GameplayTagResult = TryResolveDataPinAsGameplayTag(INPIN_GameplayTagInput);
	if (GameplayTagResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *GameplayTagResult.Value.ToString(), *INPIN_GameplayTagInput.ToString()));
	}

	static const FName INPIN_GameplayTagContainerInput = GET_MEMBER_NAME_CHECKED(UFlowNode_AllWrappedDataInputs, GameplayTagContainerInputProperty);
	const FFlowDataPinResult_GameplayTagContainer GameplayTagContainerResult = TryResolveDataPinAsGameplayTagContainer(INPIN_GameplayTagContainerInput);
	if (GameplayTagContainerResult.Result == EFlowDataPinResolveResult::Success)
	{
		LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *GameplayTagContainerResult.Value.ToString(), *INPIN_GameplayTagContainerInput.ToString()));
	}

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}
