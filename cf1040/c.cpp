#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;


struct node {
    int a, b, id;
    const bool operator<(const node &other) const {
        if(a != other.a) return a < other.a;
        return b < other.b;
    }
};

const int MAXN = 1e6+10;

node a[MAXN];

int n;

int res[MAXN];

void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].a, &a[i].b);
        a[i].id = i;
    }
    int ans = 0;
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        if(i+1<=n && a[i].a == a[i+1].a){
            continue;
        }
        res[++ans] = a[i].id;
    }
    printf("%d\n", ans);
    sort(res + 1, res + ans + 1);
    for(int i = 1; i <= ans; i++) {
        printf("%d%c", res[i], (i == ans) ? '\n' : ' ');
    }
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