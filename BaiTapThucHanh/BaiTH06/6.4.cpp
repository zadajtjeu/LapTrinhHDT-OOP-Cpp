#include <bits/stdc++.h>

using namespace std;

class THUCPHAM
{
protected:
	string tenTP;
	long giaca;
};

class TPHOP : private THUCPHAM
{
	int sohop, lop;
public:
	void Nhap()
	{
		cout<<" - Nhap ten thuc pham: ";
		getline(cin,tenTP);
		cout<<" - Nhap gia ca: ";
		cin>>giaca;
		cout<<" - Nhap so hop: ";
		cin>>sohop;
		cout<<" - Nhap lop: ";
		cin>>lop;
		cin.ignore();
	}
	void Xuat()
	{
		cout<<" - Ten thuc pham: "<<tenTP<<endl;
		cout<<" - Gia ca: "<<giaca<<endl;
		cout<<" - So hop: "<<sohop<<endl;
		cout<<" - Lop: "<<lop<<endl;
	}
	
};

class TPKHOP : private THUCPHAM
{
	double khoiluong;
public:
	void Nhap()
	{
		cout<<" - Nhap ten thuc pham: ";
		getline(cin,tenTP);
		cout<<" - Nhap gia ca: ";
		cin>>giaca;
		cout<<" - Nhap khoi luong: ";
		cin>>khoiluong;
		cin.ignore();
	}
	void Xuat()
	{
		cout<<" - Ten thuc pham: "<<tenTP<<endl;
		cout<<" - Gia ca: "<<giaca<<endl;
		cout<<" - Khoi luong: "<<khoiluong<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	TPHOP hop; TPKHOP khop;
	cout<<"* Nhap thong tin thuc pham hop: "<<endl;
	hop.Nhap();
	cout<<"* Nhap thong tin thuc pham khong hop: "<<endl;
	khop.Nhap();
	
	cout<<"* Thuc pham hop: "<<endl;
	hop.Xuat();
	cout<<"* Thuc pham khong hop: "<<endl;
	khop.Xuat();
	
	return 0;
}