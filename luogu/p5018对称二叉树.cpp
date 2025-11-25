#include <iostream>
#include <vector>
using namespace std;

#define ll long long


struct Node
{
    ll v, r, l;
    bool s;
};

vector<Node> vec;

bool same(ll idx1, ll idx2)
{
    if (idx1 == -1 && idx2 == -1)
        return true;
    if (idx1 == -1 || idx2 == -1)
        return false;
    if (vec[idx1].v != vec[idx2].v)
        return false;
    return same(vec[idx1].l, vec[idx2].r) && same(vec[idx1].r, vec[idx2].l);
}

int cnt(ll idx)
{
    return idx == -1 ? 0 : cnt(vec[idx].l) + cnt(vec[idx].r) + 1;
}


int main()
{
    int n;
    cin >> n;

    vec.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> vec[i].v;

    for (int i = 1; i <= n; i++)
        cin >> vec[i].l >> vec[i].r;

    int rst = 0;
    for (int i = 1; i <= n; i++)
    {
        if (same(i, i))
        {
            rst = max(rst, cnt(i));
        }
    }

    cout << rst << endl;

    return 0;
}
