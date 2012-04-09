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
	int tmp(a/y);
	tmp*=b;
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
