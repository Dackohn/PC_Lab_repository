#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

#define Stack_capacity 16

union d_type {
    char ch;
    int in;
    float fl;
};

typedef enum {
    CHAR,
    INTEGER,
    FLOAT
} Data_Type;

typedef struct Node {
    union d_type d;
    Data_Type type;
    struct Node* next;
} Node;

void append_int(Node** root, int value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->d.in = value;
    new_node->type = INTEGER;
    if (*root == NULL) {
        *root = new_node;
    } else {
        Node* curr = *root;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void append_ch(Node** root, char value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->d.ch = value;
    new_node->type = CHAR;
    if (*root == NULL) {
        *root = new_node;
    } else {
        Node* curr = *root;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void append_fl(Node** root, float value) {
    Node* new_node = malloc(sizeof(Node));
    if (new_node == NULL) {
        exit(1);
    }
    new_node->next = NULL;
    new_node->d.fl = value;
    new_node->type = FLOAT;
    if (*root == NULL) {
        *root = new_node;
    } else {
        Node* curr = *root;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

bool isChar(const char* input) {
    if (input == NULL || input[0] == '\0') {
        return false;
    }
    
    if (input[1] == '\0') {
        return true;  
    } else {
        return false; 
    }
}

void displayMenu() {
    printf("\nStack Operations Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. IsEmpty\n");
    printf("5. IsFull\n");
    printf("6. Exit\n");
}


int main() {
    int choice;
    int append_integer;
    int Num_el;
    char ver1[20];
    char append_char;
    float append_float;
    Node* root = NULL;
    Node* curr;
    char type[8];

    while (1) {
        displayMenu();
        printf("Make your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (root != NULL) {
                    curr = root;
                    Num_el = 1;
                    while (curr->next != NULL) {
                        curr = curr->next;
                        Num_el++;
                    }
                    if (Num_el >= Stack_capacity) {
                        printf("The stack is already full.\n");
                    } else {
                        printf("Enter the type of the value (char, integer, or float): \n");
                        scanf("%s", type);
                        if (strcmp(type, "integer") == 0) {
                            printf("Enter the value to push onto the stack: \n");
                            scanf("%d", &append_integer);
                            append_int(&root, append_integer);
                        } else if (strcmp(type, "char") == 0) {
                            printf("Enter the value to push onto the stack:  \n");
                            getchar();
                            scanf("%s",&ver1);
                            if(isChar(ver1)){
                                append_char = *ver1;
                            } else {
                                printf("Not a character.\n");
                            }
                            
                            append_ch(&root, append_char);
                            
                        } else if (strcmp(type, "float") == 0) {
                            printf("Enter the value to push onto the stack: \n");
                            scanf("%f", &append_float);
                            append_fl(&root, append_float);
                        } else{
                            printf("Invalid choice.\n");
                        }
                }
                } else{
                    printf("Enter the type of the value (char, integer, or float): \n");
                    scanf("%s", type);
                   if (strcmp(type, "integer") == 0) {
                        printf("Enter the value to push onto the stack: \n");
                        scanf("%d", &append_integer);
                        append_int(&root, append_integer);
                    } else if (strcmp(type, "char") == 0) {
                        printf("Enter the value to push onto the stack:  \n");
                        getchar();
                        scanf("%s",&ver1);
                        if(isChar(ver1)){
                            append_char = *ver1;
                        } else {
                            printf("Not a character.\n");
                        }
                            
                        append_ch(&root, append_char);
                    } else if (strcmp(type, "float") == 0) {
                        printf("Enter the value to push onto the stack: \n");
                        scanf("%f", &append_float);
                        append_fl(&root, append_float);
                    } else {
                        printf("Invalid choice.\n");
                    }
                }
                break;
            case 2:
                if (root != NULL) {
                    curr = root;
                    Node* prev = NULL;

                    while (curr->next != NULL) {
                        prev = curr;
                        curr = curr->next;
                    }

                    if (curr->type == INTEGER) {
                        printf("Popped element: %d\n", curr->d.in);
                    } else if (curr->type == CHAR) {
                        printf("Popped element: %c\n", curr->d.ch);
                    } else if (curr->type == FLOAT) {
                        printf("Popped element: %f\n", curr->d.fl);
                    }

                    free(curr);

                    if (prev != NULL) {
                        prev->next = NULL;  
                    } else {
                        root = NULL; 
                    }
                } else {
                    printf("Stack is empty, cannot pop.\n");
                }
                break;
            case 3:
                if (root != NULL){
                    curr = root;

                    while (curr->next != NULL) {
                        curr = curr->next;
                    }
                    if(curr->type == INTEGER){
                    printf("Peeked element: %d \n",curr->d.in);
                    }
                    if(curr->type == CHAR){
                        printf("Peeked element: %c \n",curr->d.ch);
                    }
                    if(curr->type == FLOAT){
                        printf("Peeked element: %f \n",curr->d.fl);
                    }
                } else{
                    printf("Stack is empty, cannot peek.\n");
                }
                break;
            case 4:
                if(root == NULL){
                    printf("The stack is empty.\n");
                } else{
                    printf("The stack is not empty.\n");
                }
                break;
            case 5:
                curr = root;
                Num_el=0;
                while (curr->next != NULL) {
                    curr = curr->next;
                    Num_el++;
                }
                if (Num_el==Stack_capacity){
                    printf("The stack if full.\n");
                } else{
                    printf("The stack is not full.\n");
                }
                break;
            case 6:
                return 0;
                while (root != NULL) {
                    Node* temp = root;
                    root = root->next;
                    free(temp);
                }

        }

        printf("Stack Contents: ");
        if(root!=NULL){
            for (curr = root; curr != NULL; curr = curr->next) {
                if(curr->type == INTEGER){
                    printf("%d ",curr->d.in);
                }
                if(curr->type == CHAR){
                    printf("%c ",curr->d.ch);
                }
                if(curr->type == FLOAT){
                    printf("%f ",curr->d.fl);
                }
            }
        } else{
            printf("(empty)");
        }
    }
}
