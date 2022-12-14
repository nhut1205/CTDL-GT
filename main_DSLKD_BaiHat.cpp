#include "DSLKD_BaiHat.h"
#define fileName_In "dsBaiHat_In.txt"
#define fileName_Out "dsBaiHat_Out.txt"
void showMenu()
{
    printf("\n----------------------------------------\n");
    printf("0.Thoat chuong trinh\n");
    printf("1.Load danh sach bai hat\n");
    printf("2.Hien thi danh sach");
    printf("\n3.Them 1 bai hat vao danh sach\n");
    printf("4.Tong thoi gian de nghe het bai hat\n");
    printf("5.Xoa mot bai hat khoi danh sach\n");
    printf("6.Tim bai hat co trong danh sach khong\n");
    printf("7.Sap xep bai hat(theo bang chu cai) theo ten bai hat\n");
    printf("8.Sap xep bai hat theo thu tu giam dan\n");
    printf("9.Doi vi tri cua bai hat\n");
    printf("----------------------------------------");
}

void process()
{
    int luachon;
    SList SL;
    initSList(SL);
    ItemType X, Y;
    SNode *P, *Q;
    do
    {
        showMenu();
        printf("\nNhap lua chon cua ban : ");
        scanf("%d", &luachon);
        switch (luachon)
        {
        case 0:
            break;
        case 1:
            docDuLieu(SL, fileName_In);
            showSList(SL);
            luuDuLieu(SL, fileName_Out);
            break;
        case 2:
            showSList(SL);
            break;
        case 3:
            int luachon2;
            printf("1.Them vao dau danh sach\n");
            printf("2.Them vao cuoi danh sach\n");
            scanf("%d", &luachon2);
            switch (luachon2)
            {
            case 1:
                nhapTTBaiHat(X);
                P = createSNode(X);
                insertTail(SL, P);
                luuDuLieu(SL, fileName_Out);
                showSList(SL);
                break;
            case 2:
                nhapTTBaiHat(X);
                P = createSNode(X);
                insertHead(SL, P);
                luuDuLieu(SL, fileName_Out);
                showSList(SL);
                break;
            }
            break;
        case 4:
            printf("Tong thoi gian de chay het list nhac : %ds(%dp%ds)", tongThoiLuongList(SL, P), tongThoiLuongList(SL, P) / 60, tongThoiLuongList(SL, P) % 60);
            break;
        case 5:
            printf("Nhap gia tri ban muon xoa trong danh sach: ");
            fflush(stdin);
            scanf("%s", &X);
            if (delteX(SL, X) == false)
            {
                printf("Khong ton tai %s trong danh sach", X.tenBH);
            }
            else
            {
                printf("\nNoi dung danh sach sau khi xoa so %s la : ", X.tenBH);
                showSList(SL);
            }
            break;
        case 6:
            printf("Them 1 bai hta \n");
            fflush(stdin);
            nhapTTBaiHat(X);
            P = createSNode(X);
            insertTail(SL, P);
            luuDuLieu(SL, fileName_Out);
            showSList(SL);
            // case 6:
            // printf("Nhap bai hat ban muon tim trong danh sach\n");
            // gets(X.tenBH);
            // if (strcmp(findSNode(SL,X),X.tenBH) == 1)
            // {
            //     printf("khong ton tai bai hat trong danh sach\n");
            // }
            // else
            // {
            //     showSList(SL);
            // }
        }
    } while (luachon != 0);
}

int main()
{
    process();
    getch();
    return 0;
}