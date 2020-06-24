#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class NSX
{
	string maNSX, tenNSX, dcNSX;
	friend class HANG;
};

class HANG
{
private:
	string maHang, tenHang;
	long donGia;
	double trongLuong;
	NSX x;
public:
	void Nhap()
	{
		cout<<" - Nhap ma hang: ";
		getline(cin, maHang);
		cout<<" - Nhap ten hang: ";
		getline(cin, tenHang);
		cout<<" - Nhap don gia: ";
		cin>>donGia;
		cout<<" - Nhap trong luong: ";
		cin>>trongLuong;
		cin.ignore();
		cout<<" - Nhap ma nha san xuat: ";
		getline(cin, x.maNSX);
		cout<<" - Nhap ten nha san xuat: ";
		getline(cin, x.tenNSX);
		cout<<" - Nhap dia chi nha san xuat: ";
		getline(cin, x.dcNSX);
	}
	void Xuat()
	{
		cout<<"* Ma hang: "<<maHang<<endl;
		cout<<"* Ten hang: "<<tenHang<<endl;
		cout<<"* Don gia: "<<donGia<<endl;
		cout<<"* Trong luong: "<<trongLuong<<endl;
		cout<<"* Ma nha san xuat: "<<x.maNSX<<endl;
		cout<<"* Ten nha san xuat: "<<x.tenNSX<<endl;
		cout<<"* Dia chi nha san xuat: "<<x.dcNSX<<endl;
	}

};

int main(int argc, char const *argv[])
{
	HANG mathang;
	mathang.Nhap();
	cout<<endl;
	cout<<"============= Thong tin mat hang =============";
	cout<<endl;

	mathang.Xuat();
	return 0;
}

/* Test case
MH01
De men phuu lu ky
45000
0.5
NSX01
Kim Dong
Ha Noi
*/
