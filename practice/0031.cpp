#include <iostream>
#include <string>

typedef unsigned int ui;

ui cnt = 0;
ui trie [100010][256];
bool exist [100010];

void insert(std::string str)
{
    ui idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (trie[idx][str[i]] == 0)
            trie[idx][str[i]] = ++cnt;
        idx = trie[idx][str[i]];
    }
    exist[idx] = true;
}

bool find(std::string str)
{
    ui idx = 0;
    for (int i = 0; i < str.size(); i++)
    {
        idx = trie[idx][str[i]];
        if (idx == 0)
            return false;
    }
    return exist[idx];
}

int main()
{
    insert("abc");
    std::cout << find("abc") << std::endl;
    std::cout << find("ab") << std::endl;
    std::cout << find("abcd") << std::endl;

    insert("ab");
    std::cout << find("abc") << std::endl;
    std::cout << find("ab") << std::endl;
    std::cout << find("abcd") << std::endl;

    return 0;
}
