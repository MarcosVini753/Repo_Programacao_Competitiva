#include <bits/stdc++.h>
using namespace std;
#define SPEED ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl "\n"
#define FOR(i, a, b) for(int i = a; i < b; i++)

int main(){ SPEED
    int t; cin >> t;
    int n, stores[101];

    while (t--){
       cin >> n;
       FOR(i, 0, n) cin >> stores[i];

       sort(stores, stores+n);

       int sum = 0;
       FOR(i, 0, n-1) sum += stores[i+1] - stores[i];

       cout << sum*2 << endl;
    }
    return 0;
}
