#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class NhanVien;
class Date
{
	int day, month, year;
	friend class NhanVien;
};


class PhongBan
{
	int maPb;
	char tenPb[50];
	char truongPhong[10];
	int soNv;
	friend class NhanVien;
	friend void showFinanceDepartment(NhanVien *ds, int n);
};

class NhanVien
{
	int maNv;
	char hoDem[25];
	char ten[10];
	Date ngaySinh;
	PhongBan phong;
public:
	void nhap()
	{
		cout<<" - Nhap ma nhan vien: ";
		cin>>maNv;
		cout<<" - Nhap ho + ten dem: ";
		fflush(stdin);
		gets(hoDem);
		cout<<" - Nhap ten nhan vien: ";
		gets(ten);
		cout<<" - Nhap ngay sinh NV (dd/mm/yyyy) : ";
		scanf("%d/%d/%d",&ngaySinh.day,&ngaySinh.month,&ngaySinh.year);
		cout<<" - Nhap thong tin phong ban cua nhan vien: "<<endl;
		{
			cout<<" 	+ Nhap ma phong ban: ";
			cin>>phong.maPb;
			cout<<" 	+ Nhap ten phong ban: ";
			fflush(stdin);
			gets(phong.tenPb);
			cout<<" 	+ Nhap ten truong phong: ";
			gets(phong.truongPhong);
			cout<<" 	+ Nhap so nha vien PB: ";
			cin>>phong.soNv;
		}
	}

	void xuat()
	{
		cout<<setw(5)<<maNv;
		cout<<setw(15)<<hoDem;
		cout<<setw(8)<<ten;
		cout<<setw(5)<<ngaySinh.day<<"/"<<setw(2)<<ngaySinh.month<<"/"<<setw(4)<<ngaySinh.year;
		cout<<setw(5)<<phong.maPb;
		cout<<setw(15)<<phong.tenPb;
		cout<<setw(15)<<phong.truongPhong;
		cout<<setw(8)<<phong.soNv;
		cout<<endl;
	}
	friend void showFinanceDepartment(NhanVien *ds, int n);
	friend void sortName(NhanVien *ds, int n);
	friend void insertEmployee(NhanVien *ds, int &n);
	friend void deleteEmployee(NhanVien *ds, int &n, int employeeNumber);
};

void showFinanceDepartment(NhanVien *ds, int n)
{
	cout<<endl;
	cout<<"======================= Danh sach nhan vien phong tai chinh ======================="<<endl;

	cout<<setw(5)<<"Ma NV";
	cout<<setw(15)<<"Ho Dem";
	cout<<setw(8)<<"Ten";
	cout<<setw(11)<<"Ngay Sinh";
	cout<<setw(7)<<"Ma PB";
	cout<<setw(15)<<"Ten PB";
	cout<<setw(15)<<"Truong phong";
	cout<<setw(8)<<"So NV";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		if (strcmp(ds[i].phong.tenPb,"Tai Chinh")==0)
		{
			ds[i].xuat();
		}
	}

}

void sortName(NhanVien *ds, int n)
{
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int check1=strcmp(ds[i].ten,ds[j].ten);
			if(check1>0){
				NhanVien temp=ds[i];
				ds[i]=ds[j];
				ds[j]=temp;
			}
			else if(check1==0){
				int check2=strcmp(ds[i].hoDem,ds[j].hoDem);
				if(check2>0){
					NhanVien temp=ds[i];
					ds[i]=ds[j];
					ds[i]=temp;
				}
			}
		}
	}

	cout<<endl;
	cout<<"=========================== Danh sach nhan vien sap xep ==========================="<<endl;

	cout<<setw(5)<<"Ma NV";
	cout<<setw(15)<<"Ho Dem";
	cout<<setw(8)<<"Ten";
	cout<<setw(11)<<"Ngay Sinh";
	cout<<setw(7)<<"Ma PB";
	cout<<setw(15)<<"Ten PB";
	cout<<setw(15)<<"Truong phong";
	cout<<setw(8)<<"So NV";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].xuat();
	}
}

void insertEmployee(NhanVien *ds, int &n)
{
	int k;
	NhanVien add;
	cout<<endl;
	cout<<"=========================== Chen 1 nhan vien vao vi tri k ==========================="<<endl;
	cout<<"* Nhap vi tri k: ";
	do{
		cin>>k;
	}while(k<0||k>n);
	cout<<"* Nhap thong tin nhan vien: "<<endl;
	add.nhap();

	//cap phat dong bo nho
	ds = (NhanVien*)realloc(ds,(n+1)*sizeof(NhanVien));
	for (int i = n; i > k-1; i--)
	{
		ds[i] = ds[i-1];
	}
	n++;
	ds[k-1] = add;

	cout<<endl;
	cout<<"=========================== Danh sach nhan vien sau khi chen ==========================="<<endl;

	cout<<setw(5)<<"Ma NV";
	cout<<setw(15)<<"Ho Dem";
	cout<<setw(8)<<"Ten";
	cout<<setw(11)<<"Ngay Sinh";
	cout<<setw(7)<<"Ma PB";
	cout<<setw(15)<<"Ten PB";
	cout<<setw(15)<<"Truong phong";
	cout<<setw(8)<<"So NV";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].xuat();
	}
	
}


void deleteEmployee(NhanVien *ds, int &n, int employeeNumber)
{
	for (int i = 0; i < n; ++i)
	{
		if (ds[i].maNv == employeeNumber)
		{
			for (int j = i; j < n; ++j)
			{
				ds[j] = ds[j+1];
			}
			n--;
		}
	}

	cout<<endl;
	cout<<"=================== Danh sach nhan vien sau khi xoa nhan vien ma "<<employeeNumber<<" ==================="<<endl;

	cout<<setw(5)<<"Ma NV";
	cout<<setw(15)<<"Ho Dem";
	cout<<setw(8)<<"Ten";
	cout<<setw(11)<<"Ngay Sinh";
	cout<<setw(7)<<"Ma PB";
	cout<<setw(15)<<"Ten PB";
	cout<<setw(15)<<"Truong phong";
	cout<<setw(8)<<"So NV";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].xuat();
	}
}


int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so nhan vien: ";
	cin>>n;
	NhanVien *ds = new NhanVien[n];

	cout<<"============================= Nhap danh sach "<<n<<" nhan vien ============================="<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin nhan vien thu "<<i+1<<": "<<endl;
		ds[i].nhap();
	}

	showFinanceDepartment(ds,n);
	sortName(ds,n);
	insertEmployee(ds,n);
	deleteEmployee(ds,n,123);
	return 0;
}

/* test case
6
456
Cao Nguyen Duy
Anh
22/12/2000
12
Tai Chinh
Nam
3
567
Pham Quang
Trung
14/03/2000
12
Tai Chinh
Nam
3
234
Lai Van
Sang
25/09/2000
22
Kinh Doanh
Dung
2
678
Nguyen Huu
Dai
30/06/2000
12
Tai Chinh
Nam
3
123
Luu Xuan
Quyen
11/11/1999
23
Ky Thuat
Nguyen
1
654
Duong Dinh
Huy
25/11/2000
22
Kinh Doanh
Dung
2
3
123
Ngo Van
Tu
01/01/2001
26
Nhan Su
Nhan
1
*/