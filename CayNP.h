#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
typedef int ItemType;
struct BTNode
{
    ItemType Info;
    BTNode *Left;
    BTNode *Right;
};
BTNode* CreateTNode(ItemType x);
void showBTNode(BTNode *p);
struct BTree
{ //Định nghĩa kiểu dữ liệu cho cây nhị phân (Cây NPTK)
    BTNode *Root;
};
void initBTree(BTree &bt);
bool isEmpty(BTree bt);
BTNode *FindTNode(BTNode *root, ItemType x);
void LRN(BTNode *root);
void LNR(BTNode *root);
void NLR(BTNode *root);
void NRL(BTNode *root);
void CreateBTree_Automatic(BTree &bt);
bool InsertBTNode(BTNode *&root, BTNode *p);
bool InsertBTNodeRight(BTNode *&T, BTNode *p);
bool InsertBTNodeLeft(BTNode *&T, BTNode *p);