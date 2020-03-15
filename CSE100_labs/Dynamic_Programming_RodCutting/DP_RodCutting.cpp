
#include <stdio.h>
#include <limits.h>
#include<climits>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

#define FLOAT_MIN -9999.0



int BottomcutRod(float p[], int n)//following pseudocode from the book
{
    int size = n;//size of arr = n
    int r[n + 1];//allocate size +1
    r[0] = 0;
    int i, j;

    for (j = 1; j <= n; j++)//for j =1 while j is less than or equal to n increment j
    {
        float q = FLOAT_MIN; //q = float_min
        for (i = 0; i < j; i++)//for i = 0 while i is less than j
            {
                q = max((float)q, p[i] + r [ j - i - 1]);// function from pseudocode in book
            }
        r[j] = q;

    }
    return r[n];
}

vector<int> where2cut(float p[], int size, int target) {
    
            vector<int> result;
            for (int i = 0; i < size; i++) {//for int i = 0 while i < size increment i
            for (int j = 0; j  < size; j++) {//for int j = 0 while j < size increment j
            if (i + j + 1 < size) {//if i+j+1 is less than size
            if (p[i] + p[j] == target) {//also if p[i] and p[j] = target
                result.push_back(i + 1);//push back i+1
                result.push_back(j + 1);//push back j+1
                return result;  //return the result
                }   
            }
            if (p[i] == target) {//if p[i] = target
                result.push_back(i + 1); //push back i+1
                return result; //return the result
            }
            if (p[j] == target) {//if p[j] = target
                result.push_back(j + 1);//push back j+1
                return result;// return the result
            }
        }
    }
    return result;
}

int main()
{
    int size;//size of arr n
    cin >> size;// get user input for the size
    float *array = new float[size]; //allocate memory for new array

    for (int i = 0; i < size; i++)// for int i = 0 while i is less than size increment i
        cin >> array[i];//get user input for array[i]

    int val = BottomcutRod(array, size);// val = bottomcutrod(array,size)
    cout << val << endl;//output val

    vector<int> v = where2cut(array, size, val);//vector v = where2cut (array,size,val)

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << "-1" << endl;


    delete[] array;
    return 0;



}

// CODE FROM TEXTBOOK PAGE 366
// For bottom up implementation
// BOTTOM-UP-CUT-ROD(p,n)
// let r[0...n]􏰯 be a new array 
// r[0] = 0
// for j = 1 to n
//     q = -oo
//     for i = 1 to j
//         q = max(q, p[i] 􏰯+ r[j - 􏰦i􏰯])
//     r[j]􏰯 = q
// return r[n]􏰯
