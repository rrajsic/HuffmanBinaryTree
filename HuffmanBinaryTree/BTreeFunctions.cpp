#include<iostream>
#include"BTreeFunctions.h"
#include"LLBasicFunctions.h"


//void addBTElement(BTreeLL* head,int x)
//{
//	BTreeLL* new_node = new BTreeLL();
//	new_node->node->x = x;
//	new_node->node->left = NULL;
//	new_node->node->right = NULL;
//	if (head == NULL) {
//		head = new_node;
//		head->next = NULL;
//	}
//	else {
//		BTreeLL* t = head;
//		while (t != NULL) t = t->next;
//		t = new_node;
//		t->next = NULL;
//	}
//}
//void addSumOfLastElementsToBTLL(LL*head,BTreeLL *bthead)
//{
//	int ultimate = peek(head);					//last element
//	removeLastElement(head);
//	int penultimate = peek(head);				//one element before last element
//	removeLastElement(head);
//
//	int sum = ultimate + penultimate;
//	addBTElement(bthead, sum);
//}
//void printBTLL(BTreeLL* bthead)
//{
//	BTreeLL* t = bthead;
//	while (t != NULL) {
//		std::cout << t->node->x << std::endl;
//		t = t->next;
//	}
//}