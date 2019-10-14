#pragma once
#include <cmath>

class MyFunction
	{
		public:
			double F(double x)
				{
					return (-2.0) * sqrt(x) * sin(0.5 * x);
				}
			double F2(double x)
				{
					return F(x) * sin(5 * x);
				}
	};
