#include<iostream>
#include<vector>
#include<fstream>
#include<array>
#include "LLBasicFunctions.h"
#include "BTreeFunctions.h"
#include "WordStatistics.h"

int main()
{
	std::string filename = "words.txt";
	std::array<int, 26>letters = { 0 };
	letters = fillArray(filename);									//this counts instances of every letter from a word file
	int wordcount;
	wordcount = getWordCount(filename);
	std::cout << "Word count: " << wordcount << std::endl;
	std::cout << "Letter count: " << getSumfromArray(letters)<<std::endl;

	struct LL* LLarray = makeList(26);
	struct BTreeLL* BTarray = NULL;									//make 2 arrays, 1 for each letter and the other one for binary tree nodes.

	fillListFromArray(LLarray, letters, getSumfromArray(letters));  //this copies number of each letter in the array
	insertionSortDesc(&LLarray);									//sort by probability
	printList(LLarray);

	addSumOfLastElementsToBTLL(&LLarray, &BTarray);					//main algorithm

	std::cout << "Binary tree preorder: \n";
	BTarray = findLast(BTarray);									//last one is root
	preOrder(BTarray->node);										//print the huffman tree, left "branch" is 1 and right "branch" is 0
}





