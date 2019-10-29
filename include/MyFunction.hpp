#pragma once
#include <cmath>

double F(double x)
	{
		return pow((1.0-x),2) + exp(x);
	}
double F2(double x)
	{
		return F(x) * sin(5.0 * x);
	}
