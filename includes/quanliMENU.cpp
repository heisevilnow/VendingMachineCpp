#include<iostream>
#include<string>		// cho chuỗi
#include<iomanip>		// cho setw()
#include<windows.h>		// cho Sleep()
#include <conio.h>
#include "quanliMENU.h"
MENU quanliMENU::THEM_MENU(string tenMon, int gia, int sl)
{
	MENU menu;
	menu.set_GIA(gia);
	menu.set_TENMON(tenMon);
	menu.set_TONKHO(sl);
	return menu;
}
MENU quanliMENU::NHAP_INFO_LOAI_NUOC(string tenmon)
{
	int gia;
	cout << "NHAP GIA: ";
	cin >> gia;
	int sl;
	cout << "NHAP SO LUONG: ";
	cin >> sl;
	return THEM_MENU(tenmon, gia, sl);
}
void quanliMENU::THEM_1_LOAI_NUOC(MENU listmenu[], int& n, int vt, MENU& x)
{
	for (int i = n - 1; i >= vt; i--)
	{
		listmenu[i + 1] = listmenu[i];
	}
	listmenu[vt] = x;
	n++;
}
void quanliMENU::XOA_1_LOAI_NUOC(MENU listmenu[], int& n, int vt) {
	for (int i = vt + 1; i < n; i++)
	{
		listmenu[i - 1] = listmenu[i];
	}
	n--;
}
void quanliMENU::XUAT_MENU(MENU listmenu[], int n) {
	cout << "---------------------------------------------------------" << endl;
	cout << "\t\t\tMENU" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << setw(5) << "STT" << setw(18) << "TENMON" << setw(17) << "GIA" << setw(17) << "TONKHO" << endl;
	for (int i = 0; i < n - 1; i++)
	{
		cout << setw(5) << i + 1 << setw(18) << listmenu[i].get_TENMON() << setw(17) << listmenu[i].get_GIA() << setw(16) << listmenu[i].get_TONKHO() << endl;
	}
	cout << "---------------------------------------------------------" << endl;
}
void quanliMENU::CAPNHAT_SL(class MENU listmenu[], int n, int N)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		if (i + 1 == N)
		{
			cout << "---------------------------------------------------------" << endl;
			cout << "==> MOI BAN CAP NHAT SO LUONG " << listmenu[i].get_TENMON() << ": ";
			int key;
			cin >> key;
			listmenu[i].set_TONKHO(key);
			cout << "WATIING..." << endl;
			Sleep(1000);
			cout << "DA CAP NHAT THANH CONG :D.";
			Sleep(1000);
			system("cls");
		}
	}
}
void quanliMENU::XINCHAO()
{
	cout << "		" << "XIN CHAO ADMIN." << endl;
}



