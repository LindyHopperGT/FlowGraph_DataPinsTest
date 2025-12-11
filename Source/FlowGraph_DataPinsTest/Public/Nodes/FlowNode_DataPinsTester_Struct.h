// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_Struct.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - Struct")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_Struct : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Vector"))
	FVector Vector_Single_Output = FVector(1, 1, 1);

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Rotator"))
	FRotator Rotator_Single_Output = FRotator(2, 2, 2);

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Transform"))
	FTransform Transform_Single_Output = FTransform(FRotator(3), FVector(3));

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Vector"))
	TArray<FVector> Vector_Array_Output = { FVector(4), FVector(5) };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Rotator"))
	TArray<FRotator> Rotator_Array_Output = { FRotator(6), FRotator(7) };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Transform"))
	TArray<FTransform> Transform_Array_Output = { FTransform(FRotator(8), FVector(8)), FTransform(FRotator(9), FVector(9)) };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Vector Vector_Wrapped_Output = FFlowDataPinValue_Vector(FVector(10));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Rotator Rotator_Wrapped_Output = FFlowDataPinValue_Rotator(FRotator(11));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Transform Transform_Wrapped_Output = FFlowDataPinValue_Transform(FTransform(FRotator(12), FVector(12)));

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Vector"))
	FVector Vector_Single_Input = FVector(-13);

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Rotator"))
	FRotator Rotator_Single_Input = FRotator(-14);

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Transform"))
	FTransform Transform_Single_Input = FTransform(FRotator(-15), FVector(-15));

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Vector"))
	TArray<FVector> Vector_Array_Input = { FVector(-16), FVector(-17) };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Rotator"))
	TArray<FRotator> Rotator_Array_Input = { FRotator(-18), FRotator(-19) };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Transform"))
	TArray<FTransform> Transform_Array_Input = { FTransform(FRotator(-20), FVector(-20)), FTransform(FRotator(-21), FVector(-21)) };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Transform Transform_Wrapped_Input = FFlowDataPinValue_Transform(FTransform(FRotator(-22), FVector(-22)));

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Vector Vector_LegacyWrapped_Output = FVector(10);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Rotator Rotator_LegacyWrapped_Output = FRotator(11);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Transform Transform_LegacyWrapped_Output = FTransform(FRotator(22), FVector(22));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Vector Vector_LegacyWrapped_Input = FVector(-10);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Rotator Rotator_LegacyWrapped_Input = FRotator(-11);

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Transform Transform_LegacyWrapped_Input = FTransform(FRotator(-22), FVector(-22));
	// --

public:
	UFlowNode_DataPinsTester_Struct(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin_Implementation(FName PinName) const override;
};