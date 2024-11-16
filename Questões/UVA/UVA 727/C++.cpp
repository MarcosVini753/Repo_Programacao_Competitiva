#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

int main(){ SPEED
    char c;
    int flag = 1;
    while ((c = getchar()) != EOF){
        if(c != '"'){
            cout << c;
        }else{
            if(flag){
                cout << "``";
            }else{
                cout << "''";
            }
            flag = !flag;
        }
    }
    return 0;
}