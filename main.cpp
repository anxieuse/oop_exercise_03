/* 
Короткевич Л. В.
М8О-208Б-19
github.com/anxieuse/oop_exercise_03
Вариант 16: 
    8-угольник
    Треугольник
    Квадрат
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

#include "Point.hpp"
#include "Figure.hpp"
#include "Square.hpp"
#include "Triangle.hpp"
#include "Octagon.hpp"

void printHelp()
{
    std::cout << "1) Add figure (type <1 1> to add Octagon, <1 2> - Triangle, <1 3> - Square)\n";
    std::cout << "2) Remove figure\n";
    std::cout << "3) Display elements\n";
    std::cout << "4) Display barycenter of figure\n";
    std::cout << "5) Display points of figure\n";
    std::cout << "6) Display area of figure\n";
    std::cout << "7) Display all information about the figure\n";
    std::cout << "8) Display total area\n";
    std::cout << "9) Exit\n";
}

int main()
{
    printHelp();

    std::vector<Figure *> figures;
    unsigned long long totalArea = 0;

    bool input = true;
    int cmdID, figureType, ID;

    Square *sampleSq;
    Octagon *sampleOc;
    Triangle *sampleTr;

    while (input)
    {
        std::cin >> cmdID;
        switch (cmdID)
        {
        case 1: // add
        {
            std::cin >> figureType;
            if (figureType == 1)
            {
                sampleOc = new Octagon;
                std::cin >> *sampleOc;
                figures.push_back(sampleOc);
            }
            if (figureType == 2)
            {
                sampleTr = new Triangle;
                std::cin >> *sampleTr;
                figures.push_back(sampleTr);
            }
            if (figureType == 3)
            {
                sampleSq = new Square;
                std::cin >> *sampleSq;
                figures.push_back(sampleSq);
            }
            totalArea += figures.back()->Area();
            std::cout << nameByType[figureType - 1] << " succesfully added at index " << figures.size() - 1 << '\n';
            break;
        }
        case 2: // remove
        {
            std::cin >> ID;
            if (ID > figures.size())
            {
                std::cout << "ID is too big. There are no such many elements!\n";
            }
            else
            {
                totalArea -= figures[ID]->Area();
                std::cout << nameByType[figures[ID]->GetType() - 1] << " successfully removed\n";
                delete figures[ID];
                figures.erase(figures.begin() + ID);
            }
            break;
        }
        case 3: // display elements
        {
            std::cout << "Index\tType\t\tArea\tCoordinates\n";
            for (int i = 0; i < figures.size(); ++i)
            {
                std::cout << i << '\t' << nameByType[figures[i]->GetType() - 1] << "\t";
                if (nameByType[figures[i]->GetType() - 1] != "Triangle")
                    std::cout << "\t";
                std::cout << figures[i]->Area() << '\t';
                figures[i]->PrintCoordinates();
            }
            break;
        }
        case 4: // barycenter
        {
            std::cin >> ID;
            if (ID > figures.size())
            {
                std::cout << "ID is too big. There are no such many elements!\n";
            }
            else
            {
                std::cout << nameByType[figures[ID]->GetType() - 1] << "'s barycenter: " << figures[ID]->Barycenter() << '\n';
            }
            break;
        }
        case 5: // coordinates
        {
            std::cin >> ID;
            if (ID > figures.size())
            {
                std::cout << "ID is too big. There are no such many elements!\n";
            }
            else
            {
                std::cout << nameByType[figures[ID]->GetType() - 1] << "'s points:\t";
                figures[ID]->PrintCoordinates();
            }
            break;
        }
        case 6: // area
        {
            std::cin >> ID;
            if (ID > figures.size())
            {
                std::cout << "ID is too big. There are no such many elements!\n";
            }
            else
            {
                std::cout << nameByType[figures[ID]->GetType() - 1]
                          << "'s area: " << figures[ID]->Area() << '\n';
            }
            break;
        }
        case 7: // info
        {
            std::cin >> ID;
            if (ID > figures.size())
            {
                std::cout << "ID is too big. There are no such many elements!\n";
            }
            else
            {
                std::cout << *figures[ID];
            }
            break;
        }
        case 8: // total area
        {
            std::cout << "Total area: " << totalArea << '\n';
            break;
        }
        case 9: // end
        {
            input = false;
            break;
        }
        }
    }
    for(auto &x : figures)
        delete x; 
    return 0;
}
