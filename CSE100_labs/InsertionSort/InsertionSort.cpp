#include<iostream>
using namespace std;
/*

 INSERTION-SORT.A/
 1 for j = 2 to A.length
 2 key = A[j]
 3 // Insert A[j]   into the sorted sequence A[1...j-1]
 4 i = j-1
 5 while i > 0 and A[i] >key
 6 A[i+1] =  A[i]
 7 i = i-1
 8 A[i+1] = key

I used the pseudocode from page 18 in the book to write my code for this lab


*/
int main()
{
    
    int j, key, length;
    
    cin >> length; //receive user input for the array size
    int arr[length]; //initialize the array size based off input
    
    for(int i=0; i<length; i++)
    {
        cin >> arr[i]; //take in user input for the elements in the array
    }
    
    
    for(int i=1; i<length; i++) //insertion_sort(arr, length);
    {
        key = arr[i]; //set key value to current index being evaluated in the array
        j=i-1;    //set j equal to the index to left of the current index (arr[i])
        
        while(j>=0 && arr[j]>key) //'while' function .. if number > than key move ahead one spot
        {
            arr[j+1]=arr[j]; //if the value where j is located is greater than the key value, then switch
            j=j-1; //j is decremented
            arr[j+1]=key; //set the value next to index j equal to the key value that we evaluated
        }
        for(int j=0; j<=i; j++)
        {
            cout << arr[j] << ";"; //print out the values in the array that have been evaluated
        }
        
        cout << "" << endl; //new line
        
    }
    
}










