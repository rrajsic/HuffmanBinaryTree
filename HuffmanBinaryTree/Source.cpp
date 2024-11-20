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
	std::array<int, 26>characters = { 0 };
	characters = fillArray(filename);									//this counts instances of every letter from a word file
	std::cout << "Total number of characters: " << getSumfromArray(characters)<<std::endl;
	std::cout << "\nCharacter count and their probability: "<<std::endl;

	struct LL* LLarray = makeList(26);
	

	struct BTreeLL* BTarray = NULL;									//make 2 arrays, 1 for each letter and the other one for binary tree nodes.

	fillListFromArray(LLarray, characters, getSumfromArray(characters));  //this copies number of each letter in the array
	insertionSortDesc(&LLarray);									//sort by probability


	addSumOfLastElementsToBTLL(&LLarray,&BTarray);					//main algorithm

	
	BTarray = findLast(BTarray);									//last one is root

	
	struct LL* lettArray = makeList(26);
	fillListFromArray(lettArray, characters, getSumfromArray(characters));
	
	printList(lettArray);
	fillBTreewithChar(BTarray->node,lettArray);

	std::cout << "\nCharacter encryption: "<<std::endl;
	printNodes(BTarray->node,"");

	std::cout<<"\n Press any key to exit."<<std::endl;
	std::cin.get();
	return 0;
}





