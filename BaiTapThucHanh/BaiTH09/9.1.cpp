#include <bits/stdc++.h>
using namespace std;

class Vector
{
	double x;
	double y;
public:
	void Nhap()
	{
		cout<<"Nhap toa do vector (x,y)? ";
		cin>>x>>y;
	}
	void Xuat()
	{
		cout<<"("<<x<<","<<y<<")";
	}
	friend Vector operator+(Vector A, Vector B);
	friend Vector operator-(Vector A, Vector B);
	
};

Vector operator+(Vector A, Vector B)
{
	Vector tong;
	tong.x = A.x + B.x;
	tong.y = A.y + B.y;
	return tong;
}

Vector operator-(Vector A, Vector B)
{
	Vector hieu;
	hieu.x = A.x - B.x;
	hieu.y = A.y - B.y;
	return hieu;
}

int main(int argc, char const *argv[])
{
	Vector A,B;
	cout<<"Vector A:"; A.Nhap();
	cout<<"Vector B:"; B.Nhap();
	cout<<" A"; A.Xuat();
	cout<<" B"; B.Xuat();
	cout<<"\n A+B="; (A+B).Xuat();
	cout<<"\n A-B="; (A-B).Xuat();
	return 0;
}