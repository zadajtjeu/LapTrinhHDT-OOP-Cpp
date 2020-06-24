#include <bits/stdc++.h>

using namespace std;

class QUANLY
{
	char maQL[10], hoTen[50];
public:
	void Nhap()
	{
		cout<<" - Nhap ma nguoi quan ly: ";
		fflush(stdin);
		gets(maQL);
		cout<<" - Nhap ten nguoi quan ly: ";
		gets(hoTen);
	}
	void Xuat()
	{
		cout<<" * Ma quan ly: "<<maQL<<endl;
		cout<<" * Ten quan ly: "<<hoTen<<endl;
	}
};

class MAY
{
	char maMay[10], kieuMay[20], tinhTrang[20];
public:
	void Nhap()
	{
		cout<<" - Nhap ma may: ";
		fflush(stdin);
		gets(maMay);
		cout<<" - Nhap kieu may: ";
		gets(kieuMay);
		cout<<" - Nhap tinh trang may: ";
		gets(tinhTrang);
	}
	void Xuat()
	{
		cout<<setw(10)<<maMay<<setw(20)<<kieuMay<<setw(20)<<tinhTrang<<endl;
	}
};

class PHONGMAY
{
	char maPhong[10], tenPhong[20];
	double dienTich;
	QUANLY x;
	MAY *y;
	int n;
public:
	void Nhap();
	void Xuat();
};


void PHONGMAY::Nhap()
{
	cout<<" - Nhap ma phong may: ";
	fflush(stdin);
	gets(maPhong);
	cout<<" - Nhap ten phong may: ";
	gets(tenPhong);
	cout<<" - Nhap dien tich phong (m2): ";
	cin>>dienTich;
	x.Nhap(); // thong tin quan ly
	cout<<" - Nhap so luong may: ";
	cin>>n;
	y = new MAY[n];
	cout<<"=========== Nhap thong tin "<<n<<" may ==========="<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"  * Thong tin may so "<<i+1<<" *  "<<endl;
		y[i].Nhap();
	}
}

void PHONGMAY::Xuat()
{
	cout<<endl<<"========= Thong tin phong may "<<maPhong<<" ========="<<endl;
	cout<<" * Ten phong may: "<<tenPhong<<endl;
	cout<<" * Dien tich: "<<dienTich<<"m2"<<endl;
	x.Xuat();
	cout<<" * Danh sach "<<n<<" may: "<<endl;
	cout<<setw(10)<<"Ma May"<<setw(20)<<"Kieu May"<<setw(20)<<"Tinh Trang"<<endl;

	for (int i = 0; i < n; ++i)
	{
		y[i].Xuat();
	}
}

int main(int argc, char const *argv[])
{
	PHONGMAY info;
	cout<<"============ Quan Ly Phong May ============"<<endl;
	info.Nhap();
	info.Xuat();
	return 0;
}

/*test case
PM1
Kim Giang 1
50
NV02
Le Ly Thi Nu
5
MAY01
Gamming
Dang su dung
MAY02
Gamming
San sang
MAY03
Van Phong
Offline
MAY04
Gamming
Dang su dung
MAY05
Laptop
Offline

*/