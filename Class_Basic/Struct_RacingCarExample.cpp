#include <iostream>
using std::cin; // 사용할 library 는 이렇게 미리 선언해 주면 됨. 이후에는 "std::" 붙이지 않아도 됨
using std::cout;
using std::endl;

namespace CAR_CONST // namespace 란 이 안에있는 모든것의 앞에 "CAR_CONST::" 를 붙여 준다는것
{
    enum // enum 은 C 와 같이 사용. #define 사용하는 것보다 효과적
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

void Car::ShowCarState() // 함수 body 는 이런식으로 밖으로 뺄 수 있음
{
    cout << "소유자ID: " << gamerID << endl;
    cout << "연료량: " << fuelGauge << "%" << endl;
    cout << "현재속도: " << curSpeed << "km/s" << endl
         << endl;
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
    Car run99 = {"run99", 100, 0}; // struct 를 이렇게 부르면 됨
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