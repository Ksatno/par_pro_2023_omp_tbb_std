// Copyright 2023 Popov Nikita
#ifndef MODULES_TASK_2_POPOV_N_SHELL_SORT_OMP_SHELL_SORT_OMP_H_
#define MODULES_TASK_2_POPOV_N_SHELL_SORT_OMP_SHELL_SORT_OMP_H_

#include <vector>

std::vector<int> newVector(int size);

std::vector<int> gradualShellSort(const std::vector<int>& vector);
std::vector<int> parallelShellSort(const std::vector<int>& vector);

#endif  // MODULES_TASK_2_POPOV_N_SHELL_SORT_OMP_SHELL_SORT_OMP_H_
