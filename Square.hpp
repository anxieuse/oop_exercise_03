#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "Figure.hpp"

class Square : public Figure
{
public:
    Square()
    {
        A = B = C = D = {0, 0};
        side = 0;
    }
    Square(const Point &a, const Point &b, const Point &c, const Point &d)
    {
        A = a, B = b, C = c, D = d;
        side = sqrt(std::min(DistanceSquared(A, B), DistanceSquared(A, C)));
    }
    Point Barycenter() const
    {
        double max_x = std::max({A.x, B.x, C.x, D.x});
        double max_y = std::max({A.y, B.y, C.y, D.y});
        return {max_x - side / 2.0, max_y - side / 2.0};
    }
    void PrintCoordinates() const {
        std::cout << A << ", " << B << ", " << C << ", " << D << '\n';
    }
    double Area() const
    {
        return side * side;
    }
    std::istream &ReadInfo(std::istream &in)
    {
        in >> A >> B >> C >> D;
        (*this) = Square(A, B, C, D);
        return in;
    }
    std::ostream &PrintInfo(std::ostream &out) const
    {
        out << "Square info: \n";
        out << "* Points:\t" << A << ", " << B << ", " << C << ", " << D << "\n";
        out << "* Sides:\t" << side << "\n";
        out << "* Area:\t\t" << Area() << '\n';
        out << "* Barycenter:\t" << Barycenter() << '\n';
        return out;
    }
    int GetType() const {
        return type;
    }
    ~Square() {}

private:
    Point A, B, C, D;
    double side;
    int type = 3;
};

#endif