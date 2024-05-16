# Introduction
This project is part of the Parallel Algorithms course offered by the Department of Computer Engineering and Informatics at the University of Patras during the Spring semester. The aim of this project is to implement a parallel sorting algorithm based on the methodology described in the course materials. Specifically, we focus on sorting a linear array using both sequential and parallel approaches to illustrate the concepts of parallel computation.

# Algorithm Description
<p align="center">
 <img src="https://github.com/nickpotamianos/Parallel-Algorithms-2024/assets/85500667/7afb5a16-2380-4f40-b0cd-2d465af09d9f">
</p>

The algorithm we implemented is known as the Linear Array Sorting Algorithm. It is designed to sort a list of 
𝑁 numbers using a linear array of processors. Each processor in the array is connected to its immediate neighbors, allowing for localized data exchanges. The sorting process involves two main phases:


## 1. Phase 1 (Sorting Phase):

- Each processor receives input from its left neighbor.
- Each processor compares the received input with its stored value.
- The larger value is sent to the right neighbor.
- The smaller value is retained locally.

This process is repeated for 2𝑁−1 steps, ensuring that by the end of this phase, the smallest value is at the leftmost processor, the second smallest at the second processor, and so on.

## 2. Phase 2 (Output Phase):

- The sorted values are output from the array. Various methods can be employed, but the key idea is to sequentially output the sorted values from the leftmost processor to the rightmost one.
- Based on our pdf, it is mentioned that `Method 4, on the other hand, requires only 3N — 1 steps to sort and output the numbers, since the numbers begin emerging from the left end of the array during alternate steps immediately following the entry of the last input into the array.`, therefore the Method 4 is used, being the most efficient one. 

# Implementation

Our implementation consists of a C++ program that reads an array of integers from a file or manual input, sorts it using the described algorithm, and measures the performance of both sequential and parallel implementations. Below is a high-level overview of our implementation logic:

## Steps in the Implementation
1. Reading Input:
- The program can read the array of numbers either from a file or through manual input from the user.
  
2. Sequential Linear Array Sorting:
- The array is sorted using the linear array sorting algorithm that iterates over the array multiple times, comparing and swapping adjacent elements as needed.
  
3. Parallel Linear Array Sorting:

- The same sorting logic is applied, but using OpenMP to parallelize the comparison and swapping of adjacent elements. This allows multiple parts of the array to be processed simultaneously, leveraging multi-core processors to speed up the sorting.
4. Performance Measurement:

- The execution time for both the sequential and parallel sorting algorithms is measured and displayed to the user, allowing for a comparison of the two approaches.
# Code Logic
## Initialization:

- The user selects whether to input numbers manually or read from a file.
- The array of integers is initialized based on the selected input method.
## Sequential Sorting Function:

- Repeatedly iterates over the array.
- Compares adjacent elements and swaps them if out of order.
- Runs for 2𝑁−1 steps to ensure complete sorting.
## Parallel Sorting Function:

- Uses OpenMP to parallelize the iteration over the array.
- Compares and swaps adjacent elements in parallel.
- Also runs for 2𝑁−1 steps, but processes multiple elements simultaneously.
## Performance Measurement:

- Uses the chrono library to measure execution time.
- Outputs the sorted array and execution time for both sequential and parallel sorting.

# Quick Guide for Execution
1. Clone the Repository:

    `git clone https://github.com/yourusername/parallel-sorting-algorithm.git` 

    `cd parallel-sorting-algorithm`

2. Compile the Program:
Make sure you have a C++ compiler with OpenMP support. 
`g++ -fopenmp -o linear_array_sort linear_array_sort.cpp`

3. Run the Program:
You can run the program and choose to input numbers manually or provide a file with numbers.

    `./linear_array_sort`

4. Input Options:

- Manual Input:
  - Enter `1` when prompted to input numbers manually.
  - Enter the number of elements.
  - Enter the elements one by one.
- File Input:
  - Enter `2` when prompted to provide a file name.
  - Enter the file name (make sure the file is in the same directory or provide the full path).
5. View Results:

- The program will display the sorted array using both sequential and parallel sorting methods.
- Execution times for both methods will also be displayed, allowing you to compare their performance.
