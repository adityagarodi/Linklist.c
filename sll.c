#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

struct node *head = NULL, *newnode, *prevnode,*temp;

int main() {
	int ch,cont, chh;
	do {
		printf("Which operation do you want to perform?\n1. Insertion\n2. Deletion\n3. Display\n4. Quite\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			do {
				printf("Insertion .\n");
				printf("At which position do you want to insert element?\n1. At beginning\n2. At end\n");
				scanf("%d", &chh);

				switch (chh) {
				case 1:
					printf("Insertion at beginning:\n");
					newnode = (struct node *)malloc(sizeof(struct node));
					printf("Enter data for new node: ");
					scanf("%d", &newnode->data);
					newnode->next = head;
					head = newnode;
					break;

				case 2:
					printf("Insertion at end:\n");
					newnode = (struct node *)malloc(sizeof(struct node));
					printf("Enter data for new node: ");
					scanf("%d", &newnode->data);
					newnode->next = NULL;

					if (head == NULL) {
						head = newnode;
					} else {
						temp = head;
						while (temp->next != NULL) {
							temp = temp->next;
						}
						temp->next = newnode;
					}
					break;

				default:
					printf("Invalid insertion choice.\n");
					break;
				}
				printf("Do you want to continue insertion? (yes=0 / no=1): ");
				scanf("%d", &cont);
			}
			while (cont == 0);
			break;

		case 2:
			printf("Deletion.\n");
			do {
				printf("At which position do you want to delete element?\n1. At beginning\n2. At end\n");
				scanf("%d", &chh);

				switch (chh) {
				case 1:
					printf("Deletion at beginning:\n");
					if (head == NULL) {
						printf("Singly linked list is empty.\n");
					} else {
						temp = head;
						head = head->next;
						temp->next = NULL;
						free(temp);
					}
					break;

				case 2:
					printf("Deletion at end:\n");
					if (head == NULL) {
						printf("Singly linked list is empty.\n");
					} else {
						temp = head;
						while (temp->next != NULL) {
							prevnode = temp;
							temp = temp->next;
						}
						if (head == temp) {
							head = NULL;
							free(temp);
						} else {
							prevnode->next = NULL;
							free(temp);
						}
					}
					break;

				default:
					printf("Invalid deletion choice.\n");
					break;
				}

				printf("Do you want to continue deletion? (yes=0 / no=1): ");
				scanf("%d", &cont);
			} while (cont == 0);
			break;



		case 3:
			printf("Displaying list:\n");
			temp = head;
			while (temp != NULL)
			{
				printf("Data: %d, Address: %p\n", temp->data, (void*)temp);
				temp = temp->next;
			}
			break;
              
          case 4:
          printf("quite:");
              exit(0);
              break; 

		default:
			printf("Invalid choice.\n");
			break;
		}
		printf("Do you want to perform another operation? (yes=0 / no=1): ");
		scanf("%d", &cont);
	}
	while (cont == 0);


	return 0;
}
