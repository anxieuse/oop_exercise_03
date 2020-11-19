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

    bool isSquare(Point p1, Point p2, Point p3, Point p4)
    {
        int d2 = DistanceSquared(p1, p2); // from p1 to p2
        int d3 = DistanceSquared(p1, p3); // from p1 to p3
        int d4 = DistanceSquared(p1, p4); // from p1 to p4

        if (d2 == 0 || d3 == 0 || d4 == 0)
            return false;

        // Если длины (p1, p2) и (p1, p3) одинаковы, то
        // для образования квадрата должны быть выполнены следующие условия:
        // 1) квадрат длины (p1, p4) такой же, как дважды квадрат (p1, p2)
        // 2) квадрат длины (p2, p3) равен удвоенному квадрату (p2, p4)

        if (d2 == d3 && 2 * d2 == d4 && 2 * DistanceSquared(p2, p4) == DistanceSquared(p2, p3))
        {
            return true;
        }

        if (d3 == d4 && 2 * d3 == d2 && 2 * DistanceSquared(p3, p2) == DistanceSquared(p3, p4))
        {
            return true;
        }
        if (d2 == d4 && 2 * d2 == d3 && 2 * DistanceSquared(p2, p3) == DistanceSquared(p2, p4))
        {
            return true;
        }

        return false;
    }

    std::istream &ReadInfo(std::istream &in)
    {
        in >> A >> B >> C >> D;
        if(isSquare(A, B, C, D))
            (*this) = Square(A, B, C, D);
        else {
            std::cout << "You entered not a square :(\n";
        }
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