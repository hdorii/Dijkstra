#pragma once

#include "CoreMinimal.h"
#include "Node.h"
#include "Graph.generated.h"

UCLASS(Blueprintable)
class AICON_API UGraph : public UObject
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    TArray<UNode*> Nodes;

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    UNode* AddNode(const FVector& Position);

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void AddEdge(UNode* From, UNode* To, float Cost);
};
