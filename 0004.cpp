#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

// ax + by = c
// dx + ey = f
// det(A) = ae-bd
// A^(-1) = 1/det(A)* ((e,-b),(-d,a))
// x = 1/det(A) *(ce-bf)
// y =			*(-cd+af)

int main(int,char**){
	double a,b,c,d,e,f;
	double x,y;
	std::cout<< std::setprecision(3) << std::setiosflags(std::ios::fixed);
	while(std::cin >> a){
		std::cin >> b >> c >> d >> e >> f;
		double det(a*e-b*d);
		x= (c*e-b*f)/det + 0;
		y= (-c*d+a*f)/det + 0;
		std::cout<< x << ' ' << y<<std::endl;
	}
	return 0;
}
