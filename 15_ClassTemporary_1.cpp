/*
Class 를 임시적으로만 사용하고 자동으로 destruct 되게 할 수 있다.
*/

#include <iostream>

class Temporary
{
private:
    int num;
public:
    Temporary(int n) : num(n)
    {
        std::cout << "create obj: " << num << std::endl;
    }
    ~Temporary()
    {
        std::cout << "destroy obj: " << num << std::endl;
    }
    void ShowTempInfo()
    {
        std::cout << "My num is: " << num << std::endl;
    }
};

int main()
{
    Temporary temp(1000); // 자동으로 지워지므로 dynamic allocation 필요없음
    //Temporary &ref_1=Temporary(2000); // Error 발생
    const Temporary &ref_2=Temporary(3000); // 'const' 지정 필요

    Temporary(100);
    std::cout << "******* after make!" << std::endl << std::endl;

    Temporary(200).ShowTempInfo(); // class 를 200 으로 초기화하고, 여기에 있는 ShowTempInfo method 실행
    std::cout << "******* after make!" << std::endl << std::endl;

    const Temporary &ref=Temporary(300); // reference 지정하면 바로 안지워짐
    std::cout << "******* end of main!" << std::endl << std::endl;

    Temporary(100).ShowTempInfo();

    return 0;
}
