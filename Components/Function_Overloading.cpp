#include <iostream>

void MyFunc(void)
{
    std::cout << "My Func(void) called" << std::endl;
}

void MyFunc(char c)
{
    std::cout << "My Func(char c) called" << std::endl;
}

void MyFunc(int a, int b)
{
    std::cout << "My Func(int a, int b) called" << std::endl;
}

int main(void)
{
    MyFunc();
    MyFunc('A');
    MyFunc(12, 13);
    return 0;
}