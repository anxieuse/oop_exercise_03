#ifndef POINT_HPP
#define POINT_HPP

#define eps 1e-3

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
    out << "(" << std::fixed << pt.x << ", " << pt.y << ")";
    return out;
}

double DistanceSquared(Point p, Point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

double Cross(Point p, Point q)
{
    return p.x * q.y - q.x * p.y;
}

#endif