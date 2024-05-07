#include "header.h"

template<typename T>
std::vector<T> getRandomVector(int size)
{
    std::vector<T> vecTemp(size);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, size);

    for (int i = 0; i < size; ++i)
    {
        vecTemp[i] = dist(gen);
    }
    return vecTemp;
}

// Функция для расчета в одном потоке
template <typename T>
void vectorAddition(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), res.begin(),
                   [](T a, T b) { return a + b; });
}

// Функция, которая принимает указатель на функцию в качестве аргумента
template <typename T>
void sumAndCountTime(void (*func)(const std::vector<T>&, const std::vector<T>&, std::vector<T>&), 
           const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res)
{
    auto startThread = std::chrono::steady_clock::now();
    func(vec1, vec2, res);
    auto endThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> threadDur = (endThread - startThread);
    std::cout << threadDur.count() << "s\t";
}

int main()
{
    // Создадим вектора для расчетов и массив из этих векторов
    std::vector<int> vec1(getRandomVector<int>(1000));
    std::vector<int> vec2(getRandomVector<int>(10000));
    std::vector<int> vec3(getRandomVector<int>(100000));
    std::vector<int> vec4(getRandomVector<int>(1000000));
    std::vector<int> arrVectors[4];
    arrVectors[0] = vec1;
    arrVectors[1] = vec2;
    arrVectors[2] = vec3;
    arrVectors[3] = vec4;

    // Создадим вектора результатов и массив из этих векторов
    std::vector<int> res1(vec1.size());
    std::vector<int> res2(vec2.size());
    std::vector<int> res3(vec3.size());
    std::vector<int> res4(vec4.size());
    std::vector<int> arrResults[4];
    arrResults[0] = res1;
    arrResults[1] = res2;
    arrResults[2] = res3;
    arrResults[3] = res4;

    unsigned int n = std::thread::hardware_concurrency();
    std::cout << "Number of hardware cores: " << n << std::endl;
    std::cout << "\n\n";
    std::cout << "\t\t1000\t\t10000\t\t100000\t\t1000000\n";

    // One Thread
    std::cout << "One thread\t";
    for (int i = 0; i < 4; ++i)
    {
        sumAndCountTime(vectorAddition<int>, arrVectors[i], arrVectors[i], arrResults[i]);
    }
    std::cout << std::endl;

    std::cout << "Two threads\t";
    for (int i = 0; i < 4; ++i)
    {
        sumAndCountTime(twoThreadsMain<int>, arrVectors[i], arrVectors[i], arrResults[i]);
    }
    std::cout << std::endl;

    std::cout << "Four threads\t";
    for (int i = 0; i < 4; ++i)
    {
        sumAndCountTime(fourThreadsMain<int>, arrVectors[i], arrVectors[i], arrResults[i]);
    }
    std::cout << std::endl;

    std::cout << "Eight threads\t";
    for (int i = 0; i < 4; ++i)
    {
        sumAndCountTime(eightThreadsMain<int>, arrVectors[i], arrVectors[i], arrResults[i]);
    }
    std::cout << std::endl;

    std::cout << "Sixteen threads\t";
    for (int i = 0; i < 4; ++i)
    {
        sumAndCountTime(sixteenThreadsMain<int>, arrVectors[i], arrVectors[i], arrResults[i]);
    }
    std::cout << std::endl;
}


/* 

// Функция для расчета в одном потоке
template <typename T>
std::vector<T> vectorAddition(const std::vector<T>& vec1, const std::vector<T>& vec2)
{
    std::vector<T> res(vec1.size());
    std::transform(vec1.begin(), vec1.end(), vec2.begin(), res.begin(),
                   [](T a, T b) { return a + b; });
    return res;
}

int main()
{
    std::vector<int> vec1(getRandomVector<int>(1000));
    std::vector<int> vec2(getRandomVector<int>(1000));
    std::vector<int> res(vec1.size());

    // One Thread
    std::cout << "One thread\t";
    auto startOneThread = std::chrono::steady_clock::now();
    res = vectorAddition(vec1, vec2);
    auto endOneThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> oneThreadDur = (endOneThread - startOneThread);
    std::cout << oneThreadDur.count() << "s\t";

    // Two Threads
    auto startTwoThread = std::chrono::steady_clock::now();
    twoThreadsMain<int>(vec1, vec2, res);
    auto endTwoThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> twoThreadDur = (endTwoThread - startTwoThread);
    std::cout << "\n Two: " << twoThreadDur.count() << "s\n";

    // Four Threads
    auto startFourThread = std::chrono::steady_clock::now();
    fourThreadsMain<int>(vec1, vec2, res);
    auto endFourThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> fourThreadDur = (endFourThread - startFourThread);
    std::cout << "Four: " << fourThreadDur.count() << "s\n";

    // Eight Threads
    auto startEightThread = std::chrono::steady_clock::now();
    eightThreadsMain<int>(vec1, vec2, res);
    auto endEightThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> eightThreadDur = (endEightThread - startEightThread);
    std::cout << "Eight: " << eightThreadDur.count() << "s\n";

    // Sixteenth Threads
    auto startSixteenThread = std::chrono::steady_clock::now();
    sixteenThreadsMain<int>(vec1, vec2, res);
    auto endSixteenThread = std::chrono::steady_clock::now();
    std::chrono::duration<double> sixteenThreadDur = (endSixteenThread - startSixteenThread);
    std::cout << "Sixteenth: " << sixteenThreadDur.count() << "s\n"; 
}*/
