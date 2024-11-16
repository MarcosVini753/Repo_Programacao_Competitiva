#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct t_Node t_Node;
struct t_Node{
    int value, layer;
    t_Node *left, *right;
}; t_Node *root = NULL;

t_Node *new_t_node(int value){
    t_Node *aux = (t_Node*) malloc(sizeof(t_Node));
    if(aux) aux->value = value, aux->layer = 0, aux->left = aux->right = NULL;
    return aux;
}
void insert_t_node(t_Node *node){
    if(!root){ root = node; return;}
    t_Node *aux = root, *parent = NULL;
    while (aux){
      parent = aux;
      aux = (node->value>aux->value ? aux->right : aux->left);
    } node->layer = parent->layer + 1;
    if(node->value > parent->value) parent->right = node;
    else parent->left = node;    
}
typedef struct ll_Node ll_Node;
struct ll_Node{
    t_Node *value;
    ll_Node *prev, *next;
}; ll_Node *head = NULL, *tail = NULL;

ll_Node *new_ll_node(t_Node *value){
    ll_Node *aux = (ll_Node*) malloc(sizeof(ll_Node));
    if(aux) aux->value = value, aux->next = aux->prev = NULL;
    return aux;
}
void insert_ll_back(ll_Node *node){
    if(!tail) tail = head = node;
    else{
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}
void remove_ll_front(){
    if(tail == head) free(head), tail = head = NULL;
    else{
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
}
const int INF = 0x3f3f3f3f;
#define TAM  256
int menores_alturas[TAM];
void bfs(){
    insert_ll_back(new_ll_node(root));
    ll_Node *nodo;
    while (!(tail == head && head == NULL)){
        nodo = head;
        //printf("layer: %d, value: %d\n", nodo->value->layer, nodo->value->value);
        if(nodo->value->value < menores_alturas[nodo->value->layer])
            menores_alturas[nodo->value->layer] = nodo->value->value;
        if(nodo->value->left) insert_ll_back(new_ll_node(nodo->value->left));
        if(nodo->value->right) insert_ll_back(new_ll_node(nodo->value->right));
        remove_ll_front();        
    }
}
int main() {
    memset(menores_alturas, INF, sizeof(menores_alturas));
    int n, aux; scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &aux);
        insert_t_node(new_t_node(aux)); 
    }
    bfs();    
    int i = 0;
    while (menores_alturas[i] != INF){
        printf("%d %d\n", i, menores_alturas[i]); i++;
    }
    return 0;
}