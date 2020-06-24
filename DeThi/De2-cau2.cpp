#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <time.h>

using namespace std;

class NGAY
{
protected:
	int ngay, thang, nam;
public:
	NGAY()
	{
		ngay = thang = nam = 0;
	}
	NGAY(int d, int m, int y)
	{
		ngay = d;
		thang = m;
		nam = y;
	}

	void nhap()
	{
		cout<<" - Nhap ngay sinh? (dd/mm/yyyy) ";
		scanf("%d/%d/%d", &ngay, &thang, &nam);
		fflush(stdin);
	}
	void xuat()
	{
		cout<<setw(7)<<right<<ngay<<"/"<<setw(2)<<thang<<"/"<<setw(4)<<nam;
	}
	
};

class NGUOI:private NGAY
{
private:
	char cmt[15], hoten[50], noisinh[20];
public:
	NGUOI()
	{
		cmt[0] = hoten[0] = noisinh[0] = '\0';
	}
	NGUOI(char cmt[15], char hoten[50], char noisinh[20])
	{
		strcpy(this->cmt, cmt);
		strcpy(this->hoten, hoten);
		strcpy(this->noisinh ,noisinh);
	}
	NGUOI(char cmt[15], char hoten[50], char noisinh[20], int d, int m, int y):NGAY(d,m,y)
	{
		strcpy(this->cmt, cmt);
		strcpy(this->hoten, hoten);
		strcpy(this->noisinh ,noisinh);
	}
	
	void nhap()
	{
		cout<<" - Nhap ho ten: ";
		gets(hoten);
		cout<<" - Nhap chung minh thu: ";
		gets(cmt);
		cout<<" - Nhap noi sinh";
		gets(noisinh);
		NGAY::nhap();
		
	}

	void xuat()
	{
		cout<<setw(30)<<left<<hoten;
		cout<<setw(20)<<cmt;
		cout<<setw(20)<<noisinh;
		NGAY::xuat();
		cout<<setw(10)<<tuoi();
		cout<<endl;
	}

	int tuoi()
	{
		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);
		int year = aTime->tm_year + 1900; 

		return year - nam;
	}

	void operator==(NGUOI infor)
	{
		strcpy(this->cmt, infor.cmt);
		strcpy(this->hoten, infor.hoten);
		strcpy(this->noisinh ,infor.noisinh);
		this->ngay = ngay;
		this->thang = thang;
		this->nam = nam;
	}
};



void title()
{
	cout<<setw(30)<<left<<"Ho ten";
	cout<<setw(20)<<"CMT";
	cout<<setw(20)<<"Noi sinh";
	cout<<setw(15)<<right<<"Ngay";
	cout<<setw(10)<<"Tuoi";
	cout<<endl;
}

void input(NGUOI *ds, int &k)
{
	
	cout<<"\n============= NHAP VAO DS "<<k<<" NGUOI =============\n";
	for (int i = 0; i < k; ++i)
	{
		cout<<"# Nhap thong tin nguoi thu "<<i+1<<endl;
		ds[i].nhap();
	}
}

void output(NGUOI *ds, int k)
{
	cout<<"\n============= DANH SACH "<<k<<" NGUOI =============\n";
	title();
	for (int i = 0; i < k; ++i)
	{
		ds[i].xuat();
	}
}

void sortbyold(NGUOI *ds, int k)
{
	for (int i = 1; i < k; ++i)
	{
		for (int j = 0; j < k-i; ++j)
		{
			if (ds[j].tuoi() <  ds[j+1].tuoi())
			{
				NGUOI tmp = ds[j];
				ds[j] = ds[j+1];
				ds[j+1] = tmp;
			}
		}
	}

	output(ds,k);
}

int main(int argc, char const *argv[])
{
	int k;
	NGUOI *ds;
	cout<<"# Nhap so k? ";
	do{ cin>> k; }while(k<1);
	fflush(stdin);
	ds = new NGUOI[k];
	input(ds,k);
	output(ds,k);
	sortbyold(ds,k);
	return 0;
}

/*
4
Pham Ba D
4656635
Ha Noi
12/02/2002
Pham Ba A
123456789
Ha Noi
12/02/2000
Pham Ba C
154245789
Ha Noi
22/12/1999
Pham Ba B
987654321
Ha Noi
06/12/1996
*/