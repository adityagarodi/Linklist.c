#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* prev;
	struct Node* next;
};

int main() {
	struct Node* head = NULL;
	struct Node* tail = NULL;
	struct Node* temp;
	int choice, value;

	while (1) {
		printf("\n1. Insert at beginning\n2. Insert at end\n3. Delete from beginning\n4. Delete from end\n 5. Display\n6. Exit\nEnter choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printf ("Insert at beginning\n");
			printf("Enter value to insert: ");
			scanf("%d", &value);
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = value;
			temp->prev = NULL;
			temp->next = head;
			if (head != NULL)
				head->prev = temp;
			else
				tail = temp;
			head = temp;
			break;

		case 2:
			printf("Insert at end\n");
			printf("Enter value to insert: ");
			scanf("%d", &value);
			temp = (struct Node*)malloc(sizeof(struct Node));
			temp->data = value;
			temp->next = NULL;
			temp->prev = tail;
			if (tail != NULL)
				tail->next = temp;
			else
				head = temp;
			tail = temp;
			break;

		case 3:
			printf("Delete from beginning:\n");
			if (head == NULL) {
				printf("List is empty\n");
			} else {
				temp = head;
				head = head->next;
				if (head != NULL)
					head->prev = NULL;
				else
					tail = NULL;
				printf("Deleted: %d\n", temp->data);
				free(temp);
			}
			break;

		case 4:
			printf("Delete from end\n");
			if (tail == NULL) {
				printf("List is empty\n");
			} else {
				temp = tail;
				tail = tail->prev;
				if (tail != NULL)
					tail->next = NULL;
				else
					head = NULL;
				printf("Deleted: %d\n", temp->data);
				free(temp);
			}
			break;

		case 5:
			printf("\nDisplay\n");
			if (head == NULL) {
				printf("List is empty\n");
			} else {
				printf("List: ");
				temp = head;
				while (temp != NULL) {
					printf("%d ", temp->data);
					temp = temp->next;
				}
				printf("\n");
			}
			break;

		case 6:
			printf("exit\n");
			return 0;

		default:
			printf("Invalid choice\n");
		}
	}

	return 0;
}
