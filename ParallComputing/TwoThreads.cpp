#include "header.h"

template <typename T>
void vecSum(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res, int start, int end)
{
    for (int i = start; i < end; ++i)
    {
        res[i] = vec1[i] + vec2[i];
    }
}

template <typename T>
void twoThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    int mid = vec1.size() / 2;
    std::thread firstTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), 0, mid);
    std::thread secTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid, vec1.size());

    firstTread.join();
    secTread.join();
}

// объ€вл€ем прототипы функций со специализацией int
template void vecSum(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& res, int start, int end);
template void twoThreadsMain(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& res);