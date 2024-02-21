#include <iostream>
#include <iomanip>

int main()
{
	double n;
	while (std::cin >> n)
	{
		int g = 0;
		double cur = n / 2, lst;
		do
		{
			lst = cur;
			cur = (cur + n / cur) / 2;
		} while (std::abs(cur - lst) >= 0.01);
		std::cout << std::fixed << std::setprecision(2) << cur << std::endl;
	}
}