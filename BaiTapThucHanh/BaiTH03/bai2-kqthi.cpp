#include <bits/stdc++.h>

using namespace std;

class SINHVIEN
{
protected:
	string hoten;
	int SBD;
public:
	void nhap()
	{
		cout<<"- Ho ten: ";
		cin.ignore();
		getline(cin, hoten);
		cout<<"- Nhap so bao danh: ";
		cin>>SBD;
	}
	
};

class DIEMTHI : public SINHVIEN
{
protected:
	double diem1, diem2;
public:
	void nhap_diem()
	{
		cout<<"- Nhap diem hai mon thi: ";
		cin>>diem1>>diem2;
	}
	
};

class KETQUA : public DIEMTHI
{
	double tong;
public:
	void xuat()
	{
		tong = diem1+diem2;
		cout<<setw(10)<<SBD<<setw(30)<<hoten<<setw(10)<<diem1<<setw(10)<<diem2<<setw(15)<<tong<<endl;
	}
	
};

int main(int argc, char const *argv[])
{
	int n;
	KETQUA sv[100];
	cout<<"Nhap so sinh vien: ";
	do{
		cin>>n;
		if(n<=0 || n>100)
			cout<<endl<<"Nhap lai! ";
	}while(n<=0 || n>100);

	for (int i = 0; i < n; ++i)
	{
		cout<<endl<<"Nhap thong tin thi sinh "<<i+1<<":"<<endl;
		sv[i].nhap();
		sv[i].nhap_diem();
	}

	cout<<endl;
	cout<<setw(10)<<"SBD"<<setw(30)<<"Ho ten TS"<<setw(10)<<"Mon 1"<<setw(10)<<"Mon 2"<<setw(15)<<"Tong Diem"<<endl;
	for (int i = 0; i < n; ++i)
	{
		sv[i].xuat();
	}

	system("PAUSE");
	return 0;
}