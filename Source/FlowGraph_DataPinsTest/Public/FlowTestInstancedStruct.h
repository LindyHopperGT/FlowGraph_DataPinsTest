// Copyright Riot Games, All Rights Reserved.

#pragma once

#include "FlowTestInstancedStruct.generated.h"

USTRUCT(BlueprintType, DisplayName = "Flow Data Pins Test InstancedStruct")
struct FLOWGRAPH_DATAPINSTEST_API FFlowTestInstancedStruct
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = DataPins, DisplayName = "Int Property")
	int32 IntProperty = 0;
};
