#include <bits/stdc++.h>

using namespace std;

class MAYIN
{
protected:
	int trongluong, namsx;
	string hangsx;
public:
	MAYIN()
	{
		trongluong=0; namsx=0;
		hangsx="Null";
	}
};

class MayInKim : private MAYIN
{
private:
	int sokim, tocdoin;
public:
	MayInKim()
	{
		sokim=0; tocdoin=0;
	}
	void Nhap()
	{
		cout<<"Nhap hang san xuat: ";
		cin.ignore(); 
		getline(cin, hangsx);
		cout<<"Nhap nam san xuat: ";
		cin>>namsx;
		cout<<"Nhap trong luong: ";
		cin>>trongluong;
		cout<<"Nhap so kim: ";
		cin>>sokim;
		cout<<"Nhap toc do in(trang/phut): ";
		cin>>tocdoin;
	}
	void Xuat()
	{
		cout<<setw(10)<<hangsx<<setw(15)<<namsx<<setw(15)<<trongluong<<setw(15)<<sokim<<setw(20)<<tocdoin<<" trang/phut"<<endl;
	}
};

class MayInLaser : private MAYIN
{
private:
	int dophangiai, tocdoin;
public:
	MayInLaser()
	{
		dophangiai=0; tocdoin=0;
	}
	void Nhap()
	{
		cout<<"Nhap hang san xuat: ";
		cin.ignore(); 
		getline(cin, hangsx);
		cout<<"Nhap nam san xuat: ";
		cin>>namsx;
		cout<<"Nhap trong luong: ";
		cin>>trongluong;
		cout<<"Nhap do phan giai: ";
		cin>>dophangiai;
		cout<<"Nhap toc do in(trang/phut): ";
		cin>>tocdoin;
	}
	void Xuat()
	{
		cout<<setw(10)<<hangsx<<setw(15)<<namsx<<setw(15)<<trongluong<<setw(15)<<dophangiai<<" dpi"<<setw(20)<<tocdoin<<" trang/phut"<<endl;
	}
};

int main(int argc, char const *argv[])
{
	int n,m;
	cout<<"Nhap so luong may in Kim: ";
	do{
		cin>>n;
		if(n<=0||n>20)
			cout<<endl<<"Nhap lai! ";
	}while(n<=0||n>20);

	cout<<"Nhap so luong may in Laser: ";
	do{
		cin>>m;
		if(m<=0||m>20)
			cout<<endl<<"Nhap lai! ";
	}while(m<=0||m>20);

	cout<<endl<<"---------------------------------------"<<endl;
	cout<<"Nhap thong tin "<<n<<" may in Kim:"<<endl;
	MayInKim kim[n];
	for (int i = 0; i < n; ++i)
	{
		cout<<endl<<"May thu "<<i+1<<":"<<endl;
		kim[i].Nhap();
	}

	cout<<endl<<"---------------------------------------"<<endl;
	cout<<"Nhap thong tin "<<m<<" may in Laser:"<<endl;
	MayInLaser laser[m];
	for (int i = 0; i < m; ++i)
	{
		cout<<endl<<"May thu "<<i+1<<":"<<endl;
		laser[i].Nhap();
	}

	cout<<endl<<endl<<"--------------May In Kim-----------------"<<endl;
	cout<<setw(10)<<"Hang SX"<<setw(15)<<"Nam SX"<<setw(15)<<"Trong Luong"<<setw(15)<<"So Kim"<<setw(20)<<"Toc do In"<<endl;
	for (int i = 0; i < n; ++i)
	{
		kim[i].Xuat();
	}
	cout<<endl<<endl<<"--------------May In Laser----------------"<<endl;
	cout<<setw(10)<<"Hang SX"<<setw(15)<<"Nam SX"<<setw(15)<<"Trong Luong"<<setw(15)<<"Do phan giai"<<setw(20)<<"Toc do In"<<endl;
	for (int i = 0; i < m; ++i)
	{
		laser[i].Xuat();
	}
	system("PAUSE");
	return 0;
}

/*
Du lieu test
5
4
Epson
2016
5
24
5
Olivetti
2014
4
24
4
Oki
2017
5
64
12
Microline
2014
6
12
10
Pantum
2017
6
64
13
Canon
2018
7
2600
12
HP
2017
6
600
18
Brother
2017
5
1200
32
JetPro
2019
6
1200
22

*/