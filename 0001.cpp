#include <iostream>
#include <vector>
#include <algorithm>

int main(int,char**){
	std::vector<int> vec(10);
	for(int i(0);i<10;++i) std::cin >> vec[i];
	std::sort(vec.begin(),vec.end());
	std::cout << vec[9] << std::endl<< vec[8] << std::endl<< vec[7] << std::endl;
	return 0;
}
