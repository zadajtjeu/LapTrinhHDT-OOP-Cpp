#include <iostream>

using namespace std;

class Complex
{
	float a,b;
public:
	Complex()
	{
		a=b=0;
	}
	Complex(float x, float y)
	{
		a=x; b=y;
	}
	Complex operator+(Complex P)
	{
		Complex S;
		S.a = this->a + P.a;
		S.b = this->b + P.b;
		return S;
	}
	friend ostream& operator<<(ostream& out, Complex P);
	friend istream& operator>>(istream& in, Complex &P);
};

istream& operator>>(istream& in, Complex &P)
{
	in>>P.a>>P.b;
	return in;
}

ostream& operator<<(ostream& out, Complex P)
{
	out<<P.a<<" + "<<P.b<<"i";
	return out;
}

int main(int argc, char const *argv[])
{
	Complex *sophuc;
	int n;
	cout<<"## Nhap n ? ";
	do
	{
		cin>>n;
	}while(n<1);
	sophuc = new Complex[n];
	for (int i = 0; i < n; ++i)
	{
		cout<<"# Nhap so phuc thu "<<i+1<<"? (VD: a+bi thi nhap a b) ";
		cin>>sophuc[i];
	}


	//tinh tong

	Complex sum;
	for (int i = 0; i < n; ++i)
	{
		sum = sum+sophuc[i];
		if (i == n-1)
			cout<<"("<<sophuc[i]<<") = ";
		else
			cout<<"("<<sophuc[i]<<") + ";
	}
	cout<<sum<<endl;

	return 0;
}