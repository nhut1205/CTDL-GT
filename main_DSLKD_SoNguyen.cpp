//#include "DSLKD_SoNguyen.cpp"
////============================================================
//void menu()
//{
//	printf("\n----------------------------------------------------------");
//	printf("\n1.Tao danh sach lien ket");
//	printf("\n2.Hien thi danh sach vua tao");
//	printf("\n3.Them so vao dau danh sach");
//	printf("\n4.Them so vao cuoi danh sach");
//	printf("\n5.Them vao so ke truoc");
//	printf("\n6.Them vao so ke sau");
//	printf("\n7.Phan mang thanh so chan va so le");
//	printf("\n8.Sap xep tang dan ,giam dan"); // chua lam
//	printf("\n9.Dem xem co bao nhieu so nguyen to");
//	printf("\n10.Tong cac so chinh phuong");
//	printf("\n11.Tim phan tu lon nhat , nho nhat");
//	printf("\n12.Co bao nhieu phan tu lon hon gap doi phan tu sau no"); // chua lam
//	printf("\n13.Xoa so dau danh sach");
//	printf("\n14.Xoa cuoi danh sach");
//	printf("\n15.Xoa mot nut sau nut q trong danh sach");
//	printf("\n16.Xoa nut co gia tri X trong danh sach");
//	printf("\n------------------------------------------------------\n");
//}
////============================================================
//void process()
//{
//	SNode *Q;
//	SNode *P;
//	bool kq;
//	SList SL;
//	SList SL1, SL2;
//	initSList(SL);
//	ItemType K, X, Y, Z, luachon;
//	do
//	{
//		menu();
//		printf("Vui long nhap lua chon cua ban : ");
//		scanf("%d", &luachon);
//		switch (luachon)
//		{
//		case 1:
//			printf("Tao danh sach lien ket ngau nhien: ");
//			createSlist_Auto(SL);
//			printf("Danh sach vua duoc tao\n");
//			showSList(SL);
//			break;
//		case 2:
//			showSList(SL);
//			break;
//		case 3:
//			printf("Nhap gia tri muon them vao : ");
//			scanf("%d", &K);
//			P = createSNode(K);
//			insertHead(SL, P);
//			showSList(SL);
//			break;
//		case 4:
//			printf("Nhap gia tri muon them vao : ");
//			scanf("%d", &K);
//			P = createSNode(K);
//			insertTail(SL, P);
//			showSList(SL);
//			break;
//		case 5:
//			printf("\nHay nhap gia tri ban muon them vao: ");
//			scanf("%d", &X);
//			printf("\nBan hay cho biet gia tri so ke sau: ");
//			scanf("%d", &Y);
//			Q = findSNode(SL, Y);
//			if (Q == NULL)
//			{
//				printf("Khong ton tai nut %d tai danh sach", Y);
//				break;
//			}
//			P = createSNode(X);
//			kq = insertBefore(SL, Q, P);
//			if (kq == false)
//			{
//				printf("Khong the them gia tri %d vao danh sach", X);
//			}
//			else
//			{
//				printf("\nNoi dung danh sach sau khi them %d vao truoc %d la : ", X, Y);
//				showSList(SL);
//			}
//			break;
//		case 6:
//			printf("\nHay nhap gia tri ban muon them vao: ");
//			scanf("%d", &X);
//			printf("\nBan hay cho biet gia tri so ke truoc: ");
//			scanf("%d", &Y);
//			Q = findSNode(SL, Y);
//			if (Q == NULL)
//			{
//				printf("Khong ton tai nut %d tai danh sach", Y);
//				break;
//			}
//			P = createSNode(X);
//			kq = insertAfter(SL, Q, P);
//			if (kq == false)
//			{
//				printf("Khong the them gia tri %d vao danh sach", X);
//			}
//			else
//			{
//				printf("\nNoi dung danh sach sau khi them %d vao sau %d la : ", X, Y);
//				showSList(SL);
//			}
//			break;
//		case 7:
//			split_SList(SL, SL1, SL2);
//			printf("Mang so chan : ");
//			showSList(SL1);
//			printf("\nMang so le : ");
//			showSList(SL2);
//			break;
//		case 8:
//			// xepTang(SL);
//			break;
//		case 9:
//			printf("So luong so nguyen to trong danh sach lien ket : %d", demPTuSNT(SL));
//			break;
//		case 10:
//			printf("\nTong cac so chinh phuong trong danh sach lien ket : %d", tongSCP(SL));
//		case 11:
//			printf("Phan tu nho nhat trong danh sach lien ket : %d\n", timMin(SL));
//			printf("Phan tu lon nhat trong danh sach lien ket : %d", timMax(SL));
//			break;
//		case 12:
//			break;
//		case 13:
//			if (deleteHead(SL) == false)
//				printf("Khong the xoa so dau trong danh sach!");
//			else
//			{
//				printf("Danh sach sau khi xoa dau : ");
//				showSList(SL);
//			}
//			break;
//		case 14:
//			if (deleteTail(SL) == false)
//				printf("Khong the xoa so cuoi torng danh sach!");
//			else
//			{
//				printf("Danh sach sau khi xoa cuoi : ");
//				showSList(SL);
//			}
//			break;
//		case 15:
//			printf("\nBan hay cho biet gia tri so ke sau: ");
//			scanf("%d", &Y);
//			Q = findSNode(SL, Y);
//			if (Q == NULL)
//			{
//				printf("Khong ton tai nut %d tai danh sach", Y);
//				break;
//			}
//			P = createSNode(Y);
//			if (deleteXSauQ(SL, Q, P) == false)
//			{
//				printf("Khong the xoa so %d trong danh sach", Y);
//			}
//			else
//			{
//				printf("\nNoi dung danh sach sau khi xoa so sau so %d la : ", Y);
//				showSList(SL);
//			}
//			break;
//		case 16:
//			printf("Nhap gia tri ban muon xoa trong danh sach: ");
//			scanf("%d", &X);
//			if (delteX(SL, X) == false)
//			{
//				printf("Khong ton tai %d trong danh sach", X);
//			}
//			else
//			{
//				printf("\nNoi dung danh sach sau khi xoa so %d la : ", X);
//				showSList(SL);
//			}
//		}
//	} while (luachon != 0);
//}
//
//int main()
//{
//	process();
//	getch();
//	return 0;
//}