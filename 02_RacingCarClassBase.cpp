/*
struct 에 전속 함수를 만들 수 있게 하면서 (Class 라는 이름도 주고) 기존 C 대비 사용이 많이 편리해졌다.

1. 변수와 함수명의 묹제가 없어졌다.
 - Class 내부의 모든것은 class name 을 namespace 로 갖기 때문에 같은 이름이 생기지 않는다.
   (같은 이름의 class 는 compiler 에서 정리된다. C 는 link 에서 정리됨)
 - Class 를 call 할때 class name 이 call 한 변수명으로 대체된다.
2. Class 내부변수/함수 접근을 'private', 'public', 'protected' 로 구분할 수 있다.
 - C 의 global, static 등의 사용을 안하거나, 최소화 할 수 있다.
 - private 으로 막아놓은 data 에의 접근은 별도 전속함수를 통해야만 한다.
3. Class 를 기존 module 이나 library 처럼 사용할 수 있고, 좀 더 편리하다.
 - Class 를 header 로 사용하고, body 를 별도 file 에 저장한다. 기존 module 과 유사하다.
4. new-reference 를 사용하여 Heap memory 에서 쓸 수 있다.
 - static 으로 쓰는것도 가능하다.
*/

/* header */
#include <iostream>
#include <cstring>

namespace CAR_CONST // 이 안에있는 모든것의 앞에 "CAR_CONST::" 를 붙여 준다는것
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

struct Car // Class 안에 전속 함수를 넣을 수 있음 (header 만 넣어도 됨)
{
private: // class 전속함수들만 접근 가능. 외부에서는 알수도 없음 (정보은닉)
    char gamerID[CAR_CONST::ID_LEN];
    int fuelGauge;
    int curSpeed;
public: // 외부에서도 인지 및 접근 가능 (library 함수와 유사)
    void InitMembers(char *ID, int fuel);
    // 초기화 등 외부에서 data 에 접근하려면 '전속 함수'를 거쳐야만 함.
    void ShowCarState();
    void Accel();
    void Break();
};

/* driver */
int main(void)
{
    // main 은 Car class 외부 함수 인데, data 는 private 으로 지정되어 있으므로, 다음과 같이 직접 초기화 못함
    // Car run99 = {"run99", 100, 0};  
    Car run99;
    run99.InitMembers("run99", 100); // class 의 내부 함수로만 가능

    Car sped77;
    sped77.InitMembers("sped77", 70);

    run99.Accel(); // class 안에 있는 public data 나 함수는 이렇게 사용하면 됨
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
void Car::InitMembers(char *ID, int fuel) // data 초기화 함수
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState() // 함수 body 는 namespace 로 엮는 방법으로 class 밖으로 뺄 수 있음
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