/*
객체간에 message 를 주고 받으며 communication 하는 사례이다. (과일 파는 사람과 사는 사람의 관계로)
- 이것을 절차지향적으로 작성을 할수도 있을것이다. Seller 와 Buyer 가 1:1 인 경우는 '절차지향'과 '객체지향' 에 큰 차이가 없을 것이다.
- 그러나 Seller 와 Buyer 가 여러명인 경우에 절차지향 방법은 개체간의 목잡한 관계를 표현하기 매우 어려울 것이다.
- 객체지향 방법은 여러명인 경우는 물론 인원이 추가되어도 큰 변화가 없다.
- 이 문제의 경우는 '객체지향' 방식이 유리한 사례일 것이다.
*/

/* header */
#include <iostream>

class FruitSeller
{
private: // seller 의 특성을 정의: 사과 가격을 정하고, 판매할 사과를 가지고 있고, 금액 잔고를 가진다.
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;
public:  // seller 가 하는 행동을 정의: 특성 숫자를 정하고, 사과를 팔고, 판매 결과를 보임
    void InitMembers(int price, int num, int money);
    int  SaleApples(int money);
    void ShowSalesResult();
};

class FruitBuyer
{
private: // buyer 의 특성을 정의: 판매할 사과를 가지고 있고, 금액 잔고를 가진다.
    int numOfApples;
    int myMoney;    
public:  // buyer 가 하는 행동을 정의: 특성 숫자를 정하고, 사과를 사고, 산 결과를 보임.
    void InitMembers(int money);
    void BuyApples(FruitSeller &seller, int money);
    // 이 부분이 다른 객체와 대화 하는 부분이다. Message Passing 이라고 부른다.
    // 누구에게서 얼마짜리를 구매하는지 정보는 seller 에게서 받아야 한다.
    // 이때문에 함수를 parameter 로 받았다.
    // 'Fruit Buyer 라는 객체가 Fruit Seller 라는 객체에게서 구매를 하는 행위가 묘사된 code 이다.
    void ShowBuyResult();     
};

/* driver */
int main()
{
    FruitSeller *seller_ptr = new FruitSeller(); // heap memory 에 생성
    FruitSeller& seller = *seller_ptr; // 사용 편리성을 위해 reference 적용
    seller.InitMembers(1000, 20, 0); // 객체 초기화

    FruitBuyer *buyer_ptr = new FruitBuyer(); // heap memory 에 생성
    FruitBuyer& buyer = *buyer_ptr; // 사용 편리성을 위해 reference 적용
    buyer.InitMembers(5000); // 객체 초기화

    buyer.BuyApples(seller, 2000); // 누구에게서 얼마짜리를 구매하는가?

    std::cout << "Fruit Seller Status" << std::endl;
    seller.ShowSalesResult();
    std::cout << "Fruit Buyer Status" << std::endl;
    buyer.ShowBuyResult();

    delete seller_ptr; // heap memory 에서 삭제
    delete buyer_ptr; // heap memory 에서 삭제
    return 0;
}

/* function body */
void FruitSeller::InitMembers(int price, int num, int money)
{
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}

int FruitSeller::SaleApples(int money)
{
    int num = money/APPLE_PRICE;
    numOfApples -= num;
    myMoney += money;
    return num;
}

void FruitSeller::ShowSalesResult()
{
    std::cout << "Apple Stock: " << numOfApples << std::endl;
    std::cout << "Sales Revenue: " << myMoney << std::endl << std::endl;
}

void FruitBuyer::InitMembers(int money)
{
    myMoney = money;
    numOfApples = 0;
}

void FruitBuyer::BuyApples(FruitSeller &seller, int money)
// 이 부분이 다른 객체와 대화 하는 부분이다. Message Passing 이라고 부른다.
// 누구에게서 얼마짜리를 구매하는지 정보는 seller 에게서 받아야 한다.
// 이때문에 함수를 parameter 로 받았다.
// 'Fruit Buyer 라는 객체가 Fruit Seller 라는 객체에게서 구매를 하는 행위가 묘사된 code 이다.
{
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
}

void FruitBuyer::ShowBuyResult()
{
    std::cout << "Current Money: " << myMoney << std::endl;
    std::cout << "Apple Stock: " << numOfApples << std::endl << std::endl;
}    