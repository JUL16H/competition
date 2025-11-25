#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<char>> before(n, vector<char>(n));
    vector<vector<char>> buff(n, vector<char>(n));
    vector<vector<char>> target(n, vector<char>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> before[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> target[i][j];


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
    }
}
