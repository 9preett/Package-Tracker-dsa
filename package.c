#include <stdio.h>
#include <stdlib.h>

struct Package {
    int id, src, dest, priority;
    struct Package *next;
};

struct Package *head = NULL;
struct Package *front = NULL;
struct Package *rear = NULL;

// Add package
void addPackage() {
    struct Package *newNode = malloc(sizeof(struct Package));

    printf("Enter ID: "); scanf("%d", &newNode->id);
    printf("Enter source: "); scanf("%d", &newNode->src);
    printf("Enter destination: "); scanf("%d", &newNode->dest);
    printf("Priority (1 High, 2 Normal): ");
    scanf("%d", &newNode->priority);

    newNode->next = NULL;

    if(head == NULL)
        head = newNode;
    else {
        struct Package *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }

    printf("Package added!\n");
}

// Display packages
void displayPackages() {
    struct Package *temp = head;

    if(!temp) {
        printf("No packages!\n");
        return;
    }

    printf("\nID  SRC  DEST  PRIORITY\n");

    while(temp) {
        printf("%d   %d    %d      %d\n",
               temp->id, temp->src, temp->dest, temp->priority);
        temp = temp->next;
    }
}

// Priority queue
void enqueuePackage() {
    int id;
    printf("Enter package ID: ");
    scanf("%d", &id);

    struct Package *temp = head;

    while(temp) {
        if(temp->id == id) {
            struct Package *newNode = malloc(sizeof(struct Package));
            *newNode = *temp;
            newNode->next = NULL;

            if(newNode->priority == 1) {
                newNode->next = front;
                front = newNode;
                if(rear == NULL) rear = newNode;
            } else {
                if(rear == NULL)
                    front = rear = newNode;
                else {
                    rear->next = newNode;
                    rear = newNode;
                }
            }

            printf("Added to queue!\n");
            return;
        }
        temp = temp->next;
    }

    printf("Package not found!\n");
}

// Deliver
void deliverPackage() {
    if(front == NULL) {
        printf("Queue empty!\n");
        return;
    }

    struct Package *temp = front;
    printf("Delivered package ID: %d\n", temp->id);

    front = front->next;
    if(front == NULL) rear = NULL;

    free(temp);
}

// Show queue
void displayQueue() {
    struct Package *temp = front;

    if(!temp) {
        printf("Queue empty!\n");
        return;
    }

    printf("\nQueue:\n");

    while(temp) {
        printf("ID: %d (Priority %d)\n",
               temp->id, temp->priority);
        temp = temp->next;
    }
}

// Search
void searchPackage() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct Package *temp = head;

    while(temp) {
        if(temp->id == id) {
            printf("Found! SRC=%d DEST=%d\n",
                   temp->src, temp->dest);
            return;
        }
        temp = temp->next;
    }

    printf("Not found!\n");
}

// Delete
void deletePackage() {
    int id;
    printf("Enter ID: ");
    scanf("%d", &id);

    struct Package *temp = head, *prev = NULL;

    while(temp) {
        if(temp->id == id) {
            if(prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("Deleted!\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Not found!\n");
}