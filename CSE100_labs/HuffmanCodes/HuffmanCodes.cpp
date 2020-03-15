#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>



// Huffman (C)
// n = |C|
// Q = C
// for i = 1 to n - 􏰐1
//         allocate a new node  z
//      z.left = x = EXTRACT-MIN(Q)
//        z.right = y = EXTRACT-MIN(Q)
//        z.freq = x.freq + y.freq
//        INSERT(Q, z)


//
//I received help learning more about huffman codes using this website https://www.geeksforgeeks.org/huffman-coding-greedy-algo-3/
//I assmued this was going to be one of the more challenging labs reading the lab09.pdf but understanding the concept of huffman codes was pretty straightforward to me.
//i feel like the book did a very good explanation of huffman codes I just wish it wouldve gave more pseudocode pertaining specifically to this lab

// return EXTRACT-MIN(Q)  //this will return the root of the tree
using namespace std;

struct HuffNode
{
    char label;//label will be used to ID each individual character
    int freq;//freq is the frequency of character
    
    HuffNode* left;//left node points to huffmannode
    HuffNode* right;//right node points to huffmannode
    
    HuffNode(char label, int freq)
    {
        this->label = label;//each left and right node have their own label
        this->freq = freq;//each left and right node have their own freq
        left = NULL;
        right = NULL;
    }
};

struct FinishedNode// finished node
{
    char label;//ID of the finished character
    string code;//code used for the character
    
    FinishedNode(char label, string code) //function for finished
    {
        this->label = label;//label
        this->code = code;//its code we're using
    }
};

struct compareHuff
{
    bool operator()(HuffNode* left, HuffNode* right)//left and right both point to Huffmannode
    {
        return(left->freq > right->freq);//return freq of left and right
    }
};

struct compareFinished
{
    bool operator()(FinishedNode* left, FinishedNode* right)//left and right point to finishednode
    {
        return(left->label > right->label);//return label of left and right
    }
};

void printCodes(struct HuffNode* root, priority_queue<FinishedNode*, vector<FinishedNode*>, compareFinished> *printArray, string str)
{
    if (!root)
    {
        return;
    }
    if (root->label != '$')
    {
        printArray->push(new FinishedNode(root->label, str));
        //cout << root->label << ": " << str << "\n";
    }
    
    printCodes(root->left, printArray, str + "0");
    printCodes(root->right, printArray, str + "1");
}


HuffNode* HuffmanCode(char letters[], int freq[], int size)//huffman code points to huffnode.. contains char letter, the frequency of character and size
{
    
    HuffNode *left, *right, *z;
    
    priority_queue<HuffNode*, vector<HuffNode*>, compareHuff > minHeap;
    for (int i = 0; i < size; i++)
    {
        minHeap.push(new HuffNode(letters[i], freq[i]));// creates a  new min heap and allocates memory
    }                                                   //to store letters[i] and freq[i]
    
    while (minHeap.size() != 1)//while minHeap.size isnt equal to 1
    {
        left = minHeap.top();
        minHeap.pop();//get rid of minmimum freq left
        right = minHeap.top();
        minHeap.pop();//get rid of minimum freq right
        
        z = new HuffNode('$', left->freq + right->freq);//new node that equals sum of left and right freq
        z->left = left;//left node
        z->right = right;//right node
        
        minHeap.push(z);
    }
    return minHeap.top();
}

int main()
{
    char arr[] = { 'A', 'B', 'C', 'D', 'E', 'F' };//create arr of elements A,B,C,D,E,F
    int* freq = new int[6];
    for (int i = 0; i < 6; i++)
    {
        cin >> freq[i];
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    
    priority_queue<FinishedNode*, vector<FinishedNode*>, compareFinished> arrayToPrint;
    
    HuffNode* root = HuffmanCode(arr, freq, size);
    printCodes(root, &arrayToPrint, "");
    
    int printSize = arrayToPrint.size();
    for (int i = 0; i < printSize; i++)
    {
        cout << arrayToPrint.top()->label << ":" << arrayToPrint.top()->code << endl;
        arrayToPrint.pop();
    }
    
    return 0;
}



