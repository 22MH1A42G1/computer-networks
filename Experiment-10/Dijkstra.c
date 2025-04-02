#include <stdio.h> 
#include <limits.h>

#define V 9  // Number of vertices in the graph

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    
    return min_index;
}

// Function to print the shortest distance from source to all vertices
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    int i;
	for (i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Implementation of Dijkstra's Algorithm using adjacency matrix
void dijkstra(int graph[V][V], int src) {
    int dist[V];   // Stores shortest distance from src to each vertex
    int sptSet[V]; // 1 if vertex is included in the shortest path tree

    // Initialize all distances as INFINITE and sptSet[] as 0
    int i;
	for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    int count;
	for (count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = 1;

        // Update the distance of adjacent vertices of the picked vertex
        int v;
		for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Driver function to test Dijkstra's Algorithm
int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 0, 10, 0, 2, 0, 0},
        {0, 0, 0, 14, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    dijkstra(graph, 0);
    return 0;
}

