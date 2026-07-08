#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const ll MOD = 1e9 + 7;
const int MAXN = 1000000;

//////////////////////////////////////////////////////////////
// GCD & LCM
//////////////////////////////////////////////////////////////

ll gcdll(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcmll(ll a, ll b) {
    return a / gcdll(a, b) * b;
}

//////////////////////////////////////////////////////////////
// Fast Power
//////////////////////////////////////////////////////////////

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll modpow(ll a, ll b, ll mod = MOD) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (__int128)res * a % mod;
        a = (__int128)a * a % mod;
        b >>= 1;
    }
    return res;
}

//////////////////////////////////////////////////////////////
// Extended Euclid
//////////////////////////////////////////////////////////////

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

//////////////////////////////////////////////////////////////
// Modular Inverse
//////////////////////////////////////////////////////////////

ll modInverse(ll a, ll mod = MOD) {
    ll x, y;
    ll g = extended_gcd(a, mod, x, y);
    if (g != 1) return -1;
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

// If mod is prime
ll modInversePrime(ll a, ll mod = MOD) {
    return modpow(a, mod - 2, mod);
}

//////////////////////////////////////////////////////////////
// Sieve
//////////////////////////////////////////////////////////////

vector<bool> isPrime(MAXN + 1, true);
vector<int> primes;

void sieve() {
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= MAXN; i++)
        if (isPrime[i])
            primes.push_back(i);
}

//////////////////////////////////////////////////////////////
// Smallest Prime Factor (SPF)
//////////////////////////////////////////////////////////////

vector<int> spf(MAXN + 1);

void SPF() {
    for (int i = 0; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

//////////////////////////////////////////////////////////////
// Prime Factorization
//////////////////////////////////////////////////////////////

map<ll,int> factorize(ll n) {
    map<ll,int> mp;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1)
        mp[n]++;

    return mp;
}

vector<ll> factorizeSPF(ll n) {
    vector<ll> f;

    while (n > 1) {
        f.push_back(spf[n]);
        n /= spf[n];
    }

    return f;
}

//////////////////////////////////////////////////////////////
// Divisors
//////////////////////////////////////////////////////////////

vector<ll> divisors(ll n) {
    vector<ll> d;

    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d.push_back(i);
            if (i != n / i)
                d.push_back(n / i);
        }
    }

    sort(d.begin(), d.end());
    return d;
}

//////////////////////////////////////////////////////////////
// Euler Totient
//////////////////////////////////////////////////////////////

ll phi(ll n) {
    ll result = n;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

//////////////////////////////////////////////////////////////
// Miller-style primality (sqrt version)
//////////////////////////////////////////////////////////////

bool isPrimeSlow(ll n) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;

    return true;
}

//////////////////////////////////////////////////////////////

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // sieve();
    // SPF();

    return 0;
}