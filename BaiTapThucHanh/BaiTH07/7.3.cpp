#include <bits/stdc++.h>

using namespace std;

class BenhNhan
{
protected:
	string hoten, quequan;
	int day, month, year;
public:
	void Nhap()
	{
		cout<<" - Nhap ho ten benh nhan: ";
		getline(cin, hoten);
		cout<<" - Nhap que quan: ";
		getline(cin, quequan);
		cout<<" - Nhap ngay sinh (dd/mm/yyyy): ";
		scanf("%d/%d/%d",&day,&month,&year);
		cin.ignore();
	}
	void Xuat()
	{
		cout<<fixed;
		cout<<setw(20)<<left<<hoten;
		cout<<setw(15)<<left<<quequan;
		cout<<setw(5)<<right<<day<<"/"<<setw(2)<<month<<"/"<<setw(4)<<year;
	}
	
};

class BenhAn : private BenhNhan
{
	string tenBA;
	long soTienVienPhi;
public:
	void Nhap()
	{
		BenhNhan::Nhap();
		cout<<" - Nhap ten benh an: ";
		getline(cin, tenBA);
		cout<<" - Nhap so tien vien phi: ";
		cin>>soTienVienPhi;
		cin.ignore();
	}
	void Xuat()
	{
		BenhNhan::Xuat();
		cout<<setw(10)<<tinhTuoi();
		cout<<setw(15)<<tenBA;
		cout<<setw(10)<<soTienVienPhi;
		cout<<endl;
	}

	int tinhTuoi()
	{
		time_t now = time(0);
		return (localtime(&now)->tm_year+1900) - year; 
	}

	friend void sortbyOld(BenhAn *BA, int n);
	friend void showBA10old(BenhAn *BA, int n);
	friend void maxVienPhi(BenhAn *BA, int n);
	
};

void sortbyOld(BenhAn *BA, int n)
{
	for (int i = 1; i <= n-1; ++i)
	{
		for (int j = 0; j < n-i; ++j)
		{
			if (BA[j].tinhTuoi() < BA[j+1].tinhTuoi() )
			{
				BenhAn temp = BA[j];
				BA[j] = BA[j+1];
				BA[j+1] = temp;
			}
		}
	}

	cout<<endl;
	cout<<"============== BENH AN XEP THEO TUOI ==============";
	cout<<endl;

	cout<<setw(20)<<left<<"Ho Ten";
	cout<<setw(15)<<left<<"Que Quan";
	cout<<setw(13)<<right<<"Ngay Sinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(15)<<"Ten BA";
	cout<<setw(10)<<"Vien Phi";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		BA[i].Xuat();
	}

}

void showBA10old(BenhAn *BA, int n)
{
	cout<<endl;
	cout<<"============= BENH NHAN DUOI 10 TUOI ==============";
	cout<<endl;

	cout<<setw(20)<<left<<"Ho Ten";
	cout<<setw(15)<<left<<"Que Quan";
	cout<<setw(13)<<right<<"Ngay Sinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(15)<<"Ten BA";
	cout<<setw(10)<<"Vien Phi";
	cout<<endl;

	int check = 0;
	for (int i = 0; i < n; ++i)
	{
		if (BA[i].tinhTuoi()<=10)
		{
			BA[i].Xuat();
			check++;
		}
	}

	if (!check)
	{
		cout<<"!!!! KHONG CO BENH NHAN NAO DUOI 10 TUOI !!!!"<<endl;
	}
}

void maxVienPhi(BenhAn *BA, int n)
{
	BenhAn maxBA = BA[0];
	for (int i = 1; i < n; ++i)
	{
		if (BA[i].soTienVienPhi > maxBA.soTienVienPhi)
		{
			maxBA = BA[i];
		}
	}
	cout<<endl;
	cout<<"========== BENH NHAN CO VIEN PHI CAO NHAT =========";
	cout<<endl;

	cout<<setw(20)<<left<<"Ho Ten";
	cout<<setw(15)<<left<<"Que Quan";
	cout<<setw(13)<<right<<"Ngay Sinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(15)<<"Ten BA";
	cout<<setw(10)<<"Vien Phi";
	cout<<endl;
	maxBA.Xuat();

}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so benh an: ";
	cin>>n;
	cin.ignore();
	BenhAn *BA = new BenhAn[n];

	cout<<"\n============== Nhap vao danh sach "<<n<<" benh an ==============\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin benh an thu "<<i+1<<": \n";
		BA[i].Nhap();
	}

	cout<<endl;
	cout<<"================ DANH SACH BENH AN ================";
	cout<<endl;

	cout<<setw(20)<<left<<"Ho Ten";
	cout<<setw(15)<<left<<"Que Quan";
	cout<<setw(13)<<right<<"Ngay Sinh";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(15)<<"Ten BA";
	cout<<setw(10)<<"Vien Phi";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		BA[i].Xuat();
	}

	sortbyOld(BA,n);
	showBA10old(BA,n);
	maxVienPhi(BA,n);

	return 0;
}


/* test case
5
Van Tien Dung
Ha Nam
08/06/1998
Ho Sot
500000
Pham Thi Thu
Ha Noi
07/12/1995
Dau Dau
300000
Le Van Ha
Hung Yen
22/06/2013
Sot XH
500000
Pham Hong Ha
Da Nang
12/12/1997
CoV19
1200000
Le Van Hoa
Nam Dinh
22/02/1999
XuatT Som
120000
*/