/*

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
    void ShowStudentInfo();
};

/* driver */
int main()
{
    Student *student_1_ptr = new Student(2137, "ihPark", 900); 
    Student& student_1 = *student_1_ptr;
    Student student_2 = student_1;

    std::cout << student_1_ptr << std::endl;
    std::cout << &student_1 << std::endl;
    std::cout << &student_2 << std::endl;

    student_1.ShowStudentInfo();
    student_2.ShowStudentInfo();

    delete &student_1;
//    delete &student_2;
    student_1.ShowStudentInfo();
    student_2.ShowStudentInfo();
    return 0;
}

/* function body */
Student::Student(int _num, char *_name, int _score) : num(_num), name(_name), score(_score)
{
    std::cout << "object created ..." << std::endl;
}

void Student::ShowStudentInfo()
{
    std::cout << num << std::endl;
    std::cout << name << std::endl;
    std::cout << score << std::endl;
}
