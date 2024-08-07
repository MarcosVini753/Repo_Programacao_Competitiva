// finds out how many primes p are in the prime factorization of n!
int p, n, s = 0;
for(int i = p; i <= n; i *= p){
    s += n/i;
}
