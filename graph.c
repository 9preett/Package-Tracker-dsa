#include <stdio.h>
#include <string.h>

#define MAX 10
#define INF 9999

int graph[MAX][MAX];
int nodes = 0;
char locationNames[MAX][30];

// Init
void initGraph() {
    for(int i = 0; i < MAX; i++)
        for(int j = 0; j < MAX; j++)
            graph[i][j] = 0;
}

// Add location
void addLocation() {
    if(nodes < MAX) {
        printf("Enter location name: ");
        scanf("%s", locationNames[nodes]);

        printf("Location '%s' added!\n", locationNames[nodes]);
        nodes++;
    } else {
        printf("Max locations reached!\n");
    }
}

// Show locations
void showLocations() {
    printf("\nLocations:\n");
    for(int i = 0; i < nodes; i++)
        printf("%d. %s\n", i, locationNames[i]);
}

// Add route
void addRoute() {
    int src, dest, dist;

    showLocations();

    printf("Enter source: ");
    scanf("%d", &src);

    printf("Enter destination: ");
    scanf("%d", &dest);

    printf("Enter distance: ");
    scanf("%d", &dist);

    if(src >= 0 && dest >= 0 && src < nodes && dest < nodes) {
        graph[src][dest] = dist;
        graph[dest][src] = dist;

        printf("Route added: %s -> %s\n",
               locationNames[src], locationNames[dest]);
    } else {
        printf("Invalid input!\n");
    }
}

// Display routes
void displayGraph() {
    printf("\nRoutes:\n");

    for(int i = 0; i < nodes; i++) {
        for(int j = i + 1; j < nodes; j++) {
            if(graph[i][j] != 0) {
                printf("%s -> %s = %d\n",
                       locationNames[i],
                       locationNames[j],
                       graph[i][j]);
            }
        }
    }
}

// Shortest path with actual route
void shortestPath() {
    int start, end;
    int distance[MAX], visited[MAX], parent[MAX];

    showLocations();

    printf("Enter source: ");
    scanf("%d", &start);

    printf("Enter destination: ");
    scanf("%d", &end);

    if(start < 0 || end < 0 || start >= nodes || end >= nodes) {
        printf("Invalid locations!\n");
        return;
    }

    for(int i = 0; i < nodes; i++) {
        distance[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }

    distance[start] = 0;

    for(int count = 0; count < nodes - 1; count++) {
        int min = INF, u = -1;

        for(int i = 0; i < nodes; i++) {
            if(!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if(u == -1) break;

        visited[u] = 1;

        for(int v = 0; v < nodes; v++) {
            if(graph[u][v] != 0 &&
               !visited[v] &&
               distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if(distance[end] == INF) {
        printf("No path exists!\n");
        return;
    }

    int path[MAX], count = 0;
    int temp = end;

    while(temp != -1) {
        path[count++] = temp;
        temp = parent[temp];
    }

    printf("\nShortest Path:\n");

    for(int i = count - 1; i >= 0; i--) {
        printf("%s", locationNames[path[i]]);
        if(i != 0) printf(" -> ");
    }

    printf("\nDistance = %d\n", distance[end]);
}