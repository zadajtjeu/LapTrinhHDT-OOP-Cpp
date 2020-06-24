#include <iostream>
#include <iomanip>
#include<string.h>

using namespace std;
class DoanhNghiep;
class Date
{
	int day, month, year;
public:
	void nhap()
	{
		scanf("%d/%d/%d",&day,&month,&year);
	}
	void xuat()
	{
		cout<<setw(2)<<day<<"/"<<setw(2)<<month<<"/"<<setw(2)<<year;
	}
	friend void tongDT2015(DoanhNghiep *dn, int n);
};


class DiaChi
{
	char dienThoai[12], phuong[30], quan[30], thanhPho[30];
public:
	friend class DoanhNghiep;
	friend void showHaNoi(DoanhNghiep *dn, int n);

};

class DoanhNghiep
{
	int maDn;
	char tenDn[60];
	Date ngayTl;
	DiaChi diaChi;
	char giamDoc[30];
	long doanhThu;
public:
	void Nhap()
	{
		cout<<" - Nhap ma doanh nghiep: ";
		cin>>maDn;
		cout<<" - Nhap ten doanh nghiep: ";
		fflush(stdin);
		gets(tenDn);
		cout<<" - Nhap ngay thanh lap DN: ";
		ngayTl.nhap();
		cout<<" - Nhap dia chi: "<<endl;
		{
			cout<<"    + Nhap dien thoai: ";
			fflush(stdin);
			gets(diaChi.dienThoai);
			cout<<"    + Nhap phuong: ";
			gets(diaChi.phuong);
			cout<<"    + Nhap quan: ";
			gets(diaChi.quan);
			cout<<"    + Nhap thanh pho: ";
			gets(diaChi.thanhPho);
		}

		cout<<" - Nhap ho ten giam doc: ";
		gets(giamDoc);
		cout<<" - Nhap doanh thu: ";
		cin>>doanhThu;
		
	}

	void Xuat()
	{
		cout<<setw(10)<<maDn;
		cout<<setw(20)<<tenDn;
		ngayTl.xuat();
		cout<<setw(12)<<diaChi.dienThoai;
		cout<<setw(15)<<diaChi.phuong;
		cout<<setw(15)<<diaChi.quan;
		cout<<setw(15)<<diaChi.thanhPho;
		cout<<setw(20)<<giamDoc;
		cout<<setw(10)<<doanhThu;
		cout<<endl;
	}

	friend void showHaNoi(DoanhNghiep *dn, int n);
	friend void tongDT2015(DoanhNghiep *dn, int n);
	friend void editDN(DoanhNghiep *dn, int n);
	
};

void showHaNoi(DoanhNghiep *dn, int n)
{
	cout<<endl;
	cout<<"=================== Danh sach doanh nghiep o Ha Noi ==================="<<endl;

	cout<<setw(10)<<"Ma DN";
	cout<<setw(20)<<"Ten DN";
	cout<<setw(10)<<"Ngay TL";
	cout<<setw(12)<<"Dien Thoai";
	cout<<setw(15)<<"Phuong";
	cout<<setw(15)<<"Quan";
	cout<<setw(15)<<"Thanh Pho";
	cout<<setw(20)<<"Giam Doc";
	cout<<setw(10)<<"Doanh Thu";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		if(strcmp(dn[i].diaChi.thanhPho,"Ha Noi")==0)
			dn[i].Xuat();
	}
}

void tongDT2015(DoanhNghiep *dn, int n)
{
	long sum = 0;
	for (int i = 0; i < n; ++i)
	{
		if (dn[i].ngayTl.year == 2015)
		{
			sum+=dn[i].doanhThu;
		}
	}
	cout<<endl;
	cout<<"* Tong doanh thu doanh nghiep 2015: "<<sum<<endl;
}

void editDN(DoanhNghiep *dn, int n)
{
	int ma;
	cout<<"* Nhap ma du an muon sua: ";
	cin>>ma;
	for (int i = 0; i < n; ++i)
	{
		if (dn[i].maDn == ma)
		{
			dn[i].Nhap();
		}
		
	}
	
	cout<<"=================== Danh sach doanh nghiep da sua ==================="<<endl;
	cout<<setw(10)<<"Ma DN";
	cout<<setw(20)<<"Ten DN";
	cout<<setw(10)<<"Ngay TL";
	cout<<setw(12)<<"Dien Thoai";
	cout<<setw(15)<<"Phuong";
	cout<<setw(15)<<"Quan";
	cout<<setw(15)<<"Thanh Pho";
	cout<<setw(20)<<"Giam Doc";
	cout<<setw(10)<<"Doanh Thu";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		dn[i].Xuat();
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so doanh nghiep: ";
	cin>>n;
	DoanhNghiep *dn = new DoanhNghiep[n];
	cout<<"=================== Nhap danh sach "<<n<<" doanh nghiep ==================="<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin doanh nghiep thu "<<i+1<<": "<<endl;
		dn[i].Nhap();
	}

	showHaNoi(dn,n);
	tongDT2015(dn,n);
	editDN(dn,n);
	return 0;
}

/*
3
1452
VinFast
12/03/2015
0918273645
Tay Tuu
Bac Tu Liem
Ha Noi
Pham Nhat Vuong
120000000
6542
Hateco
22/12/2018
0123456789
Minh Khai
Nam Tu Liem
Ha Noi
Ha Thi Co
542000000
1598
Hong Ha
22/06/2015
0987123456
Xuan Thuy
Cau Giay
Ha Nam
Hong Thi Ha
123000000
*/