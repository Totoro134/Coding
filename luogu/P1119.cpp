#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int n, m;
int d[300][300], t[300];

void solve()
{
    scanf("%d%d", &n, &m);
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i < n; i++) {
        d[i][i] = 0;
        scanf("%d", t + i);
    }
    for(int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        d[x][y] = w;
        d[y][x] = w;
    }

    int Q;
    scanf("%d", &Q);
    int cnt = 0;
    while(Q--) {
        int x, y, tt;
        scanf("%d%d%d", &x, &y, &tt);
        while(cnt < n && t[cnt] <= tt) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    d[i][j] = min(d[i][j], d[i][cnt] + d[cnt][j]);
                }
            }
            cnt++;
        }
        if(x >= cnt || y >= cnt || d[x][y] == 0x3f3f3f3f) {
            puts("-1");
        } else {
            printf("%d\n", d[x][y]);
        }
    }
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