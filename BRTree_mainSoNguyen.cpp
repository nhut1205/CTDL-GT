//#include "BRTree_SoNguyen.h"
//void menu()
//{
//	printf("\n1.Show cay\n");
//	printf("|--------------------------------------------------|");
//	printf("\n2.Duyet cay theo chieu rong(NLR)\n");
//	printf("3.Hien thi cap cua cay theo chieu ngang\n");
//	printf("4.In theo tu tu cap(BFT)\n");
//	printf("5.Xoa 1 nut\n");
//	printf("6.Them 1 nut vao danh sach\n");
//	printf("7.Kiem tra nut co ton tai trong danh sach khong\n");
//	printf("8.Dem so nut do va so nut den trong cay\n");
//	printf("9.Tong cua nut do va tong cua nut den trong cay\n");
//	printf("|--------------------------------------------------|");
//}
//void process()
//{
//	int luachon;
//	BRTree brtree;
//	initBRTree(brtree);
//	ItemType a[] = { 4, 7, 12, 15, 3, 5, 14, 18, 16, 17 };
//	int n = 10;
//	do
//	{
//	menu();
//	printf_s("\n---------------Nhap lua chon cua ban---------------");
//	scanf_s("%d", &luachon);
//	switch (luachon)
//	{
//	case 1:
//		createBRTreeFromArray(brtree, a, n);
//		printf("\nOutput: NLR\n");
//		break;
//	case 2:
//		showBRTree_InOrder(brtree.Root);
//		//printf("\nOutput: Duyet theo chieu rong (Breadth-first traverse) \n");
//		break;
//	case 3:
//		showLevelOrder(brtree.Root);
//		//printf("\nOutput: Duyet theo chieu sau Pre-Order (Depth-first traverse) \n");
//		break;
//	case 4:
//		showPreOrder(brtree.Root);
//		break;
//	case 5:
//	{
//			  int x;
//			  printf("Nhap so ban muon xoa : ");
//			  scanf_s("%d", &x);
//			  deleteByInfo(brtree.Root, x);
//			  showLevelOrder(brtree.Root);
//			  printf("\n-------------------------------------");
//	}
//		break;
//	case 6:
//	{
//			  int x;
//			  printf("Nhap so ban muon them vao : ");
//			  scanf_s("%d", &x);
//			  insert(brtree.Root, x);
//			  showLevelOrder(brtree.Root);
//	}
//		break;
//	case 7:
//	{
//			  int x;
//			  printf("Nhap vao nut can tim : ");
//			  scanf("%d", &x);
//			  if (search(brtree.Root, x) != NULL)
//				  printf("Tim thay %d trong cay", x);
//			  else
//				  printf("Khong tim thay %d trong cay",x);
//	}
//	}
//	} while (luachon != 0);
//	printf("\nChuong trinh nay duoc cai dat boi: TVTho-FIT-HUFI.");
//}
//
//int main()
//{
//	process();
//	return 0;
//	_getch();
//}
