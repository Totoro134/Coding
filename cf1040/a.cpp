#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int a[MAXN];
int n;

void solve()
{
    int res = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        res += a[i];
        if(a[i] == 0) {
            res++;
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