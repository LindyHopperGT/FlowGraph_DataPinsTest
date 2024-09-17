// Copyright Riot Games, All Rights Reserved.

#include "Nodes/FlowNode_AllWrappedDataOutputs.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(FlowNode_AllWrappedDataOutputs)

UFlowNode_AllWrappedDataOutputs::UFlowNode_AllWrappedDataOutputs(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFlowNode_AllWrappedDataOutputs::ExecuteInput(const FName& PinName)
{
	Super::ExecuteInput(PinName);

	constexpr bool bFinish = true;
	TriggerFirstOutput(bFinish);
}

FFlowDataPinResult_Bool UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsBool_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Bool Result = Super::TrySupplyDataPinAsBool_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), Result.Value ? TEXT("true") : TEXT("false"), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Int UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsInt_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Int Result = Super::TrySupplyDataPinAsInt_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %ld for pin %s"), *GetName(), Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Float UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsFloat_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Float Result = Super::TrySupplyDataPinAsFloat_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %.0f for pin %s"), *GetName(), Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Name UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsName_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Name Result = Super::TrySupplyDataPinAsName_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_String UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsString_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_String Result = Super::TrySupplyDataPinAsString_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value, *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Text UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsText_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Text Result = Super::TrySupplyDataPinAsText_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Enum UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsEnum_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Enum Result = Super::TrySupplyDataPinAsEnum_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Vector UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsVector_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Vector Result = Super::TrySupplyDataPinAsVector_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_Transform UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsTransform_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_Transform Result = Super::TrySupplyDataPinAsTransform_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_GameplayTag UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsGameplayTag_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_GameplayTag Result = Super::TrySupplyDataPinAsGameplayTag_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}

FFlowDataPinResult_GameplayTagContainer UFlowNode_AllWrappedDataOutputs::TrySupplyDataPinAsGameplayTagContainer_Implementation(const FName& PinName) const
{
	FFlowDataPinResult_GameplayTagContainer Result = Super::TrySupplyDataPinAsGameplayTagContainer_Implementation(PinName);

	LogNote(FString::Printf(TEXT("%s supplied %s for pin %s"), *GetName(), *Result.Value.ToString(), *PinName.ToString()));

	return Result;
}
