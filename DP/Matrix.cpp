#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define test int tttt=0;cin>>tttt;while(tttt--)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
#define endl "\n"
#define ll long long
#define ld long double
#define int long long
#define sz(s) (int)(s).size()
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>// set
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
void ip(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

// debuging
template<typename T>
void _print(T x) { cerr << x << "]\n"; }

#ifndef ONLINE_JUDGE
void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v) {
    cerr << t;
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#define debug(x...)               \
cerr << "[" << #x << "] = [";     \
_print(x)

#else
#define debug(x...)
#endif

namespace __Matrix {
    int mod = 1e9+7;
    typedef vector<ll> Row;
    typedef vector<Row> Matrix;

    Matrix Zero(int n, int m){
        return Matrix(n, Row(m));
    }

    Matrix Identity(int n){
        Matrix res = Zero(n, n);
        for(int i = 0; i < n; i++){
            res[i][i] = 1;
        }
        return res;
    }

    Matrix Multiply(const Matrix& a, const Matrix& b){
        Matrix res = Zero(sz(a), sz(b[0]));
        for(int i = 0; i < sz(a); i++){
            for(int j = 0; j < sz(b[0]); j++){
                for(int k = 0; k < sz(b); k++){
                    res[i][j] += a[i][k] * b[k][j];
                    res[i][j] %= mod;
                }
            }
        }
        return res;
    }

    Matrix Power(const Matrix& base, ll k){
        if(k == 0) return Identity(sz(base));
        if(k & 1) return Multiply(base, Power(base, k - 1));
        return Power(Multiply(base, base), k >> 1);
    }
}

using namespace __Matrix;
void solve() {

    ll n; cin >> n;
    Matrix M = Zero(2,2);
    M = {
        {0,1},
        {1, 1}
    };

    M = Power(M,n);


    Matrix ans = Zero(1,2);
    ans = {{0,1}};
    ans = Multiply(ans,M);
    cout << ans[0][0] << endl;
}
signed main() {

    fast

   ip();
    // test
    solve();
}