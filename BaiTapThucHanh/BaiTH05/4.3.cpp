#include <bits/stdc++.h>
using namespace std;

class ARRAY
{
private:
	int *VALUE;
	int n;
public:
	ARRAY()
	{
		n=0;
	}
	ARRAY(int gt)
	{
		n=gt;
		VALUE = new int[n]();

	}
	~ARRAY(){
		n=0;
		delete [] VALUE;
		cout<<"Ham huy duoc goi"<<endl;
	}
	void NHAP();
	void XUAT();
};

void ARRAY::NHAP()
{
	cout<<"Nhap "<<n<<" phan tu cho mang: "<<endl;
	for (int i = 0; i < n; ++i)
	{
		cin>>*(VALUE+i);
	}
}
void ARRAY::XUAT()
{
	cout<<"Cac phan tu trong mang: "<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<*(VALUE+i)<<" ";
	}
	cout<<endl;
}

int main(int argc, char const *argv[])
{
	ARRAY a(5), A(10);
	a.XUAT();
	A.NHAP();
	A.XUAT();
	return 0;
}