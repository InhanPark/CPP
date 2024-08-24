/*
this 를 활용하면 python 등에서 자주 볼 수 있는 function chain 을 만들 수 있음
*/

#include <iostream>

/* header */
class SelfRef
{
private:
    int num;
public:
    SelfRef(int n);
    SelfRef& Adder(int n);
    SelfRef& ShowCurrentNumber();
};

/* driver */
int main()
{
    SelfRef *obj_ptr = new SelfRef(3); 
    SelfRef& obj = *obj_ptr;
    SelfRef& ref = obj.Adder(2); // ref 에 자기의 pointer (this) 가 저장됨.

    obj.ShowCurrentNumber();
    ref.ShowCurrentNumber();

    ref.Adder(1).ShowCurrentNumber().Adder(2).ShowCurrentNumber();
    // ref 를 this 로 바꾸어 생각할 수 있음
    // 'this.Adder(1)' 이 실행되며 1을 더하는 동작과 'this.Adder(1)->this' 로 대체됨
    // 'this.ShowCurrentNumber()' 이 실행되고 'this.ShowCurrentNumber()->this' 대체
    // 이런식으로 왼쪽에서 오른쪽으로 self reference 를 계속하며 실행됨
    // 이런 동작은 python 에서 자주 볼 수 있는것임.
    delete obj_ptr;
    return 0;
}

/* function body */
SelfRef::SelfRef(int n) : num(n)
{
    std::cout << "object created ..." << std::endl;
}

SelfRef& SelfRef::Adder(int n)
{
    num += n;
    return *this;
}

SelfRef& SelfRef::ShowCurrentNumber()
{
    std::cout << num << std::endl;
    return *this;
}
