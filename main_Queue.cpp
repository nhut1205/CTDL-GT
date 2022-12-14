#include "Queue.h"
void showMenu()
{
    printf("\n----------------------------------------\n");
    printf("0.Thoat chuong trinh\n");
    printf("1.Tao hang doi\n");
    printf("2.Hien thi hang doi");
    printf("\n3.Them 1 so vao hang doi\n");
    printf("4.Xoa so trong hang doi\n");
    printf("----------------------------------------");
}

void process()
{
    int luachon;
    Queue SL;
    initSList(SL);
    ItemType X, Y;
    QNode *P, *Q;
    initSList(SL);
    do
    {
        showMenu();
        printf("\nNhap lua chon cua ban : ");
        scanf_s("%d", &luachon);
        switch (luachon)
        {
        case 1:
            printf("Tao danh sach lien ket ngau nhien: ");
            createSlist_Auto(SL);
            break;
        case 2:
            showSList(SL);
            break;
        case 3:
        {
            int x;
            printf("Nhap gia tri muon them vao : ");
            scanf_s("%d", &x);
            P = createSNode(x);
            bool kq = insert(SL, P);
            if (kq == true)
            {
                showSList(SL);
            }
            else
            {
                printf("Khong the thuc hien");
            }
        }
        break;
        case 4:
            if (remove(SL) == false)
                printf("Khong the xoa so cuoi torng danh sach!");
            else
            {
                printf("Danh sach sau khi xoa cuoi : ");
                showSList(SL);
            }
            break;
        case 5:
            ShowQueue(SL);
            break;
            case 6:
           if (Head(SL,P->Info) == false)
           {
            printf("danh sach rong");
           }
           else
           ShowQueue(SL);
        }
    } while (luachon != 0);
}

int main()
{
    process();
    _getch();
    return 0;
}