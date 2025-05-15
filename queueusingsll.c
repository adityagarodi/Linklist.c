#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *front = NULL, *rear = NULL, *newnode, *temp;
    int ch, val;

    do {
        printf("\nWhich operation do you want to perform?\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                newnode = (struct node *)malloc(sizeof(struct node));
                if (newnode == NULL) {
                    printf("Memory allocation failed.\n");
                    break;
                }
                printf("Enter data to enqueue: ");
                scanf("%d", &newnode->data);
                newnode->next = NULL;

                if (rear == NULL) {
                    front = rear = newnode;
                } else {
                    rear->next = newnode;
                    rear = newnode;
                }
                printf("Enqueued %d\n", newnode->data);
                break;

            case 2:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    temp = front;
                    front = front->next;
                    printf("Dequeued %d\n", temp->data);
                    free(temp);
                    if (front == NULL) {
                        rear = NULL;
                    }
                }
                break;

            case 3:
                if (front == NULL) {
                    printf("Queue is empty.\n");
                } else {
                    temp = front;
                    printf("Queue: ");
                    while (temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                    }
                    printf("NULL\n");
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (ch != 4);

    return 0;
}
