#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class XeHoi
{
private:
	string nhanHieu, hangSX, kieuDang, mauSon, xuatXu;
	int namSX;
	long giaBan;
public:
	void Nhap()
	{
		cout<<" - Nhap nhan hieu xe: ";
		cin.ignore();
		getline(cin, nhanHieu);
		cout<<" - Nhap hang san xuat: ";
		getline(cin, hangSX);
		cout<<" - Nhap kieu dang: ";
		getline(cin, kieuDang);
		cout<<" - Nhap mau son: ";
		getline(cin, mauSon);
		cout<<" - Nhap nam san xuat: ";
		cin>>namSX;
		cout<<" - Nhap xuat xu xe: ";
		cin.ignore();
		getline(cin, xuatXu);
		cout<<" - Nhap gia ban: ";
		cin>>giaBan;
	}
	void Xuat()
	{
		cout<<setw(20)<<nhanHieu;
		cout<<setw(20)<<hangSX;
		cout<<setw(20)<<kieuDang;
		cout<<setw(20)<<mauSon;
		cout<<setw(20)<<namSX;
		cout<<setw(20)<<xuatXu;
		cout<<setw(20)<<giaBan;
		cout<<endl;
	}
	friend void buddleSort(XeHoi *xe, int n);
	friend void xehoiToyota(XeHoi *xe, int n);
};

void xehoiToyota(XeHoi *xe, int n)
{
	cout<<"=============== Danh sach "<<n<<" xe hoi hang Toyota ==============="<<endl;

	cout<<setw(20)<<"Nhan Hieu";
	cout<<setw(20)<<"Hang SX";
	cout<<setw(20)<<"Kieu Dang";
	cout<<setw(20)<<"Mau Son";
	cout<<setw(20)<<"Nam SX";
	cout<<setw(20)<<"Xuat Xu";
	cout<<setw(20)<<"Gia Ban";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		if (xe[i].hangSX == "Toyota")
		{
			xe[i].Xuat();
		}
	}
}

void buddleSort(XeHoi *xe, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = n-1; j >= i; --j)
			if (xe[j].giaBan < xe[j-1].giaBan)
			{
				XeHoi temp = xe[j];
				xe[j] = xe[j-1];
				xe[j-1] = temp;
			}

	cout<<"=============== Danh sach "<<n<<" xe hoi xep theo gia ==============="<<endl;

	cout<<setw(20)<<"Nhan Hieu";
	cout<<setw(20)<<"Hang SX";
	cout<<setw(20)<<"Kieu Dang";
	cout<<setw(20)<<"Mau Son";
	cout<<setw(20)<<"Nam SX";
	cout<<setw(20)<<"Xuat Xu";
	cout<<setw(20)<<"Gia Ban";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		xe[i].Xuat();
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so luong xe hoi: ";
	cin>>n;
	XeHoi *xe = new XeHoi[n];
	cout<<"=================== Nhap danh sach "<<n<<" xe hoi ==================="<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin xe thu "<<i+1<<": "<<endl;
		xe[i].Nhap();
	}

	cout<<"================== Danh sach "<<n<<" xe hoi ================="<<endl;

	cout<<setw(20)<<"Nhan Hieu";
	cout<<setw(20)<<"Hang SX";
	cout<<setw(20)<<"Kieu Dang";
	cout<<setw(20)<<"Mau Son";
	cout<<setw(20)<<"Nam SX";
	cout<<setw(20)<<"Xuat Xu";
	cout<<setw(20)<<"Gia Ban";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		xe[i].Xuat();
	}

	xehoiToyota(xe,n);
	buddleSort(xe,n);

	return 0;
}

/* test case
5
Yaris 1.5G CVT
Toyota
Hatchback
Den
2019
Nhap Khau
650000000
Wigo 4AT
Toyota
Hatchback
Trang
2017
Noi dia
405000000
VIOS 1.5E MT
Toyota
Sedan
Ghi
2016
Nhap khau
490000000
EcoSport
Ford
Hatchback
Xanh Blue
2018
Nhap khau
545000000
Camry 2.0G
Toyota
Sedan
Bac
2015
Nhap khau
1029000000
*/