#include <bits/stdc++.h>

using namespace std;
class SACH;
class NXB
{
	char tenNXB[20], diachi[20];
	friend class SACH;
	friend void sort(SACH *ds, int n);
};

class TACGIA
{
private:
	char tenTG[20], diachi[20];
public:
	void Nhap()
	{
		cout<<" - Nhap ten tac gia: ";
		gets(this->tenTG);
		cout<<" - Nhap dia chi tac gia: ";
		gets(this->diachi);
	}
	void Xuat()
	{
		cout<<setw(15)<<this->tenTG;
		cout<<setw(10)<<this->diachi;
	}
	friend void xuatSachQNT(SACH *ds, int n);
};


class SACH
{
private:
	char tenSach[25];
	TACGIA x;
	NXB y;
public:
	void Nhap()
	{
		cout<<" - Nhap ten sach: ";
		fflush(stdin);
		gets(this->tenSach);
		x.Nhap();
		cout<<" - Nhap ten NXB: ";
		gets(y.tenNXB);
		cout<<" - Nhap dia chi NXB: ";
		gets(y.diachi);
	}

	void Xuat()
	{
		cout<<setw(20)<<tenSach;
		x.Xuat();
		cout<<setw(15)<<y.tenNXB;
		cout<<setw(10)<<y.diachi;
	}
	friend void xuatSachQNT(SACH *ds, int n);
	friend void editSach(SACH *ds, int n);
	friend void insert(SACH *ds, int &n);
	friend void sort(SACH *ds, int n);
};

void xuatSachQNT(SACH *ds, int n)
{
	int check = 0;
	cout<<"\n=========== SACH CUA QUACH TUAN NGOC ===========\n";

	cout<<setw(20)<<"Ten Sach";
	cout<<setw(15)<<"Ten TG";
	cout<<setw(10)<<"DC TG";
	cout<<setw(15)<<"Ten NXB";
	cout<<setw(10)<<"DC NXB";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		if (strcmp(ds[i].x.tenTG,"Quach Tuan Ngoc")==0 && strcmp(ds[i].tenSach,"NNLTC") ==0 )
		{
			ds[i].Xuat();
			cout<<endl;
			check++;
		}
	}
	if (!check)
	{
		cout<<"!!! Khong co thong tin sach cua TG nay !!!\n";
	}
}

void editSach(SACH *ds, int n)
{
	int check = 0;
	char tensosanh[25];
	cout<<"## Nhap ten sach can sua: ";
	fflush(stdin);
	gets(tensosanh);

	for (int i = 0; i < n; ++i)
	{
		if (strcmp(ds[i].tenSach,tensosanh)==0)
		{
			cout<<"* Nhap lai thong tin sach: \n";
			ds[i].Nhap();
			check++;
		}
	}
	if (!check)
	{
		cout<<"!!! Khong tim thay sach co ten "<<tensosanh<<" !!!\n";
	}
}


void insert(SACH *ds, int &n)
{
	int k;
	SACH newsach;
	cout<<"\n## Nhap thong tin sach moi: \n";
	newsach.Nhap();

	cout<<"* Nhap vi tri can chen: ";
	do{
		cin>>k;
	}while(k<=0 || k>n);

	//them bo nho
	ds = (SACH*)realloc(ds,(n+1)*sizeof(SACH));


	for (int i = n; i >= k-1; --i)
	{
		ds[i] = ds[i-1];
	}

	ds[k-1] = newsach; n++;

	cout<<"\n=========== THONG TIN SACH SAU KHI CHEN ===========\n";

	cout<<setw(20)<<"Ten Sach";
	cout<<setw(15)<<"Ten TG";
	cout<<setw(10)<<"DC TG";
	cout<<setw(15)<<"Ten NXB";
	cout<<setw(10)<<"DC NXB";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
		cout<<endl;
	}


}


void sort(SACH *ds, int n)
{
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int check1=strcmp(ds[i].y.tenNXB,ds[j].y.tenNXB);
			if(check1>0){
				SACH temp=ds[i];
				ds[i]=ds[j];
				ds[j]=temp;
			}
		}
	}

	cout<<"\n=========== XEP THEO TEN NXB ===========\n";

	cout<<setw(20)<<"Ten Sach";
	cout<<setw(15)<<"Ten TG";
	cout<<setw(10)<<"DC TG";
	cout<<setw(15)<<"Ten NXB";
	cout<<setw(10)<<"DC NXB";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
		cout<<endl;
	}

}


int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so cuon sach: ";
	do
	{
		cin>>n;
	}while(n<=0 || n>100);
	SACH *ds = new SACH[n];


	cout<<"\n### NHAP THONG TIN "<<n<<" CUON SACH ###\n";
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Nhap thong tin cuon sach thu "<<i+1<<": \n";
		ds[i].Nhap();
	}

	//in ds

	cout<<"\n=========== THONG TIN "<<n<<" CUON SACH ===========\n";

	cout<<setw(20)<<"Ten Sach";
	cout<<setw(15)<<"Ten TG";
	cout<<setw(10)<<"DC TG";
	cout<<setw(15)<<"Ten NXB";
	cout<<setw(10)<<"DC NXB";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
		cout<<endl;
	}


	xuatSachQNT(ds,n);
	editSach(ds,n);
	insert(ds, n);
	sort(ds,n);
	return 0;
}

/* test case
2
De Men PLK
To Hoai
Ha Noi
Kim Dong
Ha Noi
NNLTC
Quach Tuan Ngoc
Ha Noi
Thanh Nien
Ha Nam

*/