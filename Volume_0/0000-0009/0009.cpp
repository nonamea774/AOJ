#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <functional>

static int const MAX(1000000);

class Mod{
	const int n;
	public:
		Mod(const int _n):n(_n){}
		bool operator()(const int _src){
			return ! (_src % n);
		}
};

const std::vector<int> Eratosthenes(std::set<int>& src){
	std::vector<int> result;
	int cnt(0);
	while(!src.empty()){
	  int n(*src.begin());
		result.push_back(n);
		Mod mod(n);
		//std::set<int>::iterator it= std::remove_if( src.begin(), src.end(), mod );
		// n>(MAX/2) ? std::remove( src.begin(), src.end(), n ) :
		for(int i(n);i<MAX;i+=n)  {
		std::set<int>::iterator it= src.find(i);
		if(it!=src.end())
		   src.erase(it );
		}    
		//src.erase(it,src.end());
	}
	return result;
}


int main(int,char**){
	std::set<int> vec;
	int max_2(MAX-MAX/2-MAX/3-MAX/5+MAX/6+MAX/10+MAX/15-MAX/30+3);
	//	vec.reserve(max_2);
	for(int i(3);i<=MAX;i+=2){
		if(i!=3 && i%3==0) continue;
		if(i!=5 && i%5==0) continue;
		vec.insert(i);
	}
	std::vector<int> primes;
	primes.reserve(10000);
	primes =Eratosthenes(vec);
	int n;
	while(std::cin >>n){
		std::vector<int>::const_iterator const it= std::upper_bound(primes.begin(),primes.end(),n);
		int off=it -primes.begin();
		if(n>=2){ ++off; }
		std::cout << off <<std::endl;
	}
	return 0;
}