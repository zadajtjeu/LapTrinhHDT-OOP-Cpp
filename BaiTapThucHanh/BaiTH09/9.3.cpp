#include <bits/stdc++.h>
using namespace std;

class complexNumber
{
private:
	double phanThuc;
	double phanAo;
public:
	complexNumber()
	{
		phanThuc = 0; phanAo = 0;
	}
	complexNumber(double a, double b)
	{
		phanThuc = a; phanAo = b;
	}
	friend ostream& operator<<(ostream& out, complexNumber);
	friend istream& operator>>(istream& in, complexNumber &SP);
	friend complexNumber operator+(complexNumber, complexNumber);
	friend complexNumber operator-(complexNumber, complexNumber);
};

ostream& operator<<(ostream& out, complexNumber SP)
{
	out<<SP.phanThuc<<" + "<<SP.phanAo<<"*i"<<endl;
	return out;
}
istream& operator>>(istream& in, complexNumber &SP)
{
	cout<<" - Nhap phan thuc va phan ao cua so phuc (phanThuc + phanAo*i)? ";
	in>>SP.phanThuc>>SP.phanAo;
	return in;
}

complexNumber operator+(complexNumber SP1, complexNumber SP2)
{
	complexNumber tong;
	tong.phanThuc = SP1.phanThuc + SP2.phanThuc;
	tong.phanAo = SP1.phanAo + SP2.phanAo;
	return tong;
}

complexNumber operator-(complexNumber SP1, complexNumber SP2)
{
	complexNumber hieu;
	hieu.phanThuc = SP1.phanThuc - SP2.phanThuc;
	hieu.phanAo = SP1.phanAo - SP2.phanAo;
	return hieu;
}

int main(int argc, char const *argv[])
{
	complexNumber SP1, SP2, SP3, SP4;
	cout<<"So phuc SP1: "<<endl;
	cin>>SP1;
	cout<<" - SP1 = "<<SP1;

	cout<<"So phuc SP2: "<<endl;
	cin>>SP2;
	cout<<" - SP2 = "<<SP2;

	SP3 = SP1+SP2;
	SP4 = SP1-SP2;
	cout<<endl;
	cout<<" + SP3 = SP1 + SP2 = "<<SP3;
	cout<<" + SP4 = SP1 - SP2 = "<<SP4;
	return 0;
}