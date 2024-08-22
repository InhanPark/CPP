/*
Rectangle 의 data 좌표를 private 으로 바꿀때 관련된 변경 사항들임.
- Information Hiding (정보은닉) 이란 class 외부에서 내부의 어느 부분은 파악할 수 없도록 하는 것이다. 외부에서 이 정보에 직접 접근 자체가 안되도록 되어있다.
- 아래는 'class Point' 를 보강 변경한 program 이다. 'private:' 을 사용하여 information hiding 을 하였다.
- 'const' keyword 를 붙여주면, 정보에 간접 접근은 할 수 있더라도, 변경은 안되어, 정보의 safety 를 강화할 수 있다.
*/

/* header */
#include <iostream>

class Point
{
private: // 변수들을 private 으로 선언해서 'class Point' 외부에서 직접 access 를 못하게 했다.
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
public:
    Point upLeft;  // 다른 struct 을 call 할 수 있듯이, 다른 class 를 call 할 수 있음
    Point lowRight;

public:
    void ShowRecInfo();  
};

/* driver */
int main()
{
    // 초기화를 따로하므로 dynamic allocation 사용 쉬움.
    Point *pos1_ptr = new Point(); 
    Point& pos1 = *pos1_ptr;
    if(!pos1.InitMembers(-2, 4)) // 일부러 Error 를 만드는 명령
        std::cout << "Initialization Error" << std::endl;
    if(!pos1.InitMembers(2, 4))
        std::cout << "Initialization Error" << std::endl;

    // static allocation 도 가능함.
    Point pos2;
    if(!pos2.InitMembers(5, 9))
        std::cout << "Initialization Error" << std::endl;

    Rectangle rec = {pos2, pos1}; 
    rec.ShowRecInfo();

    delete pos1_ptr;
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

void Rectangle::ShowRecInfo()
{
    // 'class Point' 가 외부 class 이므로, x 와 y 값을 직접 access 못한다. GetX() 와 GetY() 를 사용한다.
    std::cout << "upLeft: " << '[' << upLeft.GetX() << ", ";
    std::cout << upLeft.GetY() << ']' << std::endl;
    std::cout << "upRight: " << '[' << lowRight.GetX() << ", ";
    std::cout << lowRight.GetY() << ']' << std::endl;
}        