#include <bits/stdc++.h>

using namespace std;

class DATE
{
private:
	int dd,mm,yyyy;
public:
	void Nhap()
	{
		scanf("%d/%d/%d",&dd,&mm,&yyyy);
	}
	void Xuat()
	{
		cout<<right<<setw(15)<<dd<<"/"<<mm<<"/"<<yyyy;
	}
};

class NHANSU
{
public:
	char hoTen[255], CMTND[20];
	DATE ngaysinh;
public:
	void Nhap()
	{
		cout<<" - Nhap ho ten nhan vien: ";
		fflush(stdin);
		gets(hoTen);
		cout<<" - Nhap ngay sinh (dd/mm/yyyy): ";
		ngaysinh.Nhap();
		cout<<" - Nhap so CMTND: ";
		fflush(stdin);
		gets(CMTND);
	}
	void Xuat()
	{
		cout<<setw(30)<<hoTen<<setw(20)<<CMTND; ngaysinh.Xuat(); cout<<endl;
	}
};


void tachten(char hoten[],char ten[]){
	for(int i=strlen(hoten)-1;i>=0;i--){
		if(hoten[i]==' '){
			strcpy(ten,hoten+1+i);
			break;
		}
	}
}
void sapxep(NHANSU danhsach[],int soNhanSu){
	for(int i=0;i<soNhanSu;i++){
		for(int j=i+1;j<soNhanSu;j++){
			char ten1[255]="",ten2[255]="";
			tachten(danhsach[i].hoTen,ten1);
			tachten(danhsach[j].hoTen,ten2);
			int check1=strcmp(ten1,ten2);
			if(check1>0){
				NHANSU temp=danhsach[i];
				danhsach[i]=danhsach[j];
				danhsach[j]=temp;
			}
			else if(check1==0){
		int check2=strcmp(danhsach[i].hoTen,danhsach[j].hoTen);
					if(check2>0){
						NHANSU temp=danhsach[i];
						danhsach[i]=danhsach[j];
						danhsach[i]=temp;
					}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	NHANSU *ds;
	int n;
	cout<<"========= Quan Ly Nhan Su ========="<<endl;
	cout<<" - Nhap so luong nhan su: ";
	cin>>n;

	ds = new NHANSU[n];

	cout<<"==== Nhap Thong Tin "<<n<<" Nhan Su ==="<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<" * Thong tin nhan su "<<i+1<<endl;
		ds[i].Nhap();
	}

	//sap xep
	sapxep(ds,n);

	cout<<endl;
	cout<<"====== Thong Tin "<<n<<" Nhan Su ====="<<endl;

	cout<<setw(30)<<"Ho Ten"<<setw(20)<<"CMTND"<<setw(15)<<"             Ngay Sinh"<<endl;

	for (int i = 0; i < n; ++i)
	{
		ds[i].Xuat();
	}
	return 0;
}

/*test case
5
Tran Cong Tam
22/12/200
2018603779
Nguyen Đac Tuyen
01/03/2000
2018603819
Tran Xuan Thai
26/03/2000
2018603959
Cao Nguyen Duy Anh
01/01/2000
2018604029
Phan Van Chinh
02/03/2000
2018604040
*/