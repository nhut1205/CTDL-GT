/*
Họ và tên : Pham PhạmMinh Nhựt
MSSV : 2001216012
MônHoc : THCTDLGT
ST4
*/
#ifndef TuDien_h
#define TuDien_h
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//==========================================================
//Khai bao du lieu
//==========================================================
struct TuDien
{
	char word[51], mean[51];
};
typedef TuDien ItemType;
//==========================================================
void nhapTTTuDien(ItemType &X);
void xuatTTTuDien(ItemType X);
//==========================================================
#endif