#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(string s)
{
    int n = static_cast<int>(s.length());
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> prefix(string str)
{
    vector<int> rst(str.size(), 0);
    for (int i = 1; i < str.size(); i++)
    {
        int j = rst[i - 1];
        while (j && str[i] != str[j])
            j = rst[j - 1];
    }
}

template <typename T>
ostream& operator<<(ostream &cout, vector<T> vec)
{
    cout << vec[0];
    for (int i = 1; i < vec.size(); i++)
        cout << " " << vec[i];

    return cout;
}

int main()
{
    string str = "ababcabababacbac";

    cout << str << endl;
    cout << prefix_function(str) << endl;

    return 0;
}
