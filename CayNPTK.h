#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stack>
#include <queue>
#include <windows.h>
using namespace std;
typedef int ItemType;
struct BSTNode
{
	ItemType Info;
	BSTNode* Left;
	BSTNode* Right;
};
BSTNode* CreateTNode(ItemType x);
void showBSTNode(BSTNode* p);
struct BTree
{ //Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
	BSTNode* Root;
};

void initBSTree(BTree& bt);
bool isEmpty(BTree bt);
BSTNode* FindTNode(BSTNode* root, ItemType x);
void LRN(BSTNode* root);
void LNR(BSTNode* root);
void NLR(BSTNode* root);
void NRL(BSTNode* root);
void CreateBTree_Automatic(BTree& bt);
bool InsertBSTNode(BSTNode*& root, BSTNode* p);
bool isLeaf(BSTNode* p);
int countNodeLeaf(BSTNode* root);
bool deleteXFromTree(BSTNode* root, ItemType x);
void traverseTree_Depth_NLR(BSTNode* root);
void traverseTree_Breath_NLR(BSTNode* root);
void CreateBTree_FromArray(BTree& bt, ItemType a[], int n);
BSTNode* findTNodeReplace(BSTNode*& p);
bool deleteXFromTree(BSTNode* root, ItemType x);
void traverseTree_Depth_NLR(BSTNode* root);
void traverseTree_Breath_NLR(BSTNode* root);
