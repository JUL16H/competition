#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    Node *prev = nullptr;
    int id;
    Node *nxt = nullptr;

    Node(int _id) : id(_id) {}
};

int main()
{
    int N;
    cin >> N;

    unordered_map<int, Node*> mp;

    for (int i = 1; i <= N; i++)
        mp[i] = new Node(i);

    int k, p;
    for (int i = 2; i <= N; i++)
    {
        cin >> k >> p;
        if (p)
        {
            mp[i]->prev = mp[k];
            mp[i]->nxt = mp[k]->nxt;
            if (mp[k]->nxt)
                mp[k]->nxt->prev = mp[i];
            mp[k]->nxt = mp[i];
        }
        else
        {
            mp[i]->nxt = mp[k];
            mp[i]->prev = mp[k]->prev;
            if (mp[k]->prev)
                mp[k]->prev->nxt = mp[i];
            mp[k]->prev = mp[i];
        }
    }

    int M;
    cin >> M;

    int x;
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        if (mp[x])
        {
            if (mp[x]->nxt)
                mp[x]->nxt->prev = mp[x]->prev;
            if (mp[x]->prev)
                mp[x]->prev->nxt = mp[x]->nxt;
            mp[x] = nullptr;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (mp[i]  && !mp[i]->prev)
        {
            x = i;
            break;
        }
    }

    while (1)
    {
        cout << x << " ";
        if (mp[x]->nxt)
            x = mp[x]->nxt->id;
        else
            break;
    }

    return 0;
}
