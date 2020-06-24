#include <iostream>
#include <string.h>
using namespace std;
class NSX
{
	string maNSX, tenNSX, dcNSX;
public:
	void NHAP();
	void XUAT();
	
};

class HANG
{
	string maHang, tenHang;
	NSX x;
public:
	void NHAP();
	void XUAT();
	
	
};

void NSX::NHAP()
{
	cout<<"Nhap ma nha san xuat: ";
	getline(cin,maNSX);
	cout<<"Nhap ten nha san xuat: ";
	getline(cin, tenNSX);
	cout<<"Nhap dia chi nha san xuat: ";
	getline(cin, dcNSX);
}
void NSX::XUAT()
{
	cout<<"Ma NSX: "<<maNSX<<endl;
	cout<<"Ten NSX: "<<tenNSX<<endl;
	cout<<"Dia chi NSX: "<<dcNSX<<endl; 
}

void HANG::NHAP()
{
	cout<<"Nhap ma hang: ";
	getline(cin, maHang);
	cout<<"Ten hang: ";
	getline(cin, tenHang);
	x.NHAP();
}

void HANG::XUAT()
{
	cout<<"Ma hang: "<<maHang<<endl;
	cout<<"Ten hang: "<<tenHang<<endl;
	x.XUAT();
}

int main(int argc, char const *argv[])
{
	HANG a;
	a.NHAP();
	a.XUAT();
	return 0;
}

/* test key
MH001
Khau trang y te 2 lop
NSX001
Cong ty TNHH Binh Minh
Bac Ninh
*/