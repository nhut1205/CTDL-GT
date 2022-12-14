#include "Queue.h"
QNode *createSNode(ItemType x)
{
	QNode *p = new QNode;
	if (p == NULL) // Nếu dữ liệu trống
	{
		printf("Khong du bo nho de cap phat node");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void showQNode(QNode *p)
{
	printf("%4d", p->Info); // Hiển thị SNode
}
//============================================================
void initSList(Queue &qu)
{
	qu.Head = NULL;
	qu.Tail = NULL;
}
//============================================================
bool isEmpty(Queue qu) // Tạo danh sách trống
{
	return (qu.Head == NULL);
	/*if (qu.Head == NULL)
	return true;
	else
	return false;*/
}
//============================================================
//============================================================
bool insert(Queue &qu, QNode *p)
{
	if (p == NULL)
		return false;
	if (isEmpty(qu) == true)
	{
		qu.Head = p;
		qu.Tail = p;
	}
	else
	{
		qu.Tail->Next = p;
		qu.Tail = p;
	}
	return true;
}
//============================================================
void showSList(Queue qu)
{
	if (isEmpty(qu))
	{
		printf("Danh sach rong!");
		return;
	}
	printf(" Noi dung cua danh sach la: ");
	for (QNode *p = qu.Head; p != NULL; p = p->Next)
		showQNode(p);
}
//============================================================
void createSlist_Auto(Queue &qu)
{
	int n;
	ItemType x;
	QNode *p;
	initSList(qu);
	printf("Ban hay cho biet so node can tao: ");
	scanf_s("%d", &n);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		x = rand() % 199 - 100;
		p = createSNode(x);
		showQNode(p);
		insert(qu, p);
	}
}
//============================================================
bool remove(Queue &qu)
{
	// xoa p snode o dau danh sach qu
	if (isEmpty(qu) == true)
		return false;
	QNode *p = qu.Head;
	qu.Head = qu.Head->Next;
	if (qu.Head == NULL)
		qu.Tail = NULL;
	delete p; // xoa node khoi danh sach
	return true;
}
//============================================================
bool Head(Queue q, ItemType &x)
{
	if (isEmpty(q) == true)
		return false; // Không thực hiện được
	x = q.Head->Info; // Lấy thông tin của nút bị hủy
	return true;	  // Thực hiện thành công
}
bool Tail(Queue q, ItemType &x)
{
	if (isEmpty(q) == true)
		return false; // Không thực hiện được
	x = q.Tail->Info; // Lấy thông tin của nút bị hủy
	return true;	  // Thực hiện thành công
}
void ShowQueue(Queue q)
{
	if (isEmpty(q) == 1)
	{
		printf("\nHang doi rong !");
		return; // Không thực hiện được
	}
	printf("\nNoi dung hang doi : ");
	for (QNode *p = q.Head; p != NULL; p = p->Next)
		printf("%4d", p->Info);
}