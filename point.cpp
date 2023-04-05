#include "point.h"

Point::Point(double x, double y) : m_x(x), m_y(y) {}

double Point::getX() const {return m_x;}
double Point::getY() const {return m_y;}

void Point::setX(int x) {m_x = x;}

void Point::setY(int y) {m_y = y;}

Point Point::operator+(const Point & p){
    return Point(m_x + p.m_x, m_y + p.m_y);
}


Point Point::operator-(const Point & p){
    return Point(m_x - p.m_x, m_y - p.m_y);
}

Point Point::operator*(const Point & p){
    return Point(m_x * p.m_x, m_y * p.m_y);
}

Point Point::operator/(const Point & p){
    return Point(m_x / p.m_x, m_y / p.m_y);
}

Point Point::operator+(double a){
    return Point(m_x + a, m_y + a);
}


Point Point::operator-(double a){
    return Point(m_x - a, m_y - a);
}

Point Point::operator*(double a){
    return Point(m_x * a, m_y * a);
}

Point Point::operator/(double a){
    return Point(m_x / a, m_y / a);
}

