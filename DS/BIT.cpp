#include <bits/stdc++.h>
#define test int tttt=0;cin>>tttt;while(tttt--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define int ll
#define sz(s) (int)(s).size()
using namespace std;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")


void ip(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct FenwickTree{
    vector<ll> BIT1, BIT2;
    int n;
    FenwickTree(int n) : n(n){
        BIT1.resize(n + 1);
        BIT2.resize(n + 1);
    }

    void updateBIT(vector<ll>& BIT, int j, ll val){
        for(int i = j; i <= n; i += i & -i){
            BIT[i] += val;
        }
    }

    ll sum(vector<ll>& BIT, int j){
        ll ans = 0;
        for(int i = j; i > 0; i -= i & -i){
            ans += BIT[i];
        }
        return ans;
    }

    void update(int l, int r, ll x){
        updateBIT(BIT1, l, x);
        updateBIT(BIT1, r + 1, -x);
        updateBIT(BIT2, l, x * (l - 1));
        updateBIT(BIT2, r + 1, -x * r);
    }

    ll pre(int r){
        ll ans = sum(BIT1, r) * r;
        ans -= sum(BIT2, r);
        return ans;
    }

    ll query(int l, int r){
        return pre(r) - pre(l - 1);
    }
};

void solve() {

}

signed main() {
    fast
    ip();

    // test
    solve();
}