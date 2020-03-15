#include<iostream>
#include <climits>

using namespace std;

//for this assignment I implemented the max subarray sum as instructed via catcourses, i definitely had trouble this lab compared to other labs but I was able to get my code working. , https://www.geeksforgeeks.org/maximum-subarray-sum-using-divide-and-conquer-algorithm/ had the same exact implementation. I did not use this website to write my code but i did use it for reference
//,, my tutor guided me to implement my code and the structure is very similar to that of the book and I am still able to explain its functionality line by line ( book pesudocode below).
//*****Update to Pseudocode**** understanding why i got it wrong...
//I was able to get my code to work by simply including the header file include c<limits> . I should //have taken the advice given earlier about using the libraries computers to compile code but I tried y lab on the computers and it didnt work so I did research..<climits> defies constants  with the limits
//of fundamental integral types for the specific system and compiler implementation used 
//source: cplusplus.com/climits/
//
//Peudocode from page 71-72
// void FindMaxCrossSub(int array[], int low, int mid, int high)
//{
// left-sum = -oo
// sum = 0
// for i = mid downto low
//     sum = sum + A[i]
//     if sum > left-sum
//         left-sum = sum
//         max-left = i 
// right-sum = 􏰥-oo
// sum = 0
// for j = mid + 1 to high
//     sum = sum + A[j] 􏰫 
//     if sum > right-sum
//         right-sum = sum
//         max-right = j
// return (max-left, max-right, left-sum + right-sum)


// }
//Pseudocode from page 72

// void FindMaxSub (int array[], int low = 0, int high = size - 1)
//{
// if (high == low)
//     return (low, high, array[low])  // base case: only one element
// else mid = [(low + high)/2] 
//     (left-low, left-high, left-sum)  =
// FindMaxSub(A, low, mid)
//     (right-low, right-high, right-sum) =
// FindMaxSub(A, mid + 1, high)
//     (cross-low, cross-high, cross-sum) =
// FIND-MAX-CROSSING-SUBARRAY (A, low, mid, high) 
// if left-sum 􏰨>= right-sum and left-sum >=􏰨 cross-sum
//     return (left-low, left-high, left-sum)
// else right-sum >=􏰨 left-sum and right-sum 􏰨>= cross-sum
//     return (right-low, right-high, right-sum) 
// else return (cross-low, cross-high, cross-sum)

// }



int MaxSubSum(int array[], int n)
{
    if(n==1)
    {
        return array[0];
    }
    int m = n/2;
    int left = MaxSubSum(array,m);//declare int left the left half side of m
    int right = MaxSubSum(array + m, n-m);//declare int right the right half side of m
    int leftsum = INT_MIN;
    int rightsum = INT_MIN;
    int sum = 0;
    
    for(int i = (m-1); i >= 0; i--) // for i = m-1 decrement i while i is greater than or eqaul to 0
    {
        sum += array[i]; // sum = sum + array[i]
        leftsum = max(leftsum, sum);//here collect all elements on the left of mid
    }
    sum = 0;
    for(int i=m; i < n; i++)// for i = m increment i while i is less than n
    {
        sum += array[i];// sum = sum + array[i]
        rightsum = max(rightsum,sum);//here collect all elements on the right of mid
    }
    int answer = max(left,right);//setting the answer equal to the sum of the left and right elements
    return max(answer,leftsum + rightsum);//return the answer
}




int main(){ 
    int size;
	cin >> size;
	int *array = new int [size];

	for(int i=0;i<size;i++)
		cin >> array[i];

	int answer = MaxSubSum(array, size);
    cout << answer;

	delete[] array;
	return 0;
}
