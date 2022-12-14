#include "Stack_DoiCoSo.h"
//============================================================
void menu()
{
	printf("\n----------------------------------------------------------");
	printf("\n1.Tao stack");
	printf("\n2.Hien thi stack vua tao");
	printf("\n3.Chuyen doi co so");
	printf("\n------------------------------------------------------\n");
}
//============================================================
void process()
{
	Stack S;
	initStack(S);
	ItemType n , a , luachon;
	do
	{
		menu();
		printf("Vui long nhap lua chon cua ban : ");
		scanf("%d", &luachon);
		switch (luachon)
		{
		case 1:
        printf("Tao stack ngau nhien : ");
        createSlist_Auto(S);
        showlStack(S);
			break;
		case 2:
        showlStack(S);
			break;
		case 3:
        printf("Nhap gia tri n : ");
        scanf("%d",&n);
        printf("Nhap he so a : ");
        scanf("%d",&a);
        stack_DoiCoSo(n,a);
        break;
        // case 4:
        // getTop(S,x);
		// 	break;
		}
	} while (luachon != 0);
}

int main()
{
	process();
	getch();
	return 0;
}