#ifndef LLBASIC_H
#define LLBASIC_H
struct LL
{
	int x;
	char a;
	long double probability;
	struct LL* next;
};
LL* makeList(int n);
void printList(LL* head);
LL* addToEnd(LL** head, int x);
LL* addToStart(int x);
void insertNodeinSorted(LL** head, int x);
void removeLastElement(LL** head);
int peek(LL* head);
double arithmeticMean(LL* head);
void insert(LL* head, int index, int x);
void insertionSortDesc(struct LL** head);
void sortedInsertDesc(struct LL** head, struct LL* new_node);
void insertionSortAsc(struct LL** head);
void sortedInsertAsc(struct LL** head, struct LL* new_node);
void fillListFromArray(LL* head, std::array<int, 26>arr, double maxProbability);


#endif