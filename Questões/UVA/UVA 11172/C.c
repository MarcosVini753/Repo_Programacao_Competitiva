#include <stdio.h>

int main(){
    int t; scanf("%d", &t);
    int a, b;
    while(t--){
        scanf("%d %d", &a, &b);
        if(a < b) printf("<\n");
        if(a > b) printf(">\n");
        if(a == b) printf("=\n");
    }
    return 0;
}
