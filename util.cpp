const int GCM(const int a,const int b){
	int x(a),y(b);
	while(x%=y){
		std::swap(x,y);
	}
	return y;
}

const int LCM(const int a,const int b){
	int x(a),y(b);
	while(x%=y){
		std::swap(x,y);
	}
	int tmp(a/y);
	tmp*=b;
	return tmp;
}

class Mod{
		const int n;
		public:
			Mod(int const _n):n(_n){}
			bool operator()(const int _src)const{
				return ! (_src % n);
			}
	};

const std::vector<int> Eratosthenes(const std::vector<int>& src){
	std::vector<int> result,tmp(src);
	while(!tmp.empty()){
		int n(tmp[0]);
		result.push_back(n);
		Mod mod(n);
		std::vector<int>::iterator it= std::remove_if( tmp.begin(), tmp.end(), mod );
		tmp.erase(it,tmp.end());
	}
	return result;
}