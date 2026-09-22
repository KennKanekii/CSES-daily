#include <bits/stdc++.h>
using namespace std;

// ==================== TYPEDEFS ====================

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pii>;
using vpll = vector<pll>;

// ==================== MACROS ====================

#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

// ==================== CONSTANTS ====================

const ll MOD = 1000000007LL;
const ll MOD2 = 998244353LL;
const ll INF = 1e18;
const int INF_INT = 1e9;

// ==================== DIRECTIONS ====================

int dx4[] = {-1, 0, 1, 0};
int dy4[] = {0, 1, 0, -1};

int dx8[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy8[] = {-1, 0, 1, -1, 1, -1, 0, 1};

// ==================== MATH ====================

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

ll modPower(ll a, ll b, ll mod = MOD) {
    a %= mod;
    ll res = 1;
    while (b) {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a) {
    return modPower(a, MOD - 2);
}

// ==================== DEBUG ====================

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

// ==================== Z-FUNCTION ====================

vi zFunction(const string &s) {
    int n = s.size();
    vi z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}

// ==================== SOLVE ====================

void solve() {
    string s, p;
    cin >> s >> p;
    int m = p.size();

    string t = p + "#" + s;
    vi z = zFunction(t);

    ll count = 0;
    for (int i = m + 1; i < sz(t); i++) {
        if (z[i] == m) count++;
    }

    cout << count << '\n';
}

// ==================== MAIN ====================

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}