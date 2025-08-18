/* How are you now */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    if(!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

void print(Node* node) {
    while(node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void printAddress(Node* node) {
    while(node) {
        printf("%p -> ", node);
        node = node->next;
    }
    printf("NULL\n");
}


void insertFirst(Node** head, int data) {
    Node* node = createNode(data);
    node->next = *head;
    *head = node;
}

void insertAfterLocation(Node* p, int data) {
    Node* node = createNode(data);
    node->next = p->next;
    p->next = node;
}

void delete(Node* pre, Node* del) {
    free(pre->next);
    pre->next = del->next;
}

int main() {
    
    Node* node1 = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    
    Node* head = node1;
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    print(head);
    
    while(1) {
        printf("\nWhat do you want to do: \n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert after a location\n");
        printf("3. deletion\n");
        printf("4. Exit\n");
        
        int input;
        scanf("%d", &input);
        switch(input) {
            
            case 1:
                while(1) {
                    printf("\n--Enter a character to go back--\n");
                    printf("Enter your data: ");
                    int data;
                    
                    if(!scanf("%d", &data)) {
                        while(getchar() != '\n');
                        break;
                    }
                    
                    insertFirst(&head, data);
                    printf("\nYour updated list is:\n");
                    print(head);
                }
                break;
                
            case 2:
                while(1) {
                    printf("\n--Enter a character to go back--\n");
                    printAddress(head);
                    int data;
                    printf("Enter data: ");
                    if(!scanf("%d", &data)) {
                        while(getchar() != '\n');
                        break;
                    }
                    Node *p;
                    printf("\nenter address: ");
                    scanf("%p", &p);
                    
                    if(!p) insertFirst(&head, data);
                    else insertAfterLocation(p, data);
                    
                    printf("\nYour updated list is:\n");
                    print(head);
                }
                break;
                
            case 3:
                while(1) {
                    printf("\n--Enter a character to go back--\n");
                    printAddress(head);
                    Node *pre, *del;
                    printf("\nEnter the address of deletion: ");
                    int i = scanf("%p", &del);
                    if(!i) {
                        char ch;
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        break;
                        
                    }
                    
                    printf("Enter the previous address: ");
                    scanf("%p", &pre);
                    
                    
                    if(!pre) {
                        head = head->next;
                    }
                    else delete(pre, del);
                    
                    print(head);
                }
                break;
                
            case 4:
                break;
            
        }
        if(input == 4) break;
    }
    
    print(head);
    
    return 0;
}
