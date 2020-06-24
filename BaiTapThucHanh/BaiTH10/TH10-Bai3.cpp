#include <bits/stdc++.h>

using namespace std;

class NhanVien
{
	string hoTen, chucVu;
	friend class PhieuKiemKe;
};

class Phong
{
	string maPhong, tenPhong, truongPhong;
	friend class PhieuKiemKe;
};

class TaiSan
{
	string tenTS, tinhTrang;
	int soluong;
	friend class PhieuKiemKe;
};


class PhieuKiemKe
{
	string maPhieu, ngayKK;
	NhanVien nv;
	Phong phong;
	TaiSan *ds;
	int soTS;
public:
	void input()
	{
		cout<<" - Ma phieu: "; getline(cin, maPhieu);
		cout<<" - Ngay kiem ke: "; getline(cin, ngayKK);
		cout<<" - Ten nhan vien lap phieu: "; getline(cin, nv.hoTen);
		cout<<" - Chuc vu nhan vien: "; getline(cin, nv.chucVu);
		cout<<" - Kiem ke tai phong: "; getline(cin, phong.tenPhong);
		cout<<" - Ma phong: "; getline(cin, phong.maPhong);
		cout<<" - Truong phong: "; getline(cin, phong.truongPhong);
		cout<<"## Nhap so tai khoan kiem ke: "; cin>>soTS; cin.ignore();
		ds = new TaiSan[soTS];
		for (int i = 0; i < soTS; ++i)
		{
			cout<<"* Nhap thong tin tai san thu "<<i+1<<": \n";
			cout<<" - Ten tai san: "; getline(cin, ds[i].tenTS);
			cout<<" - So luong KK: "; cin>>ds[i].soluong; cin.ignore();
			cout<<" - Ting trang: "; getline(cin, ds[i].tinhTrang);

		}
	}

	void output()
	{
		cout<<endl;
		cout<<" =============================PHIEU KIEM KE TAI SAN==============================";
		cout<<endl;
		cout<<setw(20)<<left<<"|Ma phieu:"<<setw(20)<<maPhieu;
		cout<<setw(20)<<left<<"Ngay kiem ke:"<<setw(20)<<ngayKK;
		cout<<"|"<<endl;
		cout<<setw(20)<<left<<"|Nhan vien kiem ke:"<<setw(20)<<nv.hoTen;
		cout<<setw(20)<<left<<"Chuc vu:"<<setw(20)<<nv.chucVu;
		cout<<"|"<<endl;
		cout<<setw(20)<<left<<"|Kiem ke tai phong:"<<setw(20)<<phong.tenPhong;
		cout<<setw(20)<<left<<"Ma phong:"<<setw(20)<<phong.maPhong;
		cout<<"|"<<endl;
		cout<<setw(20)<<left<<"|Truong phong:"<<setw(20)<<phong.truongPhong;
		cout<<setw(41)<<right<<"|"<<endl;
		cout<<"|"<<setw(80)<<right<<"|"<<endl;

		//xuat ds tai san
		cout<<setw(25)<<left<<"|Ten tai san";
		cout<<setw(25)<<"So luong";
		cout<<setw(25)<<"Tinh trang";
		cout<<setw(6)<<right<<"|"<<endl;

		int tongsoluong = 0;

		for (int i = 0; i < soTS; ++i)
		{
			tongsoluong += ds[i].soluong;
			cout<<left<<"|";
			cout<<setw(25)<<ds[i].tenTS;
			cout<<setw(25)<<ds[i].soluong;
			cout<<setw(25)<<ds[i].tinhTrang;
			cout<<setw(5)<<right<<"|"<<endl;
		}

		cout<<"|"<<setw(80)<<right<<"|"<<endl;
		cout<<setw(30)<<left<<"|So tai san da liet ke:"<<setw(10)<<soTS;
		cout<<setw(20)<<left<<"Tong so luong:"<<setw(20)<<tongsoluong;
		cout<<"|"<<endl;
		cout<<" ================================================================================";
		cout<<endl;


	}
};

int main(int argc, char const *argv[])
{
	PhieuKiemKe phieu;
	phieu.input();
	phieu.output();
	return 0;
}

/*test case
PH01
1/1/2007
Kieu Thi Thanh
Ke toan vien
To chuc hanh chinh
PTC
Hoang Bich Hao
3
May vi tinh
5
Tot
May vi tinh
3
Het khau hao - hong
Ban lam viec
6
Tot

*/