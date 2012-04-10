#include <iostream>
#include <vector>
#include <algorithm>

int main(int,char**){
	int loops;
	std::cin >> loops;
	int a,b,c;
	while(loops--){
		std::cin >> a >> b >> c;
		if(a*a-b*b-c*c && b*b-c*c-a*a && c*c-a*a-b*b) std::cout << "NO" <<std::endl;
		else std::cout << "YES" <<std::endl;
	}
	return 0;
}
