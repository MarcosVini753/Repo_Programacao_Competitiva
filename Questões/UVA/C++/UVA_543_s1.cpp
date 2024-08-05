#include <bits/stdc++.h>
using namespace std;

#define MAX 1000002

vector<int> primos(MAX, 1);
void sieve(){
	primos[0] = primos[1] = 0;
	for (int i = 2; i*i < MAX; i++){
		if(primos[i]){
			int aux = i*i;
			while (aux < MAX){
				primos[aux] = 0;
				aux += i;
			}
		}		
	}
}

int main(){
	sieve();
	int n; while (cin >> n, n){
		cout << n << " = ";
		int l = 3, r = n-1;
		long long s;
		while (l<=r){
			while (primos[r]==0) r -= 2;
			while (primos[l]==0) l += 2;
			s = r + l;
			if(s > n) r-=2;
			else if(s < n) l+=2;
			if(s == n){cout << l << " + " << r << "\n"; break;}
		}
	}
	return 0;
}