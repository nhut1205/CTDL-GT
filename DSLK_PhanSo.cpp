#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//============================================================
// Khai bao du lieu
//============================================================
//============================================================
struct PhanSo
{
	int tuSo, mauSo;
};
//============================================================
typedef PhanSo ItemType;
//============================================================
struct SNode
{
	ItemType Info;
	SNode *Next;
};
//============================================================
// SNode
//============================================================
SNode *createSNode(ItemType x);
void showPhanSo(ItemType x);
void showSNode(SNode *p);
//============================================================
// Single Link List
//============================================================
struct SList
{
	SNode *Head;
	SNode *Tail;
};
//============================================================
void initSList(SList &sl);			  // Khoi tao danh sach sl rong
bool isEmpty(SList sl);				  // kiem tra ds sl co rong hay k?
bool insertTail(SList &sl, SNode *p); // thêm node p vào cuối danh sach
void showSList(SList sl);			  // duyet va xem noi dung cua ds sl
void createSlist_Auto(SList &sl);	  // tao danh sach sl ngau nhien
//============================================================

SNode *createSNode(PhanSo x)
{
	SNode *p = new SNode;
	if (p == NULL) // Nếu dữ liệu trống
	{
		printf("Khong du bo nho de cap phat node");
		getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
void showSNode(SNode *p)
{
	printf("%4d/%d", p->Info.tuSo, p->Info.mauSo); // Hiển thị SNode
}
//============================================================
void initSList(SList &sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//============================================================
bool isEmpty(SList sl) // Tạo danh sách trống
{
	return (sl.Head == NULL);
	/*if (sl.Head == NULL)
		return true;
	else
		return false;*/
}
//============================================================
void showSList(SList sl)
{
	if (isEmpty(sl))
	{
		printf("Danh sach rong!");
		return;
	}
	printf(" Noi dung cua danh sach la: ");
	for (SNode *p = sl.Head; p != NULL; p = p->Next)
		showSNode(p);
}
//============================================================
bool insertTail(SList &sl, SNode *p)
{
	if (p == NULL)
		return false;
	if (isEmpty(sl) == true)
		sl.Head = sl.Tail = p;
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return true;
}
//============================================================
void createSlist_Auto(SList &sl)
{
	int n;
	ItemType x;
	SNode *p;
	initSList(sl);
	printf("Ban hay cho biet so phan so can tao: ");
	scanf("%d", &n);
	srand((unsigned)time(NULL));
	for (int i = 1; i <= n; i++)
	{
		x.tuSo = rand() % 100;
		int temp = (rand() % 100);
		x.mauSo = temp == 0 ? 1 : temp;
		p = createSNode(x);
		showSNode(p);
		// showSNode(p);
		insertTail(sl, p);
	}
}
//============================================================
float psNN(SList &sl)
{
	SNode *p = sl.Head;
	float min = p->Info.tuSo / p->Info.mauSo;
	while (p != NULL)
	{
		if (min > p->Info.tuSo * 1.0 / p->Info.mauSo)
		{
			min = p->Info.tuSo * 1.0 / p->Info.mauSo;
		}
		p = p->Next;
	}
	return min;
}
float psLN(SList &sl)
{
	SNode *p = sl.Head;
	float max = p->Info.tuSo / p->Info.mauSo;
	while (p != NULL)
	{
		if (max < p->Info.tuSo * 1.0 / p->Info.mauSo)
		{
			max = p->Info.tuSo * 1.0 / p->Info.mauSo;
		}
		p = p->Next;
	}
	return max;
}
//============================================================
void xuatPSLonHon1(SList &sl)
{
	SNode *p = sl.Head;
	while (p != NULL)
	{
		if (p->Info.tuSo * 1.0 / p->Info.mauSo > 1)
		{
			printf("%4d/%d", p->Info.tuSo, p->Info.mauSo);
		}
		p = p->Next;
	}
}
//============================================================
int timUCLN(int a, int b)
{
	if (a % b != 0)
		return timUCLN(b, a % b);
	else
		return b;
}
//============================================================
void rutGon(SList &sl)
{
	SNode *p = sl.Head;
	while (p != NULL)
	{
		p->Info.tuSo = p->Info.tuSo / timUCLN(p->Info.tuSo, p->Info.mauSo);
		p->Info.mauSo = p->Info.mauSo / timUCLN(p->Info.mauSo, p->Info.tuSo);
		if (p->Info.mauSo != 1)
		{
			if (p->Info.mauSo < 0)
			{
				p->Info.mauSo = p->Info.mauSo * -1;
				p->Info.tuSo = p->Info.tuSo * -1;
			}
			printf("%4d/%d", p->Info.tuSo, p->Info.mauSo);
		}
		else
		{
			printf("%4d", p->Info.tuSo);
		}
		p = p->Next;
	}
}
//============================================================
// SNode *findSNode(SList sl, ItemType x)
// {
// 	SNode *p = sl.Head;
// 	while (p != NULL)
// 	{
// 		if (p->Info == x)
// 			return p;
// 		p = p->Next;
// 	}
// 	return NULL;
// }
//============================================================
void menu()
{
	printf("\n----------------------------------------------------\n");
	printf("1.Tao danh sach lien ket phan so\n");
	printf("2.Tim phan so lon nhat , nho nhat trong danh sach\n");
	printf("3.Liet ke phan so lon hon 1 trong danh sach\n");
	printf("4.Rut gon phan so\n");
	// printf("5.Tim phan so\n");
	printf("----------------------------------------------------\n");
}
//============================================================
int main()
{
	SList SL;
	PhanSo x;
	int luachon;
	do
	{
		menu();
		printf("Nhap lua chon cua ban : ");
		scanf("%d", &luachon);
		switch (luachon)
		{
		case 0:
			printf("Thoat chuong trinh\n");
		case 1:
			createSlist_Auto(SL);
			break;
		case 2:
			printf("\nPhan so nho nhat trong mang %.2f", psNN(SL));
			printf("\nPhan so lon nhat trong mang %.2f", psLN(SL));
			break;
		case 3:
			xuatPSLonHon1(SL);
			break;
		case 4:
			rutGon(SL);
			break;
		// case 5:
		// 	printf("Nhap phan so can tim : ");
		// 	scanf("%d", &x);
		// 	break;
		}
	} while (luachon != 0);
}