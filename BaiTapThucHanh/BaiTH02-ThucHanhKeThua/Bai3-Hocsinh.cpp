#include <bits/stdc++.h>

using namespace std;

class PERSON
{
protected:
	char hoTen[50], ngaySinh[12], queQuan[100];

public:
	PERSON()
	{
		strcpy(hoTen,"Null"); strcpy(ngaySinh,"Null"); strcpy(queQuan,"Null");

	}
};

class DIEM
{
protected:
	int diemToan, diemLy, diemHoa;
public:
	DIEM()
	{
		diemToan=diemLy=diemHoa=0;
	}
};

class HOCSINH : private PERSON, private DIEM
{
private:
	char lop[30];
	int tongDiem;
public:
	HOCSINH()
	{
		strcpy(lop,"Null");
		tongDiem=0;
	}
	void Nhap()
	{
		cout<<"Nhap ho ten: ";
		fflush(stdin);
		gets(hoTen);
		cout<<"Nhap ngay sinh(dd/mm/yyyy): ";
		gets(ngaySinh);
		cout<<"Nhap que quan: ";
		gets(queQuan);
		cout<<"Nhap lop: ";
		gets(lop);
		cout<<"Nhap diem toan: ";
		cin>>diemToan;
		cout<<"Nhap diem ly: ";
		cin>>diemLy;
		cout<<"Nhap diem hoa: ";
		cin>>diemHoa;
		tongDiem = diemToan+diemLy+diemHoa;
	}

	void Xuat()
	{
		cout<<setw(20)<<hoTen<<setw(15)<<ngaySinh<<setw(20)<<queQuan<<setw(15)<<lop<<setw(10)<<diemToan<<setw(10)<<diemLy<<setw(10)<<diemHoa<<setw(10)<<tongDiem<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	HOCSINH a,b[2];
	int n=2;
	for (int i = 0; i < n; ++i)
	{
		cout<<"Nhap thong tin hoc sinh thu "<<i+1<<endl;
		b[i].Nhap();
	}

	cout<<setw(20)<<"Ho ten"<<setw(15)<<"Ngay sinh"<<setw(20)<<"Que quan"<<setw(15)<<"Lop"<<setw(10)<<"Diem Toan"<<setw(10)<<"Diem Ly"<<setw(10)<<"Diem Hoa"<<setw(10)<<"Tong"<<endl;
	a.Xuat();
	for (int i = 0; i < n; ++i)
	{
		b[i].Xuat();
	}
	system("PAUSE");
	return 0;
}

/*Du lieu test
Cao Nguyen Duy Anh
26/10/2000
Ha Noi
KTPM3
7
8
9
Nguyen Trung Anh
17/11/1999
Yen Bai
KTPM3
8
8
9
*/