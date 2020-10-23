#ifndef POINT_HPP
#define POINT_HPP

struct Point
{
    double x, y;
};

std::istream &operator>>(std::istream &in, Point &pt)
{
    in >> pt.x >> pt.y;
    return in;
}

std::ostream &operator<<(std::ostream &out, const Point &pt)
{
    out << "(" << pt.x << ", " << pt.y << ")";
    return out;
}

inline double DistanceSquared(Point p, Point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

inline double Cross(Point p, Point q)
{
    return p.x * q.y - q.x * p.y;
}

int ret[2][2] = {{0, 3}, {1, 2}};

inline int Quad(Point p)
{
    return ret[p.x >= 0][p.y >= 0];
}

bool byAngle(const Point &a, const Point &b)
{
    return Quad(a) == Quad(b) ? Cross(a, b) > 0 : Quad(a) < Quad(b);
}

#endif