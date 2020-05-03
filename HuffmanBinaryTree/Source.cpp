#include<iostream>
#include<vector>
#include<fstream>
#include<array>
#include"BTreeFunctions.h"
#include"LLBasicFunctions.h"

using namespace std;
#define MAXLETTERSIZE 5


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
	letters = fillArray(filename);
	int wordcount;
	wordcount = getWordCount(filename);
	struct LL* LLarray = makeList(26);

	struct BTreeLL* BTarray = NULL;
	fillListFromArray(LLarray, letters, getSumfromArray(letters));
	insertionSortDesc(&LLarray);
	printList(LLarray);
	addSumOfLastElementsToBTLL(&LLarray, &BTarray);
	
	printList(LLarray);
	printBTLL(BTarray);
	BTarray = findLast(BTarray);
	
	preOrder(BTarray->node);

	
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
void addSumOfLastElementsToBTLL(LL** head, BTreeLL** bthead)
{
	if ((*head)->next == NULL)return;
	int ultimate = peek(*head);					//last element
	if ((*head) != NULL)removeLastElement(head);
	int penultimate = peek(*head);				//one element before last element
	if((*head)!=NULL)removeLastElement(head);
	int sum = ultimate + penultimate;
	if ((*head) == NULL)
		(*head) = addToStart(sum);
	else
		addToEnd(head, sum);
	BTreeLL* left = findNode(*bthead, ultimate);
	BTreeLL* right = findNode(*bthead, penultimate);
	BTreeLL* new_node = new BTreeLL;
	new_node->node = new BTree;
	new_node->node->x = sum;

	if (left && (penultimate != ultimate)) {
		new_node->node->left = left->node;
	deleteNode(bthead, ultimate);
	}
	else {
		new_node->node->left = new BTree;
		new_node->node->left->x = ultimate;
		new_node->node->left->left = NULL;
		new_node->node->left->right = NULL;
	}
	if (right) {
		new_node->node->right = right->node;
		deleteNode(bthead, penultimate);
	}
	else {
		new_node->node->right = new BTree;
		new_node->node->right->x = penultimate;
		new_node->node->right->left = NULL;
		new_node->node->right->right = NULL;
	}
	if ((*head)->next != NULL) insertionSortDesc(head);
	(*bthead)=addBTElement(*bthead, new_node);
	
	addSumOfLastElementsToBTLL(head, bthead);
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
		std::cout << "Tree->" << std::endl;
		std::cout<<root->x;   
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
	as = as->left;
	as = as->right;
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