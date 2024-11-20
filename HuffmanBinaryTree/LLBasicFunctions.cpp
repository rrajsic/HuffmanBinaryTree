#include <iostream>
#include<array>
#include "LLBasicFunctions.h"


LL* makeList(int n)
{
	LL* t = NULL;
	LL* h = NULL;

	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			h = new LL;
			t = h;
		}
		else
		{
			t->next = new LL;
			t = t->next;
		}
		t->x = i+1;
		t->a = i + 97;

	}
	t->next = NULL;
	return h;
}
void printList(LL* head)
{
	LL* t = head;
	while (t != NULL)
	{
		std::cout << t->a<<": "<<t->x << " -> "<<(t->probability)*100<<"%\n";
		t = t->next;
	}
	std::cout << std::endl;
}
LL* addToEnd(LL** head, int x)
{
	if ((*head) == NULL)
	{
		LL* head = new LL;
		head->x = x;
		head->next = NULL;
		return head;
	}
	else {
		LL* t = (*head);
		while (t->next != NULL)t = t->next;
		t->next = new LL;
		t = t->next;
		t->x = x;
		t->next = NULL;
		return (*head);
	}
}

void removeLastElement(LL** head)
{
	LL* temp = NULL;
	if ((*head)->next == NULL) {
		(*head)=NULL;
		return;
	}
	LL* t = (*head);
	while (t->next->next != NULL)t = t->next;
	temp = t->next;
	free(temp);
	t->next = NULL;

}
int peek(LL* head)
{
	LL* t = head;
	while (t->next != NULL)
		t = t->next;
	return t->x;
}


void insertionSortDesc(struct LL** head)
{
	struct LL* sorted = NULL;

	struct LL* current = *head;
	while (current != NULL)
	{
		struct LL* next = current->next;
		sortedInsertDesc(&sorted, current);
		current = next;
	}

	*head = sorted;
}
void sortedInsertDesc(struct LL** head, struct LL* new_node)
{
	struct LL* current;
	if (*head == NULL || (*head)->x <= new_node->x)
	{
		new_node->next = *head;
		*head = new_node;
	}
	else
	{
		current = *head;
		while (current->next != NULL &&
			current->next->x > new_node->x)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}

void fillListFromArray(LL* head, std::array<int, 26>arr, int maxProbability)
{
	int counter(0);
	
	LL* t = head;
	while (t ->next!= NULL) {
		t->x = arr[counter];
		t->probability = static_cast<long double>(t->x) / maxProbability;
		counter++;
		t = t->next;
	}

}
