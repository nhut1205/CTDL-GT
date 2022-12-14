//#include "DSLK_SoNguyen.h"
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
//	return true;
//	else
//	return false;*/
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
//	return 1;
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
//	if (n < 2)					// Nếu số đó bé hơn 2
//		return false;			// Trả về sai
//	for (int i = 2; i < n; i++) // Vòng lập từ 2 -> căn bậc 2 của số đó
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
////{
////	if (isEmpty(sl) == 1 || sl.Head == sl.Tail)
////		return;
////	SNode *q;
////	SNode *min;
////	for (SNode *p = sl.Head; p != sl.Tail; p = p->Next)
////	{
////		min = p;
////		for (q = p->Next; q != NULL; q = q->Next)
////		if (min->Info > q->Info)
////			min = q;
////		if (min != p)
////			swap(min->Info, p->Info); // Hoán vị
////	}
////	showSList(p);
////}
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
//bool deleteHead(SList &sl)
//{
//	// xoa p snode o dau danh sach sl
//	if (isEmpty(sl) == true)
//		return false;
//	SNode *p = sl.Head;
//	sl.Head = sl.Head->Next;
//	if (sl.Head == NULL)
//		sl.Tail = NULL;
//	delete p; // xoa node khoi danh sach
//	return true;
//}
////============================================================
//bool deleteTail(SList &sl)
//{
//	if (isEmpty(sl) == true)
//		return false;
//	SNode *q = sl.Head;
//	SNode *p = sl.Tail;
//	if (p == q)
//		sl.Head = sl.Tail = NULL;
//	else
//	{
//		while (q->Next != p)
//			q = q->Next;
//		sl.Tail = q;
//		sl.Tail->Next = NULL;
//	}
//	delete p;
//	return true;
//}
////============================================================
//bool deleteXSauQ(SList &sl, SNode *q, SNode *p)
//{
//	if (q == NULL || q->Next == NULL)
//		return false;
//	else
//	{
//		p = q->Next;
//		q->Next = p->Next;
//		if (p == sl.Tail)
//			sl.Tail = q;
//		delete p;
//	}
//	return true;
//}
////============================================================
//bool deleteAfter(SList &sl, SNode *q, ItemType x)
//{
//	if (q == NULL || q->Next == NULL)
//		return false;
//	SNode *p = q->Next;
//	q->Next = p->Next;
//	if (sl.Tail == p)
//		sl.Tail = q;
//	x = p->Info;
//	delete p;
//	return 1;
//}
////============================================================
//bool delteX(SList &sl, ItemType x)
//{
//	if (isEmpty(sl) == true)
//		return false;
//	// tim phan tu p co khoa bang x va q la phan tu ke truoc p
//	SNode *p = sl.Head;
//	SNode *q = NULL;
//	while (p != NULL && p->Info != x)
//	{
//		q = p;
//		p = p->Next;
//	}
//	if (p == NULL)
//	{
//		return false;
//	}
//	if (p == sl.Head)
//		deleteHead(sl);
//	else
//		deleteAfter(sl, q, x);
//	return true;
//}