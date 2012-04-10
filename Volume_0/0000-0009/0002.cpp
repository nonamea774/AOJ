#include <iostream>
#include <vector>
#include <algorithm>

int main(int,char**){
	int i,j,temp,digits;
	while(std::cin >> i){
		std::cin >>j;
		temp = i+j;
		digits=1;
		while(temp/=10) ++digits;
		std::cout << digits <<std::endl;
	}
	return 0;
}
