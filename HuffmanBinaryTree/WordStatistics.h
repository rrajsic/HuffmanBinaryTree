#ifndef WORDSTATISTICS_H
#define WORDSTATISTICS_H
using namespace std;
std::array<int, 26> fillArray(string filename);
int getLetterCount(string filename);
void printLetterStats(array<int, 26>letters, int maxletters);
void printArr(array<int, 26>letters);
int getSumfromArray(array<int, 26>letters);



#endif