#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5+10;

int a[MAXN],n,c;

int get_cnt(int x)
{
    int cnt=0;
    while(x<=c) {
        cnt++;
        x <<= 1;
    }
    return cnt;
}

void solve()
{
    scanf("%d%d",&n,&c);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] = get_cnt(a[i]);
    }

    int res = n;

    sort(a + 1, a + n + 1);

    int now = 0;

    for(int i=1;i<=n;i++) {
        if (a[i] > now) {
            res--;
            now++;
        }
    }

    printf("%d\n", res);
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