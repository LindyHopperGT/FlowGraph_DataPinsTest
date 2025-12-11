// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "FlowTestInstancedStruct.h"
#include "Types/FlowDataPinValuesStandard.h"

#include "FlowNode_DataPinsTester_InstancedStruct.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - InstancedStruct")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_InstancedStruct : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct"))
	FInstancedStruct InstancedStruct_Untyped_Single_Output = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct", BaseStruct = "/Script/FlowGraph_DataPinsTest.FlowTestInstancedStruct"))
	FInstancedStruct InstancedStruct_Typed_Single_Output = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct"))
	TInstancedStruct<FFlowTestInstancedStruct> InstancedStruct_Templatized_Single_Output;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "InstancedStruct"))
	TArray<FInstancedStruct> InstancedStruct_Array_Output = { FInstancedStruct(FFlowTestInstancedStruct::StaticStruct()) };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_InstancedStruct InstancedStruct_Wrapped_Output = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct"))
	FInstancedStruct InstancedStruct_Untyped_Single_Input = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct", BaseStruct = "/Script/FlowGraph_DataPinsTest.FlowTestInstancedStruct"))
	FInstancedStruct InstancedStruct_Typed_Single_Input = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct"))
	TInstancedStruct<FFlowTestInstancedStruct> InstancedStruct_Templatized_Single_Input;

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "InstancedStruct"))
	TArray<FInstancedStruct> InstancedStruct_Array_Input = { FInstancedStruct(FFlowTestInstancedStruct::StaticStruct()) };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_InstancedStruct InstancedStruct_Wrapped_Input = FFlowDataPinValue_InstancedStruct({ FInstancedStruct(FFlowTestInstancedStruct::StaticStruct()), FInstancedStruct(FFlowTestInstancedStruct::StaticStruct()) });

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_InstancedStruct InstancedStruct_LegacyWrapped_Output = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_InstancedStruct InstancedStruct_LegacyWrapped_Input = FInstancedStruct(FFlowTestInstancedStruct::StaticStruct());
	// --

public:
	UFlowNode_DataPinsTester_InstancedStruct(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin_Implementation(FName PinName) const override;
};