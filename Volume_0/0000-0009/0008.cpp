#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>

int main(int,char**){
	int n,cnt;
	while(std::cin >>n){
		cnt = 0;
		for(int a(0);a<10;++a){
			if(a>n) continue;
			for(int b(0);b<10;++b){
				if(a+b>n) continue;
				for(int c(0);c<10;++c){
					if(a+b+c>n) continue;
					for(int d(0);d<10;++d){
						if(a+b+c+d==n) ++cnt;
					}
				}
			}
		}

		std::cout << cnt <<std::endl;
	}
	return 0;
}
