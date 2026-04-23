#include <stdio.h>

#define MAX 10

// Graph representation
int graph[MAX][MAX];
int nodes = 0;

// Initialize graph
void initGraph() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            graph[i][j] = 0;
        }
    }
}

// Add location (node)
void addLocation() {
    if(nodes < MAX) {
        printf("Location %d added successfully!\n", nodes);
        nodes++;
    } else {
        printf("Maximum number of locations reached!\n");
    }
}

// Add route (edge)
void addRoute() {
    int src, dest, distance;

    printf("Enter source location (0 to %d): ", nodes - 1);
    scanf("%d", &src);

    printf("Enter destination location (0 to %d): ", nodes - 1);
    scanf("%d", &dest);

    printf("Enter distance: ");
    scanf("%d", &distance);

    if(src < nodes && dest < nodes && src >= 0 && dest >= 0) {
        graph[src][dest] = distance;
        graph[dest][src] = distance; // undirected graph
        printf("Route added successfully!\n");
    } else {
        printf("Invalid location indices!\n");
    }
}

// Display adjacency matrix
void displayGraph() {
    if(nodes == 0) {
        printf("No locations added yet!\n");
        return;
    }

    printf("\nAdjacency Matrix (City Map):\n");

    printf("   ");
    for(int i = 0; i < nodes; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < nodes; i++) {
        printf("%d: ", i);
        for(int j = 0; j < nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int choice;

    initGraph();

    do {
        printf("\n===== Delivery Route System (Phase 1) =====\n");
        printf("1. Add Location\n");
        printf("2. Add Route\n");
        printf("3. Display Map\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addLocation();
                break;

            case 2:
                if(nodes < 2) {
                    printf("Add at least 2 locations first!\n");
                } else {
                    addRoute();
                }
                break;

            case 3:
                displayGraph();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 4);

    return 0;
}