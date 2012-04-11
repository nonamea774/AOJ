#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>
#include <map>
#include <list>



int main(int,char**){
	int t;
	std::cin >> t;
	while(t--){
		int n;
		std::cin >> n;
		int n2(n);
		std::vector<int> vec;
		vec.reserve(n);
		while(n2--){
			int hight;
			std::cin >> hight;
			vec.push_back(hight);
		}
		int up(0),down(0);
		for(int i(0);i<n-1;++i){ // ÅŒã‚Ìˆê‚Â‘O‚Ü‚Å
			int tempMove(vec[i+1]-vec[i]);
			if(!tempMove) continue;
			if(tempMove>0){
				if(tempMove>up) up=tempMove;
			}else{
				if(std::abs(tempMove)>down) down=std::abs(tempMove);
			}
		}
		std::cout << up << ' ' << down<<std::endl; 
	}
	return 0;
}
