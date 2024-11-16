#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node{
    Node *prev;
    int value;
    Node *next;
}; Node *head = NULL, *tail = NULL;

Node *create_node(int value){
    Node *aux = malloc(sizeof(Node));
    if(!aux) fprintf(stderr, "Memory allocation failed.\n"), exit(EXIT_FAILURE);
    else aux->prev = aux->next = NULL, aux->value = value;
    return aux;
}
void insert_front(Node *node){
    if(!head){ // NULL
        head = tail = node;
    }else{
        head->prev = node;
        node->next = head;
        head = node;
    }
}
void insert_back(Node *node){
    if(!tail){ // NULL
        head = tail = node;
    }else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}
void remove_front(){
    if(head == tail) free(head), head = tail = NULL;
    else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}
void remove_back(){
    if(head == tail) free(tail), head = tail = NULL;
    else{
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
}
void print_list(){
    Node *aux = head;
    while (aux){
        printf("%d ", aux->value);
        aux = aux->next;
    }
}
Node *search_node(int value){
    Node *aux = head;
    while (aux){
        if(aux->value == value) break;
        aux = aux->next; 
    } return aux;
}
void remove_node(Node *node){
    if(node == head) remove_front();
    else
    if(node == tail) remove_back();
    else{
        node->prev->next = node->next;
        node->next->prev = node->prev;
        free(node);
    }
}
void clear_list(){
    while (head != tail){
        remove_front();
    } remove_back();    
}
int main() {
    int n, aux;
    while (scanf("%d", &n), n){
        while(n) insert_front(create_node(n--));
        printf("Discarded cards:");
        while (head->next != tail){
            printf(" %d,", head->value);
            remove_front();
            aux = head->value;
            remove_front();
            insert_back(create_node(aux));
        }
        printf(" %d\n", head->value);
        printf("Remaining card: %d\n", tail->value);
        clear_list();        
    }
    return 0;
}