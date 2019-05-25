﻿#include <iostream>
#include <cmath>
#include "Input_Output.h"
#include "Equation.h"
#include "Daoham.h"
#define epsilon 1e-5

#define _CRT_NONSTDC_NO_WARNINGS

extern FILE * input, * output;

using namespace std;

void DaoHam_XetDau(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:
		DaoHam1(a, b);
		break;
	case 2:
		DaoHam2(a, b, c);
		break;
	case 3:
		DaoHam3(a, b, c, d);
		break;
	case 4:
		DaoHam4(a, b, c);
		break;
	case 5:
		DaoHam5(a, b, c, d);
		break;
	case 6:
		DaoHam6(a, b, c, d, e);
		break;
	default:
		break;
	}
}

void XetDau0(float a)
{
	if (a == 0) fprintf(output, "\tDao ham luon bang 0 voi moi x thuoc R\n");
	else if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R\n");
	else fprintf(output, "\tDao ham luon duong voi moi x thuoc R\n");
}

void XetDau1(float a, float b)
{
	if (a > 0)
	{
		fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f)\n", (char)236, -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, +%c)\n", -b / a, (char)236);
	}
	else
	{
		fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f)\n", (char)236, -b / a);
		fprintf(output, "\tDao ham bang 0 voi x = %.2f\n", -b / a);
		fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, +%c)\n", -b / a, (char)236);
	}
}

void XetDau2(float a, float b, float c)
{
	float x, y;
	short t;
	GiaiPT_Bac2(a, b, c, x, y, t);
	if (t == -1)
	{
		if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R\n");
		else fprintf(output, "\tDao ham luon duong voi moi x thuoc R\n");
	}
	else if (t == 0)
	{
		if (a < 0) fprintf(output, "\tDao ham luon am voi moi x thuoc R \\ {%.2f}\n", x);
		else fprintf(output, "\tDao ham luon duong voi moi x thuoc R \\ {%.2f}\n", x);
		fprintf(output, "Dao ham bang 0 tai x = %.2f\n", x);
	}
	else
	{
		if (a < 0)
		{
			fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f) va x thuoc (%.2f, +%c)\n"
				, (char)236, x, y, (char)236);
			fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %.2f)\n", x, y);
		}
		else
		{
			fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f) va x thuoc (%.2f, +%c)\n"
				, (char)236, x, y, (char)236);
			fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, %.2f)\n", x, y);
		}
		fprintf(output, "\tDao ham bang 0 tai x = %.2f va x = %.2f\n", x, y);
	}
}

void XetDau3(float a, float b)
{
	if (a * b < 0)
	{
		float temp = sqrt(-b / a);
		if (a > 0)
		{
			fprintf(output, "\tDao ham luon am voi x thuoc (-%c, %.2f) va x thuoc (%.2f, %.2f)\n"
				, (char)236, -temp, 0, temp);
			fprintf(output, "\tDao ham luon duong voi x thuoc (%.2f, %.2f) va x thuoc (%.2f, +%c)\n"
				, -temp, 0, temp, (char)236);
		}
		else
		{
			fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, %.2f) va x thuoc (%.2f, %.2f)\n"
				, (char)236, -temp, 0, temp);
			fprintf(output, "\tDao ham luon am voi x thuoc (%.2f, %.2f) va x thuoc (%.2f, +%c)\n"
				, -temp, 0, temp, (char)236);
		}
		fprintf(output, "\tDao ham bang 0 tai x = 0,  x = %.2f va x = %.2f\n", -temp, temp);
	}
	else
	{
		if (a > 0)
		{
			fprintf(output, "\tDao ham luon am voi x thuoc (-%c, 0)\n", (char)236);
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			fprintf(output, "\tDao ham luon duong voi x thuoc (0, +%c)\n", (char)236);
		}
		else
		{
			fprintf(output, "\tDao ham luon duong voi x thuoc (-%c, 0)\n", (char)236);
			fprintf(output, "\tDao ham bang 0 voi x = 0\n");
			fprintf(output, "\tDao ham luon am voi x thuoc (0, +%c)\n", (char)236);
		}
	}
}

void XetDau4(float a, float c, float d)
{
	if (a < epsilon) fprintf(output, "\tDao ham luon bang 0 voi moi x thuoc R\n");
	else if (a > 0) fprintf(output, "\tDao ham luon duong voi moi x thuoc R \\ {%.2f}\n", -d / c);
	else fprintf(output, "\tDao ham luon am voi moi x thuoc R \\ {%.2f}\n", -d / c);
	fprintf(output, "\tDao ham tien toi %c khi x = %.2f\n", (char)236, -d / c);
}

void DaoHam1(float a, float b)
{
	fprintf(output, "Ham so dao ham co dang: y' = %.2f\n", a);
	fprintf(output, "Xet dau dao ham y':\n");
	XetDau0(a);
}

void DaoHam2(float a, float b, float c)
{
	fprintf(output, "Ham so dao ham co dang: y' = ");
	PT_1(2 * a, b);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau1(2 * a, b);
}

void DaoHam3(float a, float b, float c, float d)
{
	fprintf(output, "Ham so dao ham co dang: y' = ");
	PT_2(3 * a, 2 * b, c);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau2(3 * a, 2 * b, c);
}

void DaoHam4(float a, float b, float c)
{
	fprintf(output, "Ham so dao ham co dang: y' = ");
	PT_3(4 * a, 0, 2 * b, 0);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau3(4 * a, 2 * b);
}

void DH_4(float a, float b, float c, float d)
{
	if (fabs(a * d - b * c) < epsilon) fprintf(output, "0\n");
	else
	{
		fprintf(output, "%.2f / ", a * d - b * c);
		if (2 * c * d != 0 || d * d != 0) fprintf(output, "(");
		PT_2(c * c, 2 * c * d, d * d);
		if (2 * c * d != 0 || d * d != 0) fprintf(output, ")");
	}
}

void DaoHam5(float a, float b, float c, float d)
{
	fprintf(output, "Ham so dao ham co dang: y' = ");
	DH_4(a, b, c, d);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau4(a * d - b * c, c, d);
}

void DH_5(float a, float b, float c, float d, float e)
{
	float a1 = a * d, b1 = 2 * a * e, c1 = b * e - c * d;
	if (b1 != 0 || c1 != 0) fprintf(output, "(");
	PT_2(a * d, 2 * a * e, b * e - c * d);
	if (b1 != 0 || c1 != 0) fprintf(output, ")");
	fprintf(output, " / ");
	if (2 * d * e != 0 || e * e != 0) fprintf(output, "(");
	PT_2(d * d, 2 * d * e, e * e);
	if (2 * d * e != 0 || e * e != 0) fprintf(output, ")");
}

void DaoHam6(float a, float b, float c, float d, float e)
{
	fprintf(output, "Ham so dao ham co dang: y' = ");
	DH_5(a, b, c, d, e);
	fprintf(output, "\nXet dau dao ham y':\n");
	XetDau2(a * d, 2 * a * e, b * e - c * d);
}
