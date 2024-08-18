/*
*/

#include <iostream>

/* headers */
class Point
{
private:
    int xpos, ypos;
public:
    bool Init(int x, int y);
};

class Circle
{
private:
public:
};

class Ring
{
private:
public:
};

/* driver */
int main()
{
    Ring *ring_ptr = new Ring(); 
    Ring& ring = *ring_ptr;
    if(!ring.Init(1, 1, 4, 2, 2, 9))
        std::cout << "Ring Initialization Error" << std::endl;

    delete ring_ptr;
    return 0;
}

/* functions */
bool Point::Init(int x, int y)
{
    xpos = x;
    ypos = y;

    return true;
}
