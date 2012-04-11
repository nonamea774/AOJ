#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>
#include <map>
using namespace std;

bool isLeap(const int y){
	if(!(y%400)) return true;
	if(!(y%100)) return false;
	if(!(y%4)) return true;
	return false;
}

int main(int,char**){
	int a,b;
	bool ini(0);
	while(std::cin >> a>> b){
		if(!a&&!b) break;
		if(ini) cout <<endl;
		else ini=true;
		
		bool ex(0);
		for(int i(a);i<=b;++i){
			if(isLeap(i)) {
				cout << i <<endl;
				ex = true;
			}
		}
		if(!ex) cout << "NA" <<endl;
		
	}
	return 0;
}
