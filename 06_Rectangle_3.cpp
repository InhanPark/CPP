/*
'class Rectangle' 의 data 도 은닉하고, 초기화 함수를 통해 접근하게 한 것이다.
*/

/* header */
#include <iostream>

class Point
{
private:
    int x;
    int y;
public:
    bool InitMembers(int xpos, int ypos); // 외부에서는 이 함수를 통해서만 변수를 초기화 할 수 있다.
    /* 아래 함수들을 'access function' 이라고 한다. 쓰지 않는 경우에도 기본으로 만들어둔다. */
    int GetX() const; // 외부에서는 이 함수를 통해서만 x 변수값을 가져갈 수 있다. (변경은 못한다 const)
    int GetY() const; // 외부에서는 이 함수를 통해서만 y 변수값을 가져갈 수 있다. (변경은 못한다 const)
    bool SetX(int xpos); // 외부에서는 이 함수를 통해서만 x 변수값을 바꿀 수 있다.
    bool SetY(int ypos); // 외부에서는 이 함수를 통해서만 y 변수값을 바꿀 수 있다.
};

class Rectangle
{
private:
    Point upLeft;  // 다른 struct 을 call 할 수 있듯이, 다른 class 를 call 할 수 있음
    Point lowRight;
public:
    bool InitMembers(const Point &ul, const Point &lr);
    // 외부에서는 이 함수를 통해서만 변수를 초기화 할 수 있다.
    void ShowRecInfo() const;
    // const 함수 내에서는 const가 아닌 함수의 호출이 제한된다. (변경의 가능성 없앰)
};

/* driver */
int main()
{
    Point *pos1_ptr = new Point(); 
    Point& pos1 = *pos1_ptr;
    if(!pos1.InitMembers(2, 4))
        std::cout << "Initialization Error" << std::endl;

    Point *pos2_ptr = new Point(); 
    Point& pos2 = *pos2_ptr;
    if(!pos2.InitMembers(5, 9))
        std::cout << "Initialization Error" << std::endl;

    Rectangle *rec_ptr = new Rectangle(); 
    Rectangle& rec = *rec_ptr;
    if(!rec.InitMembers(pos2, pos1))
        std::cout << "Rectangle Initialization Error" << std::endl;

    if(!rec.InitMembers(pos1, pos2))
        std::cout << "Rectangle Initialization Error" << std::endl;

    rec.ShowRecInfo();


    delete &pos1;
    delete &pos2;
    delete &rec;
//  delete pos1_ptr; // 같은 효과를 나타냄
//  delete pos2_ptr; // 같은 효과를 나타냄
//  delete rec_ptr;  // 같은 효과를 나타냄

    return 0;
}

/* function body */
bool Point::InitMembers(int xpos, int ypos)
{
    if(xpos<0 || ypos<0)
    {
        std::cout << "point coordinate is out of range" << std::endl;
        return false;
    }

    x = xpos;
    y = ypos;
    return true;
}

int Point::GetX() const
{
    return x;
}

int Point::GetY() const
{
    return y;
}

bool Point::SetX(int xpos)
{
    if(xpos>0 || xpos>100)
    {
        std::cout << "point coordinate x is out of range" << std::endl;
        return false;
    }

    x = xpos;
    return true;
}

bool Point::SetY(int ypos)
{
    if(ypos>0 || ypos>100)
    {
        std::cout << "point coordinate y is out of range" << std::endl;
        return false;
    }

    y = ypos;
    return true;
}

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if(ul.GetX() > lr.GetX() || ul.GetY() > lr.GetY())
    {
        std::cout << "wrong position data" << std::endl;
        return false;
    }
    upLeft = ul;
    lowRight = lr;
    return true;
}

void Rectangle::ShowRecInfo() const
{
    // 'class Point' 가 외부 class 이므로, x 와 y 값을 직접 access 못한다. GetX() 와 GetY() 를 사용한다.
    std::cout << "upLeft: " << '[' << upLeft.GetX() << ", ";
    std::cout << upLeft.GetY() << ']' << std::endl;
    std::cout << "upRight: " << '[' << lowRight.GetX() << ", ";
    std::cout << lowRight.GetY() << ']' << std::endl;
}        