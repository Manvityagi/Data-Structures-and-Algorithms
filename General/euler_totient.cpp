/*

Euler Totient Function phi(n) = No if in in range (1,n) such that gcd(i,n) = 1 

1. For a prime number p, phi(p) = p-1
2. For a number x = p^k, 
    phi(x) = p^k - p^k/p;  (because only multiples of p^k will have non-one gcd) 
3. For two co-prime numbers A,B(gcd(A,B) = 1), phi(A*B) = phi(A)*phi(B)
4. For a number x = P1^K1 * P2^K2 * P3^K3............ 
    P1^K1,P2^K2 are co-primes, 
    so by property 3 
    phi(X) = phi(p1^k1) * phi(p2^k2)....... 
*/ 

#include<bits/stdc++.h> 
using namespace std; 
#define int long long 
#define pii pair<int,int> //factor,its power 

int fastpower(int a, int p){
    if(a == 0) return 0;
    if(a == 1 || p == 0) return 1; 
    if(p == 1) return a; 

    int power = fastpower(a,p/2); 
    power *= power; 
    if(p & 1){
        power *= a; 
    } 
    return power; 
}

vector<pii> getFactors(int x){
    vector<pii> factors; 
    for(int i = 2; i*i <= x; i++){
        if(x%i) continue;
        int cnt = 0; 
        while(x%i == 0){
            x /= i; 
            cnt++; 
        }
        factors.emplace_back(i,cnt);
    }
    return factors;      
}

signed main() {
    int x; 
    cin >> x; 
    auto factors = getFactors(x);
    int ans = 1;
    for(auto f : factors){
        int p = f.first; 
        int k = f.second; 
        ans *= ((fastpower(p,k) - fastpower(p,k-1))); 
    } 

    cout << ans; 
    return 0; 
}