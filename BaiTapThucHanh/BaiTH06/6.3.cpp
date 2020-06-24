#include <bits/stdc++.h>

using namespace std;

class ELECTRONIC
{
protected:
	double congsuat, dienap;
public:
	ELECTRONIC(double cs, double da)
	{
		congsuat = cs;
		dienap = da;
	}
	
};

class MAYGIAT:private ELECTRONIC
{
	double dungtich;
	string loai;
public:
	MAYGIAT(double dt, string l, double a, double b):ELECTRONIC(a,b)
	{
		dungtich = dt;
		loai = l;
	}

	void XUAT()
	{
		cout<<" - Dung tich: "<<dungtich<<"kg"<<endl;
		cout<<" - Loai: "<<loai<<endl;
		cout<<" - Cong suat: "<<congsuat<<endl;
		cout<<" - Dien app: "<<dienap<<endl;
	}
	
};

class TULANH:private ELECTRONIC
{
	double dungtich;
	int songan;
public:
	TULANH(double dt, int ngan, double a, double b):ELECTRONIC(a,b)
	{
		dungtich = dt;
		songan = ngan;
	}
	void XUAT()
	{
		cout<<" - Dung tich: "<<dungtich<<"l"<<endl;
		cout<<" - So ngan: "<<songan<<endl;
		cout<<" - Cong suat: "<<congsuat<<endl;
		cout<<" - Dien app: "<<dienap<<endl;
	}
};

int main(int argc, char const *argv[])
{
	MAYGIAT a(10,"Dung",5000,220);
	TULANH b(20, 2, 4000, 220);

	cout<<"* May giat:"<<endl;
	a.XUAT();
	cout<<"* Tu lanh:"<<endl;
	b.XUAT();
	return 0;
}