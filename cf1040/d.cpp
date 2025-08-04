#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;
int a[MAXN], n;
int pos[MAXN];

void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        pos[a[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        int ps = pos[i];
        int no = 0, yes = 0;
        for(int j = 1; j < ps; j++) {
            if(a[j] > i) {
                no++;
            }
            if(a[j] > 2*n - i){
                yes++;
            }
        }

        for(int j = ps + 1; j <= n; j++) {
            if(a[j] < i) {
                no++;
            }
            if(2*n-i>a[j]){
                yes++;
            }
        }

        if(yes<=no){
            a[pos[i]] = 2*n-i;
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j = i + 1; j <= n; j++) {
            if(a[i] > a[j]) {
                ans++;
            }
        }
    }
    printf("%d\n", ans);
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