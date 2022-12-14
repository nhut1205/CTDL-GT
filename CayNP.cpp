//============================================
#include "CayNP.h"
BTNode *CreateTNode(ItemType x)
{
    BTNode *p = new BTNode;
    if (p == NULL)
    {
        printf("\nKhong du bo nho de cap phat nut moi!");
        getch();
        return NULL;
    }
    p->Info = x;
    p->Left = NULL;
    p->Right = NULL;
    return p;
}
//============================================
void initBTree(BTree &bt)
{ 
    bt.Root = NULL;
}
//============================================
void showBTNode(BTNode *p)
{
    printf("%4d", p->Info);
}

bool InsertBTNodeLeft(BTNode *&T, BTNode *p)
{
    if (T == NULL || p == NULL)
        return false; // Thực hiện không thành công
    if (T->Left != NULL)
        return false; //Đã tồn tại nút con trái của T
    T->Left = p;
    return true; // Thực hiện thành công
}

bool InsertBTNodeRight(BTNode *&T, BTNode *p)
{
    if (T == NULL || p == NULL)
        return false; // Thực hiện không thành công
    if (T->Right != NULL)
        return false; //Đã tồn tại nút con phải của T
    T->Right = p;
    return true; // Thực hiện thành công
}

bool InsertBTNode(BTNode *&root, BTNode *p)
{
    if (p == NULL)
        return false; // Thực hiện không thành công
    if (root == NULL) // Cây rỗng, nên thêm vào gốc
    {
        root = p;
        return true; // Thực hiện thành công
    }
    if (root->Info == p->Info)
        return false;
    if (p->Info < root->Info)
        InsertBTNode(root->Left, p); // Them ben trai
    else
        InsertBTNode(root->Right, p); // Them ben phai
    return true;                      // Thực hiện thành công
}

void CreateBTree_Automatic(BTree &bt)
{
    int n;
    ItemType x;
    printf("Cho biet so nut cua cay: ");
    scanf("%d", &n);
    initBTree(bt);
    srand((unsigned)time(NULL)); // Tạo số mới sau mỗi lần thực hiện
    for (int i = 1; i <= n; i++)
    {
        x = (rand() % 199) - 99; // Tạo 1 số ngẫu nhiên trong [-99, 99]
        BTNode *p = CreateTNode(x);
        InsertBTNode(bt.Root, p);
    }
}
void NLR(BTNode *root)
{
    if (root == NULL)
        return;
    showBTNode(root);
    NLR(root->Left);
    NLR(root->Right);
}

void NRL(BTNode *root)
{
    if (root == NULL)
        return;
    showBTNode(root);
    NRL(root->Right);
    NRL(root->Left);    
}

void LNR(BTNode *root)
{
    if (root == NULL)
        return;
    LNR(root->Left);
    printf("%4d", root->Info);
    LNR(root->Right);
}

void LRN(BTNode *root)
{
    if (root == NULL)
        return;
    LRN(root->Left);
    LRN(root->Right);
    printf("%4d", root->Info);
}

BTNode *FindTNode(BTNode *root, ItemType x)
{
    if (root == NULL)
        return NULL;
    if (root->Info == x)
        return root; // tìm được khóa thì dừng
    else if (root->Info > x)
        FindTNode(root->Left, x); // tìm x bên nhánh trái
    else
        FindTNode(root->Right, x); // tìm x bên nhánh phải
}
