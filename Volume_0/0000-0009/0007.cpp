#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

int main(int,char**){
	int deb(100000);
	int n;
	int tmp;
	std::cin >> n;
	while(n--){
		deb*=1.05;
		if(deb%1000) {
			deb/=1000;
			++deb;
			deb*=1000;
		}
	}
	std::cout << deb <<std::endl;
	return 0;
}
