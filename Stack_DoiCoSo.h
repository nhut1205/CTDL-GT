#ifndef Stack_DoiCoSo_h
#define Stack_DoiCoSo_h
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
typedef int ItemType;
struct StackNode
{
    ItemType Info;
    StackNode *Next;
}; 
StackNode *createStack(ItemType x);
//==========================================================
//Single Linked Slist|||||||||||||||||||||||||||||||||||||||
//==========================================================
struct Stack
{
    StackNode *Top;
};
void showStack(StackNode *s);
//==========================================================
void initStack(Stack &s);							 // Khoi tao danh sach s rong
bool isEmpty(Stack s);								 // kiem tra ds s co rong hay k?
bool push(Stack &s, StackNode *p);				 // them node p vao dau ds!
bool pop(Stack &s,ItemType &x);				 
bool getTop(Stack s , ItemType &x);
void showlStack(Stack s);							 // duyet va xem noi dung cua ds s
void createSlist_Auto(Stack &s);					 // tao danh sach s ngau nhien
void stack_DoiCoSo(int n, int a);
//==========================================================
#endif