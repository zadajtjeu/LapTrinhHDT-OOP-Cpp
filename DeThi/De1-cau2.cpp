#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Xe
{
protected:
	string mauson, bienso, noidk;
	int namdk;
public:
	Xe()
	{
		mauson = bienso = noidk = '\0';
		namdk = 0;
	}

	Xe(string mauson,string bienso,string noidk,int namdk)
	{
		this->mauson = mauson;
		this->bienso = bienso;
		this->noidk = noidk;
		this->namdk = namdk;
	}

	void nhap()
	{
		cout<<" - Nhap mau son: ";
		getline(cin, mauson);
		cout<<" - Nhap bien so: ";
		getline(cin, bienso);
		cout<<" - Nhap noi dang ky: ";
		getline(cin, noidk);
		cout<<" - Nhap nam dang ky: ";
		cin>>namdk;
		cin.ignore();
	}

	void xuat()
	{
		cout<<setw(20)<<mauson;
		cout<<setw(20)<<bienso;
		cout<<setw(20)<<noidk;
		cout<<setw(20)<<namdk;
	}
	~Xe()
	{
		mauson.clear();
		bienso.clear();
		noidk.clear();
		namdk=0;
	}
	
};

class ChuSoHuu:private Xe
{
private:
	string tenchuxe, cmt;
public:
	ChuSoHuu()
	{
		tenchuxe=cmt="";
	}
	ChuSoHuu(string tenchuxe,string cmt)
	{
		this->tenchuxe = tenchuxe;
		this->cmt = cmt;
	}

	void nhap()
	{
		cout<<" - Nhap ten chu xe: ";
		getline(cin, tenchuxe);
		cout<<" - Nhap chung minh thu: ";
		getline(cin, cmt);
		Xe::nhap();
	}

	void xuat()
	{
		cout<<setw(20)<<left<<tenchuxe;
		cout<<setw(20)<<cmt;
		Xe::xuat();
		cout<<endl;
	}

	string getnoidk()
	{
		return noidk;
	}

	~ChuSoHuu()
	{
		tenchuxe=cmt="";
	}
	
};

void title()
{
	cout<<setw(20)<<left<<"Chu xe";
	cout<<setw(20)<<"CMT";
	cout<<setw(20)<<"Mau son";
	cout<<setw(20)<<"Bien so";
	cout<<setw(20)<<"Noi DKi";
	cout<<setw(20)<<"Nam dk";
	cout<<endl;
}

void input(ChuSoHuu ds[], int k)
{
	cout<<"\n=============== NHAP DANH SACH CHU SO HUU =============== \n";

	for (int i = 0; i < k; ++i)
	{
		cout<<" ## Nhap thong tin chu so huu thu "<<i+1<<endl;
		ds[i].nhap();
	}
}

void output(ChuSoHuu *ds, int k)
{
	cout<<"\n=============== DANH SACH CHU SO HUU =============== \n";
	title();
	for (int i = 0; i < k; ++i)
	{
		ds[i].xuat();
	}
}

void show(ChuSoHuu *ds, int k)
{
	cout<<"\n======= DANH SACH CHU SO HUU DANG KY XE TAI HA NOI ======= \n";
	title();
	for (int i = 0; i < k; ++i)
	{
		if (ds[i].getnoidk() == "Ha Noi")
		{
			ds[i].xuat();
		}
		
	}
}
int main(int argc, char const *argv[])
{
	int k;
	ChuSoHuu *ds;

	cout<<"# Nhap vao so k chu so huu? k = ";
	do
	{
		cin>>k;
	}while(k<=0);
	cin.ignore();
	ds = new ChuSoHuu[k];
	input(ds,k);
	output(ds,k);
	show(ds,k);

	return 0;
}
/*
5
Pham Ha Giang
200010146
Xanh
17E75932
Thai Binh
2015
Nguyen An Van
100010146
Xanh
17E75932
Ha Noi
2015
Pham Ha Giang
200010146
Xanh
17E75932
Ha Noi
2015
Pham Ha Giang
200010146
Xanh
17E75932
Thai Binh
2015
Pham Ha Giang
200010146
Xanh
17E75932
Thai Binh
2015



*/