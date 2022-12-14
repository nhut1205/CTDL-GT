#ifndef DSLK_SoNguyen_h
#define DSLK_SoNguyen_h
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
typedef int ItemType;
struct QNode
{
    ItemType Info;
    QNode *Next;
}; 
QNode *createSNode(ItemType x);
void showQNode(QNode *p);
//==========================================================
//Single Linked Slist|||||||||||||||||||||||||||||||||||||||
//==========================================================
struct Queue
{
    QNode *Head;
    QNode *Tail;
};
//==========================================================
void initSList(Queue &qu);							 // Khoi tao danh sach qu rong
bool isEmpty(Queue qu);								 // kiem tra ds qu co rong hay k?
bool insert(Queue &qu, QNode *p);				 // them node p vao dau ds!
void showSList(Queue qu);							 // duyet va xem noi dung cua ds qu
void createSlist_Auto(Queue &qu);					 // tao danh sach qu ngau nhien
bool remove(Queue &qu);                          // xóa phần tử trong queue
bool Head(Queue q, ItemType &x);
bool Tail(Queue q, ItemType &x);
void ShowQueue(Queue q);
//==========================================================
#endif