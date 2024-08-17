/*
Rectangle 의 좌표를 받아 들이는 program 이다.
'class' 로 선언된 것을 모두 'struct' 로 바꾸어도 동작을 잘한다.
즉, 이 정도 code 에서는 struct 와 class 가 차이가 없는것이다.
*/

#include <iostream>

class Point // class 를 struct 로 바꾸어도 동작함
{
public:
    int x;
    int y;
};

class Rectangle // class 를 struct 로 바꾸어도 동작함
{
public:
    Point upLeft;  // 다른 struct 을 call 할 수 있듯이, 다른 class 를 call 할 수 있음
    Point upRight;

public:
    void ShowRecInfo()
    {
        std::cout << "upLeft: " << '[' << upLeft.x << ", ";
        std::cout << upLeft.y << ']' << std::endl;
        std::cout << "upRight: " << '[' << upRight.x << ", ";
        std::cout << upRight.y << ']' << std::endl;
    }        
};

int main()
{
    Point pos1 = {-2, 4}; // class Point 의 public 을 private 으로 바꾸면 문제가 됨.
                          // main 은 class 외부 함수이기 때문임.
    Point pos2 = {5, 9};
    Rectangle rec = {pos2, pos1}; // 다른 class 를 parameter 로 줄 수 있다.
    rec.ShowRecInfo();
    return 0;
}
