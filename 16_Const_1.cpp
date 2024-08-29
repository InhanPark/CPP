/*
Class member 함수뒤에 'const'를 붙이면, 이 함수는 class 내의 member value 는 변경하지 않고, local value 만 변경한다는 의미이다. 이때문에 이 함수는 class 전체를 const 선언을 해도 외부에서 사용할 수 있다 (member value 를 변경시키지 않는다는게 확실하므로) 
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
    void ShowData() const // member 값을 변경하지 않으므로 가급적 const 설정해서 호출 가능하게 함
    {
        std::cout << "num: " << num << std::endl;
    }
};

int main()
{
    const SoSimple obj(7); // const 인 객체 'obj' 를 생산하는 명령
    // obj.AddNum(20); 'obj' 는 const 이므로 '.AddNum(20)' 으로 변경할 수 없다
    obj.ShowData(); // '.ShowDate()'는 const 함수이므로 const 객체 'obj' 를 대상으로 호출 가능 
    return 0;
}
