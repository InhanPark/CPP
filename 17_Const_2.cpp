/*
Class 내에서 같은 함수를 하나는 일반으로, 다른 하나는 const 로 overriding 해서 만들 수 있다. 외부 (main) 에서 이 class 를 const 로 선언하게 되면, const 인 함수를 사용하게 된다. 그렇지 않으면 일반 함수를 사용하게 된다.
*/

#include <iostream>

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {
        std::cout << "create obj: " << num << std::endl;
    }
    SoSimple& AddNum(int n) 
    {
        num == n;
        return *this;
    }
    void SimpleFunc() // member value 'num' 값을 변경한다.
    {
        num += 1;
        std::cout << "SimpleFunc: " << num << std::endl;
    }
    void SimpleFunc() const // member value 'num' 값을 변경하지 못하는 overriding 함수이다.
    {
        std::cout << "const SimpleFunc: " << num << std::endl;
    }
};

void YourFunc(const SoSimple &obj) // parameter class 를 const 로 받았기 때문에, 이 class 는 const 이다.
{
    obj.SimpleFunc(); // class 내에서 const 인 member 함수만 사용할 수 있다.
}

int main(void)
{
    SoSimple obj1(2);  // 일반 객체 'obj' 를 생산하는 명령
    const SoSimple obj2(7); // const 인 객체 'obj' 를 생산하는 명령

    obj1.SimpleFunc(); // 일반 member 함수가 실행된다.
    obj2.SimpleFunc(); // const member 함수가 실행된다.

    YourFunc(obj1); // const member 함수가 실행된다.
    YourFunc(obj2); // const member 함수가 실행된다.

    return 0;
}
