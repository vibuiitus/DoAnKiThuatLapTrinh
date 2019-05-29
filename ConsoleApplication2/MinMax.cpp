#define _CRT_NONSTDC_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <iomanip>
#include "TapXacDinh.h"
#include "Equation.h"
#include "MinMax.h"
#define epsilon 1e-5
extern FILE * input, * output;
using namespace std;

void MinMax(int k, float a, float b, float c, float d, float e)
{
	switch (k)
	{
	case 1:case 11:case 12:case 13:
	{
		MinMax_1();
		break;
	}
	case 2:
	{
		MinMax_2(a, b, c);
		break;
	}
	case 3:
	{
		MinMax_3(a, b, c, d);
		break;
	}
	case 4:
	{
		MinMax_4(a, b, c);
		break;
	}
	case 5:
	{
		MinMax_5();
		break;
	}
	case 6:
	{
		MinMax_6(a, b, c, d, e);
		break;
	}
	case 14:
	{
		MinMax_17();
		break;
	}

	case 15:
	{
		MinMax_15();
		break;
	}

	case 16:
	{
		MinMax_16();
		break;
	}

	case 17:
	{
		MinMax_17();
		break;
	}

	default:
		break;
	}
}

void MinMax_1()
{
	fprintf(output, "\nHam so khong co cuc tieu hay cuc dai !!!\n\n");
}

void MinMax_2(float a, float  b, float  c)
{
	if (a < 0)
	{
		fprintf(output, "\nHam so khong co cuc tieu!!!\n\n");
		float x1 = (-b) / (2 * a);
		float MAX = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x1, MAX);
	}
	else if (a > 0)
	{
		float x1 = (-b) / (2 * a);
		float MIN = a * pow(x1, 2) + b * x1 + c;
		fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x1, MIN);
		fprintf(output, "\nHam so khong co cuc dai!!!\n\n");
	}
}

void MinMax_3(float a, float b, float c, float d)
{
	float a1 = 3 * a, b1 = 2 * b, c1 = c;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
	{
		fprintf(output, "\nHam so khong cuc dai va cuc tieu!!!\n\n");
	}
	else
	{
		if (a < 0)
		{
			float X1, X2;
			if (x < y)
			{
				float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
			else
			{
				float X1, X2;
				float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
		}
		else
		{
			if (x < y)
			{
				float X1, X2;
				float MAX = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X1 = x;
				float MIN = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X2 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
			else
			{
				float X1, X2;
				float MIN = a * pow(x, 3) + b * pow(x, 2) + c * x + d;
				X2 = x;
				float MAX = a * pow(y, 3) + b * pow(y, 2) + c * y + d;
				X1 = y;
				fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", X1, MIN);
				fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", X2, MAX);
			}
		}
	}
}

void MinMax_4(float a, float b, float c)
{
	float a1 = 4 * a, b1 = 2 * a;
	if (a > 0 && b >= 0)
	{
		fprintf(output, "\nHam so co cuc tieu la: (%d, %10f)\n\n", 0, c);
		fprintf(output, "\nHam so khong co cuc dai!!!\n\n");
	}
	else if (a < 0 && b <= 0)
	{
		fprintf(output, "\nHam so khong co cuc tieu!!!\n\n");
		fprintf(output, "\nHam so co cuc dai la: (%d, %10f)\n\n", 0, c);
	}
	else if (a > 0 && b < 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "\nHam so co 2 cuc tieu la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
		fprintf(output, "\nHam so co 1 cuc dai la: (%d , %.2f)", 0, c);
	}
	else if (a < 0 && b > 0)
	{
		float delta;
		delta = b * b - 4 * a * c;
		fprintf(output, "\nHam so co 1 cuc tieu la: (%d , %.2f)", 0, c);
		fprintf(output, "\nHam so co 2 cuc dai la: (%.2f , %.2f) va (%.2f , %.2f) ", b / (2 * a), -delta / (4 * a), -b / (2 * a), -delta / (4 * a));
	}
}

void MinMax_5()
{
	fprintf(output, "\nHam so khong co cuc tieu hay cuc dai !!!\n\n");
}

void MinMax_6(float a, float b, float c, float d, float e)
{
	float a1 = a * d;
	float b1 = 2 * a * e;
	float c1 = b * e - c * d;
	float x, y;
	short z;
	GiaiPT_Bac2(a1, b1, c1, x, y, z);
	if (z == -1 || z == 0)
		fprintf(output, "\nHam so khong co cuc tieu hay cuc dai !!!\n\n");
	else
	{
		if (Equa_2(a1, b1, c1, x - epsilon) > 0 && Equa_2(a1, b1, c1, x + epsilon) < 0)
		{
			fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", x, Equa_6(a, b, c, d, e, x));
			fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", y, Equa_6(a, b, c, d, e, y));
		}
		else
		{
			fprintf(output, "\nHam so co cuc tieu la: (%10f, %10f)\n\n", y, Equa_6(a, b, c, d, e, y));
			fprintf(output, "\nHam so co cuc dai la: (%10f, %10f)\n\n", x, Equa_6(a, b, c, d, e, x));
		}
	}
}

void MinMax_14()
{
	if (output == stdout) fprintf(output, "Ham so co cuc tieu tai cac diem (-%c/2 + k* 2%c,-1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc tieu tai cac diem (-Pi/2 + k* 2Pi,-1), k thuoc Z\n\n");
	if (output == stdout) fprintf(output, "Ham so co cuc dai tai cac diem (%c/2 + k* 2%c,1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc dai tai cac diem (Pi/2 + k* 2Pi,1), k thuoc Z\n\n");
}

void MinMax_15()
{
	if (output == stdout) fprintf(output, "Ham so co cuc tieu tai cac diem (%c + k* 2%c,-1), k thuoc Z\n\n", (char)227, (char)227);
	else fprintf(output, "Ham so co cuc tieu tai cac diem (Pi + k* 2Pi,-1), k thuoc Z\n\n");
	if (output == stdout) fprintf(output, "Ham so co cuc dai tai cac diem (k* 2%c,1), k thuoc Z\n\n", (char)227);
	else fprintf(output, "Ham so co cuc dai tai cac diem (k* 2Pi,1), k thuoc Z\n\n");
}

void MinMax_16()
{
	fprintf(output, "\nHam so khong co cuc tri!!!\n\n");
}

void MinMax_17()
{
	fprintf(output, "Ham so khong co cuc tri!!!\n\n");
}
