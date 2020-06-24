#include <bits/stdc++.h>

using namespace std;

class BAN
{
	string maBan, tenBan, ngayTL;	
	friend class TRUONGDH;
};

class KHOA
{
	string maKhoa, tenKhoa, truongKhoa;
	friend class TRUONGDH;
};


class TRUONG
{
protected:
	string maTruong, tenTruong, diaChi;
public:
	void nhap()
	{
		cout<<" - Nhap ma truong: ";
		getline(cin, maTruong);
		cout<<" - Nhap ten truong: ";
		getline(cin, tenTruong);
		cout<<" - Nhap dia chi truong: ";
		getline(cin, diaChi);
	}
	void xuat()
	{
		cout<<"Ma truong: "<<maTruong<<endl;
		cout<<"Ten truong: "<<tenTruong<<endl;
		cout<<"Dia chi: "<<diaChi<<endl;
	}
};

class TRUONGDH : private TRUONG
{
	KHOA *x;
	int n;
	BAN *y;
	int m;
public:
	void Nhap()
	{
		TRUONG::nhap();
		cout<<"## Nhap so khoa: "; cin>>n; cin.ignore();
		x = new KHOA[n];
		for (int i = 0; i < n; ++i)
		{
			cout<<"* Nhap khoa thu "<<i+1<<": \n";
			cout<<" - Ma khoa: "; getline(cin, x[i].maKhoa);
			cout<<" - Ten khoa: "; getline(cin, x[i].tenKhoa);
			cout<<" - Truong khoa: "; getline(cin, x[i].truongKhoa);
		}

		cout<<"## Nhap so ban: "; cin>>m; cin.ignore();
		y = new BAN[m];
		for (int i = 0; i < m; ++i)
		{
			cout<<"* Nhap khoa thu "<<i+1<<": \n";
			cout<<" - Nhap ma ban: "; getline(cin, y[i].maBan);
			cout<<" - Nhap ten ban: "; getline(cin, y[i].tenBan);
			cout<<" - Nhap ngayTL: "; getline(cin, y[i].ngayTL);
		}
	}

	void Xuat()
	{
		TRUONG::xuat();
		cout<<"### Thong tin "<<n<<" khoa ###\n";

		cout<<setw(5)<<"STT";
		cout<<setw(10)<<"Ma Khoa";
		cout<<setw(20)<<"Ten Khoa";
		cout<<setw(20)<<"Truong Khoa";
		cout<<endl;

		for (int i = 0; i < n; ++i)
		{
			cout<<setw(5)<<i+1;
			cout<<setw(10)<<x[i].maKhoa;
			cout<<setw(20)<<x[i].tenKhoa;
			cout<<setw(20)<<x[i].truongKhoa;
			cout<<endl;
		}

		cout<<"### Thong tin "<<m<<" ban ###\n";

		cout<<setw(5)<<"STT";
		cout<<setw(10)<<"Ma Ban";
		cout<<setw(20)<<"Ten Ban";
		cout<<setw(10)<<"NgayTL";
		cout<<endl;

		for (int i = 0; i < m; ++i)
		{
			cout<<setw(5)<<i+1;
			cout<<setw(10)<<y[i].maBan;
			cout<<setw(20)<<y[i].tenBan;
			cout<<setw(10)<<y[i].ngayTL;
			cout<<endl;
		}

	}
};

int main(int argc, char const *argv[])
{
	TRUONGDH infor;
	infor.Nhap();
	infor.Xuat();
	return 0;
}