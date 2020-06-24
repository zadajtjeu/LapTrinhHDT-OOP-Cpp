#include <iostream>

using namespace std;

class Vector
{
private:
	int n;
	float *a;
public:
	Vector()
	{
		n = 0;
		a= NULL;
	}
	Vector(int n)
	{
		this->n=n;
		a = new float[n];
	}
	Vector(int n, float a[])
	{
		this->n = n;
		this->a = new float[this->n];
		for (int i = 0; i < this->n; ++i)
		{
			this->a[i] = a[i];
		}
	}

	float maxVector()
	{
		float max = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (max < a[i])
			{
				max = a[i];
			}
		}
		return max;
	}

	float minVector()
	{
		float min = a[0];
		for (int i = 1; i < n; ++i)
		{
			if (min > a[i])
			{
				min = a[i];
			}
		}
		return min;
	}
	~Vector()
	{
		n = 0;
		delete [] a;
	}
	friend ostream& operator<<(ostream& out, Vector VT);
	friend istream& operator>>(istream& in, Vector &VT);
};

istream& operator>>(istream& in, Vector &VT)
{
	cout<<"- Nhap chieu cua vector? ";
	in>>VT.n;
	VT.a = new float[VT.n];
	cout<<"- Nhap thanh phan cua vector? (VD vector 2 chieu (2,3) nhap 2 3) ";
	for (int i = 0; i < VT.n; ++i)
	{
		in>>VT.a[i];
	}

	return in;
}

ostream& operator<<(ostream& out, Vector VT)
{
	out<<"(";
	for (int i = 0; i < VT.n; ++i)
	{
		out<<VT.a[i]<<",";
	}
	out<<")";

	return out;
}

int main(int argc, char const *argv[])
{
	    float b[10] = {5, 4, 3, 2, 1, -1, -2, -3, -4, -5};
    vector x(10, b);
    cout << "max[b] = " << x.maxVector() << endl;
    cout << "min[b] = " << x.minVector() << endl;
    cout << "- Thong tin mang khoi tao X: " << x;

    vector c;
    cout << "-- Nhap du lieu cho vector --" << endl;    cin >> c;
    cout << "- Gia tri nho nhat cua vector: " << c.minVector() << endl;
    cout << "- Gia tri lon nhat cua vector: " << c.maxVector() << endl;
    cout << "- Thong tin mang nhap C: " << c;
}