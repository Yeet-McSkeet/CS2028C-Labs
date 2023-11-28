#include<iostream>
#include<iomanip>
#include<vector>
#include<chrono>
#include<fstream>

#include"randomgenerator.h"

typedef std::chrono::high_resolution_clock Clock;

void swap(int& xp, int& yp)
{
    int temp = xp;
    xp = yp;
    yp = temp;
}

void bubbleSort(std::vector<int>& arr, int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) 
    {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}

void testBubble(int size, std::ofstream& out)
{
    std::cout << "BUBBLE SORT: SIZE " << size << "\n";
    float avg = 0;
    for (int test = 0; test < 10; ++test)
    {
        std::vector<int> bubble;
        for (int i = 0; i < size; ++i)  // Randomly generate the vector
            bubble.push_back(randomGenerator(0, 2 * size));
        auto t1 = Clock::now();
        bubbleSort(bubble, size);
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();    // Get total time elapsed
        out << time << "\n";
        std::cout << "Test " << test + 1 << ": " << time << " nanoseconds\n";
        avg += time;    // Increment the average
    }
    avg /= 10;
    std::cout << "Average time: " << avg / 100000 << " milliseconds\n\n";
    out << avg << "\n\n";
}

void insertionSort(std::vector<int>& arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void testInsert(int size, std::ofstream& out)
{
    std::cout << "INSERTION SORT: SIZE " << size << "\n";
    float avg = 0;
    for (int test = 0; test < 10; ++test)
    {
        std::vector<int> bubble;
        for (int i = 0; i < size; ++i)  // Randomly generate the vector
            bubble.push_back(randomGenerator(0, 2 * size));
        auto t1 = Clock::now();
        insertionSort(bubble, size);
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();    // Get total time elapsed
        out << time << "\n";
        std::cout << "Test " << test + 1 << ": " << time << " nanoseconds\n";
        avg += time;    // Increment the average
    }
    avg /= 10;
    std::cout << "Average time: " << avg / 100000 << " milliseconds\n\n";
    out << avg << "\n\n";
}

void selectionSort(std::vector<int>& arr, int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) 
    {
        min_idx = i;
        for (j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}

void testSelect(int size, std::ofstream& out)
{
    std::cout << "SELECTION SORT: SIZE " << size << "\n";
    float avg = 0;
    for (int test = 0; test < 10; ++test)
    {
        std::vector<int> bubble;
        for (int i = 0; i < size; ++i)  // Randomly generate the vector
            bubble.push_back(randomGenerator(0, 2 * size));
        auto t1 = Clock::now();
        selectionSort(bubble, size);
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();    // Get total time elapsed
        out << time << "\n";
        std::cout << "Test " << test + 1 << ": " << time << " nanoseconds\n";
        avg += time;    // Increment the average
    }
    avg /= 10;
    std::cout << "Average time: " << avg / 100000 << " milliseconds\n\n";
    out << avg << "\n\n";
}

int make_partition(std::vector<int>& arr, int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex) 
    {
        while (arr[i] <= pivot) 
            i++;
        while (arr[j] > pivot) 
            j--;
        if (i < pivotIndex && j > pivotIndex) 
            swap(arr[i++], arr[j--]);
    }

    return pivotIndex;
}

void quickSort(std::vector<int>& arr, int start, int end)
{
    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = make_partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
    quickSort(arr, p + 1, end);
}

void testQuick(int size, std::ofstream& out)
{
    std::cout << "QUICKSORT: SIZE " << size << "\n";
    float avg = 0;
    for (int test = 0; test < 10; ++test)
    {
        std::vector<int> bubble;
        for (int i = 0; i < size; ++i)  // Randomly generate the vector
            bubble.push_back(randomGenerator(0, 2 * size));
        auto t1 = Clock::now();
        quickSort(bubble, 0, size-1);
        auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t1).count();    // Get total time elapsed
        out << time << "\n";
        std::cout << "Test " << test + 1 << ": " << time << " nanoseconds\n";
        avg += time;    // Increment the average
    }
    avg /= 10;
    std::cout << "Average time: " << avg / 1000000 << " milliseconds\n\n";
    out << avg << "\n\n";
}

int main() 
{
    std::ofstream file;
    file.open("out.txt");
    testBubble(10, file);
    testBubble(100, file);
    testBubble(500, file);
    testBubble(5000, file);
    testBubble(25000, file);

    testInsert(10, file);
    testInsert(100, file);
    testInsert(500, file);
    testInsert(5000, file);
    testInsert(25000, file);

    testSelect(10, file);
    testSelect(100, file);
    testSelect(500, file);
    testSelect(5000, file);
    testSelect(25000, file);
    
    testQuick(10, file);
    testQuick(100, file);
    testQuick(500, file);
    testQuick(5000, file);
    testQuick(25000, file);

    return 0;
}