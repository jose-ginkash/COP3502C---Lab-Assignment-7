// Jose Mathew
// COP3502C Session 40
// Lab Assignment 7
// 3/8/24

#include <stdio.h>

// Function to swap two integers
void swap(int *ptr1, int *ptr2) 
{
    int temp = *ptr1; // store value in address ptr1 for now
    *ptr1 = *ptr2; // assign value of address ptr2 to ptr1
    *ptr2 = temp; // assign the temporarly stored value to ptr2
}


// Function for Bubble sort
void bubbleSort(int arr[], int n, int swapCount[]) 
{
    int i, j;
    for (i = 0; i < n-1; i++) // Loop over array elements
        for (j = 0; j < n-i-1; j++)  
            if (arr[j] > arr[j+1]) // If current element greater than next, swap them
            {
                swapCount[arr[j]]++;
                swapCount[arr[j+1]]++;
                swap(&arr[j], &arr[j+1]);
            }
}


// Function for Selection sort
void selectionSort(int arr[], int n, int swapCount[], int *totalSwap) 
{
    int i, j, mininumID;
    for (i = 0; i < n-1; i++) 
    {
        mininumID = i; // Assume current element is minimum 
        for (j = i+1; j < n; j++) // Loop to find the actual minimum
          if (arr[j] < arr[mininumID])
            mininumID = j; // Update the minimum element
        
        if (mininumID != i) // If minimum isn't current element, swap them
        {
            swap(&arr[mininumID], &arr[i]);
            swapCount[arr[mininumID]]++;
            swapCount[arr[i]]++;
            (*totalSwap)++; // Increment total swap count
        }
    }
}


// Function that prints number of swaps for each element and total swaps
void printSwaps(int arr[], int n, int swapCount[], int originalArr[]) 
{
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) 
    {
        printf("%d: %d\n", arr[i], swapCount[arr[i]]);
        totalSwaps += swapCount[arr[i]];
    }
    printf("Total # of swaps: %d\n\n", totalSwaps / 2);
}


int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1)/sizeof(array1[0]);
    int n2 = sizeof(array2)/sizeof(array2[0]);
    // Initialize the swap counts for individual elements and the total swaps
    int swapCount1[101] = {0};
    int swapCount2[101] = {0};

    printf("array1 Bubble Sort:\n");
    // Sort both arrays
    bubbleSort(array1, n1, swapCount1);
    printSwaps(array1, n1, swapCount1, array1);

    printf("array2 Bubble Sort:\n");
    bubbleSort(array2, n2, swapCount2);
    printSwaps(array2, n2, swapCount2, array2);

    // Reset swap counts for selection sort
    for (int i = 0; i < 101; i++) 
    {
        swapCount1[i] = 0;
        swapCount2[i] = 0;
    }

    printf("array1 Selection Sort:\n");
    selectionSort(array1, n1, swapCount1, array1);
    printSwaps(array1, n1, swapCount1, array1);

    printf("array2 Selection Sort:\n");
    selectionSort(array2, n2, swapCount2, array2);
    printSwaps(array2, n2, swapCount2, array2);

    return 0;
}

