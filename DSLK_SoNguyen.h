//#ifndef DSLK_SoNguyen_h
//#define DSLK_SoNguyen_h
//#include <stdio.h>
//#include <conio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>
//typedef int ItemType;
//struct SNode
//{
//    ItemType Info;
//    SNode *Next;
//}; 
//SNode *createSNode(ItemType x);
//void showSNode(SNode *p);
////==========================================================
////Single Linked Slist|||||||||||||||||||||||||||||||||||||||
////==========================================================
//struct SList
//{
//    SNode *Head;
//    SNode *Tail;
//};
////==========================================================
//void initSList(SList &sl);							 // Khoi tao danh sach sl rong
//bool isEmpty(SList sl);								 // kiem tra ds sl co rong hay k?
//bool insertHead(SList &sl, SNode *p);				 // them node p vao dau ds!
//bool insertTail(SList &sl, SNode *p);				 // thêm node p vào cuối danh sach
//bool insertBefore(SList &sl, SNode *q, SNode *p);	 // Them node p vao truoc q trong danh sach s1
//bool insertAfter(SList &sl, SNode *q, SNode *p);	 // Them node p vao sau q trong danh sach s1
//SNode *findSNode(SList sl, ItemType x);				 // Tim mot Node chua x
//void showSList(SList sl);							 // duyet va xem noi dung cua ds sl
//void createSlist_Auto(SList &sl);					 // tao danh sach sl ngau nhien
//void split_SList(SList &sl, SList &slc, SList &sll); // tách mảng ra làm mảng chẳn và mảng lẻ
//void sapXep(SList &sl);
//int demNT(SList &sl); //đếm số lượng số nguyên tố có trong mảng
//bool delteX(SList &sl, ItemType x);
//bool deleteAfter(SList &sl, SNode *q, ItemType x);
//bool deleteXSauQ(SList &sl, SNode *q, SNode *p);
//bool deleteTail(SList &sl);
//bool deleteHead(SList &sl);
//int timMax(SList &sl);
//int timMin(SList &sl);
//int demPTuSNT(SList &sl); //đếm số phần tử số nguyên tố
//int tongSCP(SList &sl);
////==========================================================
//#endif