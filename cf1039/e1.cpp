#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int n, k, a[MAXN], f[MAXN];


void solve()
{
    scanf("%d%d", &n, &k);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int lb = 0, rb = n + 1;

    int resl = 1, resr = 1;

    while(rb - lb > 1) {
        int mid = lb + rb >> 1;
        f[0] = 0;
        for(int i = 1; i <= n; i++) {
            f[i] = f[i - 1] + ((a[i] >= mid) ? 1 : -1);
        }

        int res = n;

        for(int i = n; i >= k; i--) {
            if(f[res] < f[i]) {
                res = i;
            }
            if(f[res] - f[i - k] >= 0) {
                lb = mid;
                resl = i - k + 1;
                resr = res;
                break;
            }
        }
        if(lb != mid) {
            rb = mid;
        }
        
    }
    printf("%d %d %d\n", lb, resl, resr);
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