#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura do nó da lista
struct Product {
    char name[50];
    float price;
    struct Product* next;
};

// Função para criar um novo nó
struct Product* createProduct(char name[], float price) {
    struct Product* newProduct = (struct Product*)malloc(sizeof(struct Product));
    strcpy(newProduct->name, name);
    newProduct->price = price;
    newProduct->next = NULL;
    return newProduct;
}

// Função para inserir um nó na lista ordenada
void insertOrderedProduct(struct Product** head, char name[], float price) {
    struct Product* newProduct = createProduct(name, price);
    struct Product* current = *head;
    struct Product* prev = NULL;

    // Encontrar o ponto de inserção na lista ordenada
    while (current != NULL && strcmp(current->name, name) < 0) {
        prev = current;
        current = current->next;
    }

    // Inserir o novo nó na lista
    if (prev == NULL) {
        // Inserir no início
        newProduct->next = *head;
        *head = newProduct;
    } else {
        // Inserir no meio ou no final
        prev->next = newProduct;
        newProduct->next = current;
    }
}

// Função para imprimir a lista de produtos
void printProductList(struct Product* head) {
    struct Product* current = head;
    while (current != NULL) {
        printf("%s - R$ %.2f\n", current->name, current->price);
        current = current->next;
    }
}

// Função principal
int main() {
	setlocale(LC_ALL, "portuguese");
    int size, i;
    char name[50];
    float price;

    // Solicitar o tamanho da lista
    printf("Digite o tamanho da lista de compras: ");
    scanf("%d", &size);
	
	system("cls");
    // Inicializar a lista de compras vazia
    struct Product* productList = NULL;

    // Solicitar produtos e preços e inserir na lista ordenada de compras
    for (i = 0; i < size; i++) {
        printf("Digite o nome do produto %d de %d: ", i + 1,size);
        scanf("%s", name);
        printf("\nDigite o pre�o do produto %d: R$ ", i + 1);
        scanf("%f", &price);
        insertOrderedProduct(&productList, name, price);
        system("cls");
    }

    // Imprimir a lista ordenada de compras
    printf("Lista Ordenada de Compras:\n");
    printProductList(productList);

	getch();
    return 0;
}
