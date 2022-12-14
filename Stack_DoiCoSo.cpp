#include "Stack_DoiCoSo.h"

StackNode *createStack(ItemType x)
{
    StackNode *p = new StackNode;
    if (p == NULL) // Nếu dữ liệu trống
    {
        printf("Khong du bo nho de cap phat stack");
        getch();
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}
//============================================================
void showStack(StackNode *s)
{
    printf("%4d", s->Info); // Hiển thị SNode
}
//============================================================
void initStack(Stack &s)
{
    s.Top = NULL;
}
//============================================================
bool isEmpty(Stack s) // Tạo danh sách trống
{
    // Hàm kiểm tra stack có rỗng hay không
    if (s.Top == NULL)
        return true;
    return false;
}
//============================================================
void showlStack(Stack s)
{
    if (isEmpty(s))
    {
        printf("Stack rong!");
        return;
    }
    printf(" Noi dung cua stack la: ");
    for (StackNode *p = s.Top; p != NULL; p = p->Next)
        showStack(p);
}
//============================================================
bool push(Stack &s, StackNode *p)
{
    if (p == NULL)
        return false;
    if (isEmpty(s) == true)
        s.Top = p;
    else
    {
        p->Next = s.Top;
        s.Top = p;
    }
    return true;
}
//============================================================
bool pop(Stack &s, ItemType &x)
{
    if (isEmpty(s) == true)
    {

        return false; // thực hiện không thành công
    }
    else
    {
        StackNode *p = s.Top;
        s.Top = s.Top->Next;
        x = p->Info;
        delete p;
    }
    return true;
}
//============================================================
void createSlist_Auto(Stack &s)
{
    int n;
    ItemType x;
    StackNode *p;
    initStack(s);
    printf("Ban hay cho biet so node can tao: ");
    scanf("%d", &n);
    srand((unsigned)time(NULL));
    for (int i = 1; i <= n; i++)
    {
        x = rand() % 199 - 100;
        p = createStack(x);
        showStack(p);
        push(s, p);
    }
}
//============================================================
void xuat(int x)
{
    if (x < 10)
    {
        printf("%d", x);
    }
    else
    {
        switch (x)
        {
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        }
    }
}
//============================================================
void stack_DoiCoSo(int n, int a)
{
    ItemType x, temp = n;
    StackNode *p;
    Stack s;
    initStack(s);
    while (n > 0)
    {
        x = n % a;
        n /= a;
        p = createStack(x);
        push(s, p);
    }
    printf("\nKet qua %d tu he 10 sang he %d : ", temp, a);
    while (1)
    {
        if (pop(s, x) == true)
        {
            xuat(x);
        }
        else
            break;
    }
}
//============================================================
