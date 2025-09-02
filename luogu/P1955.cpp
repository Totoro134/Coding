#include <cstdio>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int fa[MAXN], rk[MAXN];

void init(int n)
{
    for(int i = 1; i <= n; i++) {
        fa[i] = i;
        rk[i] = 1;
    }
}

int find(int x)
{
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if(fx == fy) return;
    if(rk[fx] < rk[fy]) swap(fx, fy);
    fa[fy] = fx;
    rk[fx] += rk[fy];
}

int xi[MAXN], yi[MAXN], e[MAXN];
unordered_map<int, int> mp;

void solve()
{
    mp.clear();
    int n, num = 0;
    scanf("%d", &n);
    init(n * 2);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d%d", &xi[i], &yi[i], &e[i]);
        if(mp.find(xi[i]) == mp.end()) {
            mp[xi[i]] = ++num;
        }
        if(mp.find(yi[i]) == mp.end()) {
            mp[yi[i]] = ++num;
        }
        xi[i] = mp[xi[i]];
        yi[i] = mp[yi[i]];
        if(e[i] == 1) {
            merge(xi[i], yi[i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(e[i] == 0) {
            if(find(xi[i]) == find(yi[i])) {
                puts("NO");
                return;
            }
        }
    }
    puts("YES");
}


int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
    return 0;
}