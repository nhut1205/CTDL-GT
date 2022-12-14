#include "BaiHat.h"
#ifndef BaiHat_h
#define BaiHat_h
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <string.h>
//==========================================================
struct SNode
{
    ItemType Info;
    SNode *Next;
};
SNode *createSNode(ItemType x);
void showSNode(SNode *p);
void luuTTBaiHat(FILE *fo, ItemType x);
void docTTBaiHat(FILE *fi, ItemType &x);
void xuatTTBaiHat(ItemType X);
//==========================================================
// Single Linked Slist|||||||||||||||||||||||||||||||||||||||
//==========================================================
struct SList
{
    SNode *Head;
    SNode *Tail;
};
//==========================================================
void docDuLieu(SList &sl, char fileName[]);
void luuDuLieu(SList sl, char fileName[]);
//==========================================================
void initSList(SList &sl);            // Khoi tao danh sach sl rong
bool isEmpty(SList sl);               // kiem tra ds sl co rong hay k?
bool insertHead(SList &sl, SNode *p); // them node p vao dau ds!
bool insertTail(SList &sl, SNode *p);
int tongThoiLuongList(SList &sl , SNode *p);
SNode *findSNode(SList sl, ItemType x); // Tim mot Node chua x
void showSList(SList sl);
//==========================================================
//Các hàm delete
//==========================================================
bool deleteHead(SList &sl);
bool deleteAfter(SList &sl,SNode *q, ItemType x);
bool delteX(SList &sl, ItemType x);
#endif