#pragma once

#include "CoreMinimal.h"
#include "Graph.h"
#include "Dijkstra.generated.h"

UCLASS()
class AICON_API UDijkstra : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    static TArray<UNode*> FindShortestPath(UGraph* Graph, UNode* StartNode, UNode* EndNode);
};
