
/*
 I also used https://www.geeksforgeeks.org/c-program-hashing-chaining/ as reference about how to get started doing this lab. 
 */



#include <vector>
#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <sstream>

using namespace std;

void Insertfunc(deque<list<int> > &hashTable, int input, int hashSize)//to insert a key
{

	hashTable[input % hashSize].push_front(input);    // (input % hashsize) represent the location where the value goes.
}

void print(deque<list<int> > &hashTable, int hashSize)
{
	for(int i = 0; i < hashSize; i++) // for int i = 0 while i less than the size of hash increment i
		{
			cout << i << ":"; //output hashtable
			for(list<int>::iterator it = hashTable[i].begin(); it != hashTable[i].end(); ++it)//for our list
                //start the iterator at the beginning, begin to iterate through deque while it doesnt reach
                //end of hashtable
				{
					
					cout << *it << "->"; // output value at  its correct location
				}
			cout << ";" << endl;
		}
}

void Deletefunc(deque<list<int> > &hashTable, int input, int hashSize)//to delete a key
{
	int n = input % hashSize; //the key they will give us to delete

	list<int>:: iterator it = find(hashTable[n].begin(), hashTable[n].end(), input);//set my iterator at the
//beginning of hashtable[n] aka whichever key is requested to be deleted
	if(it != hashTable[n].end())//if the iterator isnt as the end of the hashtable
		{
            hashTable[n].erase(it);//erase [n] key aka the input
			cout << input << ":DELETED;" << endl;// output the key that was input was deleted
		}
	else
		{
			cout << input << ":DELETE_FAILED;" << endl;//if the key wasnt found output delete failed
		}
}

void Searchfunc(deque<list<int> > &hashTable, int input, int hashSize)//to Searchfunc for a key
{
	int n = input % hashSize;//the input that will be given to us

	list<int>:: iterator it = find(hashTable[n].begin(), hashTable[n].end(), input);//same idea as above when we wanted to delete a key here we are doing the same exact thing except not erasing the key we find we simply output a message saying we found it

	if(it != hashTable[n].end())
		{
			cout << input << ":FOUND_AT" << n << "," << distance(hashTable[n].begin(), it) << ";" << endl;//output if the input was found and also what position it was found at
		}
	else
		{
			cout << input << ":NOT_FOUND;" << endl;//output if it was not found
		}
}

int main()
{
	int hashSize;
	cin >> hashSize; //will be input by user
	deque< list<int> > hashTable;//start up and resize our hashtable
	hashTable.resize(hashSize);
	string input;
	cin >> input;

	int key = 0;
	string choice = "";//whatever the user chooses ,insert,search,delete,etc
	while( input != "e")// e means end
		{
			if(input != "o")
				{
					choice = input.substr(0,1);

					stringstream convert_stm(input.substr(1,input.size()-1)); 

					if(!(convert_stm >> key)) 
						key = -1;

				if(choice == "i")//i = insert
					{
						Insertfunc(hashTable, key, hashSize);
					}
				else if(choice == "d")//d = delete
					{
					
						Deletefunc(hashTable, key, hashSize);
					}
				else if(choice == "s")//s = search
					{
						Searchfunc(hashTable, key, hashSize);
					}
				}
			else
				{
					print(hashTable, hashSize);//output the table
				}
    cin >> input;
		}
}
