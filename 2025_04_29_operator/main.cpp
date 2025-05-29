#include <iostream>

class Point{
public:
    Point() {};
    Point(int x, int y) : x(x), y(y) {};
    Point operator + (const Point &a){
        Point ret;
        ret.x = this->x + a.x;
        ret.y = this->y + a.y;
        return ret;
    };
    Point operator - (const Point &a){
        Point ret;
        ret.x = this->x - a.x;
        ret.y = this->y - a.y;
        return ret;
    };
    friend Point operator * (const Point &a, const Point &b);
    friend std::ostream &operator << (std::ostream &out, const Point &b);
    int x,y;
};
Point operator * (const Point &a, const Point &b){
    Point ret;
    ret.x = a.x * b.x;
    ret.y = a.y * b.y;
    return ret;
}
std::ostream &operator << (std::ostream &out, const Point &b){
    out << "<Point>(" << b.x << "," << b.y << ")";
    return out;
}
int main(){
    Point a(1,2), b(3,4);
    Point c, d, e;
    c = a + b;
    d = a - b;
    e = a * b;
    std::cout<<c.x<<"  "<<c.y<<std::endl;
    std::cout<<d.x<<"  "<<d.y<<std::endl;
    std::cout<<e.x<<"  "<<e.y<<std::endl;
    std::cout << c << std::endl;
    return 0;
}