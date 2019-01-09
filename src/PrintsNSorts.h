#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// @brief Will print the elements of any vector
//
// @param[in]  v     Vector to be printed
//
// @tparam     T     Type of Vector to be printed
//
template<class T>
void printVector(const vector<T> &v){
	for(T element: v){
		cout << element << endl;
	}
}


//Sorts the elements of a vector using QuickSort algorithm

/** This function takes last element as pivot, places the pivot element at its
 correct position in sorted array, and places all smaller (smaller than pivot)
 to left of pivot and all greater elements to right of pivot

 @param      arr   The arrgument
 @param[in]  low   The low
 @param[in]  high  The high

 @tparam     T     Type of vector

 @return     new index for sort
*/
template<class T>
int partition (vector<T> &arr, int low, int high)
{
    T pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element
 
    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] < pivot)
        {
            i++;    // increment index of smaller element
            iter_swap(arr.begin() + i, arr.begin() + j);
        }
    }
	iter_swap(arr.begin() + i + 1, arr.begin() + high);
    return (i + 1);
}
 
/** @brief The main function that implements QuickSort arr[] --> Array to be sorted, low --> Starting index, high  --> Ending index

 @param      arr   The vector
 @param[in]  low   The low
 @param[in]  high  The high

 @tparam     T     type of vector
*/
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

/**
 * @brief      calls  quicksort(Arr, Low, High)
 *
 * @param      arr   The Vector
 *
 * @tparam     T    type of vector
 */
template<class T>
void quickSort(vector<T> &arr){
    quickSort(arr, 0, arr.size()-1);
}


// @brief      checks if an input is of the wanted type, if so returns the input
// @tparam     T     Type to be checkf for
//
// @return     the input
//
template <class T>
T checkForType(){
	T nr;
	cin >> nr;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input, try again: ";
		cin >> nr;
	}
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return nr;
}
