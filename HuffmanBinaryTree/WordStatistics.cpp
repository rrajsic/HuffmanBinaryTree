using namespace std;
#include <iostream>
#include <fstream>
#include <array>
#include "WordStatistics.h"



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
		cout << static_cast<float>(x) / static_cast<float>(maxletters) << " ";
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
	cout << endl;
}