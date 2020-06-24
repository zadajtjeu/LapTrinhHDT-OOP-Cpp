#include <bits/stdc++.h>

using namespace std;

class SanPham
{
protected:
	string masp, tensp, ngaysx,mausac;
	double trongluong;
public:
	void Nhap()
	{
		cout<<" - Nhap ma san pham: ";
		getline(cin, masp);
		cout<<" - Nhap ten san pham: ";
		getline(cin, tensp);
		cout<<" - Nhap ngay san xuat (dd/mm/yyyy): ";
		getline(cin, ngaysx);
		cout<<" - Nhap trong luong (kg): ";
		cin>>trongluong;
		cin.ignore();
		cout<<" - Nhap mau sac: ";
		getline(cin, mausac);
	}
	
};

class HangDienTu : private SanPham
{
	double congsuat;
	unsigned dongdien;
public:
	void Nhap()
	{
		SanPham::Nhap();
		cout<<" - Nhap cong suat (w): ";
		cin>>congsuat;
		cout<<" - Nhap dong dien (1 hoac 2 chieu): ";
		cin>>dongdien;
		cin.ignore();
	}

	void Xuat()
	{
		cout<<setw(10)<<masp;
		cout<<setw(20)<<tensp;
		cout<<setw(15)<<ngaysx;
		cout<<setw(10)<<trongluong;
		cout<<setw(10)<<mausac;
		cout<<setw(10)<<congsuat;
		cout<<setw(10)<<dongdien<<" chieu";
		cout<<endl;
	}
	friend void minweight(HangDienTu *ds, int n);
};

void minweight(HangDienTu *ds, int n)
{
	double lightweight =ds[0].trongluong;
	for (int i = 0; i < n; ++i)
	{
		if (ds[i].trongluong<lightweight)
		{
			lightweight = ds[i].trongluong;
		}
	}
	cout<<"\n----------------- Danh sach hang dien tu nhe nhat -----------------\n";

	cout<<setw(10)<<"Ma SP";
	cout<<setw(20)<<"Ten SP";
	cout<<setw(15)<<"Ngay SX";
	cout<<setw(10)<<"Trong Luong";
	cout<<setw(10)<<"Mau Sac";
	cout<<setw(10)<<"COng suat";
	cout<<setw(15)<<"DOng dien";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		if (ds[i].trongluong == lightweight)
		{
			ds[i].Xuat();
		}
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so hang dien tu can nhap: ";
	cin>>n;
	cin.ignore();
	HangDienTu *ds = new HangDienTu[n];

	cout<<"\n---------------- Nhap vao danh sach "<<n<<" hang dien tu ----------------\n";

	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin hang dien tu thu "<<i+1<<": "<<endl;
		ds[i].Nhap();
	}

	cout<<"\n-------------------- Danh sach "<<n<<" hang dien tu --------------------\n";

	cout<<setw(10)<<"Ma SP";
	cout<<setw(20)<<"Ten SP";
	cout<<setw(15)<<"Ngay SX";
	cout<<setw(10)<<"Trong Luong";
	cout<<setw(10)<<"Mau Sac";
	cout<<setw(10)<<"COng suat";
	cout<<setw(15)<<"DOng dien";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}

	minweight(ds,n);
	return 0;
}