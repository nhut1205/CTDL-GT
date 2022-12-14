//============================================
#include "CayNPTK.h"
#include "stack"
#include "queue"
#include "windows.h"
using namespace std;
BSTNode* CreateTNode(ItemType x)
{
	BSTNode* p = new BSTNode;
	if (p == NULL)
	{
		printf("\nKhong du bo nho de cap phat nut moi!");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Left = NULL;
	p->Right = NULL;
	return p;
}
//============================================
void initBSTree(BTree& bt)
{
	bt.Root = NULL;
}
//============================================
void showBSTNode(BSTNode* p)
{
	printf("%4d", p->Info);
}

bool InsertBSTNode(BSTNode*& root, BSTNode* p)
{
	if (p == NULL)
		return false; // Thực hiện không thành công
	if (root == NULL) // Cây rỗng, nên thêm vào gốc
	{
		root = p;
		return true; // Thực hiện thành công
	}
	if (root->Info == p->Info)
		return false;
	else if (root->Info > p->Info)
		InsertBSTNode(root->Left, p); // Them ben trai
	else
		InsertBSTNode(root->Right, p); // Them ben phai
	return true;                       // Thực hiện thành công
}

void CreateBTree_Automatic(BTree& bt)
{
	int n;
	ItemType x;
	BSTNode* p;
	printf("Cho biet so nut cua cay: ");
	scanf_s("%d", &n);
	initBSTree(bt);
	srand((unsigned)time(NULL)); // Tạo số mới sau mỗi lần thực hiện
	int i = 0;
	while (i < n)
	{
		x = (rand() % 199) - 99; // Tạo 1 số ngẫu nhiên trong [-99, 99]
		p = CreateTNode(x);
		if (InsertBSTNode(bt.Root, p));
		i++;
	}
}

void CreateBTree_FromArray(BTree& bt, ItemType a[], int n)
{
	ItemType x;
	BSTNode* p;
	initBSTree(bt);
	int i = 0;
	while (i < n)
	{
		x = a[i];
		p = CreateTNode(x);
		if (InsertBSTNode(bt.Root, p))
			i++;
	}
}

void NLR(BSTNode* root)
{
	if (root == NULL)
		return;
	showBSTNode(root);
	NLR(root->Left);
	NLR(root->Right);
}

void NRL(BSTNode* root)
{
	if (root == NULL)
		return;
	showBSTNode(root);
	NRL(root->Right);
	NRL(root->Left);
}

void LNR(BSTNode* root)
{
	if (root == NULL)
		return;
	LNR(root->Left);
	printf("%4d", root->Info);
	LNR(root->Right);
}

void LRN(BSTNode* root)
{
	if (root == NULL)
		return;
	LRN(root->Left);
	LRN(root->Right);
	printf("%4d", root->Info);
}

BSTNode* FindTNode(BSTNode* root, ItemType x)
{
	if (root == NULL)
		return NULL;
	if (root->Info == x)
		return root; // tìm được khóa thì dừng
	else if (root->Info > x)
		FindTNode(root->Left, x); // tìm x bên nhánh trái
	else
		FindTNode(root->Right, x); // tìm x bên nhánh phải
}

bool isLeaf(BSTNode* p)
{
	// Kiem tra so la cua cay
	return (!p->Left && !p->Right);
}

int countNodeLeaf(BSTNode* root)
{
	// Dem xem cay co bao nhieu la
	if (!root)
		return 0;
	int nl = countNodeLeaf(root->Left);
	int nr = countNodeLeaf(root->Right);
	if (isLeaf(root))
		return 1 + nl + nr; // Goc node la la
	else
		return nl + nr; // Goc node khong la la
}

BSTNode* findTNodeReplace(BSTNode*& p)
{
	BSTNode* f = p;
	BSTNode* q = p->Right;
	while (q->Left != NULL)
	{
		f = q;
		q = q->Left;
	}
	p->Info = q->Info;
	if (f == p)
		f->Right = q->Right;
	else
		f->Left = q->Right;
	return q;
}

bool deleteXFromTree(BSTNode* root, ItemType x)
{
	if (!root)
		return false;
	if (root->Info > x)
		return deleteXFromTree(root->Left, x);
	else if (root->Info < x)
		return deleteXFromTree(root->Right, x);
	else
	{
		BSTNode* p = root;
		if (root->Left == NULL)
		{
			root = root->Right;
			delete p;
		}
		else if (root->Right == NULL)
		{
			root = root->Left;
			delete p;
		}
		else
		{
			BSTNode* q = findTNodeReplace(p);
			delete q;
		}
	}
	return true;
}

void traverseTree_Depth_NLR(BSTNode* root)
{
	// Duyet va xem noi dung cay theo chieu sau
	if (!root) return;
	stack<BSTNode*> st;
	st.push(root);
	while (!st.empty())
	{
		BSTNode* p = st.top();
		showBSTNode(p);
		st.pop();
		if (p->Right)
			st.push(p->Right);
		if (p->Left)
			st.push(p->Left);
	}
}

void traverseTree_Breath_NLR(BSTNode* root)
{
	// Duyet va xem noi dung cay theo chieu sau
	if (!root) return;
	queue<BSTNode*> qu;
	qu.push(root);
	while (!qu.empty())
	{
		BSTNode* p = qu.front();
		showBSTNode(p);
		qu.pop();

		if (p->Left)
			qu.push(p->Left);
		if (p->Right)
			qu.push(p->Right);
	}
}

void timMax(int a, int b)
{
	if (a > b)
		return a;
	return b;
}