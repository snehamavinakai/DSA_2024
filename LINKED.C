#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Function to insert a new node at the end of the linked list
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
}

// Function to delete the first occurrence of a key in the linked list
void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, key;
    clrscr();
    do {
	printf("\nSingly Linked List Operations\n");
	printf("1. Insert element at the beginning\n");
	printf("2. Insert element at the end\n");
	printf("3. Delete element\n");
	printf("4. Print list\n");
	printf("5. Exit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);

	switch(choice) {
	    case 1:
		printf("Enter the element to insert at the beginning: ");
		scanf("%d", &data);
		insertAtBeginning(&head, data);
		break;
	    case 2:
		printf("Enter the element to insert at the end: ");
		scanf("%d", &data);
		insertAtEnd(&head, data);
		break;
	    case 3:
		printf("Enter the element to delete: ");
		scanf("%d", &key);
		deleteNode(&head, key);
		break;
	    case 4:
		printf("Linked list elements: ");
		printList(head);
		break;
	    case 5:
		printf("Exiting...\n");
		break;
	    default:
		printf("Invalid choice\n");
	}
    } while (choice != 5);
    getch();
    return 0;
}
