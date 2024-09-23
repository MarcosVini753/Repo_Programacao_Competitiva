#include <bits/stdc++.h>
using namespace std;
#define s second 
#define f first 

unordered_map<string, pair<string, string>> tree;
unordered_set<string> vis;

int dfs(string edge){
    if(vis.count(edge)) return 1;
    vis.insert(edge);
    if(!tree.count(edge)) return 0;
    return dfs(tree[edge].f) + dfs(tree[edge].s);
}
int main(){
    int v, e, q; cin >> v >> e >> q;
    string x, y, z;
    for (int i = 0; i < e; i++){
        cin >> x >> y >> z;
        tree[z] = {x, y};
    }
    for (int i = 0; i < q; i++){
        cin >> x >> y;
        cout << (dfs(x)+dfs(y) ? "verdadeiro\n" : "falso\n");
        vis.clear();        
    }    
    return 0;
}