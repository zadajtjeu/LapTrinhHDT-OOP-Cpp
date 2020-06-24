#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class HANG;
class DATE
{
	int D,M,Y;
	friend class HANG;
};

class HANG
{
private:
	string maHang, tenHang;
	DATE ngaySX;
public:
	void Nhap()
	{
		cout<<" - Nhap ma hang: ";
		cin.ignore();
		getline(cin,maHang);
		cout<<" - Nhap ten hang: ";
		getline(cin, tenHang);
		cout<<" - Nhap ngay san xuat: (dd/mm/yyyy) ";
		scanf("%d/%d/%d",&ngaySX.D,&ngaySX.M,&ngaySX.Y);
	}
	void Xuat()
	{
		cout<<setw(10)<<maHang;
		cout<<setw(20)<<tenHang;
		cout<<setw(5)<<ngaySX.D<<"/"<<ngaySX.M<<"/"<<ngaySX.Y;
		cout<<endl;
	}
	int getY()
	{
		return ngaySX.Y;
	}
};



int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so mat hang: ";
	cin>>n;

	HANG *ds = new HANG[n];
	cout<<"================== Nhap danh sach "<<n<<" mat hang =================="<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Thong tin mat hang thu "<<i+1<<": "<<endl;
		ds[i].Nhap();
	}

	cout<<endl;
	cout<<"================== Danh sach mat hang san xuat nam 2017 =================="<<endl;
	cout<<setw(10)<<"Ma Hang";
	cout<<setw(20)<<"Ten Hang";
	cout<<setw(15)<<"Ngay SX";
	cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		if (ds[i].getY() == 2017)
		{
			ds[i].Xuat();
		}
	}

	return 0;
}