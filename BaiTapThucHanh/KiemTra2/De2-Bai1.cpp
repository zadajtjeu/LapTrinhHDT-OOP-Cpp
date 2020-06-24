#include <bits/stdc++.h>

using namespace std;
class Student;
class Person
{
protected:
	char hoTen[25];
	int tuoi;
public:
	void Nhap()
	{
		cout<<" - Nhap ho ten: ";
		gets(hoTen);
		cout<<" - Nhap tuoi: ";
		cin>>tuoi;
		fflush(stdin);
	}
	void Xuat()
	{
		cout<<setw(20)<<left<<hoTen;
		cout<<setw(10)<<tuoi;
	}
	friend class School;
};

class School
{
	char tenTruong[20], diaChi[20];
	Person hieutruong;
	friend class Student;
	friend void showStudentinSchool(Student *ds, int n);
};

class Student : private Person
{
	char lop[10], nganh[10];
	School truong;
public:
	void Nhap()
	{
		cout<<"* Thong tin sinh vien: \n";
		Person::Nhap();
		cout<<" - Nhap lop: ";
		gets(lop);
		cout<<" - Nhap nganh: ";
		gets(nganh);
		cout<<" - Nhap ten truong: ";
		gets(truong.tenTruong);
		cout<<" - Nhap dia chi truong: ";
		gets(truong.diaChi);
		cout<<"* Thong tin hieu truong: \n";
		truong.hieutruong.Nhap();
	}

	void Xuat()
	{
		Person::Xuat();
		cout<<setw(10)<<lop;
		cout<<setw(10)<<nganh;
		cout<<setw(20)<<truong.tenTruong;
		cout<<setw(15)<<truong.diaChi;
		truong.hieutruong.Xuat();
		cout<<endl;
	}
	
	friend void showStudentinSchool(Student *ds, int n);
	friend void insertnewStudent(Student *ds, int &n);
};

void title()
{
	cout<<setw(20)<<left<<"Ho ten";
	cout<<setw(10)<<"Tuoi";
	cout<<setw(10)<<"Lop";
	cout<<setw(10)<<"Nganh";
	cout<<setw(20)<<"Truong";
	cout<<setw(15)<<"Dia Chi";
	cout<<setw(20)<<"Hieu truong";
	cout<<setw(10)<<"Tuoi";
	cout<<endl;
}

void showStudentinSchool(Student *ds, int n)
{
	cout<<"\n### SINH VIEN TRUONG DHCNHN ### \n";
	title();
	for (int i = 0; i < n; ++i)
	{
		if (strcmp(ds[i].truong.tenTruong,"DHCNHN") == 0)
		{
			ds[i].Xuat();
		}
	}
}

void insertnewStudent(Student *ds, int &n)
{
	Student newsv;
	int vt;
	cout<<"## Nhap thong tin sinh vien moi: \n";
	newsv.Nhap();
	cout<<"* Nhap vi tri chen: ";
	do{
		cin>>vt;
	}while(vt<=0 || vt>n);
	ds = (Student*)realloc(ds,(n+1)*sizeof(Student));
	for (int i = n; i >= vt-1; --i)
	{
		ds[i] = ds[i-1];
	}

	ds[vt-1] = newsv; n++;

	cout<<"\n### DANH SACH VUA CHEN ###\n";
	title();
	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}

}

int main(int argc, char const *argv[])
{
	int n;
	cout<<"* So sinh vien: ";
	do{
		cin>>n;
		fflush(stdin);
	}while(n<=0 || n>100);
	Student *ds = new Student[n];
	

	cout<<"### NHAP DANH SACH "<<n<<" SINH VIEN ###\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Thong tin sinh vien thu "<<i+1<<" *\n";
		ds[i].Nhap();
	}

	cout<<"\n### NTHONG TIN "<<n<<" SINH VIEN ###\n";
	title();
	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}

	showStudentinSchool(ds,n);
	insertnewStudent(ds,n);
	return 0;
}