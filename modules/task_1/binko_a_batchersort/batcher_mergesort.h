// Copyright 2023 Binko Alexandr
#ifndef MODULES_TASK_1_BINKO_A_BATCHERSORT_BATCHER_MERGESORT_H_
#define MODULES_TASK_1_BINKO_A_BATCHERSORT_BATCHER_MERGESORT_H_

#include <algorithm>
#include <vector>

using vector_d = std::vector<double>;

std::vector<double> getRandVec(size_t vec_size, double lower_bound,
                               double upper_bound);
std::vector<vector_d> genDigitCounters(vector_d* source_vec, size_t elem_num);
void radixPass(vector_d* source_vec,
               const std::vector<vector_d>& digitCounters);
void floatRadixSort(vector_d* source_vec);
void evenSplitter(vector_d* res_vec, const vector_d& first_vec,
                  const vector_d& second_vec);
void oddSplitter(vector_d* res_vec, const vector_d& first_vec,
                 const vector_d& second_vec);
void batcherComparator(vector_d* res_vec);
vector_d batcherMerge(const vector_d& first_vec, const vector_d& second_vec);

#endif  // MODULES_TASK_1_BINKO_A_BATCHERSORT_BATCHER_MERGESORT_H_
