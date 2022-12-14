#include "HashTable.h"

HashNode* bucket[KEYSIZE];

int HashFunction(int Key)
{
	return (Key % KEYSIZE);
}

void InitBucket()
{
	for (int b = 0; b < KEYSIZE; b++)
		bucket[b] = NULL;
}

void Push(int b, int x)
{
	HashNode* p = new HashNode;
	p->Key = x;
	p->Next = bucket[b];
	bucket[b] = p;
}

void InsertAfter(HashNode *p, int k)
{
	if (p == NULL)
		printf("Khong them vao Node duoc");
	else {
		HashNode* q = new HashNode;
		q->Key = k;
		p->Next = q;
	}
}


int Search(int k)
{
	int b = HashFunction(k);
	HashNode* p = bucket[b];
	while (k > p->Key && p != NULL)
		p = p->Next;
	if (p == NULL || k != p->Key)
		return -1;
	else
		return b;
}

void Place(int b, int k)
{
	HashNode* p, *q;
	q = NULL;
	for (p = bucket[b]; p != NULL&& k > p->Key; p = p->Next)
		q = p;
	if (q == NULL)
		Push(b, k);
	else
		InsertAfter(q, k);
}

int IsEmptyBucket(int b)
{
	return(bucket[b] == NULL ? 1 : 0);
}

int Pop(int b)
{
	HashNode* p;
	int k;
	if (IsEmptyBucket(b))
	{
		printf("Bucket %d bi rong , khong xoa duoc", b);
		return 0;
	}
	p = bucket[b];
	k = p->Key;
	bucket[b] = p->Next;
	delete p;
	return k;
}

int deleteAfter(HashNode* p)
{
	HashNode* q;
	int k;
	if (p == NULL || p->Next == NULL)
	{
		printf("\nKhong xoa Node duoc");
		return 0;
	}
	q = p->Next;
	k = q->Key;
	p->Next = q->Next;
	delete q;
	return k;
}

void DeleteHashNode(HashNode* p)
{
	delete p;
}

void TraverseBucket(int b)
{
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		printf("%4d", p->Key);
		p = p->Next;
	}
}
//===================================================================
// Duyet qua bang bam
void Traverse()
{
	for (int b = 0; b < KEYSIZE; b++)
	{
		printf("\n Bucket[%d]=", b);
		TraverseBucket(b);
	}
}
//===================================================================
// Xoa tren mot bucket
void ClearBucket(int b)
{
	HashNode* q = NULL;
	HashNode* p = bucket[b];
	while (p != NULL)
	{
		q = p;
		p = p->Next;
		DeleteHashNode(q);
	}
	bucket[b] = NULL;
}
//===================================================================
// Xoa toan bo bang bam
void Clear()
{
	for (int b = 0; b < KEYSIZE; b++)
	{
		ClearBucket(b);
	}
}

void Insert(int k)
{
		int b;
	b = HashFunction(k);
	Place(b, k);
}

void Remove(int k)
{
	int b;
	HashNode *p, *q;
	b = HashFunction(k);
	p = bucket[b];
	q = p;
	while (p != NULL && p->Key != k)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
		printf("\n Khong co HashNode co khoa la: %d", b);
	else if (p == bucket[b])
		Pop(b);
	else
		deleteAfter(q);
}