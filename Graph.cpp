#include "Graph.h"

UNode* UGraph::AddNode(const FVector& Position)
{
    UNode* NewNode = NewObject<UNode>();
    NewNode->Position = Position;
    Nodes.Add(NewNode);
    return NewNode;
}

void UGraph::AddEdge(UNode* From, UNode* To, float Cost)
{
    if (From && To)
    {
        From->Neighbors.Add(To);
        From->Costs.Add(Cost);
    }
}
