#include "CayNPTK.h"
void menu()
{
	printf("\n----------------------------------------------------------");
	printf("\n|1.Tao cay ngau nhien                                      |");
	printf("\n|2. Tao cay from array                                     |");
	printf("\n|3.Hien thi cay                                            |");
	printf("\n|4.So nut la cua cay                                       |");
	printf("\n|5.Xoa x trong cay                                         |");
	printf("\n|6.Xoa toan bo cay                                         |");
	printf("\n|7.Duyet cay theo chieu sau                                |");
	printf("\n|8.Duyet cay theo chieu rong                               |");
	printf("\n-----------------------------------------------------------");
}
//============================================================
void process()
{
	ItemType A[] = { 45, 20, 35, 84, 21, 10, 67, 89, 72, 98, 16, 38, 30, 5, 63 };
	int n = 15;
	ItemType x;
	BSTNode* P, *Q;
	BTree bt;
	initBSTree(bt);
	int luachon;
	do
	{
		menu();
		printf("\nVui long nhap lua chon cua ban : ");
		scanf_s("%d", &luachon);
		switch (luachon)
		{
		case 1:
			printf("Tao danh sach lien ket ngau nhien: ");
			CreateBTree_Automatic(bt);
			printf("Danh sach vua duoc tao\n");
			NLR(bt.Root);
			break;
		case 2:
			CreateBTree_FromArray(bt, A, n);
			printf("Noi dung cua cay NLR : ");
			NLR(bt.Root);
			break;
		case 3:
			printf("Hien thi cay NLR : ");
			NLR(bt.Root);
			printf("\nHien thi cay NRL : ");
			NRL(bt.Root);
			break;
		case 4:
			printf("So nut la cua cay : %d", countNodeLeaf(bt.Root));
			break;
		case 5:
			printf("Nhap x can xoa : ");
			scanf_s("%d", &x);
			if (deleteXFromTree(bt.Root, x) == false)
				printf("Khong tim thay x trong cay");
			else
				printf("Cay sau khi xoa %d : ", x);
			NLR(bt.Root);
		case 6:
			break;
		case 7:
			printf("Duyet cay theo chieu sau : ");
			traverseTree_Depth_NLR(bt.Root);
			break;
		case 8:
			printf("Duyet cay theo chieu rong : ");
			traverseTree_Breath_NLR(bt.Root);
			break;
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
	_getch();
	return 0;
}