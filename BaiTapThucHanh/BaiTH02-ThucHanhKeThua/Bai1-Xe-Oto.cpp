#include <bits/stdc++.h>

using namespace std;

class XE
{
protected:
	string Nhanhieu;
	long long gia;
	int namsx;
public:
	XE()
	{
		Nhanhieu = "Null";
		gia = 0;
		namsx = 0;
	}
	XE(string nh, long long g, int nam)
	{
		Nhanhieu = nh;
		gia = g;
		namsx = nam;
	}
};

class OTO : private XE
{
private:
	int chongoi, trongtai;
public:
	OTO()
	{
		chongoi=0; trongtai=0;
	}
	OTO(string nh, long long gia, int nam, int cho, int tai):XE(nh,gia,nam)
	{
		chongoi=cho; trongtai=tai;
	}
	void Nhap()
	{
		cout<<"Nhap nhan hieu xe: ";
		cin.ignore(); 
		getline(cin, Nhanhieu);
		cout<<"Nhap gia: ";
		cin>>gia;
		cout<<"Nhap nam san xuat: ";
		cin>>namsx;
		cout<<"Nhap so cho ngoi: ";
		cin>>chongoi;
		cout<<"Nhap trong tai xe: ";
		cin>>trongtai;
	}
	void Xuat()
	{
		cout<<setw(10)<<Nhanhieu<<setw(15)<<gia<<setw(15)<<namsx<<setw(15)<<chongoi<<setw(15)<<trongtai<<endl;
	}
};

int main(int argc, char const *argv[])
{
	OTO xe[20];
	int n;
	cout<<"Nhap so luong xe: ";
	do{
		cin>>n;
		if(n<=0||n>20)
			cout<<endl<<"Nhap lai! ";
	}while(n<=0||n>20);

	cout<<"-------------------------------------------------------"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<endl<<"Nhap thong tin xe thu "<<i+1<<":"<<endl;
		xe[i].Nhap();
	}


	cout<<endl;
	cout<<setw(10)<<"Nhan hieu"<<setw(15)<<"Gia"<<setw(15)<<"Nam SX"<<setw(15)<<"Cho ngoi"<<setw(15)<<"Trong tai"<<endl;
	for (int i = 0; i < n; ++i)
	{
		xe[i].Xuat();
	}
	system("PAUSE");
	return 0;
}

/*
Du lieu test
5
Mercedes
4567000000
2009
7
1
Hyundai
765000000
2016
5
1
Mazda
456789123
2018
4
1
Ford
765098000
2011
7
1
Mitsubishi
345000000
2007
12
2

*/