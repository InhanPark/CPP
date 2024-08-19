/*
C++ 에서는 C 의 structure 에 dedicated function 을 넣을 수 있게 했다. 이것 하나로 C++ 의 '객체지향 Object Oriented Programming' 과 '절차지향 Procedural Programming' 을 모두 사용할 수 있게 되었다. Dedicated function 을 사용 안하면 절차지향으로 작성할 수 밖에 없게 된다. 

아래 예제는 이 새로운 structure 를 가지고 Programming 하는 pattern 을 설명한다.

 - enumeration 을 namespace 를 따로 주어서 structure-like 하게 사용하는법
 - structure 를 header 작성하는 법
 - Dedicated function 들의 body 를 별도로 작성하는 법

이후의 coding 에서는 code 를 header, driver (main), function body 의 세부분으로 작성한다. 이렇게 하면 나중에 큰 program 을 만들때는 단지 세부분을 별도 file 로 나누기만 하면 되기 때문이다.

먼저, C 에서 struct 를 어떻게 사용했었는지 remind 해보자.

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

/* header */
#include <iostream>

namespace CAR_CONST // 이 안에있는 모든것의 앞에 "CAR_CONST::" 를 붙여 준다는것
{
    enum // enum 은 C 와 동일하게 사용. '#define' 사용보다 효과적
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


/* driver */
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

/* function body */
void Car::ShowCarState() // body 는 namespace 로 엮는 방법으로 structure 밖으로 뺄 수 있음
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
        fuelGauge -= CAR_CONST::FUEL_STEP; // enumeration 정의한 것 사용법

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

