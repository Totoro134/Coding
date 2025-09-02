#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

int n, a[MAXN], b[MAXN], cnt[MAXN], s[MAXN];
bool flag[MAXN];

void solve()
{
    scanf("%d", &n);
    int mx = 0, mxi = 0;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if(a[i] > mx) {
            mx = a[i];
            mxi = i;
        }
    }
    for(int i = 0; i < n; i++) {
        b[i] = a[(mxi + i) % n];
    }
    b[n] = mx;
    ll ans = 0;
    int top = 0;
    for(int i = n; i >= 1; i--) {
        cnt[i] = 1;
        while(top && b[s[top]] <= b[i]) {
            ans += cnt[s[top]];
            if(b[s[top]] == b[i]) {
                cnt[i] += cnt[s[top]];
            }
            top--;
        }
        if(top) {
            ans++;
        }
        if(b[i] == b[n] || (top && s[top] == n)){
            flag[i] = true;
        }
        s[++top] = i;
    }
    mx = 0;
    for(int i = 1; i < n; i++) {
        if(!flag[i] && b[i] >= mx) {
            ans++;
        }
        mx = max(mx, b[i]);
    }
    printf("%lld\n", ans);
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