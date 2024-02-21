#include <iostream>
#include <iomanip>

const double PI = 3.14159265358979323846;

int main()
{	
	double r;
	while (std::cin >> r)
	{
		double v = PI * r * r * r * 4 / 3;
		std::cout << std::fixed << std::setprecision(6) << v << std::endl;
	}
}