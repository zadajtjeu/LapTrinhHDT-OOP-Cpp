#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class SINHVIEN
{
private:
	string maSV, hoTen;
	double diemToan, diemLy, diemHoa;
public:
	void Nhap()
	{
		cin.ignore();
		cout<<" - Nhap ma sinh vien: ";
		getline(cin, maSV);
		cout<<" - Nhap ho ten sinh vien: ";
		getline(cin, hoTen);
		cout<<" - Nhap diem toan: ";
		cin>>diemToan;
		cout<<" - Nhap diem ly: ";
		cin>>diemLy;
		cout<<" - Nhap diem hoa: ";
		cin>>diemHoa;
	}
	void Xuat()
	{
		cout<<setw(10)<<maSV;
		cout<<setw(20)<<hoTen;
		cout<<setw(10)<<diemToan;
		cout<<setw(10)<<diemLy;
		cout<<setw(10)<<diemHoa;
		cout<<setw(10)<<diemToan+diemLy+diemHoa;
		cout<<endl;
	}
	friend void buddleSort(SINHVIEN, int);
	friend double tongDiem(SINHVIEN);
};

double tongDiem(SINHVIEN sv)
{
	return sv.diemToan + sv.diemLy + sv.diemHoa;
}

void buddleSort(SINHVIEN *sv, int n)
{
	for (int i = 1; i < n; ++i)
		for (int j = n-1; j >= i; --j)
			if (tongDiem(sv[j]) < tongDiem(sv[j-1]))
			{
				SINHVIEN temp = sv[j];
				sv[j] = sv[j-1];
				sv[j-1] = temp;
			}
}
int main(int argc, char const *argv[])
{
	int n;
	cout<<"* Nhap so sinh vien: ";
	cin>>n;
	SINHVIEN *sv = new SINHVIEN[n];
	cout<<"================== Nhap danh sach "<<n<<" sinh vien =================="<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<"* Thong tin sinh vien thu "<<i+1<<": "<<endl;
		sv[i].Nhap();
	}

	//sapxep
	buddleSort(sv,n);

	cout<<"========= Danh sach "<<n<<" sinh vien duoc sap xep theo tong diem ========="<<endl<<endl;
	
	cout<<setw(10)<<"Ma SV";
	cout<<setw(20)<<"Ho Ten";
	cout<<setw(10)<<"Toan";
	cout<<setw(10)<<"Ly";
	cout<<setw(10)<<"Hoa";
	cout<<setw(10)<<"Tong";
	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		sv[i].Xuat();
	}



	return 0;
}

/* test case
10
SV01
Cao Nguyen Duy	Anh
7.5
6
8.5
SV02
Nguyen Thi Ngoc	Anh
6.5
4.5
8.5
SV03
Nguyen Thi Ngoc	Anh
6.5
7
8
SV04
Dao Thi Ninh Binh
7
6
8
SV05
Nguyen Trong Cuong
5
6
7
SV06
Pham Quoc Cuong
6
7
9
SV07
Ngo Van	Diem
5
4.75
6
SV08
Bach Quoc Dong
6
7
7
SV09
Tran Trung Dung
6
8.5
7
SV10
Pham Van Duy
7
8
9
*/