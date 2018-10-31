#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Will print the elements of any vector
template<class T>
void printVector(const vector<T> &v){
	for(T element: v){
		cout << element << endl;
	}
}


//Sorts the elements of a vector using QuickSort algorithm

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class T>
int partition (vector<T> &arr, int low, int high)
{
    T pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            iter_swap(arr.begin() + i, arr.begin() + j);
        }
    }
	iter_swap(arr.begin() + i + 1, arr.begin() + high);
    return (i + 1);
}
 
/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template<class T>
void quickSort(vector<T> &arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
 
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

template<class T>
void quickSort(vector<T> &arr){
    quickSort(arr, 0, arr.size()-1);
}