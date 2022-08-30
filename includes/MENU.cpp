#include <iostream>
#include <string>		// cho chuỗi
#include <cstdlib>
#include <conio.h>
#include "MENU.h"

void MENU::XINCHAO()
{
	cout << "XIN CHAO." << endl;
}
int MENU::get_GIA(void) {
	return GIA;
}
int MENU::get_TONKHO(void) {
	return TONKHO;
}
string MENU::get_TENMON(void) {
	return TENMON;
}
void MENU::set_GIA(int gia) {
	GIA = gia;
}
void MENU::set_TONKHO(int sl) {
	TONKHO = sl;
}
void MENU::set_TENMON(string tenmon) {
	TENMON = tenmon;
}
// HÀM CHỌN NƯỚC MÀ BẠN MUỐN.
void MENU::NHAP_SO(class MENU listmenu[], int n, int N)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 == N)
		{
			cout << "---------------------------------------------------------" << endl;
			cout << "==> BAN CHON " << listmenu[i].TENMON << endl;
		}
	}
}
// HÀM TÍNH TIỀN
int MENU::TINH_TIEN(class MENU listmenu[], int n, int N, int TIEN)
{
	int TRATIEN = 0;

	for (int i = 0; i < n; i++)
	{
		if (i + 1 == N)
		{
			TRATIEN = TIEN - listmenu[i].GIA;
			break;
		}
	}
	return TRATIEN;
}
void MENU::GIAM_SL_SP(class MENU listmenu[], int n, int N)
{
	listmenu[N - 1].TONKHO--;
}