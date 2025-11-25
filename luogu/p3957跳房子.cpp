#include <iostream>
#include <vector>
#include <utility>
#include <deque>
using namespace std;

#define inf 0x3f3f3f3f

int n, d, k;
vector<int> dis;
vector<int> score;

bool solve(int g) {
    // cout << g << endl;
    int cur = 0;
    deque<pair<int, int>> que;

    vector<int> dp(n + 1, -inf);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        while (cur < i && (dis[i] - dis[cur]) >= d - g) {
            while (!que.empty() && dp[cur] >= que.back().second)
                que.pop_back();
            que.push_back({dis[cur], dp[cur++]});
        }
        while (!que.empty() && (dis[i] - que.front().first) > d + g)
            que.pop_front();
        if (que.empty() || que.front().second == -inf)
            dp[i] = -inf;
        else
            dp[i] = que.front().second + score[i];
        if (dp[i] >= k) {
            // for (int i = 0; i <= n; i++)
            //     cout << dp[i] << " ";
            // cout << endl;
            return true;
        }
    }
    // for (int i = 0; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    return false;
}

int main() {
    cin >> n >> d >> k;

    dis.resize(n + 1, 0);
    score.resize(n + 1, 0);

    for (int i = 1; i <= n; i++)
        cin >> dis[i] >> score[i];

    int l = 0, r = dis[n - 1], ans = -1;

    while (l <= r) {
        int mid = l + ((r - l) >> 1);
        if (solve(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ans << endl;

    return 0;
}

