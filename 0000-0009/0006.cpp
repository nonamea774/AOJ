#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

int main(int,char**){
	std::string str;
	std::cin >> str;
	for(int i(str.size()-1);i>=0;--i){
		std::cout << str[i];
	}
	std::cout <<std::endl;
	return 0;
}