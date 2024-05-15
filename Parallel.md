# Parallel Sorting Function
## Overview
The parallel sorting function uses OpenMP to distribute the comparison and swapping operations across multiple threads. By doing so, it allows different parts of the array to be processed simultaneously, reducing the overall execution time.

## Implementation Details
1. Parallel Loop:
  - The core of the parallel implementation is the use of the #pragma omp parallel for directive, which instructs the compiler to parallelize the loop that performs the comparison and swapping of adjacent elements.
  - Each iteration of the loop can be executed independently by different threads, allowing multiple elements of the array to be processed in parallel.
```
void parallel_linear_array_sort(std::vector<int>& array, int N) {
    for (int step = 0; step < 2 * N - 1; ++step) {        
        #pragma omp parallel for        
        for (int i = 0; i < N - 1; ++i) {        
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
            }
        }
    }
}
```
2. Synchronization:

  - OpenMP ensures that each thread executes its portion of the loop concurrently while managing any necessary synchronization between threads.
  - The loop boundary (for (int i = 0; i < N - 1; ++i)) ensures that adjacent elements are compared and swapped correctly, maintaining the integrity of the sorting process even when multiple threads are involved.
3. Load Balancing:

  - OpenMP automatically distributes the loop iterations among the available threads, balancing the workload to optimize performance.
This dynamic distribution helps to minimize idle time for threads, ensuring that all processing units are utilized efficiently.
