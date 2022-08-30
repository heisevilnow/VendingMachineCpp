#include <iostream>
#include <string>		// cho chuỗi
#include <iomanip>		// cho setw()
#include <windows.h>		// cho Sleep()
#include <cstdlib>
#include <time.h>
#include <fstream>		// cho ĐỌC FILE
#include <conio.h>
#include "includes/MENU_BANHANG.h"
#include "includes/quanliMENU.h"

using namespace std;
void gotoxy(int x, int y)						//su dung toa do cho cac doi tuong.
{
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x; // Starts from 0
	dwPos.Y = y; // Starts from 0
	SetConsoleCursorPosition(hCon, dwPos);
}
void TextColor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;

	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
// HÀM IN WELCOME
void WELCOME()
{
	int x = 30;
	int y = 8;
	for (int i = 0; i < 10; i++) {
		TextColor(i);
		Sleep(500);
		gotoxy(x, y);     cout << " _ _ _ _____ __    _____ _____ _____ _____ ";
		gotoxy(x, y + 1); cout << "| | | |   __|  |  |     |     |     |   __|";
		gotoxy(x, y + 2); cout << "| | | |   __|  |__|   --|  |  | | | |   __|";
		gotoxy(x, y + 3); cout << "|_____|_____|_____|_____|_____|_|_|_|_____|";
	}
	TextColor(7);
	Sleep(500);
	system("cls");
	gotoxy(x, y);		cout << "*******************************" << endl;
	gotoxy(x, y + 1);	cout << "*************     *************" << endl;
	gotoxy(x, y + 2);	cout << "********               ********" << endl;
	gotoxy(x, y + 3);	cout << "******                    *****" << endl;
	gotoxy(x, y + 4);	cout << "****       0       0       ****" << endl;
	gotoxy(x, y + 5);	cout << "***                         ***" << endl;
	gotoxy(x, y + 6);	cout << "***                         ***" << endl;
	gotoxy(x, y + 7);	cout << "***                         ***" << endl;
	gotoxy(x, y + 8);	cout << "****        --------       ****" << endl;
	gotoxy(x, y + 9);	cout << "*****      '.      .'     *****" << endl;
	gotoxy(x, y + 10); cout << "*******      '....'     *******" << endl;
	gotoxy(x, y + 11); cout << "*********             *********" << endl;
	gotoxy(x, y + 12); cout << "*************     *************" << endl;
	gotoxy(x, y + 13); cout << "*******************************";

	Sleep(500);
	system("cls");
	gotoxy(x, y);	 cout << "*******************************" << endl;
	gotoxy(x, y + 1); cout << "*************     *************" << endl;
	gotoxy(x, y + 2); cout << "********               ********" << endl;
	gotoxy(x, y + 3); cout << "******                    *****" << endl;
	gotoxy(x, y + 4); cout << "****       >       <       ****" << endl;
	gotoxy(x, y + 5); cout << "***                         ***" << endl;
	gotoxy(x, y + 6); cout << "***                         ***" << endl;
	gotoxy(x, y + 7); cout << "***                         ***" << endl;
	gotoxy(x, y + 8); cout << "****        --------       ****" << endl;
	gotoxy(x, y + 9); cout << "*****      '.      .'     *****" << endl;
	gotoxy(x, y + 10); cout << "*******      '....'     *******" << endl;
	gotoxy(x, y + 11); cout << "*********             *********" << endl;
	gotoxy(x, y + 12); cout << "*************     *************" << endl;
	gotoxy(x, y + 13); cout << "*******************************";
	Sleep(500);
	system("cls");
}
void TILTE_VENDING()
{
	cout << R"(
 .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .-----------------. .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| | ____   ____  | || |  _________   | || | ____  _____  | || |  ________    | || |     _____    | || | ____  _____  | || |    ______    | |
| ||_  _| |_  _| | || | |_   ___  |  | || ||_   \|_   _| | || | |_   ___ `.  | || |    |_   _|   | || ||_   \|_   _| | || |  .' ___  |   | |
| |  \ \   / /   | || |   | |_  \_|  | || |  |   \ | |   | || |   | |   `. \ | || |      | |     | || |  |   \ | |   | || | / .'   \_|   | |
| |   \ \ / /    | || |   |  _|  _   | || |  | |\ \| |   | || |   | |    | | | || |      | |     | || |  | |\ \| |   | || | | |    ____  | |
| |    \ ' /     | || |  _| |___/ |  | || | _| |_\   |_  | || |  _| |___.' / | || |     _| |_    | || | _| |_\   |_  | || | \ `.___]  _| | |
| |     \_/      | || | |_________|  | || ||_____|\____| | || | |________.'  | || |    |_____|   | || ||_____|\____| | || |  `._____.'   | |
| |              | || |              | || |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' )"<<endl;
}
void GHI_FILE(ofstream& fileout, MENU listmenu[], int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		fileout << listmenu[i].get_TENMON() << "," << listmenu[i].get_GIA() << " " << listmenu[i].get_TONKHO();
		dem++;
		if (dem < n)
		{
			fileout << "\n";
		}
	}
}
//HÀM ĐỌC THÔNG TIN 1 MENU TỪ FILE
void DOC_FILE_DRINK(ifstream& filein, MENU& drink)
{
	string tenmon;
	getline(filein, tenmon, ',');
	drink.set_TENMON(tenmon);
	int gia;
	filein >> gia;
	drink.set_GIA(gia);
	int sl;
	filein >> sl;
	drink.set_TONKHO(sl);
}
//HÀM ĐỌC MENU TỪ FILE VÀ LƯU VÀO TRONG listmenu
void DOC_FILE(ifstream& filein, MENU listmenu[], int& n, int vt, quanliMENU menu)
{
	while (filein.eof() == false)
	{
		MENU drink;		// KHAI BÁO 1 MENU drink ĐỂ LƯU DỮ LIỆU ĐỌC TỪ FILE VỀ
		DOC_FILE_DRINK(filein, drink);
		string tam;
		getline(filein, tam);		// xuong dong
		menu.THEM_1_LOAI_NUOC(listmenu, n, vt, drink);
		vt++;
	}
}
int l;
string password = "12345678";
int main()
{
	typedef MENU Menu;
	typedef MENU_BANHANG Menu_BanHang;
	Menu_BanHang menu_banhang;
	typedef quanliMENU QuanLi_Menu;
	QuanLi_Menu qlmenu;
	Menu* menu;
	Menu listmenu[100];
	int n = 0;
	int vt = 0;
	Sleep(2000);
	ifstream filein;
	filein.open(".\\DRINK.txt", ios_base::in);		// MỞ FILE RA VÀ ĐỌC
	DOC_FILE(filein, listmenu, n, vt, qlmenu);
	filein.close();
	int dem = 0;
	int k;
	int s = 0;
	int N;
	WELCOME();
	do
	{
		TextColor(27);
		TILTE_VENDING();
		TextColor(3);
		gotoxy(65, 14); cout << "1.MENU" << endl;
		TextColor(4);
		gotoxy(65, 15); cout << "2.QUANLI" << endl;
		TextColor(26);
		gotoxy(65, 16); cout << "3.THOAT" << endl;
		TextColor(7);
		gotoxy(43, 17); cout << "----------------------------------------------------------" << endl;
		gotoxy(59, 18); cout << "MOI BAN CHON CHE DO: ";
		int key;
		cin >> key;
		system("cls");
		switch (key) {
		case 1: {
			menu = &menu_banhang;
			TextColor(3);
			menu->XINCHAO();
			TextColor(7);
			Sleep(1000);
			qlmenu.XUAT_MENU(listmenu, n);
			cout << "DUA TIEN VAO TRUOC(>=10000): ";
			int time = 0;
			while (true)
			{
				if (!_kbhit())
				{
					Sleep(7);
					time++;
					if (time == 700)
					{
						system("cls");
						WELCOME();
						k = 5;
						break;
					}
				}
				if (_kbhit())
				{
					int TIEN;
					cin >> TIEN;
					if (TIEN < 10000) {
						system("cls");
						break;
					}
					else
					{
						cout << "==> BAN DUA " << TIEN << "VND" << endl;
						cout << "---------------------------------------------------------" << endl;
						cout << "MOI BAN NHAP SO: ";
						cin >> N;
						qlmenu.NHAP_SO(listmenu, n, N);
						do
						{
							for (int i = 0; i < n; i++)
							{
								if (i + 1 == N)
								{
									if (TIEN >= listmenu[i].get_GIA())
									{
										l = 1;
										break;
									}
									else
									{
										cout << "---------------------------------------------------------" << endl;
										cout << "BAN KHONG DU TIEN" << endl;
										cout << "MOI BAN NHAP LAI SO: ";
										cin >> N;
										qlmenu.NHAP_SO(listmenu, n, N);
										l = -2;
									}

								}
							}
						} while (l < 0);
						int TRA = qlmenu.TINH_TIEN(listmenu, n, N, TIEN);
						qlmenu.GIAM_SL_SP(listmenu, n, N);
						system("cls");
						qlmenu.XUAT_MENU(listmenu, n);
						cout << "---------------------------------------------------------" << endl;
						cout << "TIEN DU CUA BAN LA: " << TRA << " VND" << endl;
						cout << "---------------------------------------------------------" << endl;
						do
						{
							if (TRA < 10000) {
								cout << "BAN KHONG DU TIEN DE MUA";
								s = -2;
							}
							else {
								cout << "BAN CO MUON MUA THEM (Y/N)?: ";
								char muathem;
								cin >> muathem;
								cout << "---------------------------------------------------------" << endl;
								if (muathem == 'Y') {
									s = 2;
									cout << "MOI BAN NHAP SO: ";
									cin >> N;
									qlmenu.NHAP_SO(listmenu, n, N);
									cout << "---------------------------------------------------------" << endl;
									qlmenu.GIAM_SL_SP(listmenu, n, N);
									system("cls");
									qlmenu.XUAT_MENU(listmenu, n);
									cout << "TIEN DU CUA BAN LA: " << qlmenu.TINH_TIEN(listmenu, n, N, TRA) << " VND" << endl;
									TRA = qlmenu.TINH_TIEN(listmenu, n, N, TRA);
									if (TRA == 0) {
										s = -2;
										break;
									}
									cout << "---------------------------------------------------------" << endl;
								}
								else if (muathem == 'N')
									s = -2;
							}
						} while (s > 0);
						cout << "\t\t\tFINISH." << endl;
						cout << "---------------------------------------------------------";
						ofstream fileout;
						fileout.open("..\\DRINK.txt", ios_base::out);
						GHI_FILE(fileout, listmenu, n);
						Sleep(5000);
						system("cls");
						WELCOME();
						break;
					}
				}
			}
			break;
		}
		case 2:
		{
			bool error = 0;
			string pw;
			do
			{
				cout << "VUI LONG NHAP MAT KHAU: ";
				cin.ignore();
				getline(cin, pw);
				if (pw == password) {
					error = 0;
				}
				else {
					error = 1;
				}
			} while (error == 1);

			menu = &qlmenu;
			TextColor(4);
			menu->XINCHAO();
			TextColor(3);
			cout << "1.THEM" << endl;
			TextColor(26);
			cout << "2.XOA" << endl;
			TextColor(29);
			cout << "3.CAP NHAT SO LUONG" << endl;
			TextColor(23);
			cout << "4.DOI MAT KHAU" << endl;
			TextColor(7);
			cout << "\t\tMOI BAN CHON CHE DO" << endl;
			cout << "---------------------------------------------------------" << endl;
			int banchon;
			cin >> banchon;
			switch (banchon) {
			case 1:
			{
				qlmenu.XUAT_MENU(listmenu, n);
				cout << "THEM 1 LOAI NUOC MA BAN MUON" << endl;
				string tenmon;
				cin.ignore();
				cout << "NHAP TEN NUOC: ";
				int time = 0;
				while (true)
				{
					if (!_kbhit())
					{
						Sleep(7);
						time++;
						if (time == 700)
						{
							system("cls");
							WELCOME();
							break;
						}
					}
					if (_kbhit())
					{
						getline(cin, tenmon);
						MENU menuThem = qlmenu.NHAP_INFO_LOAI_NUOC(tenmon);
						int vt;
						cout << "NHAP VI TRI BAN MUON THEM: ";
						cin >> vt;
						cout << "WAITING...";
						Sleep(1000);
						system("cls");
						qlmenu.THEM_1_LOAI_NUOC(listmenu, n, vt, menuThem);
						ofstream fileout;
						fileout.open(".\\DRINK.txt", ios_base::out);
						GHI_FILE(fileout, listmenu, n);
						TextColor(13);
						cout << "\t  MENU SAU KHI THEM 1 LOAI NUOC MOI" << endl;
						TextColor(7);
						qlmenu.XUAT_MENU(listmenu, n);
						Sleep(4000);
						system("cls");
						cin.ignore();
						break;
					}
				}
				break;
			}
			case 2:
			{
				qlmenu.XUAT_MENU(listmenu, n);
				cout << "XOA 1 LOAI NUOC MA BAN MUON" << endl;
				int vitri;
				cout << "NHAP VI TRI MUON XOA: ";
				int time = 0;
				while (true)
				{
					if (!_kbhit())
					{
						Sleep(7);
						time++;
						if (time == 700)
						{
							system("cls");
							WELCOME();

							break;
						}
					}
					if (_kbhit())
					{
						cin >> vitri;
						cout << "WAITING...";
						Sleep(1000);
						system("cls");
						qlmenu.XOA_1_LOAI_NUOC(listmenu, n, vitri);
						ofstream fileout;
						fileout.open(".\\DRINK.txt", ios_base::out);
						GHI_FILE(fileout, listmenu, n);
						TextColor(13);
						cout << "\t\tMENU SAU KHI XOA" << endl;
						TextColor(7);
						qlmenu.XUAT_MENU(listmenu, n);
						Sleep(4000);
						system("cls");
						cin.ignore();
						break;
					}
				}
				break;
			}
			case 3:
			{
				qlmenu.XUAT_MENU(listmenu, n);
				cout << "MOI BAN NHAP SO: ";
				cin >> N;
				qlmenu.CAPNHAT_SL(listmenu, n, N);
				ofstream fileout;
				fileout.open(".\\DRINK.txt", ios_base::out);
				GHI_FILE(fileout, listmenu, n);
				cin.ignore();
				break;
			}
			case 4:
			{
				bool compare = 0;
				do
				{
					cin.ignore();
					cout << "NHAP MAT KHAU MOI" << endl;
					cin.ignore();
					getline(cin, password);
					string tam;
					cout << "NHAP LAI MAT KHAU MOI" << endl;
					cin.ignore();
					getline(cin, tam);
					if (tam == password) {
						cout << "DOI MAT KHAU THANH CONG" << endl;
						compare = 1;

						system("cls");
					}
					else {
						cout << "DOI MAT KHAU THAT BAI" << endl;
						compare = 0;
					}
				} while (compare==0);
				break;
			}
			}
			break;
		}
		case 3:
		{
			cout << "END.\n";
			dem = -1;
			break;
		}
		}
		dem++;
	} while (dem > 0);
	system("pause");
	return 0;
}
