#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int a[MAXN], n, m;
int st[MAXN][20];


void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        st[i][0] = a[i];
    }
    for(int j = 1; j < 20; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1; i <= m; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        int k = log2(r - l + 1);
        printf("%d%c", min(st[l][k], st[r - (1 << k) + 1][k]), (i == m) ? '\n' : ' ');
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