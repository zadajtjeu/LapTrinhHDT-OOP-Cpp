#include <bits/stdc++.h>

using namespace std;

class PRINTER
{
protected:
	int trongluong, namsx, tocdo;
	string hangsx;
};

class DOTPRINTER : private PRINTER
{
private:
	int matdokim;
public:
	void Nhap()
	{
		cout<<"Nhap hang san xuat: ";
		getline(cin, hangsx);
		cout<<"Nhap nam san xuat: ";
		cin>>namsx;
		cout<<"Nhap trong luong: ";
		cin>>trongluong;
		cout<<"Nhap toc do in(trang/phut): ";
		cin>>tocdo;
		cout<<"Nhap mat do kim kim: ";
		cin>>matdokim;
		cin.ignore(); 
	}
	void Xuat()
	{
		cout<<setw(10)<<hangsx;
		cout<<setw(8)<<namsx;
		cout<<setw(10)<<trongluong;
		cout<<setw(20)<<tocdo;
		cout<<setw(15)<<matdokim;
		cout<<endl;
	}
};

class LASERPRINTER : private PRINTER
{
private:
	int dophangiai;
public:
	void Nhap()
	{
		cout<<"Nhap hang san xuat: ";
		getline(cin, hangsx);
		cout<<"Nhap nam san xuat: ";
		cin>>namsx;
		cout<<"Nhap trong luong: ";
		cin>>trongluong;
		cout<<"Nhap toc do in(trang/phut): ";
		cin>>tocdo;
		cout<<"Nhap do phan giai: ";
		cin>>dophangiai;
		cin.ignore(); 
	}
	void Xuat()
	{
		cout<<setw(10)<<hangsx;
		cout<<setw(8)<<namsx;
		cout<<setw(10)<<trongluong;
		cout<<setw(20)<<tocdo;
		cout<<setw(15)<<dophangiai;
		cout<<endl;
	}
};

int main(int argc, char const *argv[])
{
	DOTPRINTER inkim;
	LASERPRINTER inlaser;
	cout<<"* Nhap thong tin may in kim: "<<endl;
	inkim.Nhap();
	cout<<endl;

	cout<<"* Nhap thong tin may in laser: "<<endl;
	inlaser.Nhap();
	cout<<endl;

	cout<<"================= MAY IN KIM ================="<<endl;
	cout<<setw(10)<<"Hang SX";
	cout<<setw(8)<<"Nam SX";
	cout<<setw(10)<<"T.Luong";
	cout<<setw(20)<<"Toc do (trang/phut)";
	cout<<setw(15)<<"Mat do kim";
	cout<<endl;
	inkim.Xuat();

	cout<<endl;

	cout<<"================= MAY IN LASER ================"<<endl;
	cout<<setw(10)<<"Hang SX";
	cout<<setw(8)<<"Nam SX";
	cout<<setw(10)<<"T.Luong";
	cout<<setw(20)<<"Toc do (trang/phut)";
	cout<<setw(15)<<"Do Phan Giai";
	cout<<endl;
	inlaser.Xuat();

	return 0;
}

/*
Du lieu test
Canon
2018
7
30
5
HP
2017
6
8
1200

*/