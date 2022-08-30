#include<iostream>
#include"MENU.h"
class quanliMENU : public MENU {	//inheritance pulic

public:
	MENU THEM_MENU(string tenMon, int gia, int sl);
	MENU NHAP_INFO_LOAI_NUOC(string tenmon);
	void THEM_1_LOAI_NUOC(MENU listmenu[], int& n, int vt, MENU& x);
	void XOA_1_LOAI_NUOC(MENU listmenu[], int& n, int vt);
	void XUAT_MENU(MENU listmenu[], int n);
	void CAPNHAT_SL(class MENU listmenu[], int n, int N);
	void XINCHAO();
};
