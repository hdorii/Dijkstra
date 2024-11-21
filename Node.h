#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Node.generated.h"

UCLASS(Blueprintable)
class AICON_API UNode : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    FVector Position;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    TArray<UNode*> Neighbors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    TArray<float> Costs; // 비용 배열
};
