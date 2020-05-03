#include<iostream>
#include<vector>
#include<fstream>
#include<array>
#include"BTreeFunctions.h"
#include"LLBasicFunctions.h"

using namespace std;


std::array<int, 26> fillArray(string filename);
int getWordCount(string filename);
void printLetterStats(array<int, 26>letters, int maxletters);
void printArr(array<int, 26>letters);
int getSumfromArray(array<int, 26>letters);

struct BTree
{
	int x;
	struct BTree* left, * right;
};
struct BTreeLL
{
	struct BTree* node;
	struct BTreeLL* next;
};

BTreeLL* addBTElement(BTreeLL* head, BTreeLL*new_node);
void addSumOfLastElementsToBTLL(LL** head, BTreeLL** bthead);
BTreeLL* findNode(BTreeLL* bthead, int x);
void printBTLL(BTreeLL* bthead);
void preOrder(struct BTree* root);
BTreeLL* findLast(BTreeLL* head);
void printNode(BTreeLL* head);
void deleteNode(struct BTreeLL** head_ref, int key);

int main()
{
	string filename = "words.txt";
	array<int, 26>letters = { 0 };
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
	BTarray = findLast(BTarray);
	preOrder(BTarray->node);										//print the huffman tree, left "branch" is 1 and right "branch" is 0
}



std::array<int, 26> fillArray(string filename)
{
	array<int, 26> lettercounter = { 0 };
	ifstream txtfile;
	txtfile.open(filename, ios::in);
	char a = '\0';
	while (!txtfile.eof()) {

		txtfile >> a;
		if (a > 64 && a < 91)a += 32;				//velika u mala slova
		if (a > 96 && a < 123) {
			int temp = static_cast<int>(a) - 97;	//svako slovo se broji sa brojacem znakova
			lettercounter[temp]++;
		}
	}
	txtfile.close();
	return lettercounter;
}
int getWordCount(string filename)
{
	ifstream txtfile;
	txtfile.open(filename, ios::in);
	char a = '\0';
	int counter(0);
	while (!txtfile.eof()) {
		txtfile >> a;
		if (a > 96 && a < 123)
			counter++;
	}
	txtfile.close();
	return counter;
}
void printLetterStats(array<int, 26>letters, int maxletters)
{
	int i(0);
	for (auto x : letters) {
		cout  << static_cast<float>(x)/static_cast<float>(maxletters)<< " ";
		i++;
	}
	std::cout << std::endl;
}
int getSumfromArray(array<int, 26>letters)
{
	int sum(0);
	for (auto x : letters)
	{
		sum += x;
	}
	return sum;
}
void printArr(array<int, 26>letters)
{
	for (auto x : letters)
		cout << x << " ";
	cout<<endl;
}
void preOrder(struct BTree* root);

BTreeLL* addBTElement(BTreeLL* head,BTreeLL*new_node)
{
	BTreeLL*t = head;
	if (head == NULL) {
		head = new_node;
		head->next = NULL;
	}
	else {
		while (t->next != NULL) t = t->next;
		t->next = new_node;
		t = t->next;
		t->next = NULL;
	}
	return head;
}
void addSumOfLastElementsToBTLL(LL** LLhead, BTreeLL** BThead)
{
	if ((*LLhead)->next == NULL)return;					//escape function

	int ultimate = peek(*LLhead);						//last element in list (smallest element)
	if ((*LLhead) != NULL)removeLastElement(LLhead);
	int penultimate = peek(*LLhead);					//one element before last element (second smallest element)
	if((*LLhead)!=NULL)removeLastElement(LLhead);

	int sum = ultimate + penultimate;			
	(*LLhead)=addToEnd(LLhead, sum);					//add new element to the list (sum)
	insertionSortDesc(LLhead);

	BTreeLL* left = findNode(*BThead, ultimate);		//Look through binary tree linked list, if it doesnt exist
	BTreeLL* right = findNode(*BThead, penultimate);	//value will be NULL

	BTreeLL* new_node = new BTreeLL;
	new_node->node = new BTree;
	new_node->node->x = sum;							//make a new node in binary tree with value of sum

	if (left && (penultimate != ultimate)) {			//if left is not NULL (it exists in Binary tree LL and smallest and second smallest ARE DIFFERENT
		new_node->node->left = left->node;				//then connect nodes, if they are the same then create new node because both left and right nodes
	deleteNode(BThead, ultimate);						//would point to the same node.
	}
	else {
		new_node->node->left = new BTree;
		new_node->node->left->x = ultimate;
		new_node->node->left->left = NULL;
		new_node->node->left->right = NULL;
	}
	if (right) {										//if right exists then point to it
		new_node->node->right = right->node;
		deleteNode(BThead, penultimate);
	}
	else {												//if not make a new one
		new_node->node->right = new BTree;
		new_node->node->right->x = penultimate;
		new_node->node->right->left = NULL;
		new_node->node->right->right = NULL;
	}
	
	(*BThead)=addBTElement(*BThead, new_node);			//add this whole new_node to the binary tree List (array)
	
	addSumOfLastElementsToBTLL(LLhead, BThead);			//recursion
}
BTreeLL* findNode(BTreeLL* bthead, int x)
{
	BTreeLL* t = bthead;
	while (t != NULL) {
		if (t->node->x==x)return t;
		t = t->next;
	}
	return NULL;
}
void printBTLL(BTreeLL* bthead)
{
	BTreeLL* t = bthead;
	while (t != NULL) {
		std::cout << t->node->x << std::endl;
		t = t->next;
	}
}
void preOrder(struct BTree* root) { 
	if (root == NULL) {
		return;
	}
	else { 
		std::cout << "Tree->";
		std::cout<<root->x<<std::endl;   
	preOrder(root->left);  
	preOrder(root->right); 
	} 
}
BTreeLL* findLast(BTreeLL* head)
{
	BTreeLL* t = head;
	while (t->next != NULL)
		t = t->next;
	return t;
}
void printNode(BTreeLL* head)
{
	BTreeLL* t = head;
	BTree* as = t->node;
	std::cout <<"t="<< as->x << "\n";
	std::cout << "t->left=" << as->left->x << "\n";
	std::cout << "t->right=" << as->right->x << "\n";
}

void deleteNode(struct BTreeLL** head_ref, int key)
{
	if ((*head_ref)->node->x == key)return;

	struct BTreeLL* temp = *head_ref;
	struct BTreeLL* prev = temp;

	if (temp != NULL && temp->node->x == key)
	{
		*head_ref = temp->next;  
		free(temp);              
		return;
	}

	while (temp != NULL && temp->node->x != key)
	{
		prev = temp;
		temp = temp->next;
	}
 
	if (temp == NULL) return;

	prev->next = temp->next;

	free(temp);
}