/*
*/

#include <iostream>

/* header */
class Point
{
private:
    int xpos, ypos;
public:
    Point(int x, int y);
    ~Point();
};

/* driver */
int main()
{
    Point *point_ptr = new Point(1, 1); 
    Point& point = *point_ptr;

    delete point_ptr;
    return 0;
}

/* function body */
Point::Point(int x, int y)
{
    xpos = x;
    ypos = y;
}

Point::~Point()
{
    //Empty
}
