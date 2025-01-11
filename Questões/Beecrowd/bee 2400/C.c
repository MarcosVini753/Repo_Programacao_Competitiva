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
int main(){
    int n, x; scanf("%d", &n);

    long long ans = 0;

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        // BIT[0, x] += 1;
        update(x, 1);
        // qnt lida - qnt de menores == qnt de maiores
        ans += i - RSQ(x-1);
    } printf("%lld\n", ans);

    return 0;    
}