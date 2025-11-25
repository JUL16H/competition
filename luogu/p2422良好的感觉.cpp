#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

#define int long long

signed main() {
    int N;
    cin >> N;

    vector<int> vec(N);
    for (int i = 0; i < N; i++)
        cin >> vec[i];

    vector<int> sum(N + 1, 0);
    for (int i = 0; i < N; i++)
        sum[i + 1] = sum[i] + vec[i];

    deque<pair<int, int>> que;
    vector<pair<int, int>> range(N);

    for (int i = 0; i < N; i++) {
        while (!que.empty() && que.front().second > vec[i]) {
            range[que.front().first].second = i - 1;
            que.pop_front();
        }
        while (!que.empty() && que.back().second > vec[i]) {
            range[que.back().first].second = i - 1;
            que.pop_back();
        }
        if (que.empty())
            range[i].first = 0;
        else
            range[i].first = que.back().first + 1;
        que.push_back({i, vec[i]});
    }
    while (!que.empty()) {
        range[que.front().first].second = N - 1;
        que.pop_front();
    }

    // for (int i = 0; i < N; i++)
    //     cout << range[i].first << " " << range[i].second << '\n';

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = max(vec[i] * (sum[range[i].second + 1] - sum[range[i].first]), ans);

    cout << ans << endl;

    return 0;
}
