#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int MAXN = 1e6+10;
const int mod = 100000000 - 3;

int n, a[MAXN], b[MAXN], p[MAXN], t[MAXN];
P c[MAXN];

int lbt(int x)
{
    return x & -x;
}

void add(int x, int k)
{
    while(x <= n) {
        t[x] += k;
        x += lbt(x);
    }
}

int ask(int x)
{
    int ans = 0;
    while(x > 0) {
        ans += t[x];
        x -= lbt(x);
    }
    return ans;
}

void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i].first);
        c[i].second = i;
        t[i] = 0;
    }

    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = c[i].second; 
    }

    for(int i = 1; i <= n; i++) {
        scanf("%d", &c[i].first);
        c[i].second = i;
    }

    sort(c + 1, c + n + 1);
    for(int i = 1; i <= n; i++) {
        b[i] = c[i].second; 
    }

    for(int i = 1; i <= n; i++) {
        p[a[i]] = b[i];
    }

    ll ans = 0;
    for(int i = n; i >= 1; i--) {
        add(p[i], 1);
        ans += ask(p[i] - 1);
        ans %= mod;
    }
    printf("%lld\n", ans);
}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}