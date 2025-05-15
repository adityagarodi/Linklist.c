#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* top = NULL;
    struct Node* temp;
    int choice, value;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &value);
            temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = value;
            temp->next = top;
            top = temp;
        } else if (choice == 2) {
            if (top == NULL) {
                printf("Stack is empty\n");
            } else {
                temp = top;
                top = top->next;
                printf("Popped: %d\n", temp->data);
                free(temp);
            }
        } else if (choice == 3) {
            temp = top;
            if (temp == NULL) {
                printf("Stack is empty\n");
            } else {
                printf("Stack: ");
                while (temp != NULL) {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
