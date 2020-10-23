#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "Figure.hpp"

class Octagon : public Figure
{
public:
    Octagon()
    {
        points.resize(8);
        std::fill(points.begin(), points.end(), Point{0, 0});
        sides.resize(8);
        std::fill(sides.begin(), sides.end(), 0.0);
    }
    Octagon(const std::vector<Point> &pts)
    {
        points.resize(8);
        points = pts;
        std::sort(points.begin(), points.end(), byAngle);

        sides.resize(8);
        for (int i = 1; i < 8; ++i)
        {
            sides[i] = sqrt(DistanceSquared(points[i], points[i - 1]));
        }
        sides[0] = sqrt(DistanceSquared(points[7], points[0]));
    }
    Point Barycenter() const
    {
        double sumx = 0, sumy = 0;
        for (auto &pt : points)
        {
            sumx += pt.x;
            sumy += pt.y;
        }
        return {sumx / 8.0, sumy / 8.0};
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
        for (auto &pt : points)
        {
            in >> pt;
        }
        (*this) = Octagon(points);
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
        out << "* Sides:\t";
        for (int i = 0; i < 8; ++i)
        {
            out << sides[i];
            if (i != 7)
                out << ", ";
        }
        out << '\n';
        out << "* Area:\t\t" << Area() << '\n';
        out << "* Barycenter:\t" << Barycenter() << '\n';
        return out;
    }
    int GetType() const
    {
        return type;
    }
    ~Octagon() {}

private:
    std::vector<Point> points;
    std::vector<double> sides;
    double side;
    int type = 1;
};

#endif