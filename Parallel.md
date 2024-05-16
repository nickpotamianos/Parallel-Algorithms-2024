# Parallel Sorting Function
## Overview
The parallel sorting function uses OpenMP to distribute the comparison and swapping operations across multiple threads. By doing so, it allows different parts of the array to be processed simultaneously, reducing the overall execution time.

#Properties of the algorithm

## Implementation Details
## 1. Parallel Loop:
  - The core of the parallel implementation is the use of the `#pragma omp parallel` for directive, which instructs the compiler to parallelize the loop that performs the comparison and swapping of adjacent elements.
  - Each iteration of the loop can be executed independently by different threads, allowing multiple elements of the array to be processed in parallel.
```ccp
void phase1_parallel_linear_array_sort(std::vector<int>& array, int N) {
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

- `for (int step = 0; step < 2 * N - 1; ++step)`: This loop corresponds to that the algorithm runs for 2N-1 steps.
- `for (int i = 0; i < N - 1; ++i)`: Iterates through the array elements.
- `if (array[i] > array[i + 1]) { std::swap(array[i], array[i + 1]); }`: Compares and swaps elements, analogous to the comparison and swapping in each step of Phase 1 as described.

1. "Accepts the input from its left neighbor"

  - In the context of the code, each element in the array acts as a processor.
  - The element at index `i` considers the value at index `i-1` as input from its "left neighbor".
  - This is implicit in the loop where `array[i]` is compared with `array[i + 1]`.

2. "Compares the input with its stored value"
  - This comparison is performed by `if (array[i] > array[i + 1])`.
  - Here, `array[i]` is the stored value of the current processor (or element), and `array[i + 1]` is the input from the right neighbor.
    
3. "Outputs the larger value to the right neighbor"
  - If `array[i] > array[i + 1]`, the larger value (`array[i]`) is swapped to the right neighbor's position (`array[i + 1]`).
This is achieved by `std::swap(array[i], array[i + 1])`.

4. "Stores the smaller value locally"
  - After the swap, the smaller value is stored in the current position `array[i]`.
    
## 2. Synchronization:

  - OpenMP ensures that each thread executes its portion of the loop concurrently while managing any necessary synchronization between threads.
  - The loop boundary (`for (int i = 0; i < N - 1; ++i)`) ensures that adjacent elements are compared and swapped correctly, maintaining the integrity of the sorting process even when multiple threads are involved.
## 3. Load Balancing:

  - OpenMP automatically distributes the loop iterations among the available threads, balancing the workload to optimize performance.
This dynamic distribution helps to minimize idle time for threads, ensuring that all processing units are utilized efficiently.

## 4. Notes:
  - Based on my executions, phase 2 doesn't make any difference neither if is executed parallel nor if executed sequentialy.
  - For the purposes of the exercise the phase 2 is being implemented using both methods (sequential & parallel).
