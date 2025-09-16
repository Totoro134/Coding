#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;

int nex[500005][26];
set<int> exist[500005];
int cnt;
int n, m;

char s[100];

void insert(int id, char *s)
{
    int len = strlen(s);
    int p = 0;
    for(int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if(!nex[p][c]) {
            nex[p][c] = ++cnt;
        }
        p = nex[p][c];
    }
    exist[p].insert(id);
}

void query(char *s)
{
    int p = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        int c = s[i] - 'a';
        if(!nex[p][c]) {
            puts("");
            return;
        }
        p = nex[p][c];
    }
    auto it = exist[p].begin();
    for(; it != exist[p].end(); it++) {
        if(it != exist[p].begin()) 
            printf(" ");
        printf("%d", *it);
    }
    printf("\n");
}

void solve()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        int L;
        scanf("%d", &L);
        while(L--) {
            scanf("%s", s);
            insert(i, s);
        }
    }
    scanf("%d", &m);
    while(m--) {
        scanf("%s", s);
        query(s);
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