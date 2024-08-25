/*
Class 를 복사하여 새로운 class 를 만들 수 있다. 실제로는 별도로 초기화를 해서 만드는 것 대비 장점이 없으므로 사용하지 않지만, class 를 함수에 parameter 로 전달할때나 함수가 class 를 return 할때 임시로 사용하기 위하여 사용된다. (함수는 stack 에 있다가 지워지므로, return 하는 내용은 memory 의 다른 부분에 임시로 있어야 한다.)
- 이러한 복사를 할 경우 필요한 것이 copy constructor 이다. 이것은 보통 compiler 가 자동으로 만들어 준다.
- 하지만 자동으로 만들어 주는 것은 shallow-copy, 즉 내부 data 의 pointer 만을 copy 하기 때문에 경우에 따라서는 문제가 된다.
- 이런경우 user 가 pointer 만이 아니라, pointer 가 가리키는 내용까지 deep-copy 를 하도록 copy constructor 를 따로 만들어 주어야 한다.
- 아래 예처럼 delete 할때 copy 된 class 들은 문제가 된다 (아직 해결 못함)
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
    Student(int _num, char *_name, int score); // original constructor
    Student(Student &copy);  // copy constructor
    ~Student();  // destructor
    void ShowStudentInfo();
    void MemberChange(int _num, char *_name, int _score);
};

/* driver */
int main()
{
    Student *student_1_ptr = new Student(2137, "ihPark", 900); 
    Student& student_1 = *student_1_ptr;
    Student student_2 = student_1;
    Student student_3(student_1);

    std::cout << student_1_ptr << std::endl;
    std::cout << &student_1 << std::endl;
    std::cout << &student_2 << std::endl;
    std::cout << &student_3 << std::endl;
    std::cout << std::endl;

    student_1.ShowStudentInfo();
    student_2.ShowStudentInfo();
    student_3.ShowStudentInfo();
    std::cout << std::endl;
    student_2.MemberChange(3245, "mikeLee", 700);
    student_3.MemberChange(4335, "mickyMouse", 600);

    student_1.ShowStudentInfo();
    student_2.ShowStudentInfo();
    student_3.ShowStudentInfo();
    std::cout << std::endl;

    delete &student_3;
    delete &student_2; // debugger 로 실행 시키면 여기서 문제가 발생한다.
    delete &student_1;
    return 0;
}

/* function body */
Student::Student(int _num, char *_name, int _score) : num(_num), name(_name), score(_score)
{
    std::cout << "object Student is created ..." << std::endl;
}

Student::Student(Student &copy) : num(copy.num), name(copy.name), score(copy.score)
{
    std::cout << "object Student is copied ..." << std::endl;
    score = 0;
}

Student::~Student()
{
    std::cout << "object Student is destroyed ..." << std::endl;
}

void Student::MemberChange(int _num, char *_name, int _score)
{
    num = _num;
    name = _name;
    score = _score;
}

void Student::ShowStudentInfo()
{
    std::cout << num << " " << name << " " << score << std::endl;
}
