#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Figure.hpp"

class Triangle : public Figure
{
public:
    Triangle()
    {
        A = B = C = {0, 0};
        a = b = c = 0;
    }
    Triangle(const Point &_A, const Point &_B, const Point &_C)
    {
        A = _A, B = _B, C = _C;
        a = sqrt(DistanceSquared(A, B));
        b = sqrt(DistanceSquared(A, C));
        c = sqrt(DistanceSquared(B, C));
    }
    Point Barycenter() const
    {
        double cx = (A.x + B.x + C.x) / 3.0;
        double cy = (A.y + B.y + C.y) / 3.0;
        return {cx, cy};
    }
    void PrintCoordinates() const
    {
        std::cout << A << ", " << B << ", " << C << '\n';
    }
    double Area() const
    {
        double p = 0.5 * (a + b + c);
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    bool isRegularTriangle(Point p1, Point p2, Point p3)
    {
        double  a = DistanceSquared(p1, p2), 
                b = DistanceSquared(p1, p3), 
                c = DistanceSquared(p2, p3);
        // Если a == b, a == c, b == c, тогда треугольник является равносторонним:
        if ((fabs(a - b) < eps) && (fabs(a - c) < eps) && (fabs(b - c) < eps))
        {
            return true;
        }
        return false;
    }
    std::istream &ReadInfo(std::istream &in)
    {
        in >> A >> B >> C;
        if (isRegularTriangle(A, B, C))
            (*this) = Triangle(A, B, C);
        else
        {
            std::cout << "You entered not a regular triangle :(\n";
        }
        return in;
    }
    std::ostream &PrintInfo(std::ostream &out) const
    {
        out << "Triangle info: \n";
        out << "* Points:\t" << A << ", " << B << ", " << C << '\n';
        out << "* Sides:\t" << a << ", " << b << ", " << c << '\n';
        out << "* Area:\t\t" << Area() << '\n';
        out << "* Barycenter:\t" << Barycenter() << '\n';
        return out;
    }

    int GetType() const
    {
        return type;
    }
    ~Triangle() {}

private:
    Point A, B, C;
    double a, b, c;
    int type = 2;
};

#endif