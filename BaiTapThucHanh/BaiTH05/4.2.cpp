#include <bits/stdc++.h>
using namespace std;
class Phuongtrinh
{
private:
	double a,b,c;
public:
	Phuongtrinh()
	{
		a=b=c=0;
	}
	Phuongtrinh(double x, double y, double z)
	{
		a=x; b=y; c=z;
	}
	void Nhap();
	void Xuat();
	void Giai();
};

void Phuongtrinh::Nhap()
{
	cout<<"Nhap gia tri a,b,c trong phuong trinh aX^2 + bX +c = 0? ";
	cin>>a>>b>>c;
}
void Phuongtrinh::Xuat()
{
	cout<<"Phuong trinh "<<a<<"X^2 + "<<b<<"X + "<<c<<" = 0"<<endl;
}
void Phuongtrinh::Giai()
{
	if(a==0)
	{
		if(b==0)
			if(c==0)
				cout<<"Phuong trinh vo so nghiem"<<endl;
			else
				cout<<"Phuong trinh vo nghiem"<<endl;
		else
			cout<<"Phuong trinh co nghiem duy nhat X = "<<-c/b<<endl;
	}
	else
	{
		double delta = b*b-4*a*c;
		if (delta>0)
		{
			cout<<"Phuong trinh co 2 nghiem phan biet:"<<endl;
			cout<<"- X1 = "<<(-b+sqrt(delta))/(2*a)<<endl;
			cout<<"- X2 = "<<(-b-sqrt(delta))/(2*a)<<endl;
		}
		else if(delta==0)
			cout<<"Phuong trinh co nghiem kep X1 = X2 = "<<-b/2*a<<endl;
		else
			cout<<"Phuong trinh vo nghiem"<<endl;
	}
}

int main(int argc, char const *argv[])
{
	Phuongtrinh P(2,-3,1), Q;
	P.Xuat();
	P.Giai();
	Q.Nhap();
	Q.Xuat();
	Q.Giai();
	return 0;
}