#include<iostream>

using namespace std;
int size;
/*

 Here is the pseudocode utilized in CLRS for MERGE SORT
 MERGE.(A,p,q,r)
 1 n1 = q-p+1
 2 n2 = r-q
 3 let L[1..n1+1] and R[1..n2+1] be new arrays
 4 for i =1 to n1
 5 L[i] = A[p+i-1]
 6 for j=1 to n2
 7 R[j] = A[q+j]
 8 L[n1 +1] = infinity
 9 R[n2 +1] = infinity
 10 i = 1
 11 j = 1
 12 for k = p to r
 13 if L[i] <= R[j]
 14 A[k] = L[i]
 15 i = i+1
 16 else A[k] = R[j]
 17 j = j+1
 

 
 MergeSort(arr[], l,  r)
 If r > l
 1. Find the middle point to divide the array into two halves:
 middle m = (l+r)/2
 2. Call mergeSort for first half:
 Call mergeSort(arr, l, m)
 3. Call mergeSort for second half:
 Call mergeSort(arr, m+1, r)
 4. Merge the two halves sorted in step 2 and 3:
 Call merge(arr, l, m, r)
 
 THIS PIECE OF PSEUDOCODE IS FROM https://www.geeksforgeeks.org/merge-sort/ I DID NOT COPY ANY CODE FROM THIS SITE AND DID NOT FOLLOW ITS IMPLEMENTATION I ONLY USED IT AS GUIDANCE TO UNDERSTAND WHAT EACH FUNCTION WAS CALLED FOR
 */
void merge(int array[], int mid, int left, int right) {
    int leftSubArray[mid - left + 1], rightSubArray[right - mid];
    
    for (int i = 0; i < mid - left + 1; i++)
        leftSubArray[i] = array[left + i];
    for (int i = 0; i < right - mid; i++)
        rightSubArray[i] = array[mid + 1 + i];
    int i = 0, j = 0, k = left;
    
    while (i < mid - left + 1 && j < right - mid)// while i and j are both between  the divided arrays
    {
        if (leftSubArray[i] <= rightSubArray[j]) //compare the two arrays  if the leftsubArray first index is less than the rightsubarray
            array[k++] = leftSubArray[i++]; //increments leftsubarray
        
        else
            array[k++] = rightSubArray[j++];//if left array index >= than right index, then increment the right array index
    }
    
    
    // adding the excess values that are left over from the other while loop
    while (i < mid - left + 1)
        array[k++] = leftSubArray[i++];
    
    while (j < right - mid)
        array[k++] = rightSubArray[j++];
}

/*
 
 1. Starting Array (unsorted)
 
 2. MergeSort(array, left, mid)  -  MergeSort(array, left, mid)
 
 3. MergeSort(array, left, mid)  -  MergeSort(array, left, mid)
 
 4. MergeSort(array, left, mid)  -  MergeSort(array, left, mid)
 
 [
 */

void mergeSort(int array[], int left = 0, int right = size - 1) {
    int mid;
    if (left < right) //recurse until finished
    {
        mid = (left + right) / 2;
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, mid, left, right);
        //merge the sub arrays together
    }
}

int main(){
    
    cin >> size;
    int *array = new int [size];
    
    for(int i=0;i<size;i++)
        cin >> array[i];
    
    mergeSort(array);
    for (int i = 0; i < size; i++)
        cout << array[i] << ";";
    
    delete[] array;
    return 0;
}
