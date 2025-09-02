#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e5+10;

int a[MAXN],n;

void solve()
{
    scanf("%d",&n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 1, right = n;

    int flag = 1;

    while(left < right) {
        if(a[left]<a[right]){
            if(flag){
                printf("LR");
            } else {
                printf("RL");
            }
        } else {
            if(flag){
                printf("RL");
            } else {
                printf("LR");
            }
        }
        flag ^= 1;
        left++;
        right--;
    }

    if (left == right) {
        puts("L");
    } else {
        puts("");
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