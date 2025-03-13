#include <stdio.h>
#include <string.h>

int n, i;
char pre[30], in[30];

int middle(char x){
    for(int i = 0; i < n; i++) if(in[i] == x) return i;
}

void reconstruction(int start, int end){
    char letter = pre[i];
    int root = middle(pre[i++]);
    if(root - start > 0) reconstruction(start, root-1);
    if(end - root > 0) reconstruction(root+1, end);
    printf("%c", letter);
}

int main(){
    while (scanf("%s %s", pre, in) != EOF){
        n = strlen(pre);
        reconstruction(0, n-1); printf("\n");
        i = 0;
    }
    return 0;    
}
