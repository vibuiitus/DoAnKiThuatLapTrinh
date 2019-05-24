#include "Input_Output.h"
#include "TapXacDinh.h"
#include "Equation.h"
#include <iostream>
#define epsilon 1e-5

using namespace std;

template<class T>
void Input(char ch, T& k)
{
	cout << ch << " = ";
	cin >> k;
}

void Input_Equation(int& k)
{
	cout << "Chon Ham so ax + b = 0                    : Nhap 1" << endl;
	cout << "Chon Ham so ax^2 + bx + c = 0             : Nhap 2" << endl;
	cout << "Chon Ham so ax^3 + bx^2 + cx + d = 0      : Nhap 3" << endl;
	cout << "Chon Ham so ax^4 + bx^2 + c = 0           : Nhap 4" << endl;
	cout << "Chon Ham so (ax + b) / (cx + d) = 0       : Nhap 5" << endl;
	cout << "Chon Ham so (ax^2 + bx + c) / (dx + e) = 0: Nhap 6" << endl;
	cout << "De dung chuong trinh                      : Nhap 0" << endl;
	cout << "Nhap vao 1 so N: ";
	while (true)
	{
		Input('N', k);
		if (k < 0 || k>6)
		{
			cout << "Du lieu ban nhap vao khong hop le!!!\a" << endl;
			cout << "Xin moi ban nhap lai 1 so N: ";
		}
		else break;
	}

}

void Output_Equation(int& k, float& a, float& b, float& c, float& d, float& e)
{
	switch (k)
	{
	case 1:
		Input('a', a);
		Input('b', b);
	Equation1:
		cout << "Ham so co dang: y = ";
		PT_1(a, b);
		cout << endl;
		break;
	case 2:
		Input('a', a);
		Input('b', b);
		Input('c', c);
	Equation2:
		if (a == 0)
		{
			k = 1;
			a = b;
			b = c;
			goto Equation1;
		}
		cout << "Ham so co dang: y = ";
		PT_2(a, b, c);
		cout << endl;
		break;
	case 3:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		if (a == 0)
		{
			k = 2;
			a = b;
			b = c;
			c = d;
			goto Equation2;
		}
		cout << "Ham so co dang: y = ";
		PT_3(a, b, c, d);
		cout << endl;
		break;
	case 4:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		if (a == 0)
		{
			k = 2;
			a = b;
			b = 0;
			goto Equation2;
		}
		cout << "Ham so co dang: y = ";
		PT_4(a, b, c);
		cout << endl;
		break;
	case 5:
	Equa5:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
	Equation5:
		if (c == 0 && d == 0)
		{
			cout << "Ham so khong hop le vi mau so bang 0!!!" << endl;
			cout << "Ban muon nhap lai phuong trinh loai nay : Nhap 1" << endl;
			cout << "Ban muon nhap cac loai phuong trinh khac: Nhap 2" << endl;
			short n;
			while (true)
			{
				Input('N', n);
				if (n != 1 && n != 2)
				{
					cout << "Du lieu ban nhap vao khong hop le!!!\a" << endl;
					cout << "Xin moi ban nhap lai 1 so N: ";
				}
				else break;
			}
			if (n == 1) goto Equa5;
			else
			{
				k = 0;
				return;
			}
		}
		if (c == 0)
		{
			k = 1;
			a /= d;
			b /= d;
			goto Equation1;
		}
		if (b == 0 && d == 0)
		{
			k = 1;
			b = a / c;
			a = 0;
			goto Equation1;
		}
		if (fabs(Equa_1(a, b, -d / c)) < epsilon)
		{
			k = 1;
			b = a / c;
			a = 0;
			goto Equation1;
		}
		cout << "Ham so co dang: y = ";
		PT_5(a, b, c, d);
		cout << endl;
		break;
	case 6:
	Equa6:
		Input('a', a);
		Input('b', b);
		Input('c', c);
		Input('d', d);
		Input('e', e);
		if (a == 0)
		{
			k = 5;
			a = b;
			b = c;
			c = d;
			d = e;
			goto Equation5;
		}
		if (d == 0 && e == 0)
		{
			cout << "Ham so khong hop le vi mau so bang 0!!!" << endl;
			cout << "Ban muon nhap lai phuong trinh loai nay : Nhap 1" << endl;
			cout << "Ban muon nhap cac loai phuong trinh khac: Nhap 2" << endl;
			short n;
			while (true)
			{
				Input('N', n);
				if (n != 1 && n != 2)
				{
					cout << "Du lieu ban nhap vao khong hop le!!!\a" << endl;
					cout << "Xin moi ban nhap lai 1 so N: ";
				}
				else break;
			}
			if (n == 1) goto Equa6;
			else
			{
				k = 0;
				return;
			}
		}
		if (d == 0)
		{
			k = 2;
			a /= e;
			b /= e;
			c /= e;
			goto Equation2;
		}
		if (a == 0 && b == 0 && c == 0)
		{
			k = 1;
			goto Equation1;
		}
		if (c == 0 && e == 0)
		{
			k = 2;
			a /= d;
			b /= d;
			goto Equation1;
		}
		float x, y;
		short n;
		GiaiPT_Bac2(a, b, c, x, y, n);
		if (n != -1)
		{
			if (n == 0) y = x;
			if (fabs(x + e / d) < epsilon)
			{
				k = 1;
				float temp = a;
				a /= d;
				b = -a * y / d;
				goto Equation1;
			}
			if (fabs(y + e / d) < epsilon)
			{
				k = 1;
				float temp = a;
				a /= d;
				b = -a * x / d;
				goto Equation1;
			}
		}
		cout << "Ham so co dang: y = ";
		PT_6(a, b, c, d, e);
		cout << endl;
		break;
	default:
		break;
	}
}

