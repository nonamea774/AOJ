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
	long long tmp(a);
	tmp*=b;
	tmp/=y;
	return tmp;
}