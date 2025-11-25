#include <iostream>
#include <vector>

#define max(a,b) ((a)>(b)?(a):(b))


template <typename T>
class Heap
{
private:
    std::vector<T> vec;

    void swap(int a, int b)
    {
        if (a == b || max(a, b) >= vec.size())
            return;

        T tmp = vec[a];
        vec[a] = vec[b];
        vec[b] = tmp;
    }

public:
    T top() { return vec[0]; }

    void insert(T val)
    {
        vec.push_back(val);
        int idx = vec.size() - 1;

        while (idx && vec[(idx - 1) >> 1] < vec[idx])
        {
            swap((idx - 1) >> 1, idx);
            idx = (idx - 1) >> 1;
        }
    }

    void pop()
    {
        swap(vec.size() - 1, 0);
        vec.pop_back();

        int idx = 0;
        while (true)
        {
            int left = (idx << 1) + 1;
            int right = (idx << 1) + 2;

            if (left >= vec.size())
                break;

            int nxt = vec[left] > vec[right] ? left : right;

            if (vec[idx] >= vec[nxt])
                break;

            swap(idx, nxt);
            idx = nxt;
        }
    }
};
