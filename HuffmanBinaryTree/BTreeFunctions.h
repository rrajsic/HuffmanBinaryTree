#ifndef BTREEFUNCTIONS_H
#define BTREEFUNCTIONS_H
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

BTreeLL* addBTElement(BTreeLL* head, BTreeLL* new_node);
void addSumOfLastElementsToBTLL(LL** head, BTreeLL** bthead);
BTreeLL* findNode(BTreeLL* bthead, int x);
void printBTLL(BTreeLL* bthead);
void preOrder(struct BTree* root);
BTreeLL* findLast(BTreeLL* head);
void printNode(BTreeLL* head);
void deleteNode(struct BTreeLL** head_ref, int key);

#endif