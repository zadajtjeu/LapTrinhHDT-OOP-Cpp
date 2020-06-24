#include <bits/stdc++.h>

using namespace std;

class PTS1
{
private:
	double x;
public:
	PTS1 operator-(PTS1 S)
	{
		PTS1 Temp;
		Temp.x = x - S.x;
		return Temp;
	}
	PTS1 operator/(PTS1 S)
	{
		PTS1 Temp;
		Temp.x = x / S.x;
		return Temp;
	}

	friend ostream& operator<<(ostream& out, PTS1 S);
	friend istream& operator>>(istream& in, PTS1 &S);
};

istream& operator>>(istream& in, PTS1 &S)
{
	in>>S.x;
	return in;
}

ostream& operator<<(ostream& out, PTS1 S)
{
	out<<S.x;
	return out;
}

int main(int argc, char const *argv[])
{
	PTS1 x1, x2;
	cout<<" - Nhap vao 2 so thuc x1,x2: ";
	cin>>x1;
	cin>>x2;
	PTS1 hieu = x1-x2;
	PTS1 thuong = x1/x2;
	cout<<"Hieu x1-x2 = "<<hieu<<endl;
	cout<<"Thuong x1/x2 = "<<thuong<<endl;
	return 0;
}