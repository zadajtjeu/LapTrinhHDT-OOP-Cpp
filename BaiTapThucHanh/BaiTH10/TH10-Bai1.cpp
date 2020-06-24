#include <bits/stdc++.h>

using namespace std;

class STUDENT;
class SCHOOL
{
	string Name, Date;
	friend class FACULTY;
	friend void showSchoolDHCNHN(STUDENT *ds, int n);
};

class FACULTY
{
	string Name,Date;
	SCHOOL x;
public:
	void input()
	{
		cout<<" - School's Name: ";
		getline(cin, x.Name);
		cout<<" - School's Date (dd/mm/yyyy): ";
		getline(cin, x.Date);
		cout<<" - Faculty's Name: ";
		getline(cin, this->Name);
		cout<<" - Faculty's Date (dd/mm/yyyy): ";
		getline(cin, this->Date);
	}
	void output()
	{
		cout<<setw(20)<<x.Name;
		cout<<setw(13)<<x.Date;
		cout<<setw(15)<<this->Name;
		cout<<setw(13)<<this->Date;
	}

	friend void showSchoolDHCNHN(STUDENT *ds, int n);
};

class PERSON
{
protected:
	string Name, Birth, Address;
public:
	PERSON()
	{
		Name = Birth = Address = "NULL";
	}
	void input()
	{
		cout<<" - Student's Name: ";
		getline(cin, Name);
		cout<<" - Birth Day (dd/mm/yyyy): ";
		getline(cin, Birth);
		cout<<" - Address: ";
		getline(cin, Address);
	}
	void output()
	{
		cout<<setw(20)<<left<<Name;
		cout<<setw(13)<<Birth;
		cout<<setw(20)<<Address;
	}
	
};

class STUDENT : private PERSON
{
	FACULTY y;
	string CLass;
	double Score;
public:
	STUDENT()
	{
		CLass = "NULL";
		Score = -1;
	}
	void input()
	{
		PERSON::input();
		y.input();
		cout<<" - CLass' Name: ";
		getline(cin, CLass);
		cout<<" - Score: ";
		cin>>Score;
		cin.ignore();
	}
	void output()
	{
		PERSON::output();
		y.output();
		cout<<setw(10)<<CLass;
		cout<<setw(8)<<right<<Score;
		cout<<endl;
	}

	friend void sortbyScore(STUDENT *ds, int n);
	friend void showSchoolDHCNHN(STUDENT *ds, int n);
	
};

void title()
{
	cout<<setw(20)<<left<<"Stu'Name";
	cout<<setw(13)<<"Birth";
	cout<<setw(20)<<"Address";
	cout<<setw(20)<<"School Name";
	cout<<setw(13)<<"Sch'Date";
	cout<<setw(15)<<"FacultyName";
	cout<<setw(13)<<"Facu'Date";
	cout<<setw(10)<<"CLass";
	cout<<setw(8)<<right<<"Score";
	cout<<endl;
}


void sortbyScore(STUDENT *ds, int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = n-1; j >= i; --j)
		{
			if (ds[j].Score < ds[j-1].Score)
			{
				swap(ds[j],ds[j-1]);
			}
		}
	}
	cout<<endl<<"### Danh sach sinh vien sau khi sap xep ###"<<endl;
	title();
	for (int i = 0; i < n; ++i)
	{
		ds[i].output();
	}
}


void showSchoolDHCNHN(STUDENT *ds, int n)
{
	cout<<endl<<"### Danh sach sinh vien DHCN Ha Noi ###"<<endl;
	title();
	for (int i = 0; i < n; ++i)
	{
		if (ds[i].y.x.Name == "DHCN Ha Noi")
		{
			ds[i].output();
		}
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cout<<" - Nhap so sinh vien: ";
	do
	{
		cin>>n;
		cin.ignore();
	}while(n<=0 || n>=100);

	STUDENT *ds = new STUDENT[n];

	cout<<endl<<"### Nhap danh sach "<<n<<" sinh vien ###"<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin sinh vien thu "<<i+1<<" *"<<endl;
		ds[i].input();
		cout<<endl;
	}

	cout<<endl<<"### Thong tin"<<n<<" sinh vien ###"<<endl;
	title();
	for (int i = 0; i < n; ++i)
	{
		ds[i].output();
	}

	sortbyScore(ds,n);

	showSchoolDHCNHN(ds,n);

	return 0;
}


/* test case
5
Pham Thanh Nam
10/03/2000
Thai Binh
DHCN Ha Noi
10/08/1898
CNTT
05/07/1999
KTPM3
7.5
Luu Xuan Quyen
22/05/2000
Vinh Phuc
DHCN Ha Noi
10/08/1898
CNTT
05/07/1999
KTPM3
8
Nguyen Manh Long
25/06/2000
Thai Binh
DHBK Ha Noi
15/10/1956
SoICT
22/12/1999
HTTT
8.5
Pham Quoc Cuong
05/06/2000
Thai Binh
DHCN Ha Noi
10/08/1898
CNTT
05/07/1999
KHMT
6.5
Dang Phi Long
27/03/2000
Thai Lo
DHCN Ha Noi
10/08/1989
Dien Tu
99/99/1999
Vien Thong
6

*/