#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define M 5
#define Distance 10
typedef int ItemType;
struct BNode
{
	int numTree;
	ItemType Keys[M - 1];
	BNode* Branch[M];
};
struct BTree
{
	BNode* Root;//con tro quan ly' node goc'
};
typedef BNode* NodePtr;/*Kieu du lieu con tro node*/
enum KeyStatus { Duplicate , SearchFailure , Success , InsertIt , LessKeys};
void initBTree(BTree &bt);
void displayBTree(NodePtr pRoot, int blanks);
int searchPosition(ItemType key, ItemType *keyArray, int numTree);
KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr* newNode);
void insert(NodePtr &root, ItemType key);
void deleteNod(NodePtr &root, ItemType key);
KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
void search(NodePtr root, ItemType key);