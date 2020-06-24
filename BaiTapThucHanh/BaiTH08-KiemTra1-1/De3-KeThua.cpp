#include <bits/stdc++.h>

using namespace std;

class THE
{
protected:
	string soThe;
	long giaTriThe;
	int day, month, year;
public:
	void input()
	{
		cout<<" - Nhap ma so cua the: ";
		cin.ignore();
		getline(cin, soThe);
		cout<<" - Nhap menh gia the(20000): ";
		cin>>giaTriThe;
		cout<<" - Nhap ngay het han cua the(dd/mm/yyyy): ";
		scanf("%d/%d/%d",&day,&month,&year);
	}

	void output()
	{
		cout<<setw(20)<<soThe;
		cout<<setw(15)<<giaTriThe;
		cout<<setw(5)<<right<<day<<"/"<<setw(2)<<month<<"/"<<setw(4)<<year;
	}
};

class TheDienThoai : private THE
{
	string hangCC;
	int songaySD;
public:
	void Nhap()
	{
		THE::input();
		cout<<" - Nhap hang cung cap: ";
		cin.ignore();
		getline(cin, hangCC);
		cout<<" - Nhap so ngay su dung: ";
		cin>>songaySD;
	}

	void Xuat()
	{
		THE::output();
		cout<<setw(10)<<hangCC;
		cout<<setw(10)<<songaySD;
		cout<<endl;
	}
	friend void outputInfo(TheDienThoai *ds, int n);
	friend void inputInfor(TheDienThoai *ds, int n);
	friend void sortbyDate(TheDienThoai *ds, int n);
	friend void maxGiaTri(TheDienThoai *ds, int n);
};


void inputInfor(TheDienThoai *ds, int n)
{
	cout<<"\n### 	NHAP THONG TIN CUA "<<n<<" THE ###\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin the thu "<<i+1<<" :"<<endl;
		ds[i].Nhap();
		cout<<endl;
	}
}

void outputInfo(TheDienThoai *ds, int n)
{
	cout<<setw(20)<<"So The";
	cout<<setw(15)<<"Menh Gia";
	cout<<setw(13)<<"Ngay Het Han";
	cout<<setw(10)<<"Hang CC";
	cout<<setw(10)<<"So Ngay SD";
	cout<<endl;
	
	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}
}

void maxGiaTri(TheDienThoai *ds, int n)
{
	long maxGT = ds[0].giaTriThe;
	int chiso=0;
	for (int i = 1; i < n; ++i)
	{
		if (ds[i].giaTriThe > maxGT)
		{
			maxGT = ds[i].giaTriThe;
			chiso = i;
		}
	}

	cout<<"\n### THONG TIN THE GIA TRI LON NHAT ###\n";
	cout<<setw(20)<<"So The";
	cout<<setw(15)<<"Menh Gia";
	cout<<setw(13)<<"Ngay Het Han";
	cout<<setw(10)<<"Hang CC";
	cout<<setw(10)<<"So Ngay SD";
	cout<<endl;

	ds[chiso].Xuat();
}

void sortbyDate(TheDienThoai *ds, int n)
{
	for (int i = 1; i <= n-1; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			if (ds[j].songaySD > ds[j+1].songaySD )
			{
				TheDienThoai temp = ds[j];
				ds[j] = ds[j+1];
				ds[j+1] = temp;
			}
		}
	}
	cout<<"\n### XEP THEO NGAY ###\n";
	outputInfo(ds,n);

}


int main(int argc, char const *argv[])
{
	int n;
	cout<<"## Nhap vao so the dien thoai: ";
	do{
		cin>>n;
	}while(n<=0);

	TheDienThoai *ds = new TheDienThoai[n];

	inputInfor(ds,n);
	outputInfo(ds,n);
	maxGiaTri(ds,n);
	sortbyDate(ds,n);
	return 0;
}

/* test case
3
123456789
20000
12/12/2020
Viettel
30
987654321
50000
22/02/2021
Vinaphone
50
564789123
100000
20/02/2022
MobiFone
60
*/