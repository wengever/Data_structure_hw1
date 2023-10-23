#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int source, destination, weight;
};

struct Subset {
    int parent, rank;
};

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void unionSets(struct Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

long long kruskalMST(struct Edge edges[], int V, int E){
    qsort(edges, E, sizeof(struct Edge), compareEdges);
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    long long minCost = 0;  // Initialize the result
    for(int i = 0, e = 0; e < V-1; i++){
        struct Edge nextEdge = edges[i];
        int x = find(subsets, nextEdge.source);
        int y = find(subsets, nextEdge.destination);
        if (x != y) {
            minCost += nextEdge.weight;
            unionSets(subsets, x, y);
            e++;
        }
    }
    free(subsets);
    return minCost;
}


int main(){
    int V,E;
    scanf("%d %d",&V,&E);
    struct Edge* edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    for (int i = 0; i < E; i++) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);
        edges[i].source = s;
        edges[i].destination = t;
        edges[i].weight = c;
    }
    long long minCost = kruskalMST(edges, V, E);
    printf("%lld\n", minCost);
    free(edges);

}