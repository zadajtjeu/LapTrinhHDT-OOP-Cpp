#include <bits/stdc++.h>

using namespace std;

class NhanVien
{
protected:
	string maNV, tenNV;
public:
	void Input()
	{
		cout<<" - Nhap ma nhan vien: ";
		cin.ignore();
		getline(cin, this->maNV);
		cout<<" - Nhap ten nhan vien: ";
		getline(cin, this->tenNV);
	}
	void Output()
	{
		cout<<setw(10)<<left<<maNV;
		cout<<setw(20)<<tenNV;
	}
};

class nvBienChe : private NhanVien
{
	double hsLuong, hsPC;
public:
	void Input()
	{
		NhanVien::Input();
		cout<<" - Nhap he so luong nv: ";
		cin>>hsLuong;
		cout<<" - Nhap he so phu cap chuc vu: ";
		cin>>hsPC;
	}
	void Output()
	{
		NhanVien::Output();
		cout<<setw(10)<<right<<hsLuong;
		cout<<setw(10)<<hsPC;
		cout<<setw(15)<<luongBC();
		cout<<endl;
	}

	double luongBC()
	{
		return 1000 * (1.0 + hsLuong + hsPC);
	}

};


class nvHopDong : private NhanVien
{
	double tienCong, songayLV, hsVuotGio;
public:
	void Input()
	{
		NhanVien::Input();
		cout<<" - Nhap tien cong: ";
		cin>>tienCong;
		cout<<" - Nhap so ngay lam viec trong thang: ";
		cin>>songayLV;
		cout<<" - Nhap he so vuot gio: ";
		cin>>hsVuotGio;
	}
	void Output()
	{
		NhanVien::Output();
		cout<<setw(10)<<right<<tienCong;
		cout<<setw(10)<<songayLV;
		cout<<setw(8)<<hsVuotGio;
		cout<<setw(15)<<luongHD();
		cout<<endl;
	}
	 double luongHD()
	 {
	 	return tienCong * songayLV * (1 + hsVuotGio);
	 }
};

void showTitleBC()
{
	cout<<setw(10)<<left<<"Ma NV";
	cout<<setw(20)<<"Ten NV";
	cout<<setw(10)<<right<<"H.S Luong";
	cout<<setw(10)<<"Phu Cap";
	cout<<setw(15)<<"Luong";
	cout<<endl;
}

void showTitleHD()
{
	cout<<setw(10)<<left<<"Ma NV";
	cout<<setw(20)<<"Ten NV";
	cout<<setw(10)<<right<<"Tien Cong";
	cout<<setw(10)<<"Ngay Cong";
	cout<<setw(8)<<"OT";
	cout<<setw(15)<<"Luong";
	cout<<endl;
}


void inputNhanVien(nvBienChe *dsBC, nvHopDong *dsHD, int soBC, int soHD)
{

	cout<<"\n================= NHAP DANH SACH "<<soBC<<" NHAN VIEN BIEN CHE =================\n";
	for (int nhanvien = 0; nhanvien < soBC; ++nhanvien)
	{
		cout<<"* Nhap nhan vien thu "<<nhanvien+1<<": \n";
		dsBC[nhanvien].Input();
	}

	cout<<endl;

	cout<<"\n================= NHAP DANH SACH "<<soHD<<" NHAN VIEN HOP DONG =================\n";
	for (int nhanvien = 0; nhanvien < soHD; ++nhanvien)
	{
		cout<<"* Nhap nhan vien thu "<<nhanvien+1<<": \n";
		dsHD[nhanvien].Input();
	}
}


void showNhanVien(nvBienChe *dsBC, nvHopDong *dsHD, int soBC, int soHD)
{
	cout<<"\n=================== DANH SACH "<<soBC<<" NHAN VIEN BIEN CHE ====================\n";
	showTitleBC();
	for (int nhanvien = 0; nhanvien < soBC; ++nhanvien)
	{
		dsBC[nhanvien].Output();
	}

	cout<<"\n=================== DANH SACH "<<soHD<<" NHAN VIEN HOP DONG ====================\n";
	showTitleHD();
	for (int nhanvien = 0; nhanvien < soHD; ++nhanvien)
	{
		dsHD[nhanvien].Output();
	}

}

void maxLuong(nvBienChe *dsBC, nvHopDong *dsHD, int soBC, int soHD)
{
	int ismaxBC = (int)dsBC[0].luongBC();
	int ismaxHD = (int)dsHD[0].luongHD();


	for (int nhanvien = 1; nhanvien < soBC; ++nhanvien)
	{
		if ((int)dsBC[nhanvien].luongBC() > ismaxBC)
		{
			ismaxBC = (int)dsBC[nhanvien].luongBC();
		}
	}

	for (int nhanvien = 1; nhanvien < soHD; ++nhanvien)
	{
		if ((int)dsHD[nhanvien].luongHD() > ismaxHD)
		{
			ismaxHD = (int)dsHD[nhanvien].luongHD();
		}
	}


	cout<<"\n=================== NHAN VIEN BIEN CHE CO LUONG CAO NHAT ====================\n";
	showTitleBC();
	for (int nhanvien = 0; nhanvien < soBC; ++nhanvien)
	{
		if ((int)dsBC[nhanvien].luongBC() == ismaxBC)
		{
			dsBC[nhanvien].Output();
		}
			
	}

	cout<<"\n=================== NHAN VIEN HOP DONG CO LUONG CAO NHAT ====================\n";
	showTitleHD();
	for (int nhanvien = 0; nhanvien < soHD; ++nhanvien)
	{
		if ((int)dsHD[nhanvien].luongHD() == ismaxHD)
		{
			dsHD[nhanvien].Output();
		}
		
	}

}



int main(int argc, char const *argv[])
{
	nvBienChe *dsBC;
	nvHopDong *dsHD;
	int soBC = 0, soHD = 0;

	cout<<"# Nhap vao so nhan vien Bien Che: ";
	cin>>soBC;
	dsBC = new nvBienChe[soBC];

	cout<<"# Nhap vao so nhan vien Hop Dong: ";
	cin>>soHD;
	dsHD = new nvHopDong[soHD];

	inputNhanVien(dsBC, dsHD, soBC, soHD);
	showNhanVien(dsBC, dsHD, soBC, soHD);
	maxLuong(dsBC, dsHD, soBC, soHD);
	return 0;
}

/*test case
5
5
NV01
Ly Nha Ky
3.5
0.6
NV02
Luong A Han
3.2
0.8
NV03
Ha Thi Van
3.45
0.87
NV04
Phung A Ly
3.2
0.7
NV05
Ha Gia Tao
3.55
0.75
NV06
Ng Kim Chien
180
18
0.3
NV07
Ng Cong Hieu
200
19
0.4
NV08
Vu Tien Loc
150
20
0.3
NV09
Tran Thi Van
200
17
0.4
NV10
Ta Van Ninh
200
19
0.4

*/