void PT_1(float a, float b)
{
	if (a != 0)
	{
		if (a == 1) cout << "x";
		else if (a == -1) cout << "-x";
		else cout << a << "x";
	}
	if (a == 0) cout << b;
	else
	{
		if (b > 0) cout << " + " << b;
		else if (b < 0) cout << " - " << -b;
	}
}

void PT_2(float a, float b, float c)
{
	if (a == 0)
	{
		PT_1(b, c);
		return;
	}
	if (a == 1) cout << "x^2";
	else if (a == -1) cout << "-x^2";
	else cout << a << "x^2";
	if (b != 0)
	{
		if (b == 1) cout << " + x";
		else if (b == -1) cout << " - x";
		else if (b > 0) cout << " + " << b << "x";
		else if (b < 0) cout << " - " << -b << "x";
	}
	if (c != 0)
	{
		if (c > 0) cout << " + " << c;
		else if (c < 0) cout << " - " << -c;
	}
}

void PT_3(float a, float b, float c, float d)
{
	if (a == 0)
	{
		PT_2(b, c, d);
		return;
	}
	if (a == 1) cout << "x^3";
	else if (a == -1) cout << "-x^3";
	else cout << a << "x^3";
	if (b != 0)
		if (b == 1) cout << " + x^2";
		else if (b == -1) cout << " - x^2";
		else if (b > 0) cout << " + " << b << "x^2";
		else if (b < 0) cout << " - " << -b << "x^2";
	if (c != 0)
		if (c == 1) cout << " + x";
		else if (c == -1) cout << " - x";
		else if (c > 0) cout << " + " << c << "x";
		else if (c < 0) cout << " - " << -c << "x";
	if (d != 0)
	{
		if (d > 0) cout << " + " << d;
		else if (d < 0) cout << " - " << -d;
	}
}

void PT_4(float a, float b, float c)
{
	if (a == 0)
	{
		PT_2(b, 0, c);
		return;
	}
	if (a == 1) cout << "x^4";
	else if (a == -1) cout << "-x^4";
	else cout << a << "x^4";
	if (b != 0)
		if (b == 1) cout << " + x^2";
		else if (b == -1) cout << " - x^2";
		else if (b > 0) cout << " + " << b << "x^2";
		else if (b < 0) cout << " - " << -b << "x^2";
	if (c != 0)
	{
		if (c > 0) cout << " + " << c;
		else if (c < 0) cout << " - " << -c;
	}
}

void PT_5(float a, float b, float c, float d)
{
	if (a != 0 && b != 0) cout << "(";
	PT_1(a, b);
	if (a != 0 && b != 0) cout << ")";
	cout << " / ";
	if (c != 0 && d != 0) cout << "(";
	PT_1(c, d);
	if (c != 0 && d != 0) cout << ")";
}

void PT_6(float a, float b, float c, float d, float e)
{
	if (a == 0)
	{
		PT_5(b, c, d, e);
		return;
	}
	if (b != 0 || c != 0) cout << "(";
	PT_2(a, b, c);
	if (b != 0 || c != 0) cout << ")";
	cout << " / ";
	if (d != 0 && e != 0) cout << "(";
	PT_1(d, e);
	if (d != 0 && e != 0) cout << ")";
}

