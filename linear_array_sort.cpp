#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <omp.h>

// Function to read array from a file
std::vector<int> read_array_from_file(const std::string& filename, int& N) {
    std::ifstream file(filename);
    std::vector<int> array;
    int number;

    if (file.is_open()) {
        while (file >> number) {
            array.push_back(number);
        }
        file.close();
        N = array.size();
    } else {
        std::cerr << "Unable to open file";
    }
    return array;
}

// Function to print the array
void print_array(const std::vector<int>& array) {
    for (int i : array) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

// Phase 1: Sequential linear array sorting algorithm
void phase1_sequential_linear_array_sort(std::vector<int>& array, int N) {
    for (int step = 0; step < 2 * N - 1; ++step) {
        for (int i = 0; i < N - 1; ++i) {
            if (array[i] > array[i + 1]) {
                std::swap(array[i], array[i + 1]);
            }
        }
    }
}

// Phase 1: Parallel linear array sorting algorithm
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

// Phase 2: Sequential output sorted array (Method 4)
void phase2_sequential_output_sorted_array(std::vector<int>& array, int N) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 1; i < N; ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                std::swap(array[i - 1], array[i]);
            }
        }
    }
    print_array(array);
}

// Phase 2: Parallel output sorted array (Method 4)
void phase2_parallel_output_sorted_array(std::vector<int>& array, int N) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        #pragma omp parallel for shared(sorted)
        for (int i = 1; i < N; ++i) {
            if (array[i - 1] > array[i]) {
                sorted = false;
                std::swap(array[i - 1], array[i]);
            }
        }
    }
    print_array(array);
}

int main() {
    int N, choice;
    std::vector<int> array;

    std::cout << "Enter 1 to input numbers manually, 2 to provide a file name: ";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter the number of elements: ";
        std::cin >> N;
        array.resize(N);
        std::cout << "Enter the elements: ";
        for (int i = 0; i < N; ++i) {
            std::cin >> array[i];
        }
    } else if (choice == 2) {
        std::string filename;
        std::cout << "Enter the file name: ";
        std::cin >> filename;
        array = read_array_from_file(filename, N);
    } else {
        std::cerr << "Invalid choice!";
        return 1;
    }

    std::vector<int> original_array = array; // Store the original array

    // Measure and display time for sequential sorting (Phase 1 and Phase 2)
    auto start_sequential = std::chrono::high_resolution_clock::now();
    phase1_sequential_linear_array_sort(array, N);
    phase2_sequential_output_sorted_array(array, N); // Phase 2 sequential
    auto end_sequential = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_sequential = end_sequential - start_sequential;
    std::cout << "Sequential execution time: " << duration_sequential.count() << " seconds" << std::endl;

    // Restore the original array for parallel sorting
    array = original_array;

    // Measure and display time for parallel sorting (Phase 1 and Phase 2)
    auto start_parallel = std::chrono::high_resolution_clock::now();
    phase1_parallel_linear_array_sort(array, N);
    phase2_parallel_output_sorted_array(array, N); // Phase 2 parallel
    auto end_parallel = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_parallel = end_parallel - start_parallel;
    std::cout << "Parallel execution time: " << duration_parallel.count() << " seconds" << std::endl;
    std::cout << "Sequential execution time: " << duration_sequential.count() << " seconds" << std::endl;

    return 0;
}
