#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#define pi 3.1415926535897

#include "Figure.hpp"

class Octagon : public Figure
{
public:
    Octagon()
    {
        points.resize(8, {0, 0});
        center = {0, 0};
        r = 0;
        angle = 0;
    }
    Octagon(const Point &_center, const double &_r, const double &_angle)
    {
        center = _center;
        r = _r;
        angle = _angle;
        points.resize(8);
        // Построение правильного восьмиугольника путем откладывания радиус-вектора, повернутого на 0, 45, 90, ..., 315 градусов
        for(int i = 0; i < 8; ++i) {
            points[i].x = r * cos(2 * pi * i / 8 + angle * pi/180) + center.x;
            points[i].y = r * sin(2 * pi * i / 8 + angle * pi/180) + center.y;
        }
    }
    Point Barycenter() const
    {
        return center;
    }
    void PrintCoordinates() const
    {
        for (int i = 0; i < 8; ++i)
        {
            std::cout << points[i];
            if(i != 7) std::cout << ", ";
        }
        std::cout << '\n';
    }
    double Area() const
    {
        // Вычисление площади с помощью векторного произведения  
        double area = 0;
        for (int i = 1; i < 8; ++i)
        {
            area += Cross(points[i - 1], points[i]);
        }
        area += Cross(points[7], points[0]);
        return fabs(area) / 2.0;
    }
    std::istream &ReadInfo(std::istream &in)
    {
        in >> center.x >> center.y >> r >> angle;
        *this = Octagon(center, r, angle);
        return in;
    }
    std::ostream &PrintInfo(std::ostream &out) const
    {
        out << "Octagon info:\n";
        out << "* Points:\t";
        for (int i = 0; i < 8; ++i)
        {
            out << points[i];
            if (i != 7)
                out << ", ";
        }
        out << '\n';
        out << "* Side:\t" << 2 * r * sin (pi/8);
        out << '\n';
        out << "* Area:\t\t" << Area() << '\n';
        out << "* Barycenter:\t" << center << '\n';
        return out;
    }
    int GetType() const
    {
        return type;
    }
    ~Octagon() {}

private:
    double r, angle;
    Point center;
    std::vector<Point> points;
    int type = 1;
};

#endif
