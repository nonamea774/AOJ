#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>
#include <map>


int main(int,char**){
	typedef std::map<short,unsigned long long> Data;
	
	int n;
	while(std::cin>>n){
		if(!n) break;
		bool ex(0);
		Data tbl;
		std::vector<int> seq;
		while(n--){
			int Cnum,at,num;
			std::cin >>Cnum>>at>>num;
			if(tbl[Cnum]==0) seq.push_back(Cnum);
			tbl[Cnum]+=at*num;
		}
		for(std::vector<int>::const_iterator it=seq.begin();it!=seq.end();++it){
			if(tbl[*it]>=1000000){ std::cout<< *it << std::endl; ex=1;}
		}
		if(!ex) std::cout << "NA"<<std::endl;
	}

	return 0;
}
