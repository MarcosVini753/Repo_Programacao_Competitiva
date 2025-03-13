#include <stdio.h>
#include <string.h>

char pre[30], in[30];

int n, i;

int middle(char x){
    for(int i = 0; i < n; i++) if(in[i] == x) return i;
}
void postorder(int start, int end){
    char letter = pre[i];
    int root = middle(pre[i++]);
    if(root - start > 0) postorder(start, root-1);
    if(end - root > 0) postorder(root+1, end);
    printf("%c", letter);
}
int main(){
    int x; scanf("%d", &x);
  
    while (scanf("%d %s %s", &n, pre, in) != EOF){
        postorder(0, n-1); printf("\n");
        i = 0;
    }
    return 0;    
}
