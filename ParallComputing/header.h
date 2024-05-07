#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <random>

// объ€вл€ем прототипы шаблонных функций из разных файлов .cpp
template <typename T>
void vecSum(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res, int start, int end);

template<typename T>
void twoThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res);

template<typename T>
void fourThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res);

template<typename T>
void eightThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res);

template<typename T>
void sixteenThreadsMain(const std::vector<T>& vec1, const std::vector<T>& vec2, std::vector<T>& res);

#endif // HEADER_H