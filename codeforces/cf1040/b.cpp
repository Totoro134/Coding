#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int a[MAXN];
int n, s;

void solve()
{
    int sum = 0;
    int cnt[3] = {0, 0, 0};
    scanf("%d%d", &n, &s);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        cnt[a[i]] ++;
    }

    if(sum > s || sum == s - 1) {
        for(int i = 1; i <= cnt[0]; i++) {
            printf("0 ");
        }
        for(int i = 1; i <= cnt[2]; i++) {
            printf("2 ");
        }
        for(int i = 1; i <= cnt[1]; i++) {
            printf("1 ");
        }
        puts("");
        return;
    }

    puts("-1");
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