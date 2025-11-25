#include <iostream>
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
    int n, m;
    cin >> n >> m;

    Node *head = new Node(1);
    Node *cur = head;

    for (int i = 1; i < n; i++)
    {
        cur->nxt = new Node(cur->id + 1);
        cur->nxt->prev = cur;
        cur = cur->nxt;
    }

    cur->nxt = head;
    head->prev = cur;
    cur = head;

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++) cur = cur->nxt;
        cout << cur->id << " ";
        cur->nxt->prev = cur->prev;
        cur->prev->nxt = cur->nxt;
        cur = cur->nxt;
    }

    return 0;
}
