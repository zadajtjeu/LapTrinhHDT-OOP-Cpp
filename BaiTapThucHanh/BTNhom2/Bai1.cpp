#include <bits/stdc++.h>

using namespace std;

class DaThuc
{
	int bacDT;
	int *heso;
public:
	DaThuc()
	{
		bacDT = 0;
	}
	DaThuc(int bac)
	{
		bacDT = bac;
		heso = new int[bac+1]();
	}
	DaThuc(int n, int mang[])
	{
		bacDT = n;
		heso = new int[bacDT+1]();
		for (int i = 0; i <= bacDT; ++i)
		{
			heso[i] = mang[i];
		}
	}

	DaThuc operator+(DaThuc F);
	DaThuc operator-(DaThuc F);
	DaThuc operator*(DaThuc F2);
	DaThuc operator/(DaThuc right);

	friend ostream& operator<<(ostream& out, DaThuc DT);

};

DaThuc DaThuc::operator+(DaThuc F)
{
	DaThuc H;
	if (bacDT > F.bacDT)
	{
		H.bacDT = bacDT;
		H.heso = new int[bacDT];
		for (int i = 0; i <= F.bacDT; ++i)
			H.heso[i] = heso[i]+F.heso[i];
		for (int i = F.bacDT+1; i <= bacDT; ++i)
			H.heso[i] = heso[i];
	}
	else
	{
		H.bacDT = F.bacDT;
		H.heso = new int[F.bacDT];
		for (int i = 0; i <= bacDT; ++i)
			H.heso[i] = heso[i]+F.heso[i];
		for (int i = bacDT+1; i <= F.bacDT; ++i)
			H.heso[i] = F.heso[i];
	}
	return H;
}

DaThuc DaThuc::operator-(DaThuc F)
{
	DaThuc H;
	if (bacDT > F.bacDT)
	{
		H.bacDT = bacDT;
		H.heso = new int[bacDT];
		for (int i = 0; i <= F.bacDT; ++i)
			H.heso[i] = heso[i]-F.heso[i];
		for (int i = F.bacDT+1; i <= bacDT; ++i)
			H.heso[i] = heso[i];
	}
	else
	{
		H.bacDT = F.bacDT;
		H.heso = new int[F.bacDT];
		for (int i = 0; i <= bacDT; ++i)
			H.heso[i] = heso[i]-F.heso[i];
		for (int i = bacDT+1; i <= F.bacDT; ++i)
			H.heso[i] = F.heso[i];
	}

	return H;
}

DaThuc DaThuc::operator*(DaThuc F2)
{
	//F1 * F2 = F3 voi F3.bacDT = F1.bacDT + F2.bacDT

	//tao F3 voi:
	// F3.bacDT = F1.bacDT + F2.bacDT
	// F3.heso = 0
	int *mang = new int[bacDT + F2.bacDT+1]();
	DaThuc F3(bacDT + F2.bacDT, mang);

	for(int i1=0;i1 <= F3.bacDT;i1++)
	{
		for(int i=0;i<=bacDT;i++)
		{
			for(int j=0;j<=F2.bacDT;j++)
			{
				if(i+j==i1)
				{
					F3.heso[i1]=F3.heso[i1]+heso[i]*F2.heso[j];
				}
			}
		}
	}
	return F3;
}

DaThuc DaThuc::operator/(DaThuc right)
{
	int temp;
	if (bacDT < right.bacDT)
		return 0 ;
	temp = bacDT - right.bacDT ;
	DaThuc d(temp) ;
	DaThuc temp1(bacDT,heso);
	for ( int i = bacDT ; i >= right.bacDT ; i-- , temp-- )
	{
		d.heso[i-right.bacDT ] = temp1.heso[i]/right.heso[right.bacDT];
		if ( i - 1 >= right.bacDT )
		{
			for (int j = i-1 , k = right.bacDT-1; k >= 0; j--, k--)
				temp1.heso[j] -= d.heso[i-right.bacDT] * right.heso[k] ;
		}
	}
	return d;
}

