#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int a[MAXN], n;

ll dp[MAXN][2];

void solve()
{
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        dp[i][0] = dp[i][1] = 0;
    }

    dp[1][0] = 0;
    dp[1][1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][1] + 1;
        if(a[i] < a[i - 1]) {
            dp[i][1] += i - 1;
        }
    }

    printf("%lld\n", dp[n][0] + dp[n][1]);
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