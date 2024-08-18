/*
- 'class Rectangle' 을 보강 변경한 program 이다. 'class' 단어를 'struct' 로 바꾸어도 동작을 잘한다. 
- 이제까지 사용하던 'InitMembers' 초기화 함수를 constructor 함수로 바꾸어 본다.
- constructor 함수는 class 와 같은 이름을 가지고, 초기화가 필요한 parameter 들을 가진, object 생성시에만 한번 사용되는 함수이다. constructor 의 핵심은 "object 가 생성과 동시에 초기화" 되는것이다.
- "생성과 동시에 초기화" 편리할 뿐만 아니라, 약간이라도 빨라진다. 또한 const 선언된 member value 도 초기화 할 수 있고, reference 를 생성해서 사용할수도 있는 여러가지 장점이 있다.
- destructor 함수는 object 를 지우기전에 마무리할 것을 하는 함수이다. class 이름앞에 '~' 를 붙인다. 보통 작업중 사용된 dynamic memory 를 해제하는데 사용한다.
- constructor 와 destructor 모두 return value 는 없다.
- constructor 도 함수이므로 overriding 이 가능하다.
- user 가 지정을 하지 않으면 constructor 와 destructor 모두 자동으로 만들어진다.
- constructor 는 private 으로도 지정 가능하다. (좀 더 복잡해짐)
*/

#include <iostream>

/* headers */
class Point
{
private:
    int x;
    int y;
public:
    Point(int x, int y); // constructor 함수
    int GetX() const; 
    int GetY() const; 
    bool SetX(int xpos); 
    bool SetY(int ypos); 
    ~Point(); // destructor 함수
};

class Rectangle
{
private:
    Point upLeft;  
    Point lowRight;
public:
    Rectangle(const int &x1, const int &y1, const int &x2, const int &y2); // constructor 함수
    void ShowRecInfo() const;
    ~Rectangle(); // destructor 함수
};

/* driver */
int main()
{
    // 선언과 동시에 초기화되므로 간단해짐
    // new 는 constructor 를 호출하지만, malloc 은 그런 기능이 없다. 단순히 address 만 넘겨줌.
    Rectangle *rec_ptr = new Rectangle(1, 1, 5, 5); 
    Rectangle& rec = *rec_ptr;
    rec.ShowRecInfo();

    delete rec_ptr;
    return 0;
}

/* functions */
Point::Point(int xpos, int ypos)
{
    x = xpos;
    y = ypos;
}

int Point::GetX() const { return x; }
int Point::GetY() const { return y; }

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

Point::~Point()
{
    // Empty
}


Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2) : upLeft(x1, y1), lowRight(x2, y2) // 변수 4개를 reference 로 받아서, upLeft 와 lowRight 를 선언한다.
// 선언과 동시에 초기화 되므로 member 변수의 reference 를 사용할 수 있다
// Point object 두개의 초기화도 constructor 함수 선언에서 선언과 동시에 한번에 진행할 수 있다
// const variable 도 여기서 선언할 수 있다.
{
    // Empty (모두 처리되어 할게 없음. 단 위의 initialization 작업을 여기서 해도 됨. 명확한 장점)
}

void Rectangle::ShowRecInfo() const
{
    // 'class Point' 가 외부 class 이므로, x 와 y 값을 직접 access 못한다. GetX() 와 GetY() 를 사용한다.
    std::cout << "upLeft: " << '[' << upLeft.GetX() << ", ";
    std::cout << upLeft.GetY() << ']' << std::endl;
    std::cout << "upRight: " << '[' << lowRight.GetX() << ", ";
    std::cout << lowRight.GetY() << ']' << std::endl;
}        

Rectangle::~Rectangle()
{
    // Empty
}
