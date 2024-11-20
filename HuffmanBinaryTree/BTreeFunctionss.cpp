#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "LLBasicFunctions.h"
#include "BTreeFunctions.h"
#include <cstring>
BTreeLL* addBTElement(BTreeLL* head, BTreeLL* new_node)
{
	BTreeLL* t = head;
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
	removeLastElement(LLhead);
	int penultimate = peek(*LLhead);					//one element before last element (second smallest element)
	removeLastElement(LLhead);

	int sum = ultimate + penultimate;
	(*LLhead) = addToEnd(LLhead, sum);					//add new element to the list (sum)
	insertionSortDesc(LLhead);							//sort list downwards
	

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

	(*BThead) = addBTElement(*BThead, new_node);			//add this whole new_node to the binary tree List (array)

	addSumOfLastElementsToBTLL(LLhead, BThead);			//recursion
}

BTreeLL* findNode(BTreeLL* bthead, int x)
{
	BTreeLL* t = bthead;
	while (t != NULL) {
		if (t->node->x == x)return t;
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
		std::cout << root->x << std::endl;
		preOrder(root->left);
		preOrder(root->right);
	}
}

void fillBTreewithChar(struct BTree* root,LL*head)
{
	if (root == NULL)
	{
		return;
	}
	LL* t = head;
	while (t != NULL)
	{
		if (root->x == t->x) {
			root->a = t->a;
		}
		t = t->next;
	}
	fillBTreewithChar(root->left,head);
    fillBTreewithChar(root->right,head);

	
}
BTreeLL* findLast(BTreeLL* head)
{
	BTreeLL* t = head;
	while (t->next != NULL)
		t = t->next;
	return t;
}
void printNodes(BTree* head,const char *code)
{
	char totalcode[26];
	if (head->left == NULL && head->right == NULL)
		std::cout << head->a << ": " << code<<std::endl;
	else
	{
		strcpy_s(totalcode, code);
		printNodes(head->left, strcat(totalcode,"1"));
		strcpy_s(totalcode, code);
		printNodes(head->right, strcat(totalcode,"0"));
	}
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
