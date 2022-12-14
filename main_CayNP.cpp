#include "CayNP.h"
void menu()
{
	printf("\n----------------------------------------------------------");
	printf("\n1.Tao cay");
	printf("\n2.Hien thi cay vua tao");
}
//============================================================
void process()
{
	ItemType x;
	BTNode *P, *Q;
	BTree bt;
	initBTree(bt);
	int luachon;
	do
	{
		menu();
		printf("\nVui long nhap lua chon cua ban : ");
		scanf("%d", &luachon);
		switch (luachon)
		{
		case 1:
			printf("Tao danh sach lien ket ngau nhien: ");
			CreateBTree_Automatic(bt);
			printf("Danh sach vua duoc tao\n");
			NLR(bt.Root);
			break;
		case 2:
			printf("Noi dung cua cay NLR : ");
			NLR(bt.Root);
			printf("\nNoi dung cua cay RLN");
			NRL(bt.Root);
		default:
			printf("\nThoat chuong trinh");
			break;
		}
	} while (luachon != 0);
}
//============================================================
int main()
{
	process();
	getch();
	return 0;
}