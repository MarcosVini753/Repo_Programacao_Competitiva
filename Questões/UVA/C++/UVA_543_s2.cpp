#include <bits/stdc++.h>
using namespace std;

#define MAX 1e6+1

vector<int> isPrime(MAX, 0);
vector<int> primes;
void sieve(){
    isPrime[2] = 1;
    primes.push_back(2);
    for (int i = 3; i < MAX; i += 2){
        int p = 1;
        for (int ii = 0; primes[ii]*primes[ii] <= i && ii < primes.size(); ii++){
            if(i%primes[ii] == 0){ p = 0; break; }
        }
        if(p){ primes.push_back(i); isPrime[i] = 1; }
    }
}

int main(){
	sieve();
	int n; while (cin >> n, n){
        cout << n << " = ";
        // n = a + b;
        int a, b, aux = 1;
        while (1){
            a = primes[aux++];
            b = n-a;
            if(isPrime[b]) break;
        }
        cout << a << " + " <<  b << "\n";
	}
	return 0;
}