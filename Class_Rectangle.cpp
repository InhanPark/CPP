#include<iostream>

class Point
{
public:
    int x; // x coordinate range 는 0~100
    int y; // y coordinate range 는 0~100
};

class Rectangle
{
public:
    Point upLeft;
    Point lowRight;

public:
    void ShowRecInfo()
    {
        std::cout << "Up Left: " << '[' << upLeft.x << ", ";
        std::cout << upLeft.y << ']' << std::endl;
        std::cout << "Low Right: " << '[' << lowRight.x << ", ";
        std::cout << lowRight.y << ']' << std::endl;

    }
};

int main(void)
{
    Point pos1 = {-2, 4};
    Point pos2 = {5, 9};

    Rectangle rec={pos2, pos1};
    rec.ShowRecInfo();

    return 0;
}