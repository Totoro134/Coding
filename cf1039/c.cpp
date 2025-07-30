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
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }

    int mini = a[1];

    for(int i = 2; i <= n; i++) {
        if(a[i] >= 2 * mini) {
            puts("NO");
            return;
        }
        mini = min(mini, a[i]);
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