#include <bits/stdc++.h>

using namespace std;

class PERSON
{
protected:
	string hoTen, ngaySinh, queQuan;
	
};

class KYSU:private PERSON
{
	string nganhHoc;
	int namTN;
public:
	void Nhap()
	{
		cout<<" - Nhap ho ten ky su: ";
		cin.ignore();
		getline(cin, hoTen);
		cout<<" - Nhap ngay sinh (dd/mm/yyyy): ";
		getline(cin, ngaySinh);
		cout<<" - Nhap que quan: ";
		getline(cin, queQuan);
		cout<<" - Nhap nganh hoc: ";
		getline(cin, nganhHoc);
		cout<<" - Nhap nam tot nghiep: ";
		cin>>namTN;
	}
	void Xuat()
	{
		cout<<setw(20)<<hoTen;
		cout<<setw(15)<<ngaySinh;
		cout<<setw(15)<<queQuan;
		cout<<setw(15)<<nganhHoc;
		cout<<setw(10)<<namTN;
		cout<<endl;
	}
	friend void Newest(KYSU *ds, int n);
};

void Newest(KYSU *ds, int n)
{
	int newest=ds[0].namTN;
	for (int i = 0; i < n; ++i)
	{
		if (newest<ds[i].namTN)
		{
			newest = ds[i].namTN;
		}
	}

	cout<<endl;
	cout<<"----------------- Ky su tot nghiep gan nhat -----------------"<<endl;
	cout<<setw(20)<<"Ho Ten";
	cout<<setw(15)<<"Nam Sinh";
	cout<<setw(15)<<"Que Quan";
	cout<<setw(15)<<"Nganh Hoc";
	cout<<setw(10)<<"Nam TN";
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		if (ds[i].namTN == newest)
		{
			ds[i].Xuat();
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap vao so luong ky su: ";
	cin>>n;
	KYSU *ds = new KYSU[n];

	cout<<"--------------- Nhap thong tin cua "<<n<<" ky su ---------------"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Thong tin ky su thu "<<i+1<<" :"<<endl;
		ds[i].Nhap();
	}

	cout<<endl;
	cout<<"----------------- Thong tin cua "<<n<<" ky su -----------------"<<endl;
	cout<<setw(20)<<"Ho Ten";
	cout<<setw(15)<<"Nam Sinh";
	cout<<setw(15)<<"Que Quan";
	cout<<setw(15)<<"Nganh Hoc";
	cout<<setw(10)<<"Nam TN";
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}
	Newest(ds,n);
	return 0;
}