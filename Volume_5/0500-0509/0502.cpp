#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>
#include <map>

class dice{
	int _Top;
	int _South;
	int _East;
public:
	dice() : _Top(1),_South(2),_East(3) {}
	const int Top() const { return _Top; }
	void North() { std::swap(_Top,_South); _South = 7-_South; }
	void East() { std::swap(_Top,_East); _Top = 7-_Top; }
	void South() { std::swap(_Top,_South); _Top = 7-_Top; }
	void West() { std::swap(_Top,_East); _East = 7-_East; }
	void Right() { std::swap(_East,_South); _East = 7-_East; }
	void Left() { std::swap(_East,_South); _South = 7-_South; }
};

std::string North("North"), East("East"), South("South"), West("West"),
		Right("Right"), Left("Left");

int main(int,char**){
	int n;
	std::string que;
	while(std::cin >> n){
		if(!n) break;
		dice die;
		int sum(1);
		while(n--){
			std::cin >>que;
			if(que==North) die.North();
			if(que==East) die.East();
			if(que==South) die.South();
			if(que==West) die.West();
			if(que==Right) die.Right();
			if(que==Left) die.Left();
			sum += die.Top();
		}
		std::cout << sum <<std::endl;
	}
	return 0;
}
