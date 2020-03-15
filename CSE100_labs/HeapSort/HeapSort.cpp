#include<iostream>

using namespace std;


/*
 PseudoCode for Heapsort page 160
 
 HEAPSORT(A)
 1 BUILD MAX HEAP(A)
 2 FOR I = A.LENGTH downto 2
 3 exchange A[1] with A[i]
 4 A.heap-size = A.heap-size-1
 5 MAX-HEAPIFY(A,1)


*/



/*
 
 PseudoCode for max heapify page 154
 
 MAX-HEAPIFY(A,i)
 
 l L = LEFT(i)
 2 R = right(i)
 3 if L <= A:heap-size and A[L]  > A[i]
 4 largest = L
 5 else largest = i
 6 if r<= A.heapsize and A[r] > A[largest]
 7 largest = r
 8 if largest doesnt equal i
 9 exchange A[i] with A[largest]
 10 MAX- Heapify (A,largest)
 */

void MaxHeapify(int array[], int i, int heap_size)
{
    int left = 2*i + 1;
    int right = 2*i + 2;                                        //             The pseudocode and implementation
    int largest;                                                // of heapsort was pretty straightforward
    if (left < heap_size && array[left] > array[i])            //
        largest = left;                                         //
                                                                //
    else                                                            //  I used the pseudocode from pages
        largest = i;                                                //154-164 from the textbook because of the
    if (right < heap_size && array[right] > array[largest])            // various pseudocodes they
        largest = right;                                            // provided.
    if (largest != i){                                              //
        swap(array[i], array[largest]);                             //
        MaxHeapify(array, largest, heap_size);                      //
    }                                                               //
}                                                                   //

/*
 PseudoCode for build max heap page 157
 
 BUILD MAX HEAP(A)
 1 A.heap-size = A.length
 2 for i = [A.length/2] downto 1
 3 MAX-HEAPIFY(A,i)
 */
void BuildMaxHeap(int array[], int heap_size) {
    for (int i = heap_size/2 - 1; i >= 0; i--) {
        MaxHeapify(array, i, heap_size);
    }
}
void MaxHeap(int array[], int size){    
    BuildMaxHeap(array, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        MaxHeapify(array, 0, i);
    }
}

int main(){ 
    int size;
	cin >> size;
	int *array = new int [size];

	for(int i=0;i<size;i++)
		cin >> array[i];

	MaxHeap(array, size);
    for (int i = 0; i < size; i++) {
        cout << array[i] << ";";
    }
	delete[] array;
	return 0;
}
