#include "header.h"

template <typename T>
void fourThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    int mid = vec1.size() / 2;
    int quarter = vec1.size() / 4;
    std::thread firstTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), 0, quarter);
    std::thread secTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter, mid);
    std::thread thirdTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid, mid + quarter);
    std::thread fourthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter, vec1.size());

    firstTread.join();
    secTread.join();
    thirdTread.join();
    fourthTread.join();
}

// объявляем прототип функции со специализацией int
template void fourThreadsMain(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& res);