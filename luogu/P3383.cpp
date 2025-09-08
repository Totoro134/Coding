#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e8 + 10;

bool is_prime[MAXN];
int primes[MAXN / 50];

void solve()
{
    int n, q;
    scanf("%d%d", &n, &q);

    for(int i = 2; i <= n; i++) {
        is_prime[i] = true;
    }

    int cnt = 0;

    for(int i = 2; i <= n; i++) {
        if(is_prime[i]) {
            primes[++cnt] = i;
        }
        for(int j = 1; j <= cnt; j++) {
            if(1ll * i * primes[j] > n) break;
            is_prime[i * primes[j]] = false;
            if(i % primes[j] == 0) break;
        }
    }

    while(q--) {
        int k;
        scanf("%d", &k);
        printf("%d\n", primes[k]);
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