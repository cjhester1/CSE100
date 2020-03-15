#include<iostream>
#include<cstdlib>

using namespace std;
//  This implementation of quicksort was similar to that of heapsort it was very straightforward
// I received my pseudocode from pages 171-179 of the textbook this implementation was similar to heapsort
// in that there was pseudocode for several different code we needed to write. I feel the book basically
//gave us the whole formula for both labs 4-1 and 4-2 which I love and I wish it was like this for every lab
//
//



/*
 
 
 Quicksort (A,p,r)
 1 if p<r
 2 q = Partition(A,p,r)
 3 Quicksort (A,p,q-1)
 4 Quicksort (A,q+1,r)
 
 */


/*
 Pseudocode page 171 from textbook
 Partition (A,p,r)
 x = A[r]
 i = p-1
 for j = p to r-1
 if A[j] <= x
 i = i+1
 exchange A[i] with A[j]
 exchange A[i+1] with A[r]
 return i+1
 
 */
int partition(int array[], int p, int r){
    int x = array[r];
    int i = p - 1;
    for (int j = p; j <= (r - 1); j++){
        if (array[j] < x){
            i = i + 1;
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1],array[r]);
    return i + 1;
}



/*
 Pseudocode page 179 of textbook
 Randomized_Partition (A,p,r)
 1 i = Random(p,r)
 2 exchange A[r] with A[i]
 3 return Partition(A,p,r)
 
 */
int RandPartition(int array[], int p, int r) {
        int i = p + rand() % (r - p + 1);
        swap (array[r], array[i]);
        return partition(array,p,r); 
    }


/*
 Pseudocode page 179 of textbook
 Randomized_Quicksort (A,p,r)
 1  if p<r
 2  q = Randomized_Partition (A,p,r)
 3 Randomized_Quicksort (A,p,q-1)
 4 Randomized_Quicksort (A,q+1,r)
 
 */
void RandQuicksort(int array[], int p, int r, int size){    
    if (p<r) {
       int q = RandPartition(array, p, r);
       RandQuicksort(array, p, q-1, size);
       RandQuicksort(array, q+1, r, size);
    }
}

int main(){ 
    int size;
	cin >> size;
	int *array = new int [size];

	for(int i=0;i<size;i++)
		cin >> array[i];

	RandQuicksort(array, 0, size - 1, size);
    for (int i = 0; i < size; i++) {
        cout << array[i] << ";";
    }
	delete[] array;
	return 0;
}
