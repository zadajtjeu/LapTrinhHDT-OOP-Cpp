#include <bits/stdc++.h>

using namespace std;

class NGUOI
{
protected:
	string ma, hoten, ngaysinh;
public:
	virtual void nhap()
	{
		cout<<"Nhap ma dinh danh: ";
		cin.ignore();
		getline(cin,ma);
		cout<<"Nhap ho va ten: ";
		getline(cin,hoten);
		cout<<"Nhap ngay sinh(dd/mm/yyyy): ";
		getline(cin,ngaysinh);
	}
	virtual void xuat()
	{
		cout<<setw(10)<<ma<<setw(25)<<hoten<<setw(15)<<ngaysinh;
	}
	
};

class GV : public NGUOI
{
	int sobaibao;
public:
	GV()
	{
		sobaibao=0;
	}
	void nhap()
	{
		NGUOI::nhap();
		cout<<"Nhap so bai bao: ";
		cin>>sobaibao;
	}
	void xuat()
	{
		NGUOI::xuat();
		cout<<setw(10)<<sobaibao;
	}
	int getis()
	{
		return sobaibao;
	}
};

class SV : public NGUOI
{
	double diemthiTN;
public:
	SV()
	{
		diemthiTN=0;
	}
	void nhap()
	{
		NGUOI::nhap();
		cout<<"Nhap diem thi tot nghiep: ";
		cin>>diemthiTN;
	}
	void xuat()
	{
		NGUOI::xuat();
		cout<<setw(10)<<diemthiTN;
	}
	double getis()
	{
		return diemthiTN;
	}
	
};

int main(int argc, char const *argv[])
{
	int n,m;
	cout<<"Nhap so giang vien: ";
	cin>>n;
	cout<<"Nhap so sinh vien: ";
	cin>>m;
	NGUOI *p;
	SV svien[m];
	GV gvien[n];

	cout<<endl<<"\t\t===NHAP THONG TIN GIANG VIEN==="<<endl;
	for (int i = 0; i < n; i++)
	{
		cout<<"Nhap thong tin giang vien thu "<<i+1<<" "<<endl;
		p = &gvien[i];
		p->nhap();
	}
	cout<<endl<<"\t\t===NHAP THONG TIN SINH VIEN==="<<endl;
	for (int i = 0; i < m; i++)
	{
		cout<<"Nhap thong tin sinh vien thu "<<i+1<<" "<<endl;
		p = &svien[i];
		p->nhap();
	}


	cout<<endl<<"\t\t===XUAT THONG TIN DUOC KHEN THUONG==="<<endl;
	cout<<endl<<"\tGIANG VIEN(bai bao > 3)"<<endl;
	cout<<setw(10)<<"Ma GV"<<setw(25)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(10)<<"So bai bao"<<endl;

	for (int i = 0; i < n; i++)
	{
		if (gvien[i].getis()>3)
		{
			p = &gvien[i];
			p->xuat();
			cout<<endl;
		}
	}

	cout<<endl<<"\tSINH VIEN(diem tot nghiep > 8)"<<endl;
	cout<<setw(10)<<"Ma SV"<<setw(25)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(10)<<"Diem TN"<<endl;

	for (int i = 0; i < m; i++)
	{
		if (svien[i].getis()>8)
		{
			p = &svien[i];
			p->xuat();
			cout<<endl;
		}
	}
	return 0;
}

/*test
3
4
GV1
Giang vien 1
11/12/1985
4
GV2
Giang vien 2
10/10/1995
3
GV3
Giang vien 3
11/02/1991
5
SV1
Sinh vien 1
Ngay1
7.5
SV2
Sinh vien 2
Ngay2
8.5
SV3
Sinh vien 3
Ngay3
6
SV4
Sinh vien 4
Ngay4
9

*/