/*
C 에서 struct 를 어떻게 사용했었는지 remind 해보자.

struct car {
    char gamerID[20];
    int  fuelGauge;
    int  curSpeed;
}

void main()
{
    struct car run99 = {"run99", 100, 0}; // struct object 생성 및 초기화
    struct car sped77 = {"sped77", 70, 30};

    run99.fuelGauge = 90; // data 의 변경
}
*/

/*
C++ 은 C 의 structure 에 dedicated function 을 넣을 수 있게했다. 

    1. 함수 Code 전체를 넣어도 되고 header 만 넣어도 된다.
      - Header 만 넣을 경우 함수 본체는 namespace 로 struct 에 전속된다. 
      - 함수 사용은 data 사용과 똑같다 (선언명.함수명).
    2. struct 선언도 'struct'를 빼고 'int a' 처럼 간단하게 했다.

함수가 structure 내부로 들어가 전속함수(dedicated function)이 되면 'data structure 와 function 이 하나'가 되면서 structure 는 독립적 존재가 되고, 이것을 사용한 programming 은 '객체지향 Object Oriented Programming' 방법을 사용해야 한다. 이는 기존에 data structure 와 function 이 독립적인 '절차지향 Procedural Programming' 과는 서로 방법이 다르게 된다.

객체지향은 structure 가 data 와 function 을 모두 가졌기에, 독립적인 structure 사이에 무언가를 주고 받는 방식으로 동작한다 (상대편의 함수를 통해서). 반면 절차지향은 structure 는 data 만을 가지고 있기에, 거기에 있는 data 를 바꾸고, 이동시키는 것은 외부의 함수들이 control 하는 방식으로 동작한다. 객체지향도 structure 내부에서는 절차지향으로 동작할 수 밖에 없다.

'data structure 와 function 이 하나'가 된 structure 가 class 이다. 실제로는 다음과 같이 동작한다.

1. 처음 struct 의 구조를 정의할때, data structure 와 전속 함수의 address 들이 정해진다. (function 도 address 를 가지고 있기에 가능하다.) (이 상태는 class 이다.)
2. 이것이 선언되는 순간 memory 에는 structure 의 data structure 만 공간이 만들어진다. (이것을 객체 (object) 라고 부른다)
3. 선언이 여러번 되어 여러 객체가 만들어져도, 이들은 function 은 공유한다. function address 는 모두 같고, 단지 data structure 의 내용만 다르기 때문이다.

다른 시각으로 보면 C++ 의 structure 나 class 는 data 와 function 이 있는 C 의 독립적 program 한개와 같다. 그런 독립적 program 여러개가 서로 data 를 주고 받으며 (다른것에 전속된 function 을 library 처럼 불러서 사용하기도 하면서) 돌아가기 때문에, 마치 multi-process 처럼 돌아가는 것 처럼 보일수도 있다. 이때문에 C++ 의 structure 나 class 가 어렵기도 하면서 매력적인 것이다.

Class 를 사용할때 C 의 독립적 program 한개를 작성한다고 생각하는 것은 좋은 방법일 것이다.
*/


// 아래는 C++ 의 structure 를 설명하며, C 의 structure 가 C++ 의 class 로 발전되는것을 이해하는데 도움이 될 것이다. 이 code 전체가 (driver 인 main 빼고) 하나의 class 가 된다.

#include <iostream>

namespace CAR_CONST // namespace 란 이 안에있는 모든것의 앞에 "CAR_CONST::" 를 붙여 준다는것
{
    enum // enum 은 C 와 동일하게 사용. #define 사용하는 것보다 효과적
    {
        ID_LEN = 20,
        MAX_SPD = 200,
        FUEL_STEP = 2,
        ACC_STEP = 10,
        BRK_STEP = 10
    };
}

struct Car // C 와 다르게 struct 안에 함수를 넣을 수 있음 (header 만 넣어도 됨)
{
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;

    void ShowCarState();
    void Accel();
    void Break();
};

void Car::ShowCarState() // 함수 body 는 namespace 로 엮는 방법으로 structure 밖으로 뺄 수 있음
{
    std::cout << "Owner ID: " << gamerID << std::endl;
    std::cout << "Fuel Gauge: " << fuelGauge << "%" << std::endl;
    std::cout << "Current Speed: " << curSpeed << "km/s" << std::endl
         << std::endl;
}

void Car::Accel()
{
    if (fuelGauge <= 0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if ((curSpeed + CAR_CONST::ACC_STEP) >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }

    curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }

    curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void)
{
    Car run99 = {"run99", 100, 0}; // struct 선언이 C 보다 간단 ('int a' 와 같음)
    Car sped77 = {"sped77", 70, 30};
    run99.Accel(); // struct 안에 있는 함수는 이렇게 사용하면 됨
    sped77.Break();
    run99.ShowCarState();
    sped77.ShowCarState();
    run99.Break();
    sped77.Accel();
    run99.ShowCarState();
    sped77.ShowCarState();
    return 0;
}