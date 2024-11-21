#include "Dijkstra.h"

TArray<UNode*> UDijkstra::FindShortestPath(UGraph* Graph, UNode* StartNode, UNode* EndNode)
{
    if (!Graph || !StartNode || !EndNode)
    {
        return TArray<UNode*>();
    }

    TMap<UNode*, float> Distances;
    TMap<UNode*, UNode*> PreviousNodes;
    TSet<UNode*> UnvisitedNodes;

    for (UNode* Node : Graph->Nodes)
    {
        Distances.Add(Node, FLT_MAX); // 초기화
        UnvisitedNodes.Add(Node);
    }
    Distances[StartNode] = 0;

    while (UnvisitedNodes.Num() > 0)
    {
        UNode* CurrentNode = nullptr;
        float SmallestDistance = FLT_MAX;

        for (UNode* Node : UnvisitedNodes)
        {
            float CurrentDistance = Distances[Node];
            if (CurrentDistance < SmallestDistance)
            {
                SmallestDistance = CurrentDistance;
                CurrentNode = Node;
            }
        }

        if (CurrentNode == EndNode)
        {
            break; // 목표 노드 도달
        }

        UnvisitedNodes.Remove(CurrentNode);

        for (int32 i = 0; i < CurrentNode->Neighbors.Num(); i++)
        {
            UNode* Neighbor = CurrentNode->Neighbors[i];
            float EdgeCost = CurrentNode->Costs[i];
            float NewDistance = Distances[CurrentNode] + EdgeCost;

            if (NewDistance < Distances[Neighbor])
            {
                Distances[Neighbor] = NewDistance;
                PreviousNodes.Add(Neighbor, CurrentNode);
            }
        }
    }

    TArray<UNode*> Path;
    UNode* Current = EndNode;

    while (Current)
    {
        Path.Insert(Current, 0);
        Current = PreviousNodes.FindRef(Current);
    }

    return Path;
}
