#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Graph.h"
#include "GraphActor.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AICON_API AGraphActor : public AActor
{
    GENERATED_BODY()

public:
    AGraphActor();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pathfinding")
    UGraph* Graph;

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    UNode* AddNodeAtLocation(const FVector& Location);

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void AddEdgeBetweenNodes(UNode* FromNode, UNode* ToNode, float Cost);

    UFUNCTION(BlueprintCallable, Category = "Pathfinding")
    void DrawGraph();
};
