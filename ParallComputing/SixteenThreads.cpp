#include "header.h"

template <typename T>
void sixteenThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    int mid = vec1.size() / 2;
    int quarter = vec1.size() / 4;
    int oneEighth = vec1.size() / 8;
    int oneSixteenth = vec1.size() / 16;

    std::thread firstTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), 0, oneSixteenth);
    std::thread secTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), oneSixteenth, oneEighth);
    std::thread thirdTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), oneEighth, oneEighth + oneSixteenth);
    std::thread fourthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), oneEighth + oneSixteenth, quarter);
    std::thread fifthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter, quarter + oneSixteenth);
    std::thread sixthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter + oneSixteenth, quarter + oneEighth);
    std::thread seventhTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter + oneEighth, quarter + oneEighth + oneSixteenth);
    std::thread eighthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), quarter + oneEighth + oneSixteenth, mid);
    std::thread ninthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid, mid + oneSixteenth);
    std::thread tenthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + oneSixteenth, mid + oneEighth);
    std::thread eleventhTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + oneEighth, mid + oneEighth + oneSixteenth);
    std::thread twelfthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + oneEighth + oneSixteenth, mid + quarter);
    std::thread thirteenthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter, mid + quarter + oneSixteenth);
    std::thread fourteenthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter + oneSixteenth, mid + quarter + oneEighth);
    std::thread fifteenthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter + oneEighth, mid + quarter + oneEighth + oneSixteenth);
    std::thread sixteenthTread(vecSum<int>, std::ref(vec1), std::ref(vec2), std::ref(res), mid + quarter + oneEighth + oneSixteenth, vec1.size());

    firstTread.join();
    secTread.join();
    thirdTread.join();
    fourthTread.join();
    fifthTread.join();
    sixthTread.join();
    seventhTread.join();
    eighthTread.join();
    ninthTread.join();
    tenthTread.join();
    eleventhTread.join();
    twelfthTread.join();
    thirteenthTread.join();
    fourteenthTread.join();
    fifteenthTread.join();
    sixteenthTread.join();
}

// объявляем прототип функции со специализацией int
template void sixteenThreadsMain(const std::vector<int>& vec1, const std::vector<int>& vec2, std::vector<int>& res);