/*
명함관리는 주소록, 단어장 등에 적용가능한 Pattern 이다.
 - enumeration 의 사용법 (class 는 아니고 namespace 만 정의)
 - NameCard 의 data structure 와 method
*/

#include <iostream>
#include <cstring>

/* headers */
namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPositionInfo(int pos);
}

class NameCard
{
private:
    char *name;
    char *company;
    char *phone;
    int position;
public:
    NameCard(char *_name, char *_company, char *_phone, int pos);
    void ShowNameCardInfo();
    ~NameCard();
};

/* driver */
int main()
{
    NameCard *manClerk_ptr = new NameCard("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK); 
    NameCard& manClerk = *manClerk_ptr;
    NameCard *manSENIOR_ptr = new NameCard("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR); 
    NameCard& manSENIOR = *manSENIOR_ptr;
    NameCard *manAssist_ptr = new NameCard("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST); 
    NameCard& manAssist = *manAssist_ptr;

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();

    delete manClerk_ptr;
    delete manSENIOR_ptr;
    delete manAssist_ptr;
    return 0;
}

/* functions */
void COMP_POS::ShowPositionInfo(int pos)
{
    switch(pos)
    {
    case CLERK:
        std::cout << "clerk" << std::endl;
        break;
    case SENIOR:
        std::cout << "senior" << std::endl;
        break;
    case ASSIST:
        std::cout << "assist" << std::endl;
        break;
    case MANAGER:
        std::cout << "manager" << std::endl;
        break;
    }
}

NameCard::NameCard(char *_name, char *_company, char *_phone, int pos)
        : position(pos)
{
    name = new char[strlen(_name)+1];
    company = new char[strlen(_company)+1];
    phone = new char[strlen(_phone)+1];
    strcpy(name, _name);
    strcpy(company, _company);
    strcpy(phone, _phone);
}

void NameCard::ShowNameCardInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Company: " << company << std::endl;
    std::cout << "Phone: " << phone << std::endl;
    std::cout << "Rank: "; COMP_POS::ShowPositionInfo(position);
    std::cout <<std::endl;
}

NameCard::~NameCard()
{
    delete []name;
    delete []company;
    delete []phone;
}