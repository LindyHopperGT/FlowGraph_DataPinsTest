#pragma once

#include "FlowNode_DataPinsTesterBase.h"
#include "Types/FlowDataPinValuesStandard.h"
#include "FlowNode_DataPinsTester_String.generated.h"

UCLASS(BlueprintType, DisplayName = "Data Pins Tester - String")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTester_String : public UFlowNode_DataPinsTesterBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Name"))
	FName Name_Single_Output = "Anna";

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "String"))
	FString String_Single_Output = "Bob";

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Text"))
	FText Text_Single_Output = FText::FromString("Carrie");

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Name"))
	TArray<FName> Name_Array_Output = { "Donald", "Emma" };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "String"))
	TArray<FString> String_Array_Output = { "Frank", "Georgia" };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (SourceForOutputFlowPin, FlowPinType = "Text"))
	TArray<FText> Text_Array_Output = { FText::FromString("Harry"), FText::FromString("Ingrid") };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Name Name_Wrapped_Output = FFlowDataPinValue_Name({ "Marge", "Ned" });

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_String String_Wrapped_Output = FFlowDataPinValue_String(FString(TEXT("Olivia")));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_Text Text_Wrapped_Output = FFlowDataPinValue_Text(FText::FromString(TEXT("Peter")));

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Name"))
	FName Name_Single_Input = "-Quinn";

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "String"))
	FString String_Single_Input = TEXT("-Robert");

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Text"))
	FText Text_Single_Input = FText::FromString("-Sasha");

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Name"))
	TArray<FName> Name_Array_Input = { "-Terry", "-Ursula" };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "String"))
	TArray<FString> String_Array_Input = { "-Vance", "-Wendy" };

	UPROPERTY(EditAnywhere, Category = DataPins, meta = (DefaultForInputFlowPin, FlowPinType = "Text"))
	TArray<FText> Text_Array_Input = { FText::FromString("-Xavier"), FText::FromString("-Yenta") };

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinValue_String String_Wrapped_Input = FFlowDataPinValue_String(FString(TEXT("-Barney")));

	// #FlowDataPinLegacy
	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Name Name_LegacyWrapped_Output = FFlowDataPinOutputProperty_Name(FName("Zach"));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_String String_LegacyWrapped_Output = FFlowDataPinOutputProperty_String(FString(TEXT("Abe")));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinOutputProperty_Text Text_LegacyWrapped_Output = FFlowDataPinOutputProperty_Text(FText::FromString("Barney"));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Name Name_LegacyWrapped_Input = FFlowDataPinInputProperty_Name(FName("-Zack"));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_String String_LegacyWrapped_Input = FFlowDataPinInputProperty_String(FString(TEXT("-Abe")));

	UPROPERTY(EditAnywhere, Category = DataPins)
	FFlowDataPinInputProperty_Text Text_LegacyWrapped_Input = FFlowDataPinInputProperty_Text(FText::FromString("-Barney"));
	// --

public:
	UFlowNode_DataPinsTester_String();

	// IFlowCoreExecutableInterface
	virtual void ExecuteInput(const FName& PinName) override;

	// IFlowDataPinValueSupplierInterface
	virtual FFlowDataPinResult TrySupplyDataPin(FName PinName) const override;
};