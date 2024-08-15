#include <iostream>

inline int SQUARE(int x)
{
    return x * x;
}

int main(void)
{
    std::cout << SQUARE(5) << std::endl;
    std::cout << SQUARE(3.14) << std::endl;
    return 0;
}