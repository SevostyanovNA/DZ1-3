#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int val; // Just value
    struct node* next; // Points to the next node
} node_t;

//Functions

void push(node_t **head, int value); //Add a node
void pop(node_t** head); //Delete the "top" node
void list(node_t* head); //Just... List IDK


int main(void) {
    int i = 0;
    int a = 0;
    node_t* head = (node_t *) calloc(sizeof(node_t), 1);
    printf("What do you want from me?\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - List\n");
    printf("4 - End\n");
    scanf("%d", &i);
    while(1) {
        switch (i) {
            case (1):
                printf("Enter some number\n");
                scanf("%d", &a);
                push(&head, a);
                printf("What's next?\n");
                scanf("%d", &i);
                break;
            case (2):
                pop(&head);
                printf("What's next?\n");
                scanf("%d", &i);
                break;
            case (3):
                list(head);
                scanf("%d", &i);
                break;
            case (4):
                printf("Goodbye\n");
                exit(0);
        }
    }
    return (0);
}

void push(node_t** head, int value) {
    node_t* tmp = (node_t*)calloc(sizeof(node_t),1);
    tmp->val = value;
    tmp->next = *head;
    *head = tmp;
}

void pop(node_t** head) {
    if ((*head)->next == NULL) {
        printf("No object to delete\n");
        return;
    }
    node_t* deleted = NULL; //Sozdal ukazatel, chtoby pochistit' po nemu pamyat'
    deleted = *head;
    *head = (*head)->next;
    free(deleted); // Free the memory of a deleted node
}

void list(node_t* head) {
    if (head->next ==0) printf("No objects in a list\n");
    while (head->next !=0) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}
