#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // You can change the size

int queue[MAX];
int front = -1, rear = -1;

// Function to insert (enqueue) an element
void enqueue(int value) {
    if ((front == 0 && rear == MAX - 1) || (rear + 1) % MAX == front) {
        printf("Circular Queue is full!\n");
        return;
    }

    if (front == -1)  // first element
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
    printf("%d inserted into the circular queue.\n", value);
}

// Function to delete (dequeue) an element
void dequeue() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("%d deleted from the circular queue.\n", queue[front]);

    if (front == rear) {
        // Queue becomes empty after deletion
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// Function to display the circular queue
void display() {
    if (front == -1) {
        printf("Circular Queue is empty!\n");
        return;
    }

    printf("Circular Queue elements are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

// Main function with switch menu
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue Operations ---\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
