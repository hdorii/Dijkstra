#include "GraphActor.h"
#include "DrawDebugHelpers.h"

AGraphActor::AGraphActor()
{
    Graph = CreateDefaultSubobject<UGraph>(TEXT("Graph"));
}

void AGraphActor::BeginPlay()
{
    Super::BeginPlay();
}

UNode* AGraphActor::AddNodeAtLocation(const FVector& Location)
{
    if (!Graph) return nullptr;

    UNode* NewNode = Graph->AddNode(Location);

    DrawDebugSphere(GetWorld(), Location, 50.0f, 12, FColor::Blue, true, -1.0f);
    return NewNode;
}

void AGraphActor::AddEdgeBetweenNodes(UNode* FromNode, UNode* ToNode, float Cost)
{
    if (!Graph || !FromNode || !ToNode) return;

    Graph->AddEdge(FromNode, ToNode, Cost);
    DrawDebugLine(GetWorld(), FromNode->Position, ToNode->Position, FColor::Yellow, true, -1.0f, 0, 5.0f);
}

void AGraphActor::DrawGraph()
{
    if (!Graph) return;

    for (UNode* Node : Graph->Nodes)
    {
        for (int32 i = 0; i < Node->Neighbors.Num(); i++)
        {
            UNode* Neighbor = Node->Neighbors[i];
            DrawDebugLine(GetWorld(), Node->Position, Neighbor->Position, FColor::Green, false, -1.0f, 0, 5.0f);
        }
    }
}
