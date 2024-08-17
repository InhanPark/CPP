/*
Virtual memory map 에 네곳의 data 저장 영역이 있고, 각각의 저장 특성이 모두 다르다. Program 중에서 사용하는 data 의 성격에 따라서 선택해 사용한다.

1. Initialized data (.data): program loading 시 만들어지며, program 이 끝날때까지 유지된다.
2. Uninitialized data (.bss): 처음 사용될때 만들어지며, program 이 끝날때까지 유지된다.
3. Run-time heap: new (malloc) 명령에 의해 만들어지며, delete (free) 명령에 의해 삭제된다.
4. User stack: 함수가 시작되면 만들어지며, 함수가 끝나면 자동으로 삭제된다.
*/

/*
Heap memory 를 사용하면 필요할때 아무때나 만들어 쓰고, 사용후에는 지우면 되므로 여러 장점이 있다. 예를들어 어떤 함수가 만들어 놓은 것을 다른 함수가 사용할수도 있다 (address 만 넘겨주면 된다). Stack 은 함수가 끝나면 자동으로 지워지므로 불가능하다.

그러나 일부러 지워주어야만 한다는 문제가 있다. 지우지 않을 경우 쓰지도 않으면서 memory 를 낭비하게 된다. Java 나 Python 은 garbage collection 기능이 있어서 안쓰는 memory 를 찾아서 자동으로 지워주지만 (완벽하지는 앟음) C, C++ 은 반드시 지워주어야 한다.
*/

#include <iostream>
#include <string.h>

char* MakeStr(int len)
/* heap memory 에 'len' byte 만큼의 memory 를 만들고, 그 시작점 주소를 전달해주는 함수 */
{
    char *str = new char[len];
    return str;
}

class Simple
{
public:
    Simple()
    {
        std::cout << "I'm a simple constructor!" << std::endl;
    }
};

int main(void)
{
    /* pointer 로 (string 만들기) heap memory 사용 */
    char* mystr = MakeStr(30); // 30-byte memory 의 시작점 주소를 받는다.
    strcpy(mystr, "This string is on a heap memory."); // 여기에 string data 넣는다
    std::cout << mystr << std::endl; // 출력해 본다
    delete mystr; // heap memory 를 지운다
    mystr = NULL;
    std::cout << mystr << std::endl; // memory 를 지워도 pointer 는 남아있음을 주의 !!!
    // 만약 memory 를 지우기전에 pointer 의 내용을 바꿔 버리면, memory 를 지울 방법이 없어진다.
    // 사용이 끝난 memory 는 즉시 지우는 것이 최선이다.

    /* reference 로 heap memory 사용 */
    int *iptr = new int;
    int& iref = *iptr;
    iref = 100; // 일반 int 변수 처럼 사용할 수 있다.
    std::cout << iref << std::endl;
    delete iptr;
    // int 하나를 heap 에 만들어 사용하는 것은 번거롭지만, array 같이 size 가 큰것은 효율적이다.

    /* class 는 무조건 heap memory 를 사용한다 */
    Simple* sp1 = new Simple;
    std::cout << std::endl << "end of main" << std::endl;
    delete sp1;

    return 0;
}