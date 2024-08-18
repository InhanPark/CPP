#include <iostream>

class Algebra
{
public:
    double pi;
    char* s;

    int add (int c, int d)
    {
        return c+d;
    }
};

int main()
{
    Algebra cal{3.14, "string para"};

    std::cout << cal.pi << cal.s << std::endl;
    std::cout << cal.add(2,3) << std::endl;

    return 0;
}
