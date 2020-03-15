#include <iostream>
#include <stdlib.h>
using namespace std;


//RADIX-SORT.(A,d)
//1 for i:1 to d
//2 use a stable sort to sort array A on digit i

/*
 
 
 
 
 */

class vec
{
      public:
        int key[11]; // key[11] of type int
        vec()
        {
                for (int i = 1; i <= 10; i++)//for i =1 while i is less than or equal to 10 increment i
                {
                        key[i] = 0; //set key[i] for current value
                }
        }
};
vec **arr;// vector array
vec **arr1;// vector array1


void Sortofmychoice(int i, int size)
{
        int x, j, y, c[4];//here i create variable x,j,y,c[4] of type int
        for (x = 0; x < 4; x++)//for x =0 while x is less than 4 increment x
        {
                c[x] = 0;//set c[x] for the current value
        }
        for (j = 1; j <= size; j++)//for j=1 while j is less than or equal to size increment j
        {
                c[arr[j]->key[i]] = c[arr[j]->key[i]] + 1;//set   c[arr[j]->key[i]]  to    c[arr[j]->key[i]]+1
        }
        for (x = 1; x < 4; x++)//for x=1 while x is less than 4 increment x
        {
                c[x] = c[x] + c[x - 1];// c[x] = c[x] + c[x - 1]
        }
        for (j = size; j >= 1; j--)//for j=size while j is greater than or equal 1 decrement x
        {
                arr1[c[arr[j]->key[i]]] = arr[j];//arr1[c[arr[j]->key[i]]] = arr[j]
                c[arr[j]->key[i]] = c[arr[j]->key[i]] - 1;// c[arr[j]->key[i]] = c[arr[j]->key[i]] - 1
        }
        for (y = 1; y <= size; y++)//for y=1 while y is less than or equal to size increment y
        {
                arr[y] = arr1[y];
        }
}

void radixsort(int size)//Radix Sort
{
        for (int i = 10; i >= 1; i--)//for int i = 10 while i is greater than or equal to 1 decrement i
        {
                Sortofmychoice(i, size);
        }
}

int main()
{
        int value, x, size;
        cin >> size;//get the size from user
        arr = new vec *[size + 1]; // allocate space on heap for arr
        arr1 = new vec *[size + 1]; //allocate space on the heap for arr1

        for (value = 1; value <= size; value++)//for value =1 while value is less than or equal to size increment value
        {
                arr[value] = new vec();//arr[value] = allocate space on heap for vec()
                for (int x = 1; x <= 10; x++)//for int x =1 while x is less than or equal to 10 increment x
                {
                        cin >> arr[value]->key[x];//get the value of arr[value]->key[x]
                }
        }
        radixsort(size);
        for (value = 1; value <= size; value++)//for value = 1 while value is less than or equal to size increment value
        {
                for (x = 1; x <= 10; x++)//for x =1 while x is less than or equal to 10 increment x
                {
                        cout << arr[value]->key[x] << ";";
                }
                cout << "\n";
        }
        for (value = 1; value <= size; value++)//for value = 1 while values is less than or equal to size increment value
        {
                delete arr[value]; //delete arr[value]
        }
        delete[] arr;//delete arr
        delete[] arr1;//delete arr1
        return 0;
}
