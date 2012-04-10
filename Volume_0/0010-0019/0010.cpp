#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>

// x^2+y^2+ax+by+c=0

int main(int,char**){
	std::cout<< std::setprecision(3) << std::setiosflags(std::ios::fixed);
	int n;
	std::cin >> n;
	while(n--){
		double x1,y1,x2,y2,x3,y3,a,b,c;
		std::cin >>  x1 >> y1 >> x2 >> y2 >> x3 >>y3;
		double vec[]={ -x1*x1-y1*y1, -x2*x2-y2*y2, -x3*x3-y3*y3};
		double det(x1*y1+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
		double inv[3][3] = { 
			{ y2-y3, -(y1-y3), y1-y2 },
			{ -(x2-x3), x1-x3, -(x1-x2) },
			{ x2*y3-x3*y2, -(x1*y3-x3*y1), x1*y2-x2*y1}
		};
		a= (inv[0][0]*vec[0] +inv[0][1]*vec[1] +inv[0][2]*vec[2])/det;
		b= (inv[1][0]*vec[0] +inv[1][1]*vec[1] +inv[1][2]*vec[2])/det;
		c= (inv[2][0]*vec[0] +inv[2][1]*vec[1] +inv[2][2]*vec[2])/det;
		std::cout<< 0-a/2 << ' ' << 0-b/2<<' ' << std::sqrt((a*a+b*b)/4-c)<<std::endl;
	}
	return 0;
}
