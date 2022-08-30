#ifndef __MENU__
#define __MENU__
#include<iostream>
#include <string>
using namespace std;

class MENU
{
protected:			//encapsulation.
	string TENMON;
	int GIA;
	int TONKHO;
public:
	MENU()			//constructor.
	{
		TENMON = "NULL";
		GIA = 0;
		TONKHO = 0;
	}
	virtual void XINCHAO();
	void NHAP_SO(MENU listmenu[], int n, int N);
	int TINH_TIEN(MENU listmenu[], int n, int N, int TIEN);
	void GIAM_SL_SP(class MENU listmenu[], int n, int N);
	int get_GIA(void);
	int get_TONKHO(void);
	string get_TENMON(void);
	void set_GIA(int gia);
	void set_TONKHO(int sl);
	void set_TENMON(string tenmon);
};

#endif

