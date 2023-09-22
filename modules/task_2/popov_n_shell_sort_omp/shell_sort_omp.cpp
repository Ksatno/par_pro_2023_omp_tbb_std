// Copyright 2023 Popov Nikita
#include <vector>
#include <random>
#include <iostream>
#include "../../modules/task_2/popov_n_shell_sort_omp/shell_sort_omp.h"

std::vector<int> newVector(int size) {
    std::random_device dev;
    std::mt19937 gen(dev());
    std::vector<int> vector(size);
    for (int i = 0; i < size; ++i) {
        vector[i] = gen() % 100;
    }
    return vector;
}

std::vector<int> gradualShellSort(const std::vector<int>& vector) {
    int vectorSize = static_cast<int>(vector.size());
    std::vector<int> result(vector);

    for (int _s = vectorSize / 2; _s > 0; _s /= 2) {
        for (int i = _s; i < vectorSize; ++i) {
            for (
                int j = i - _s;
                j >= 0 && result[j] > result[j + _s];
                j -= _s
            ) {
                std::swap(result[j], result[j + _s]);
            }
        }
    }

    return result;
}

std::vector<int> parallelShellSort(const std::vector<int>& vector) {
    int vectorSize = static_cast<int>(vector.size());
    std::vector<int> result(vector);

    for (int _s = vectorSize / 2; _s > 0; _s /= 2) {
        #pragma omp parallel for shared(result, _s, vectorSize)
        for (int i = 0; i < _s; ++i) {
            for (int j = _s + i; j < vectorSize; j += _s) {
                int k = j;
                while (k > i && result[k - _s] > result[k]) {
                    std::swap(result[k - _s], result[k]);
                    k -= _s;
                }
            }
        }
    }

    return result;
}
