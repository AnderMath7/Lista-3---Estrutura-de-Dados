#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertOrdered(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* current = *head;
    struct Node* prev = NULL;

    while (current != NULL && current->data < value) {
        prev = current;
        current = current->next;
    }

    
    if (prev == NULL) {
        
        newNode->next = *head;
        *head = newNode;
    } else {
       
        prev->next = newNode;
        newNode->next = current;
    }
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int size, value, i;
    

    printf("Digite o tamanho da lista: ");
    scanf("%d", &size);

    
    struct Node* head = NULL;

    
    for( i = 0; i < size; i++){
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &value);
        insertOrdered(&head, value);
    }

	system("cls");
	
    printf("Lista Ordenada: ");
    printList(head);
 
 	getch();
    return 0;
}
