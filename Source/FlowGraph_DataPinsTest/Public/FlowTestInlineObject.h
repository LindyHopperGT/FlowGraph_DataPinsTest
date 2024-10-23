// Copyright https://github.com/MothCocoon/FlowGraph/graphs/contributors

#pragma once

#include "FlowTestInlineObject.generated.h"

UCLASS(EditInlineNew, BlueprintType, DisplayName = "Flow Data Pins Test Inline Object")
class UFlowTestInlineObject : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int Property")
	int32 IntProperty = 0;
};
