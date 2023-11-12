#include <iostream>
#include <iomanip>
using namespace std;

struct DaThuc
{
	float a[100];
	int n;
};
typedef struct DaThuc DATHUC;

void Nhap(DATHUC&);
void Xuat(DATHUC);

int LonNhat(int, int);
void GiamBac(DATHUC&);
DATHUC Tong(DATHUC, DATHUC);
DATHUC Hieu(DATHUC, DATHUC);

int main()
{
	DATHUC ff;
	cout << "Nhap da thuc ff: " << endl;
	Nhap(ff);

	cout << "Da thuc ff vua nhap: ";
	Xuat(ff);

	DATHUC gg;
	cout << "\nNhap da thuc gg: " << endl;
	Nhap(gg);

	cout << "Da thuc gg vua nhap: ";
	Xuat(gg);

	DATHUC c = Hieu(ff, gg);
	GiamBac(c);
	cout << "\nHieu la: ";
	Xuat(c);

	cout << "\n\n\nKet thuc!!!";
	return 0;
}

void Nhap(DATHUC& f)
{
	cout << "Nhap bac n: ";
	cin >> f.n;
	for (int i = f.n; i >= 0; i--)
	{
		cout << "Nhap a[" << i << "]: ";
		cin >> f.a[i];
	}
}

void Xuat(DATHUC f)
{
	for (int i = f.n; i >= 1; i--)
	{
		cout << setw(8) << "(" << f.a[i] << ")";
		cout << "x^" << i << " + ";
	}
	cout << setw(8) << "(" << f.a[0] << ") ";
}

int LonNhat(int a, int b)
{
	int lc = a;
	if (b > lc)
		lc = b;
	return lc;
}

void GiamBac(DATHUC& f)
{
	while (f.a[f.n] == 0)
		f.n--;
}

DATHUC Tong(DATHUC f, DATHUC g)
{
	DATHUC temp;
	temp.n = LonNhat(f.n, g.n);

	for (int i = temp.n; i >= 0; i--)
		temp.a[i] = 0;

	for (int i = f.n; i >= 0; i--)
		temp.a[i] += f.a[i];

	for (int i = g.n; i >= 0; i--)
		temp.a[i] += g.a[i];
	GiamBac(temp);
	return temp;
}

DATHUC Hieu(DATHUC f, DATHUC g)
{
	for (int i = 0; i <= g.n; i++)
		g.a[i] = -g.a[i];
	return Tong(f, g);
}