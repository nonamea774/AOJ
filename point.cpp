#include <iostream>
//http://codepad.org/Nd0zKyFy に追記
struct point
{
    point() : x(0), y(0) { }
    point(double x_, double y_) : x(x_), y(y_) { }
    double x, y;
};
point operator-(const point& a, const point& b) { return point(a.x - b.x, a.y - b.y); }
point operator+(const point& a, const point& b) { return point(a.x + b.x, a.y + b.y); }

bool greaterX(const point& a, const point& b) {
	if (a.x > b.x) return true;
	if (a.x < b.x) return false;
	return (a.y > b.y); 
}
bool greaterY(const point& a, const point& b) {
	if (a.y > b.y) return true;
	if (a.y < b.y) return false;
	return (a.x > b.x); 
}

void show(const point& a){ std::cout << '('<<a.x<<','<<a.y<<')'<<std::endl; }

typedef point vector2d;

double cross(const vector2d& a, const vector2d& b)
{
    return a.x * b.y - a.y * b.x;
}

// 点 p が反時計回りの三角形 abc の内側にあるかどうか判定
bool point_in_triangle(const point& p, const point& a, const point& b, const point& c)
{
    // p が ab の右側にあれば三角形の外側にある
    if (cross(p - a, b - a) < 0.0) return false;
    // p が bc の右側にあれば三角形の外側にある
    if (cross(p - b, c - b) < 0.0) return false;
    // p が ca の右側にあれば三角形の外側にある
    if (cross(p - c, a - c) < 0.0) return false;
    return true;
}
