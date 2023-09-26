## Sorting Algorithms And Big O Notation - Project

![Alt text](https://embed-ssl.wistia.com/deliveries/70d6f4e10e2badb5ef394f00c17ad2bc1c14f6e7.jpg)

Sorting algorithms are algorithms that rearrange elements in a list or array in a specific order, typically in ascending or descending order based on some comparison criteria. Sorting is a fundamental operation in computer science and is used in various applications, such as searching, data analysis, and information retrieval. There are many different sorting algorithms, each with its own characteristics and performance trade-offs. In this project, we implemented a series of some of the sorting algorithms.

## Project's Programming Language
* C 

## Styles
* Betty linter

## Authors

- [@habibaadam](https://www.github.com/habibaadam)
- [@mukoe2020](https://www.github.com/mukoe2020)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic  -std=gnu89 *.c -o <nameofobjectfile>
```

Sorting Algorithm            |            Summary
--------------------------   | --------------------------------------------------------                     
Bubble Sort                  |  Simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and sorts them if they are in wrong order. Relatively inefficient for large datasets but easy to understand and implement.
Selection Sort               | Sorts an array by repeatedly finding the minimum element from the unsorted part and moving it to the sorted part.Simple and straightforward but not very efficient for large datasets.
Insertion Sort               | Builds the final sorted array one item at a time by repeatedly taking an element from the unsorted part and inserting it into its correct position. Efficient for small datasets and nearly sorted data.
Quick Sort                   | Divide-and-conquer algorithm that chooses a pivot, partitions the array, and recursively sorts subarrays.
Shell Sort                   | Variation of insertion sort that uses varying gap sizes to perform partial sorting. Gap sizes are based on Knuth's sequence, which provides good performance characteristics.
Cocktail Sort                | Variant of bubble sort that sorts in both directions (forward and backward) through the list. More efficient than traditional bubble sort in some cases.
Counting Sort                | Non-comparative integer sorting algorithm that uses counting to determine the position of elements in the sorted output. Efficient for sorting a range of integers with a limited range of values.
Merge Sort                   | Divide-and-conquer algorithm that divides the array into smaller subarrays, sorts them, and then merges them back together, Offers stable sorting.
Heap Sort                    | Uses a binary heap data structure to build a heap and repeatedly extract the maximum element to sort the array.
Radix Sort                   | Non-comparative sorting algorithm that sorts numbers by processing individual digits or characters from the least significant to the most significant. Efficient for sorting integers and strings with fixed-length keys
Bitonic Sort                 | A parallel sorting algorithm that recursively builds a bitonic sequence and then merges it to produce a sorted result, Suitable for parallel processing architectures.
Quick Sort(Hoare Partition)  | Quick Sort variant that uses the Hoare partition scheme to select a pivot(the last element in the array) and partition the array. Efficient and widely used sorting algorithm


## Big O notation/ Time Complexity
Big O notation, often referred to as time complexity, is a mathematical notation used to describe the upper bound or worst-case behavior of an algorithm's runtime as a function of its input size. It provides a way to analyze and compare the efficiency of algorithms without getting into fine-grained details, In summary
Big O notation is a tool for expressing and comparing the efficiency of algorithms by providing an upper bound on their runtime in relation to the input size, helping us make informed choices when selecting algorithms for various tasks. With every sorting algorithm, there are best cases, average cases and worst cases when it comes to the time they take to run.

* O(1) - Constant Time: Represents algorithms with a fixed and constant runtime, regardless of input size
* O(n) - Linear Time: Represents algorithms where the runtime grows linearly with input size. eg linear search through an unsorted array
* O(log n) - Logarithmic Time: Represents algorithms whose runtime grows logarithmically with input size.
eg Binary search in a sorted array.
* O(n log n) - Linearithmic Time: Represents algorithms with runtime between linear and quadratic, common in efficient sorting algorithms.
* O(n^2) - Quadratic Time: Represents algorithms where the runtime grows quadratically with input size.
* O(n^k) - Polynomial Time: Represents algorithms with a polynomial growth rate, eg Some matrix multiplication algorithms have O(n^3) time complexity.
* O(2^n) - Exponential Time: Represents algorithms with an exponential growth rate. Eg Some brute-force search algorithms have O(2^n) time complexity.
* O(n!) - Factorial Time: Represents algorithms with factorial growth rate.
* O(n^k * log n) - Polynomialithmic Time: Represents algorithms with a combination of polynomial and logarithmic growth.

The following table shows the algorithms done in this project, and their time complexities

Sorting Algorithm      | Best Case         | Average Case        | Worst Case
---------------------- | ----------------- | ------------------- | ---------------------------------
Bubble Sort            | O(n)              | O(n^2)              | O(n^2)
Insertion Sort         | O(n)              | O(n^2)              | O(n^2)