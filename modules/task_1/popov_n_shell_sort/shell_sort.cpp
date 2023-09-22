// Copyright 2023 Popov Nikita
#include <vector>
#include <random>
#include <iostream>
#include "../../modules/task_1/popov_n_shell_sort/shell_sort.h"

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
                j -= _s;
            ) {
                std::swap(result[j], result[j + _s]);
            }
        }
    }

    return result;
}
