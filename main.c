#include <stdio.h>

// Graph
void initGraph();
void addLocation();
void addRoute();
void displayGraph();
void shortestPath();

// Package
void addPackage();
void displayPackages();
void enqueuePackage();
void deliverPackage();
void displayQueue();
void searchPackage();
void deletePackage();

int main() {
    int choice;

    initGraph();

    do {
        printf("\n===== Delivery Route & Package Tracker =====\n");
        printf("1. Add Location\n");
        printf("2. Add Route\n");
        printf("3. Display Routes\n");
        printf("4. Add Package\n");
        printf("5. Display Packages\n");
        printf("6. Add Package to Priority Queue\n");
        printf("7. Deliver Package\n");
        printf("8. Display Delivery Queue\n");
        printf("9. Shortest Path\n");
        printf("10. Search Package\n");
        printf("11. Delete Package\n");
        printf("12. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: addLocation(); break;
            case 2: addRoute(); break;
            case 3: displayGraph(); break;
            case 4: addPackage(); break;
            case 5: displayPackages(); break;
            case 6: enqueuePackage(); break;
            case 7: deliverPackage(); break;
            case 8: displayQueue(); break;
            case 9: shortestPath(); break;
            case 10: searchPackage(); break;
            case 11: deletePackage(); break;
            case 12: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(choice != 12);

    return 0;
}