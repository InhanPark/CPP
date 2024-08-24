/*
object 로 만들어진 class 의 address 주소를 갖고있는 것이 'this' 이다. 
- dynamic allocation 을 하면 이미 그 class 의 address 를 알수는 있다.
- 그러나 test 를 해보면 dynamic allocation 의 address 와 this 의 address 는 다르다. 그렇지만 실행결과는 다르다. 아마도 alias 처럼 동작하는것 같다.
- class 의 함수를 call 하는 방법이 중요함 (class name 과 pointer)
*/

#include <iostream>
#include <cstring>

/* header */
class Student
{
private:
    int   num;
    char *name;
    int   score;
public:
    Student(int _num, char *_name, int score);
    Student *GetThisPointer();
    void ShowStudentInfo();
};

/* driver */
int main()
{
    Student *obj_ptr = new Student(2137, "ihPark", 900); 
    Student& obj = *obj_ptr;
    Student *this_ptr = obj.GetThisPointer();

    std::cout << obj_ptr << std::endl;
    std::cout << this_ptr << std::endl;

    // 세가지 방법으로 함수 call 한 결과, 모두 같은 결과를 나타낸다.
    obj.ShowStudentInfo();
    obj_ptr -> ShowStudentInfo();
    this_ptr -> ShowStudentInfo();

    delete &obj;
    // delete this_ptr; // 이것은 동작을 하지 않음
    return 0;
}

/* function body */
Student::Student(int _num, char *_name, int _score) : num(_num), name(_name), score(_score)
{
    std::cout << "object created ..." << std::endl;
}

Student *Student::GetThisPointer()
{
    return this;
}

void Student::ShowStudentInfo()
{
    std::cout << num << std::endl;
    std::cout << name << std::endl;
    std::cout << score << std::endl;
}
