#include <stdio.h>

#define MAX 100002
int P(int n){ return n&-n; } // maior potência de 2 que divide n
// No K-ésimo elemento de BIT será guardada a informação sobre [k - P(k) + 1, k]
int BIT[MAX]; // Binary Indexed Tree
void update(int i, int v){
    while (i < MAX){
        BIT[i] += v;
        i += P(i);
    }
}
int RSQ(int i){ // Range Sum Query
    int sum = 0;
    while (i){
        sum += BIT[i];
        i -= P(i);
    } return sum;
}
int vet[MAX];
int main(){
    int n, i; scanf("%d", &n);

    for (i = 1; i <= n; i++) scanf("%d", &vet[i]), update(i, vet[i]);

    char aux;

    while(scanf(" %c %d", &aux, &i) != EOF){
        if(aux == 'a') update(i, -vet[i]);
        else printf("%d\n", RSQ(i-1));
    }
    return 0;    
}