ostream& operator<<(ostream& out, DaThuc DT)
{


	//in co vavidate TH heso = 0,1

	if (DT.bacDT == 1){
		if(DT.heso[0] != 0)
			out<<DT.heso[0]<<" + ";
		if(DT.heso[1] != 0)
		{
			if(DT.heso[1] == 1 )
				out<<"x ";
			else
				out<<DT.heso[1]<<"*x ";
		}
	}
	else
	{
		if(DT.heso[0] != 0)
			out<<DT.heso[0]<<" + ";
		if(DT.heso[1] != 0)
		{
			if(DT.heso[1] == 1 )
				out<<"x + ";
			else
				out<<DT.heso[1]<<"*x + ";
		}
			
		for (int i = 2; i < DT.bacDT; ++i)
		{
			if (DT.heso[i] != 0 )
			{
				if(DT.heso[i] == 1 )
					out<<"x^"<<i<<" + ";
				else
					out<<DT.heso[i]<<"*x^"<<i<<" + ";
			}
		}

		if(DT.heso[DT.bacDT] == 1 )
			out<<"x^"<<DT.bacDT;
		else if(DT.heso[DT.bacDT] == 0)
			out<<"0";
		else
			out<<DT.heso[DT.bacDT]<<"*x^"<<DT.bacDT;
	}
	return out;
	
}

void menu()
{
	cout<<"\n\n\n    ME NU CHINH    \n";
	cout<<" ______________________________\n";
	cout<<"||1) TONG  2  DA  THUC        ||\n";
	cout<<"||____________________________||\n";
	cout<<"||2) HIEU  2  DA  THUC        ||\n";
	cout<<"||____________________________||\n";
	cout<<"||3) TICH  2  DA  THUC        ||\n";
	cout<<"||____________________________||\n";
	cout<<"||4)CHIA DA THUC CHO SO NGUYEN||\n";
	cout<<"||____________________________||\n";
	cout<<"\n #De thuc hien thao tac hay chon phim chuc nang tuong ung! \n ";

}

int main(int argc, char const *argv[])
{
	int n, m;
	cout<<"\n## Nhap thong tin da thuc thu nhat ##\n";
	cout<<" - Bac cua da thuc thu nhat: ";
	do{
		cin>>n;
	}while(n<=0 || n>20);
	cout<<" - Nhap cac he so cua da thuc (Vd: 5 + X^2 + 3X^3 thi nhap 5 0 1 3 voi bac = 3): \n";
	int *a = new int[n+1];
	for (int i = 0; i <= n; ++i)
	{
		cin>>a[i];
	}

	cout<<"\n## Nhap thong tin da thuc thu hai ##\n";
	cout<<" - Bac cua da thuc thu nhat: ";
	do{
		cin>>m;
	}while(m<=0 || m>20);
	cout<<" - Nhap cac he so cua da thuc (Vd: 5 + X^2 + 3X^3 thi nhap 5 0 1 3 voi bac = 3): \n";
	int *b = new int[m+1];
	for (int i = 0; i <= m; ++i)
	{
		cin>>b[i];
	}

	DaThuc F1(n,a), F2(m,b);
	

	int co = 0;
	do
	{
		system("cls"); 
		int choice;
		menu();
		cout<<setw(15)<<"F1(x) = "<<F1<<endl;
		cout<<setw(15)<<"F2(x) = "<<F2<<endl;
		cout<<"_ Ban chon? ";
		do
		{
			cin>>choice;
		}while(choice<=0 || choice>4);

		switch(choice)
		{
			case 1: 
				cout<<setw(15)<<"F1(x)+F2(x) = "<<F1+F2<<endl;
				break;
			case 2:
				cout<<setw(15)<<"F1(x)-F2(x) = "<<F1-F2<<endl;
				break;
			case 3:
				cout<<setw(15)<<"F1(x)*F2(x) = "<<F1*F2<<endl;
				break;
			case 4:
				cout<<setw(15)<<"F1(x)/F2(x) = "<<F1/F2<<endl;
				break;
		}

		cout<<" #MUON THAO TAC TIEP ?\n";
		cout<<" - Chon 1-co va 0-khong: ";
		cin>>co;
		
	}while(co);


	return 0;
}