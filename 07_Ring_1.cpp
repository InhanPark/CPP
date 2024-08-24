/*
Encapsulation (캡슐화) 란 이미 만들어진 class 들을 순서에 따라 배치해서 새로운 class 를 만드는 것이다. 불러오는 class 들을 'private' 으로 선언하면, 외부에서는 어떤 것을 사용했는지 알수가 없어서 정보은닉도 된다.
- 아래는 Point 로 center 위치를 정하고, 여기에 radius 를 추가하여 Circle 을 만들고, Circle 2개를 모아서 새로운 class 인 Ring 을 만드는 program 이다. Ring class 가 Encapsulation 이다.
*/

#include <iostream>

/* header */
class Point
{
private:
    int xpos, ypos;
public:
    bool Init(int x, int y);
    void ShowPointInfo() const;
};

class Circle
{
private:
    int radius;
    Point center;
public:
    bool Init(int x, int y, int r);
    void ShowCircleInfo() const;
};

class Ring
// Encapsulation class 이다.
{
private:
    Circle inCircle; // class 호출은 main 에서 하므로 여기서는 dynamic allocation 을 할 필요없다.
    Circle outCircle;
public:
    bool Init(int inX, int inY, int inR, int outX, int outY, int outR);
    void ShowRingInfo() const;
};

/* driver */
int main()
{
    Ring *ring_ptr = new Ring(); 
    Ring& ring = *ring_ptr;
    if(!ring.Init(1, 1, 4, 2, 2, 9))
        std::cout << "Ring Initialization Error" << std::endl;
    ring.ShowRingInfo();

    delete &ring;
    return 0;
}

/* function body */
bool Point::Init(int x, int y)
{
    xpos = x;
    ypos = y;

    return true;
}

void Point::ShowPointInfo() const
{
    std::cout << "[" << xpos << ", " << ypos << "]" << std::endl;
}

bool Circle::Init(int x, int y, int r)
{
    radius = r;
    center.Init(x, y);
    return true;
}

void Circle::ShowCircleInfo() const
{
    std::cout << "radius : " << radius << std::endl;
    center.ShowPointInfo();
}

bool Ring::Init(int inX, int inY, int inR, int outX, int outY, int outR)
{
    inCircle.Init(inX, inY, inR);
    outCircle.Init(outX, outY, outR);
    return true;
}

void Ring::ShowRingInfo() const
{
    std::cout << "Inner Circle Info..." << std::endl;
    inCircle.ShowCircleInfo();
    std::cout << "Outer Circle Info..." << std::endl;
    outCircle.ShowCircleInfo();
}