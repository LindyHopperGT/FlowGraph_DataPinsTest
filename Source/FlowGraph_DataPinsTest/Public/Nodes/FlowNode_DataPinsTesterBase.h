// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "Nodes/FlowNode.h"
#include "Types/FlowDataPinValuesStandard.h"
#include "Types/FlowArray.h"

#include "FlowNode_DataPinsTesterBase.generated.h"

UCLASS(Abstract, BlueprintType, DisplayName = "Data Pins Tester Base")
class FLOWGRAPH_DATAPINSTEST_API UFlowNode_DataPinsTesterBase : public UFlowNode
{
	GENERATED_BODY()

protected:
	template <typename T>
	void LogResults(const FName& PinName, EFlowDataPinResolveResult ResultEnum, const TArray<T>& Values, TFunctionRef<FString(const T&)> Formatter) const
	{
		if (ResultEnum == EFlowDataPinResolveResult::Success)
		{
			const FString ValueString = FlowArray::FormatArrayString<T>(Values, Formatter);
			LogNote(FString::Printf(TEXT("%s resolved %s for pin %s"), *GetName(), *ValueString, *PinName.ToString()));
		}
		else
		{
			LogNote(FString::Printf(TEXT("%s %s for pin %s"), *GetName(), *UEnum::GetDisplayValueAsText(ResultEnum).ToString(), *PinName.ToString()));
		}
	}

	UPROPERTY(EditAnywhere, Category = Test)
	bool bIsResolver = false;
};
