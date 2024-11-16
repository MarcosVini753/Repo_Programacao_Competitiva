#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl "\n"

int clockwise(int i, int f){
    if(i > f) return i - f; else 
    if(f > i)return i - f + 40;
    else return 0;
}
int counterClockwise(int i, int f){
    if(f > i) return f - i; else 
    if(i > f)return f - i + 40;
    else return 0;
}
int main(){ SPEED
    int ini, p1, p2, p3;
    while (cin >> ini >> p1 >> p2 >> p3, ini+p1+p2+p3){
        cout << 1080 + 9*clockwise(ini, p1) + 9*counterClockwise(p1,p2) + 9*clockwise(p2,p3) << endl;
    }
    return 0;
}
