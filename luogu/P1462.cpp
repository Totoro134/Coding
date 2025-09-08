#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

int n, m, B;
int f[MAXN], a[MAXN], b[MAXN];
ll d[MAXN], c[MAXN];
bool vis[MAXN], pick[MAXN];

struct edge
{
    int v;
    ll c;
    edge(int v, ll c): v(v), c(c) {}
};

vector<edge> G[MAXN];

void dijkstra(int s=1)
{
    priority_queue<P, vector<P>, greater<P>> pq;
    memset(vis, 0, sizeof(vis));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    pq.push(P(0, s));

    while(!pq.empty()) {
        P p = pq.top(); pq.pop();
        int u = p.second;
        if(vis[u]) continue;
        vis[u] = true;

        for(auto e : G[u]) {
            if(d[e.v] > d[u] + e.c) {
                d[e.v] = d[u] + e.c;
                pq.push(P(d[e.v], e.v));
            }
        }
    }
}

bool calcu(int maxf) 
{
    memset(pick, 0, sizeof(pick));
    for(int i = 1; i <= n; i++) {
        if(f[i] <= maxf)
            pick[i] = true;
        G[i].clear();
    }
    for(int i = 1; i <= m; i++) {
        if(a[i] == b[i])
            continue;
        if(pick[a[i]] && pick[b[i]]) {
            G[a[i]].push_back(edge(b[i], c[i]));
            G[b[i]].push_back(edge(a[i], c[i]));
        }
    }
    dijkstra();
    return d[n] <= B;
}


void solve()
{
    scanf("%d%d%d", &n, &m, &B);
    for(int i = 1; i <= n; i++) {
        scanf("%d", f + i);
    }

    for(int i = 1; i <= m; i++) {
        scanf("%d%d%lld", a + i, b + i, c + i);
    }

    if(!calcu(INF)) {
        puts("AFK");
        return;
    }

    int lb = -1, rb = INF;

    while(rb - lb > 1) {
        int mid = lb + rb >> 1;
        if(calcu(mid)) {
            rb = mid;
        } else {
            lb = mid;
        }
    }
    printf("%d\n", rb);
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