#include <iostream>
#include <vector>
#include <algorithm>


const int GCM(const int a,const int b){
	int x(a),y(b);
	while(x%=y){
		std::swap(x,y);
	}
	return y;
}

const int LCM(const int a,const int b){
	int x(a),y(b);
	while(x%=y){
		std::swap(x,y);
	}
	long long tmp(a);
	tmp*=b;
	tmp/=y;
	return tmp;
}


int main(int,char**){
	int a,b;
	while(std::cin >>a){
		std::cin >> b;
		std::cout << GCM(a,b) << ' ' << LCM(a,b)<<std::endl;
	}
	return 0;
}
