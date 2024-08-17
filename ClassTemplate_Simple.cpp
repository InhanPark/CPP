#include <iostream>

class Algebra
{
public:
    double pi;

    int add (int c, int d)
    {
        return c+d;
    }
};

int main()
{
    Algebra *cal_ptr = new Algebra(); // heap memory 에 생성
    Algebra& cal = *cal_ptr; // 사용 편리성을 위해 reference 적용
    cal = {3.14}; // 객체 초기화

    std::cout << cal.pi << std::endl;
    std::cout << cal.add(2,3) << std::endl;

    delete cal_ptr; // heap memory 에서 삭제
    return 0;
}
