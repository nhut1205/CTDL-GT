#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>


#define KEYSIZE 26
#define TRUE 1
#define FALSE 0

struct HashNode
{//Định nghĩa kiểu dữ liệu cho 1 nut của Bảng băm
	int Key;
	HashNode *Next;
};

int HashFunction(int Key);
void InitBucket();
void Push(int b, int x);
void InsertAfter(HashNode *p, int k);
void Place(int b, int k);
int IsEmptyBucket(int b);
int Pop(int b);
int deleteAfter(HashNode* p);
int Search(int k);
void Remove(int k);
void Insert(int k);
void Clear();
void TraverseBucket(int b);
void Traverse();
void DeleteHashNode(HashNode* p);
void Insert(int k);