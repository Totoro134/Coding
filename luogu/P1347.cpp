#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int n, m;
int a[1000], b[1000];
int ru[100], chu[100], tpru[100], tpchu[100];
bool vis[100];
char ans[100];
vector<int> G[100];

int topo_sort()
{
    int res = 1;
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(ru[i] == 0) {
            q.push(i);
        }
        tpru[i] = ru[i];
        tpchu[i] = chu[i];
    }
    int cnt = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(!q.empty())
            res = 2;
        ans[cnt++] = u + 'A' - 1;
        for(int v: G[u]) {
            tpru[v]--;
            if(tpru[v] == 0){
                q.push(v);
            }
        }
    }
    if(cnt < n)
        return 0;
    ans[cnt] = '.';
    ans[cnt + 1] = '\0';
    return res;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        char s[10];
        scanf("%s", s);
        a[i] = s[0] - 'A' + 1;
        b[i] = s[2] - 'A' + 1;
    }

    for(int i = 1; i <= m; i++) {
        if(a[i] == b[i]) {
            printf("Inconsistency found after %d relations.\n", i);
            return;
        }
        G[a[i]].push_back(b[i]);
        chu[a[i]]++;
        ru[b[i]]++;
        int tag = topo_sort();
        if(tag == 2)
            continue;
        if(tag == 1){
            printf("Sorted sequence determined after %d relations: ", i);
            puts(ans);
            return;
        } else {
            printf("Inconsistency found after %d relations.\n", i);
            return;
        }
    }
    puts("Sorted sequence cannot be determined.");
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