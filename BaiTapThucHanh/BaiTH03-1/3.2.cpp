#include <bits/stdc++.h>

using namespace std;

class HANG
{
	char maHang[10], tenHang[30];
	long donGia;
public:
	void Nhap();
	void Xuat();
};

class PHIEU
{
	char maPhieu[10];
	HANG *x;
	int n;
public:
	void Nhap();
	void Xuat();
};


void HANG::Nhap()
{
	fflush(stdin);
	cout<<" - Nhap ma hang: ";
	gets(maHang);
	cout<<" - Nhap ten hang: ";
	gets(tenHang);
	cout<<" - Nhap don gia: ";
	cin>>donGia;
}
void HANG::Xuat()
{
	cout<<setw(10)<<maHang<<setw(20)<<tenHang<<setw(10)<<donGia<<endl;
}

void PHIEU::Nhap()
{
	fflush(stdin);
	cout<<"Nhap ma phieu: ";
	gets(maPhieu);
	cout<<"Nhap so mat hang: ";
	cin>>n;
	x = new HANG[n];
	cout<<"========= Nhap thong tin "<<n<<" mat hang ========="<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<"* Mathang thu "<<i+1<<": "<<endl;
		x[i].Nhap();
	}

}


void PHIEU::Xuat()
{
	cout<<endl<<"=============== Thong tin phieu xuat =============="<<endl;
	cout<<"Ma phieu xuat: "<<maPhieu<<endl;
	cout<<"========== Danh sach mat hang trong phieu ========="<<endl;
	cout<<setw(10)<<"Ma Hang"<<setw(20)<<"Ten Hang"<<setw(10)<<"Don Gia"<<endl;
	for (int i = 0; i < n; ++i)
	{
		x[i].Xuat();
	}
}

int main(int argc, char const *argv[])
{
	PHIEU xuat;
	xuat.Nhap();
	xuat.Xuat();
	return 0;
}


/* test case
PX01
3
MH01
Khau Trang
56000
MH02
Nuoc rua tay
50000
MH03
Con 90
12000
*/