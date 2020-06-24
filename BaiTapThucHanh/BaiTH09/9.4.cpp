#include <bits/stdc++.h>

using namespace std;

class TamThucBacHai
{
private:
	float a,b,c;
public:
	TamThucBacHai()
	{
		a=b=c=0;
	}
	TamThucBacHai(float a1, float b1, float c1)
	{
		this->a = a1;
		this->b = b1;
		this->c = c1;
	}

	TamThucBacHai operator--()
	{
		TamThucBacHai S;
		S.a = -a;
		S.b = -b;
		S.c = -c;
		return S;
	}

	TamThucBacHai operator+(TamThucBacHai P)
	{
		TamThucBacHai S;
		S.a = a+P.a;
		S.b = b+P.b;
		S.c = c+P.c;
		return S;
	}

	TamThucBacHai operator-(TamThucBacHai P)
	{
		TamThucBacHai S;
		S.a = a-P.a;
		S.b = b-P.b;
		S.c = c-P.c;
		return S;
	}

	friend ostream& operator<<(ostream& out, TamThucBacHai S);
	
};

ostream& operator<<(ostream& out, TamThucBacHai S)
{
	out<<S.a<<"x2 + "<<S.b<<"x + "<<S.c;
	return out;
}


int main(int argc, char const *argv[])
{
	TamThucBacHai P1(2,3,1), P2(1,4,2), S1, S2;
	cout<<"* Tam thuc ban dau: \n";
	cout<<P1<<endl<<P2<<endl;
	S1=--P1;
	S2=--P2;
	cout<<"* Tam thuc da doi dau: \n";
	cout<<S1<<endl<<S2<<endl;
	cout<<"("<<S1<<") + ("<<S2<<") = "<<S1+S2<<endl;
	cout<<"("<<S1<<") - ("<<S2<<") = "<<S1-S2<<endl;
	
	return 0;
}