#include "DSLKD_BaiHat.h"
//==========================================================
SNode *createSNode(ItemType x)
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
//==========================================================
void initSList(SList &sl)
{
    sl.Head = NULL;
    sl.Tail = NULL;
}
//==========================================================
bool isEmpty(SList sl) // Tạo danh sách trống
{
    return (sl.Head == NULL);
    /*if (sl.Head == NULL)
    return true;
    else
    return false;*/
}
//==========================================================
void showSNode(SNode *p)
{
    xuatTTBaiHat(p->Info);
}
//==========================================================
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
//==========================================================
bool insertHead(SList &sl, SNode *p)
{
	p->Next = sl.Head;
	sl.Head = p;
	return true;
}
//==========================================================
void docTTBaiHat(FILE *fi, ItemType &x)
{
    fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%d\n", &x.tenBH, &x.tenTG, &x.tenCS, &x.thoiGian);
}
//==========================================================
void docDuLieu(SList &sl, char fileName[])
{
    //đọc dữ liệu file text
    FILE *fi = fopen(fileName, "rt");
    if (!fi)
    {
        printf("loi khong doc duoc file");
        return;
    }
    int n;
    fscanf(fi, "%d\n", &n);
    ItemType x;
    SNode *p;
    initSList(sl);
    for (int i = 1; i <= n; i++)
    {
        docTTBaiHat(fi, x);
        p = createSNode(x);
        insertTail(sl, p);
    }
    fclose(fi);
}
//==========================================================
void luuTTBaiHat(FILE *fo, ItemType x)
{
    fprintf(fo, "%-30s%-30s%-30s%3ds(%dp%ds)", x.tenBH, x.tenTG, x.tenCS,x.thoiGian, x.thoiGian/60,x.thoiGian%60);
}
//==========================================================
void luuDuLieu(SList sl, char fileName[])
{
    // Duyệt và lưu nội dung danh sách sl
    FILE *fo = fopen(fileName, "wt");
    if (!fo)
    {
        printf("Loi in file text");
        return;
    }
    if (isEmpty(sl))
    {
        printf("Danh sach rong!");
        return;
    }
    fprintf(fo, "Danh sach bai hat\n");
    fprintf(fo, "%-5s%-30s%-30s%-30s%10s", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SI", "THOI LUONG");
    int i = 1;
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        fprintf(fo, "\n%-5d", i++);
        luuTTBaiHat(fo, p->Info);
    }
    fclose(fo);
}
//==========================================================

//==========================================================
void showSList(SList sl)
{
    if (isEmpty(sl))
    {
        printf("danh sach rong!");
        return;
    }
    printf("danh sach bai hat \n");
    printf("%-5s%-30s%-30s%-30s%10s", "STT", "TEN BAI HAT", "TEN TAC GIA", "TEN CA SI", "THOI LUONG");
    int i = 1;
    for (SNode *p = sl.Head; p != NULL; p = p->Next)
    {
        printf("\n%-5d", i++);
        showSNode(p);
    }
}
//==========================================================
void xuatTTBaiHat(ItemType X)
{
    printf("%-30s%-30s%-30s%3ds(%dp%ds)",X.tenBH,X.tenTG,X.tenCS,X.thoiGian,X.thoiGian/60,X.thoiGian%60);
}
//==========================================================
void nhapTTBaiHat(ItemType &X)
{
    printf("Nhap thong tin bai hat moi\n");
    printf("Nhap ten bai hat\n");
    fflush(stdin);
    gets(X.tenBH);
    fflush(stdin);
    printf("Nhap ten tac gia\n");
    gets(X.tenTG);
    fflush(stdin);
    printf("Nhap ten ca si\n");
    gets(X.tenCS);
    fflush(stdin);
    printf("Nhap thoi luong bai hat\n");
    scanf("%d",&X.thoiGian);
}
//==========================================================
int tongThoiLuongList(SList &sl , SNode *p)
{
    int tong = 0;
    for(p = sl.Head ;p != NULL ; p = p->Next)
    {
        tong+=p->Info.thoiGian;
    }
    return tong;
}
//==========================================================
bool deleteHead(SList &sl)
{
	// xoa p snode o dau danh sach sl
	if (isEmpty(sl) == true)
		return false;
	SNode *p = sl.Head;
	sl.Head = sl.Head->Next;
	if (sl.Head == NULL)
		sl.Tail = NULL;
	delete p; // xoa node khoi danh sach
	return true;
}
//==========================================================
bool deleteAfter(SList &sl, SNode *q, ItemType x)
{
	if (q == NULL || q->Next == NULL)
		return false;
	SNode *p = q->Next;
	q->Next = p->Next;
	if (sl.Tail == p)
		sl.Tail = q;
	x = p->Info;
	delete p;
	return 1;
}
//==========================================================
bool delteX(SList &sl, ItemType x)
{
	if (isEmpty(sl) == true)
		return false;
	// tim phan tu p co khoa bang x va q la phan tu ke truoc p
	SNode *p = sl.Head;
	SNode *q = NULL;
	while (p->Info.tenBH != NULL && p->Info.tenBH != x.tenBH)
	{
		q = p;
		p = p->Next;
	}
	if (p == NULL)
	{
		return false;
	}
	if (p == sl.Head)
		deleteHead(sl);
	else
		deleteAfter(sl, q, x);
	return true;
}
//==========================================================
// SNode *findSNode(SList sl, ItemType x)
// {
// 	SNode *p = sl.Head;
// 	while (p != NULL)
// 	{
// 		if (p->Info =x)
// 			return p;
// 		p = p->Next;
// 	}
// 	return NULL;
// }