//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
////============================================================
//// Khai bao du lieu
////============================================================
//typedef int ItemType;
//struct SNode
//{
//	ItemType Info;
//	SNode *Next;
//};
////============================================================
//// SNode
////============================================================
//SNode *createSNode(ItemType x);
//void showSNode(SNode *p);
////============================================================
//// Single Link List
////============================================================
//struct SList
//{
//	SNode *Head;
//	SNode *Tail;
//};
////============================================================
//void initSList(SList &sl);							 // Khoi tao danh sach sl rong
//bool isEmpty(SList sl);								 // kiem tra ds sl co rong hay k?
//bool insertHead(SList &sl, SNode *p);				 // them node p vao dau ds!
//bool insertTail(SList &sl, SNode *p);				 // thêm node p vào cuối danh sach
//bool insertBefore(SList &sl, SNode *q, SNode *p);	 // Them node p vao truoc q trong danh sach s1
//bool insertAfter(SList &sl, SNode *q, SNode *p);	 // Them node p vao sau q trong danh sach s1
//SNode *findSNode(SList sl, ItemType x);				 // Tim mot Node chua x
//void showSList(SList sl);							 // duyet va xem noi dung cua ds sl
//void createSlist_Auto(SList &sl);					 // tao danh sach sl ngau nhien
//void split_SList(SList &sl, SList &slc, SList &sll); // tách mảng ra làm mảng chẳn và mảng lẻ
//void sapXep(SList &sl);
//int demNT(SList &sl); //đếm số lượng số nguyên tố có trong mảng
////============================================================
//
//SNode *createSNode(ItemType x)
//{
//	SNode *p = new SNode;
//	if (p == NULL) // Nếu dữ liệu trống
//	{
//		printf("Khong du bo nho de cap phat node");
//		getch();
//		return NULL;
//	}
//	p->Info = x;
//	p->Next = NULL;
//	return p;
//}
//void showSNode(SNode *p)
//{
//	printf("%4d", p->Info); // Hiển thị SNode
//}
////============================================================
//void initSList(SList &sl)
//{
//	sl.Head = NULL;
//	sl.Tail = NULL;
//}
////============================================================
//bool isEmpty(SList sl) // Tạo danh sách trống
//{
//	return (sl.Head == NULL);
//	/*if (sl.Head == NULL)
//		return true;
//	else
//		return false;*/
//}
////============================================================
//bool insertHead(SList &sl, SNode *p)
//{
//	p->Next = sl.Head;
//	sl.Head = p;
//	return true;
//}
////============================================================
//void showSList(SList sl)
//{
//	if (isEmpty(sl))
//	{
//		printf("Danh sach rong!");
//		return;
//	}
//	printf(" Noi dung cua danh sach la: ");
//	for (SNode *p = sl.Head; p != NULL; p = p->Next)
//		showSNode(p);
//}
////============================================================
//void createSlist_Auto(SList &sl)
//{
//	int n;
//	ItemType x;
//	SNode *p;
//	initSList(sl);
//	printf("Ban hay cho biet so node can tao: ");
//	scanf("%d", &n);
//	srand((unsigned)time(NULL));
//	for (int i = 1; i <= n; i++)
//	{
//		x = rand() % 199 - 100;
//		p = createSNode(x);
//		// showSNode(p);
//		insertHead(sl, p);
//	}
//}
////============================================================
//SNode *findSNode(SList sl, ItemType x)
//{
//	SNode *p = sl.Head;
//	while (p != NULL)
//	{
//		if (p->Info == x)
//			return p;
//		p = p->Next;
//	}
//	return NULL;
//}
////============================================================
//bool insertTail(SList &sl, SNode *p)
//{
//	if (p == NULL)
//		return false;
//	if (isEmpty(sl) == true)
//		sl.Head = sl.Tail = p;
//	else
//	{
//		sl.Tail->Next = p;
//		sl.Tail = p;
//	}
//	return true;
//}
////============================================================
//bool insertBefore(SList &sl, SNode *q, SNode *p)
//{
//	if (p == NULL || q == NULL)
//		return false;
//	if (q == sl.Head)
//	{
//		insertHead(sl, p);
//		return true;
//	}
//	SNode *r = sl.Head;
//	while (r->Next != q)
//	{
//		r = r->Next;
//	}
//	p->Next = q;
//	r->Next = p;
//	return true;
//}
////============================================================
//bool insertAfter(SList &sl, SNode *q, SNode *p)
//{
//	if (p == NULL || q == NULL)
//		return false;
//	p->Next = q->Next;
//	q->Next = p;
//	if (sl.Tail == q)
//		sl.Tail = p;
//	return true;
//}
////============================================================
//void split_SList(SList &sl, SList &slc, SList &sll)
//{					// Tao 2 danh sach con slc : chua chan va sll : chua so le
//	initSList(slc); // tạo danh sách trống số chẵn
//	initSList(sll); // tạo danh sách trống số lẻ
//	SNode *p = sl.Head;
//	while (p != NULL)
//	{
//		if (p->Info % 2 == 0) // nếu chia hết cho 2 đưa vào mảng số chẵn
//			insertTail(slc, p);
//		else
//			insertTail(sll, p); // ngược lại đưa vào mảng số lẻ
//		p = p->Next;
//	}
//}
////============================================================
//bool IsPrime(int n) // Kiểm tra số nguyên tố
//{
//	if (n < 2)						   // Nếu số đó bé hơn 2
//		return false;				   // Trả về sai
//	for (int i = 2; i <= sqrt(n); i++) // Vòng lập từ 2 -> căn bậc 2 của số đó
//	{
//		if (n % i == 0) // Nếu chia hết trong khoảng đó
//		{
//			return false; // trả về sai vì không là số nguyên tố
//		}
//	}
//	return true; // ngược lại trả về đúng
//}
////============================================================
//int demPTuSNT(SList &sl) //đếm số phần tử số nguyên tố
//{
//	int dem = 0;		// khởi tạo biến đếm bằng 0
//	SNode *p = sl.Head; // khai báo snode từ vị trí đầu
//	while (p != NULL)	// vòng lập đến khi khác null
//	{
//		if (IsPrime(p->Info) == true) //đúng đều kiện số nguyên tố tăng đếm lên 1
//		{
//			dem++;
//		}
//		p = p->Next; // chạy đến snode tiếp theo
//	}
//	return dem; // trả về số lượng đếm
//}
////============================================================
//void swap(ItemType x, ItemType y) // hàm đổi chỗ 2 số
//{
//	ItemType temp = x;
//	x = y;
//	y = temp;
//}
////============================================================
//// void xepTang(SList &sl)
//// {
//// 	if (isEmpty(sl) == 1 || sl.Head == sl.Tail)
//// 		return;
//// 	SNode *q;
//// 	SNode *min;
//// 	for (SNode *p = sl.Head; p != sl.Tail; p = p->Next)
//// 	{
//// 		min = p;
//// 		for (q = p->Next; q != NULL; q = q->Next)
//// 			if (min->Info > q->Info)
//// 				min = q;
//// 		if (min != p)
//// 			swap(min->Info, p->Info); // Hoán vị
//// 	}
//// 	showSList(p);
//// }
////============================================================
//void xepGiam(SList &sl)
//{
//}
////============================================================
//bool scp(int n)
//{
//	int sqr = sqrt(n);
//	return (sqr * sqr == n);
//}
////============================================================
//int tongSCP(SList &sl)
//{
//	ItemType tong;
//	SNode *p = sl.Head;
//	while (p != NULL)
//	{
//		if (p->Info == scp(p->Info))
//		{
//			tong += p->Info;
//		}
//		p = p->Next;
//	}
//	return tong;
//}
////============================================================
//int timMin(SList &sl)
//{
//	int min;
//	SNode *p = sl.Head;
//	min = p->Info;
//	while (p != NULL)
//	{
//		if (min > p->Info)
//		{
//			min = p->Info;
//		}
//		p = p->Next;
//	}
//	return min;
//}
////============================================================
//int timMax(SList &sl)
//{
//	int max;
//	SNode *p = sl.Head;
//	max = p->Info;
//	while (p != NULL)
//	{
//		if (max < p->Info)
//		{
//			max = p->Info;
//		}
//		p = p->Next;
//	}
//	return max;
//}
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
//	printf("\n------------------------------------------------------\n");
//}
////============================================================
//void process()
//{
//	SNode *Q;
//	SNode *P;
//	bool kq;
//	SList SL;
//	initSList(SL);
//	SList SL1, SL2;
//	ItemType K, X, Y, luachon;
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
//		default:
//			printf("Thoat chuong trinh");
//			break;
//		}
//	} while (luachon != 0);
//}
////============================================================
//int main()
//{
//	process();
//	getch();
//	return 0;
//}