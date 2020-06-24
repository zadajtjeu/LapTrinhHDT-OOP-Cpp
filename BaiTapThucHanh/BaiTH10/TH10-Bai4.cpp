#include <bits/stdc++.h>

using namespace std;

class ARRAY
{
	float a[100];
	int n;
public:
	void input()
	{
		cout<<"# Nhap so luong phan tu mang: ";
		do
		{
			cin>>n;
		}while(n<=0 || n>100);

		cout<<"# Nhap "<<n<<" phan tu trong mang: ";
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
	}

	void output()
	{
		cout<<"* Cac phan tu cua mang *"<<endl;
		for (int i = 0; i < n; ++i)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}

	void operator--()
	{
		for (int i = 1; i < n; ++i)
		{
			for (int j = n-1; j >= i; --j)
			{
				if (a[j] < a[j-1])
				{
					swap(a[j],a[j-1]);
				}
			}
		}

	}

	void operator++()
	{
		for (int i = 1; i < n; ++i)
		{
			for (int j = n-1; j >= i; --j)
			{
				if (a[j] > a[j-1])
				{
					swap(a[j],a[j-1]);
				}
			}
		}

	}
};

int main(int argc, char const *argv[])
{
	ARRAY mang;
	mang.input();
	mang.output();
	--mang;
	cout<<"\n======== Sap Xep Tang ========\n";
	mang.output();
	++mang;
	cout<<"\n======== Sap Xep Giam ========\n";
	mang.output();
	return 0;
}