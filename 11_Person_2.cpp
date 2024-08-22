/*
class array 를 선언할때 constructor function 에 parameter 를 줄 수 없는 문제를 해결하기 위하여
- pointer array 를 만든다. (Person *parr[3];)
- for loop 를 이용하여 class 를 하나씩 만들며, 그 address 를 pointer array 에 저장한다.
- 하나씩 만들기 때문에 constructor 에 parameter 를 줄 수 있다.
- pointer array 의 address 를 기준으로 작업을 한다.
- 만들어진 class 하나하나를 memory 반환을 해주어야 한다 (destructor)

아래 code 에서 dynamic memory allocation 이 어느 부분에서 이루어지고, 그 memory 의 delete 는 어디서 이루어 지는지 자세히 보아야 한다.
*/

#include <iostream>
#include <cstring>

/* headers */
class Person
{
private:
    char *name;
    int age;
public:
    Person(char *myname, int myage);
    Person();
    void SetPersonInfo(char *myname, int myage); // data 를 setting
    void ShowPersonInfo() const; // 받은 data 로 하는 작업. 여기서는 간단히 data 를 출력만 함.
    ~Person();
};

/* driver */
int main()
{
    Person *parr[3]; // pointer array 를 만든다.
    char namestr[100];
    int age;

    for(int i=0; i<3; i++)
    {
        std::cout << "name: ";
        std::cin >> namestr;
        std::cout << "age: ";
        std::cin >> age;
        parr[i] = new Person(namestr, age);
        // class 를 하나씩 parameter 를 지정해주면서 만든다.
        // 이것을 pointer array 에 지정해 준다.
    }

    parr[0]->ShowPersonInfo(); // pointer array 의 address 를 기준으로 작업
    parr[1]->ShowPersonInfo();
    parr[2]->ShowPersonInfo();

    delete parr[0]; // class 를 하나씩 지워준다.
    delete parr[1];
    delete parr[2];
    return 0;
}

/* functions */
Person::Person(char *myname, int myage) 
{
    int len = strlen(myname) + 1;
    name = new char[len]; 
    strcpy(name, myname); 
    age = myage;
}

Person::Person()
{
    name = NULL;
    age = 0;
    std::cout << "called Person()" << std::endl;   
}

void Person::SetPersonInfo(char *myname, int myage)
{
    name = myname; // myname 은 main 에서 dynamic memory 에 이미 allocation 된 상태이므로 pointer 만 copy 해주면 된다.
    age = myage;
}

void Person::ShowPersonInfo() const
{
    std::cout << "name: " << name << ", ";
    std::cout << "age: " << age << std::endl;
}


Person::~Person()
{
    delete []name; // main 에서 dynamic allocation 해 준 memory 를 반환한다.
    std::cout << "called destructor!" << std::endl;   
}