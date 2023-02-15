#include <stdio.h>
#include <stdlib.h>

//Creating structure for node
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL, *newNode, *temp;

void addNode(void){
    //creation of a new node
    newNode = (struct node*) malloc(sizeof(struct node));  //malloc returns a void pointer, so we need to typecast it to a pointer to a node
    if (newNode == NULL){ //overflown, malloc returns a null pointer
        printf("Overflown!");
        return;
    }
    printf("Enter the data you want to store in the node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;

    //making the new node the head of the list if the head is not defined
    if (head == NULL){
        head = temp = newNode;
    }
    //If the head is already made, we make a new node and assign the address to the new node
    else{
        temp->next = newNode;
        temp = newNode;
    }
}

void traverseList(void){
    temp = head;  //begin from head
    
    if (head == NULL){
        printf("The linked list is empty!");
        return;
    }

    while(temp != NULL){ //until the next variable is NULL
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void updateNode(){
    int pos, data;
    temp = head;

    if (head == NULL){
        printf("The linked list is empty!");
        return;
    }

    printf("Enter the position of the node: ");
    scanf("%d", &pos);
    printf("Enter the data you want to store: ");
    scanf("%d", &data);

    for (int i = 0; i < pos; i++){
        temp = temp->next;
    }
    temp->data = data;
}

int main(){
    int selection;
    while(1){
        printf("1. Add a node \n2. Traverse the list \n3. Update a node \nEnter your selection: ");
        scanf("%d", &selection);
        switch(selection){
            case 1:
                addNode();
                break;
            case 2:
                traverseList();
                break;
            case 3:
                updateNode();
                break;
            default:
                printf("You're really an idiot, right?");
                break;
        }
    }
    
    return 0;
}