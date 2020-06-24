#include <bits/stdc++.h>

using namespace std;

class PhanSo
{
private:
	double tu, mau;
public:
	PhanSo()
	{
		tu = 0; mau = 1;
	}
	PhanSo operator*(PhanSo P)
	{
		PhanSo N;
		N.tu = tu*P.tu;
		N.mau = mau*P.mau;
		return N;
	}

	PhanSo operator/(PhanSo P)
	{
		PhanSo C;
		C.tu = tu*P.mau;
		C.mau = mau*P.tu;
		return C;
	}

	PhanSo operator+(PhanSo P)
	{
		PhanSo C;
		C.tu = tu*P.mau + mau*P.tu;
		C.mau = mau*P.mau;
		return C;
	}

	PhanSo operator-(PhanSo P)
	{
		PhanSo C;
		C.tu = tu*P.mau - mau*P.tu;
		C.mau = mau*P.mau;
		return C;
	}

	friend istream& operator>>(istream& in, PhanSo &P);
	friend ostream& operator<<(ostream& out, PhanSo P);

};

istream& operator>>(istream& in, PhanSo &P)
{
	cout<<" ,nhap tu va mau cua phan so: ";
	in>>P.tu>>P.mau;
	return in;
}

ostream& operator<<(ostream& out, PhanSo P)
{
	out<<P.tu<<"/"<<P.mau;
	return out;
}

int main(int argc, char const *argv[])
{
	PhanSo A, B;
	cout<<"Phan so A";
	cin>>A;
	cout<<A<<endl;
	cout<<"Phan so B";
	cin>>B;
	cout<<B<<endl;
	cout<<"A*B = "<<A*B<<endl;
	cout<<"A:B = "<<A/B<<endl;
	cout<<"A+B = "<<A+B<<endl;
	cout<<"A-B = "<<A-B<<endl;
	return 0;
}