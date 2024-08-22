/*
class array 를 선언하면 한번에 여러개가 생기기 때문에 constructor function 에 parameter 를 줄 수 없는 문제가 생긴다.
- 'Person()' 와 같이 parameter 가 없는 constructor 를 만들어 둔다.
- class 가 만들어진 후에 'void SetPersonInfo(char *myname, int myage)' 와 같은 함수를 사용하여 값을 하나하나 setting 해 주어야 한다.
- 그 다음에 data 를 가지고 작업을 한다.

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
    Person *parr = new Person[3]; // array 는 자체가 pointer 이므로 이렇게만 해주면 된다. 시작 address 가 생긴다.
    char namestr[100];
    char *strptr;
    int age;
    int len;

    for(int i=0; i<3; i++)
    {
        std::cout << "name: ";
        std::cin >> namestr;
        std::cout << "age: ";
        std::cin >> age;
        len = strlen(namestr) + 1;
        strptr = new char[len];  // memory 를 allocation 하고
        strcpy(strptr, namestr); // 여기에 namestr 을 copy 한 후에
        parr[i].SetPersonInfo(strptr, age); // 함수에 넘겨준다
        //delete strptr; // 함수에 넘겨주었기에, 여기서 memory 를 지우면 안된다.
    }

    parr[0].ShowPersonInfo();
    parr[1].ShowPersonInfo();
    parr[2].ShowPersonInfo();

    delete[] parr; // 시작 address 를 지워주면 된다.
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