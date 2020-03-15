

#include <algorithm> 
#include <climits>
#include <vector>
#include <iostream>
#include <utility>
//#define INT_MAX 99999



//Pseudocode
// FOR matrix chaining
// MATRIX-CHAIN-ORDER(p)
// n = p.length - 1
// let m[1...n, 1...n] and s[1...n - 1, 2..n] be new tables
// for i = 1 to n
//     m[i,i] = 0
// for l = 2 to n //l is the chain length
//     for i = 1 to n - l + 1
//         j = i + l - 1
//         m[i,j] = oo
//         for k = i to j - 1
//             q = m[i,k] + m[k + 1, j] + p(i-1) * p(k) * p(j)
//             if q < m[i, j]
//             m[i, j] = q
//             s[i, j] = k
// return m and s


//Pseudocode
// PRINT-OPTIMAL-PARENS(s, i, j)
// if(i==j)
//     print “A”i
// else print “(”
//     PRINT-OPTIMAL-PARENS(s, i, s[i, j])
//     PRINT-OPTIMAL-PARENS(s, s[i, j]􏰯 + 1, j)
//     print “)”

using namespace std;

// C-style function modifier 
extern void print(vector< vector<int> > &m, int i, int j);

//the goal is to find the most computationally efficient matrix order when multiplying an arbitrary number of matrices in a row.
void MatrixChainOrder(int * p, int n)
{
    
    int matrix[n+1][n+1];
    int SENTINEL_VALUE = INT_MAX, R = 0, counts = 0, C = 0, k = 0,L = 2,q = 0, sum = 0;
    
    for (R = 0; R <= n; R++)//for i = 1 to n
    {
        matrix[R][R] = 0;// m[i,i] = 0
    }
	vector <vector<int> > t;
    t.resize(n+1, vector<int>(n+1, -1));

    while (L <= n)
    {
		for(R = 1; R <= n - L +1; R++)//for i = 1 to n - l + 1
        {
			C = R + L - 1;//j = i + l - 1
			matrix[R][C] = SENTINEL_VALUE;//m[i,j] = oo
			for(k = R; k <= C - 1; k++) //for k = i to j - 1
            {
                sum = matrix[R][k] + matrix[k+1][C];//setting sum = matrix[R][k] + matrix[k+1][C] to carry out next operation
				q = sum + (p[R-1] * p[k] * p[C]);//q = m[i,k] + m[k + 1, j] + p(i-1) * p(k) * p(j)
                int num = matrix[R][C];
				if(q < num)//if q < m[i, j]
                {
                    t[R][C] = k; //m[i, j] = q
					matrix[R][C] = q; //s[i, j] = k
				}
			}
        }
    L++;
    }
    
	cout << matrix[1][n] << endl;
	print(t,1,n);
    cout << endl;
}

void print(vector< vector<int> > &m, int i, int j)
{
	if(i == j) cout << "A" << (i-1); //if(i==j)  print “A”
    else//else print
    {
		cout << "(";
		print(m,i,m[i][j]);// PRINT-OPTIMAL-PARENS(s, i, s[i, j])
        
		print(m,m[i][j]+1,j);// PRINT-OPTIMAL-PARENS(s, s[i, j]􏰯 + 1, j)
		cout << ")";
	}
}


int main()
{

    int size;//init size
    cin >> size;///getting size for input
    int *array = new int[size + 1]; //allocating space for size +1

    for (int i = 0; i <= size; i++)//for int i i <size i ++
        cin >> array[i];//get arr[i] from input

    MatrixChainOrder(array, size);

    delete[] array;
    return 0;

}
//Pseudocode
// FOR matrix chaining
// MATRIX-CHAIN-ORDER(p)
// n = p.length - 1
// let m[1...n, 1...n] and s[1...n - 1, 2..n] be new tables
// for i = 1 to n
//     m[i,i] = 0
// for l = 2 to n //l is the chain length
//     for i = 1 to n - l + 1 
//         j = i + l - 1
//         m[i,j] = oo
//         for k = i to j - 1
//             q = m[i,k] + m[k + 1, j] + p(i-1) * p(k) * p(j)
//             if q < m[i, j]
//             m[i, j] = q
//             s[i, j] = k
// return m and s


//Pseudocode
// PRINT-OPTIMAL-PARENS(s, i, j)
// if(i==j)
//     print “A”i
// else print “(”
//     PRINT-OPTIMAL-PARENS(s, i, s[i, j]) 
//     PRINT-OPTIMAL-PARENS(s, s[i, j]􏰯 + 1, j) 
//     print “)”
