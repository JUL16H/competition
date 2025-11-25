#include <iostream>
#include <utility>
#include <queue>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int x;
    deque<pair<int, int>> s, b;
    queue<int> sout, bout;

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        while (!s.empty() && x <= s.back().first) s.pop_back();
        while (!b.empty() && x >= b.back().first) b.pop_back();

        s.push_back({x, i});
        b.push_back({x, i});

        while (!s.empty() && i - s.front().second >= k) s.pop_front();
        while (!b.empty() && i - b.front().second >= k) b.pop_front();

        if (i >= k - 1)
        {
            sout.push(s.front().first);
            bout.push(b.front().first);
        }
    }

    while (!sout.empty()) cout << sout.front() << " ", sout.pop(); cout << endl;
    while (!bout.empty()) cout << bout.front() << " ", bout.pop();

    return 0;
}
