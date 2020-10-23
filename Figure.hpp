#ifndef FIGURE_HPP
#define FIGURE_HPP

std::vector<std::string> nameByType = {"Octagon", "Triangle", "Square"};

class Figure
{
public:
    virtual Point Barycenter() const = 0;
    virtual void PrintCoordinates() const = 0;
    virtual double Area() const = 0;
    virtual int GetType() const = 0;
    virtual std::ostream &PrintInfo(std::ostream &out) const = 0;
    virtual std::istream &ReadInfo(std::istream &in) = 0;
    virtual ~Figure() {}
};

std::ostream &operator<<(std::ostream &out, const Figure &fg)
{
    return fg.PrintInfo(out);
}

std::istream &operator>>(std::istream &in, Figure &fg)
{
    return fg.ReadInfo(in);
}

#endif