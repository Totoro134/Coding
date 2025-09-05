#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+10;

struct node
{
    int max0, max1, leftmax0, rightmax0, leftmax1, rightmax1, sum0, sum1;
    int lz0, lz1;
    int lb, rb;
    node(int max0=0, int max1=0, int leftmax0=0, int rightmax0=0,
         int leftmax1=0, int rightmax1=0, int sum0=0, int sum1=0,
         int lz0=-1, int lz1=0, int lb=0, int rb=0):
         max0(max0), max1(max1), leftmax0(leftmax0), rightmax0(rightmax0),
         leftmax1(leftmax1), rightmax1(rightmax1), sum0(sum0), sum1(sum1),
         lz0(lz0), lz1(lz1), lb(lb), rb(rb) {}
};

node t[MAXN];

int n, m, a[MAXN];

void pushup(int p)
{
    int l = 2 * p, r = 2 * p + 1;
    t[p].max0 = max(max(t[l].max0, t[r].max0), t[l].rightmax0 + t[r].leftmax0);
    t[p].max1 = max(max(t[l].max1, t[r].max1), t[l].rightmax1 + t[r].leftmax1);
    t[p].leftmax0 = t[l].sum1 == 0 ? t[l].leftmax0 + t[r].leftmax0 : t[l].leftmax0;
    t[p].rightmax0 = t[r].sum1 == 0 ? t[r].rightmax0 + t[l].rightmax0 : t[r].rightmax0;
    t[p].leftmax1 = t[l].sum0 == 0 ? t[l].leftmax1 + t[r].leftmax1 : t[l].leftmax1;
    t[p].rightmax1 = t[r].sum0 == 0 ? t[r].rightmax1 + t[l].rightmax1 : t[r].rightmax1;
    t[p].sum0 = t[l].sum0 + t[r].sum0;
    t[p].sum1 = t[l].sum1 + t[r].sum1;
    t[p].lz0 = -1;
    t[p].lz1 = 0;
}

node merge(node a, node b)
{
    node ans;
    ans.max0 = max(max(a.max0, b.max0), a.rightmax0 + b.leftmax0);
    ans.max1 = max(max(a.max1, b.max1), a.rightmax1 + b.leftmax1);
    ans.leftmax0 = a.sum1 == 0 ? a.leftmax0 + b.leftmax0 : a.leftmax0;
    ans.rightmax0 = b.sum1 == 0 ? b.rightmax0 + a.rightmax0 : b.rightmax0;
    ans.leftmax1 = a.sum0 == 0 ? a.leftmax1 + b.leftmax1 : a.leftmax1;
    ans.rightmax1 = b.sum0 == 0 ? b.rightmax1 + a.rightmax1 : b.rightmax1;
    ans.sum0 = a.sum0 + b.sum0;
    ans.sum1 = a.sum1 + b.sum1;
    ans.lz0 = -1;
    ans.lz1 = 0;
    return ans;
}

void build(int p, int lb, int rb)
{
    if(lb == rb) {
        int num0 = a[lb] ^ 1, num1 = a[lb];
        t[p] = node(num0, num1, num0, num0, num1, num1, 
                    num0, num1, -1, 0, lb, rb);
        return;
    }
    int mid = lb + rb >> 1;
    build(2 * p, lb, mid);
    build(2 * p + 1, mid + 1, rb);
    pushup(p);
    t[p].lb = lb, t[p].rb = rb;
}

void setvalue(int p, int tag)
{
    if(tag == 0) {
        t[p].max0 = t[p].leftmax0 = t[p].rightmax0 = t[p].sum0 = t[p].rb - t[p].lb + 1;
        t[p].max1 = t[p].leftmax1 = t[p].rightmax1 = t[p].sum1 = 0;
        t[p].lz0 = 0;
        t[p].lz1 = 0;
    } else if(tag == 1) {
        t[p].max0 = t[p].leftmax0 = t[p].rightmax0 = t[p].sum0 = 0;
        t[p].max1 = t[p].leftmax1 = t[p].rightmax1 = t[p].sum1 = t[p].rb - t[p].lb + 1;
        t[p].lz0 = 1;
        t[p].lz1 = 0;
    } else if(tag == 2) {
        swap(t[p].max0, t[p].max1);
        swap(t[p].leftmax0, t[p].leftmax1);
        swap(t[p].rightmax0, t[p].rightmax1);
        swap(t[p].sum0, t[p].sum1);
        t[p].lz1 ^= 1;
    }
}

void pushdown(int p)
{
    if(t[p].lz0 != -1) {
        setvalue(2 * p, t[p].lz0);
        setvalue(2 * p + 1, t[p].lz0);
    }

    if(t[p].lz1 != 0) {
        setvalue(2 * p, 2);
        setvalue(2 * p + 1, 2);
    }
    t[p].lz0 = -1;
    t[p].lz1 = 0;
}

void update(int p, int lb, int rb, int tag)
{
    if(t[p].rb < lb || t[p].lb > rb) {
        return;
    }
    if(t[p].lb >= lb && t[p].rb <= rb) {
        setvalue(p, tag);
        return;
    }

    pushdown(p);

    update(2 * p, lb, rb, tag);
    update(2 * p + 1, lb, rb, tag);

    pushup(p);
}

node ask(int p, int lb, int rb)
{
    if(t[p].rb < lb || t[p].lb > rb) {
        return node();
    }
    if(t[p].lb >= lb && t[p].rb <= rb) {
        return t[p];
    }
    pushdown(p);
    node a = ask(2 * p, lb, rb);
    node b = ask(2 * p + 1, lb, rb);
    return merge(a, b);
}

void solve()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    build(1, 1, n);

    while(m--) {
        int tag, lb, rb;
        scanf("%d%d%d", &tag, &lb, &rb);
        lb++; rb++;
        if(tag < 3) {
            update(1, lb, rb, tag);
        } else {
            node ans = ask(1, lb, rb);
            if(tag == 3) {
                printf("%d\n", ans.sum1);
            } else {
                printf("%d\n", ans.max1);
            }
        }
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