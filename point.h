#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double m_x;
    double m_y;
public:
    Point(double x, double y);
    double getX() const;
    double getY() const;

    void setX(int x);
    void setY(int y);

    Point operator+(const Point &p);
    Point operator-(const Point &p);
    Point operator*(const Point &p);
    Point operator/(const Point &p);
    Point operator+(double a);
    Point operator-(double a);
    Point operator*(double a);
    Point operator/(double a);
};
#endif // POINT_H
