#include <conio.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <Windows.h>
using namespace std;

/* Khai báo kiểu dữ liệu của Node */
typedef int ItemType;

/* Khai báo thuộc tính color */
enum EColor { RED, BLACK };

/* Khai báo cấu trúc node */
struct BRTNode
{
	ItemType Info;
	EColor Color;
	BRTNode *Left, *Right, *Parent;
};

/* Khai báo cấu trúc cây Đỏ-Đen */
struct BRTree
{
	BRTNode *Root;
};
//==================================================
void set_Color(int colorBackground, int colorText);
void showTNode(BRTNode *p);
void initBRTree(BRTree &brt);

void swapColors(EColor &color1, EColor &color2);
void swapInfos(ItemType &info1, ItemType &info2);

void showBRTree_PreOrder(BRTNode *root);
void showBRTree_InOrder(BRTNode *root);
void showBRTree_PostOrder(BRTNode *root);

void levelOrder(BRTNode *root);
void showLevelOrder(BRTNode *root);

void iterativePreOrder(BRTNode *root);
void showPreOrder(BRTNode *root);
void iterativeInOrder(BRTNode *root);
void showInOrder(BRTNode *root);
void iterativePostOrder(BRTNode *root);
void showPostOrder(BRTNode *root);

BRTNode* BRTInsert(BRTNode* root, BRTNode *pNew);
void rotateLeft(BRTNode *&root, BRTNode *&p);
void rotateRight(BRTNode *&root, BRTNode *&p);
void fixViolation(BRTNode *&root, BRTNode *&p);
void insert(BRTNode *&root, ItemType Info);

bool isOnLeft(BRTNode *p);
bool hasRedChild(BRTNode *p);
BRTNode *findUncle(BRTNode *p);
BRTNode *findSibling(BRTNode *p);
BRTNode *findSuccessor(BRTNode *p);
void fixDoubleBlack(BRTNode *&root, BRTNode *p);
BRTNode *BSTReplace(BRTNode *p);
void deleteNode(BRTNode *&root, BRTNode *pDelete);
BRTNode *search(BRTNode *root, ItemType x);
void deleteByInfo(BRTNode *&root, ItemType x);
void createBRTreeFromArray(BRTree &brt, ItemType a[], int na);
int countRed(BRTree brt, BRTNode a[], int na);
//==================================================
BRTNode* createBRTNode(ItemType x);
void set_Color(int colorBackground, int colorText);
void showTNode(BRTNode *p);
void initBRTree(BRTree &brt);
void docDuLieu(BRTree &sl, char fileName[]);
void luuDuLieu(BRTree sl, char fileName[]);
//==========================================================
void initBRTree(BRTree &sl);            // Khoi tao danh sach sl rong
bool isEmpty(BRTree sl);               // kiem tra ds sl co rong hay k?
bool insertHead(BRTree &sl, BRTNode *p); // them node p vao dau ds!
bool insertTail(BRTree &sl, BRTNode *p);
int tongThoiLuongList(BRTree &sl, BRTNode *p);
BRTNode *findBRTNode(BRTree sl, ItemType x); // Tim mot Node chua x
void showBRTree(BRTree sl);
//==========================================================
//Các hàm delete
//==========================================================
bool deleteHead(BRTree &sl);
bool deleteAfter(BRTree &sl, BRTNode *q, ItemType x);
bool delteX(BRTree &sl, ItemType x);
void swapColors(EColor &color1, EColor &color2);
void swapInfos(ItemType &info1, ItemType &info2);
