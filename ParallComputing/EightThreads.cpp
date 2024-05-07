#include "header.h"

template <typename T>
void eightThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    int mid = vec1.size() / 2;
    int quarter = vec1.size() / 4;
    int oneEighth = vec1.size() / 8;
    std::thread firstTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), 0, oneEighth);
    std::thread secTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), oneEighth, quarter);
    std::thread thirdTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter, quarter + oneEighth);
    std::thread fourthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter + oneEighth, mid);
    std::thread fifthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid, mid + oneEighth);
    std::thread sixthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + oneEighth, mid + quarter);
    std::thread seventhTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter, mid + quarter);
    std::thread eighthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter + oneEighth, vec1.size());

    firstTread.join();
    secTread.join();
    thirdTread.join();
    fourthTread.join();
    fifthTread.join();
    sixthTread.join();
    seventhTread.join();
    eighthTread.join();
}

// объявляем прототип функции со специализацией int
template void eightThreadsMain(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& res);