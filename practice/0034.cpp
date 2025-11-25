#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];


    deque<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        while (!que.empty() && i - que.front().first >= k)
            que.pop_front();
        while (!que.empty() && que.back().second <= vec[i])
            que.pop_back();
        que.push_back({i, vec[i]});
        cout << que.front().second << " ";
    }

    return 0;
}
