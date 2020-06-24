#include <bits/stdc++.h>

using namespace std;
class NamSinh
{
private:
	int dd,mm,yyyy;
public:
	NamSinh()
	{
		dd=mm=01;
		yyyy=1970;
	}
	void NhapNgay()
	{
		scanf("%d/%d/%d",&dd,&mm,&yyyy);
	}
	void XuatNgay()
	{
		cout<<right<<setw(15)<<dd<<"/"<<mm<<"/"<<yyyy;
	}
};

class NHANSU
{
protected:
	char hoten[50], gioitinh[5], diachi[100];
	NamSinh namsinh;
public:
	NHANSU()
	{
		strcpy(hoten,"Null"); strcpy(gioitinh,"Null"); strcpy(diachi,"Null");
	}
	friend class NamSinh;
};

class CONGCHUC : private NHANSU
{
protected:
	char nganhnghe[20], trinhdo[50];
	int namvaoCQ;
	float hsluong, phcap;
public:
	CONGCHUC()
	{
		strcpy(nganhnghe,"Null");
		strcpy(trinhdo,"Null");
		namvaoCQ=0; hsluong=phcap=1;
	}
	void Nhap()
	{
		cout<<"Nhap ho ten: ";
		fflush(stdin);
		gets(hoten);
		cout<<"Nhap Gioi tinh: ";
		gets(gioitinh);
		cout<<"Nhap nam sinh(dd/mm/yyyy): ";
		namsinh.NhapNgay();
		cout<<"Nhap dia chi: ";
		fflush(stdin);
		gets(diachi);
		cout<<"Nhap nganh nghe: ";
		gets(nganhnghe);
		cout<<"Nhap trinh do(DH,CD,TC): ";
		gets(trinhdo);
		cout<<"Nhap nam vao co quan: ";
		cin>>namvaoCQ;
		cout<<"Nhap he so luong: ";
		cin>>hsluong;
		cout<<"Nhap so tien phu cap: ";
		cin>>phcap;
	}
	void Xuat()
	{
		cout<<setw(20)<<hoten<<setw(10)<<gioitinh; namsinh.XuatNgay(); 
		cout<<setw(20)<<diachi<<setw(20)<<nganhnghe<<setw(10)<<trinhdo<<setw(10)<<namvaoCQ<<setw(10)<<setprecision(2)<<hsluong<<setw(10)<<fixed<<phcap<<setw(10)<<thunhap()<<endl;
	}

	double thunhap()
	{
		return hsluong*830+phcap;
	}
};

void minLuong(CONGCHUC ds[], int n)
{
	double minL=ds[0].thunhap();
	int stt=0;
	for (int i = 0; i < n; ++i)
	{
		if (minL>ds[i].thunhap())
		{
			minL=ds[i].thunhap();
			stt = i;
		}
	}
	cout<<endl<<"Thong tin nguoi co thu nhap thap nhat: "<<endl;
	cout<<setw(20)<<"Ho Ten"<<setw(10)<<"GT"<<setw(20)<<"ngSinh"; 
	cout<<setw(20)<<"Dia Chi"<<setw(20)<<"Nganh Nghe"<<setw(10)<<"Trinh do"<<setw(10)<<"Nam vao CQ"<<setw(10)<<"HesoL"<<setw(10)<<"Phu Cap"<<setw(10)<<"Thu nhap"<<endl;
	ds[stt].Xuat();
}

void BuddleSort(CONGCHUC ds[], int n)
{
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = n-1; j > i; --j)
		{
			if(ds[j].thunhap()>ds[j-1].thunhap())
			{
				CONGCHUC tmp = ds[j];
				ds[j] = ds[j-1];
				ds[j-1] = tmp;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	CONGCHUC ds[50];
	int n;
	cout<<"Nhap so cong nhan vien chuc: ";
	do
	{
		cin>>n;
		if(n<=0||n>50)
			cout<<endl<<"Nhap lai!";
	}while(n<=0||n>50);

	for (int i = 0; i < n; ++i)
	{
		cout<<endl<<"Nhap thong tin nguoi thu "<<i+1<<":"<<endl;
		ds[i].Nhap();
	}


	minLuong(ds,n);
	//Sap xep
	BuddleSort(ds,n);

	cout<<endl;
	cout<<endl<<"Danh sach cong chuc: "<<endl;
	cout<<setw(20)<<"Ho Ten"<<setw(10)<<"GT"<<setw(20)<<"ngSinh"; 
	cout<<setw(20)<<"Dia Chi"<<setw(20)<<"Nganh Nghe"<<setw(10)<<"Trinh do"<<setw(10)<<"Nam vao CQ"<<setw(10)<<"HesoL"<<setw(10)<<"Phu Cap"<<setw(10)<<"Thu nhap"<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}
	system("PAUSE");
	return 0;
}

/* Du lieu test
6
Cao Nguyen Duy Anh
Nam
26/10/2000
Ha Noi
Nhan Vien
Dai Hoc
2017
1.5
100
Nguyen Trung Anh
Nam
17/11/1999
Yen Bai
Nhan Vien
Dai Hoc
2017
1.5
100
Nguyen Hoang Anh
Nam
20/09/2000
Soc Son
Bao Ve
Dai Hoc
2016
1.6
120
Le Nhu Bach
Nu
17/05/2000
Thai Lan
Ke Toan
Dai Hoc
2018
1.4
120
Nguyen Van Nam
Nam
28/11/2000
Vinh Phuc
Tiep Tan
Cao Dang
2018
1.4
100
Phi Ngoc Van
Gay
11/11/1999
Thai Lo
Culi
Trung Cap
2014
1.4
100
*/