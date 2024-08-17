#include <iostream>
#include <typeinfo>

void addressHandlingPointer()
/* virtual memory map 에서 address 를 handling 하는 방법 기초 */
{
  // '*변수명' 으로 선언한 variable 은 virtual memory map 의 address 중 하나를 저장할 수 있다. 'int' 로 선언하면 정수중 하나를 저장할 수 있는것과 같다.
  // 저장된 것이 address 이다보니, virtual memory map 중 어딘가를 가르키게 (pointing) 된다. 이때문에 pointer 라고 부른다.
  // 이 변수를 선언시 addess data 라는것에 추가하면, pointing 하는 곳에 저장되어 있는 data 를 어떻게 해석해야 하는지를 알려준다. 또한 pointer 연산에도 필요하다.

  // void 는 저장된 data 가 특정 data-type 이 아닌 1-byte 란 의미이다.
  void *ptr_v;
  std::cout << "Value at ptr_v = " << ptr_v << "\n";
  ptr_v++; // ptr_v 에 있는 address 를 증가시키면 1 이 증가한다. 1-byte 이기 때문이다.
  std::cout << "Value at ptr_v = " << ptr_v << "\n";
  ptr_v--; // 증가된 것을 다시 원복시키고

  // int pointer 'ptr_i' 를 만들고 같은 pointer data 인 ptr_v 의 값으로 초기화 해준다.
  // 양쪽의 type 을 맞추기 위해서 (int *) 가 필요하다. (안하면 error 발생) 
  int* ptr_i = (int *)ptr_v;
  std::cout << "Value at ptr_i = " << ptr_i << "\n";
  ptr_i++; // ptr_v 에 있는 address 를 증가시키면 4가 증가한다. int 가 4-byte 이기 때문이다.
  std::cout << "Value at ptr_i = " << ptr_i << "\n";

  // 'pointer' 의 개념을 '가르키는 곳이 어딘가있는 data' 라고 하면 틀리지 않는다. 그러나 '내가 원하는 data 를 계속 pointing 하고 있는것' 이라고 생각하면 틀리게 된다. 왜냐하면 위에 볼 수 있듯 변수에 들어있는 address 를 마음대로 바꿀 수 있기 때문이다. Program 실행 중 내용이 바뀌면 더이상 pointing 을 제대로 하고 있지 않게된다.

  // 이런 이유로 pointer 보다는 address handling 의 개념으로 이해하는 것이 좋다.

  // ※ pointer 를 이해할때는 괄호를 쳐서 생각하면 쉽다.

  // int (*ptr) : (ptr) 에 저장된 것이 (*ptr) address data 인데, 그 address 에 저장된 data 는 int 이다.
  // int **ptr : (ptr) 에 저장된 것이 (*ptr) address data 인데, 그 address 에 저장된 data 는 *(*ptr) 또다른 address data 이다. (**ptr) address 에 저장된 data 는 최종적으로 int 이다.
}

void addressHandlingReference()
{
  // pointer 는 pointing 을 안할수도 있다.
  int a = 10;
  int *a_ptr = &a;
  std::cout << "a_ptr is " << a_ptr << " pointing -> " << &a << "\n";
  a_ptr = NULL;
  std::cout << "a_ptr is " << a_ptr << " pointing -> " << &a << "\n";
  // program 수행중 a_ptr 의 내용이 바뀌면 더이상 int a 를 pointing 하지 않는다.

  // reference 는 처음부터 int a 만을 pointing 하고 절대 바뀌지 않는다.
  // reference 는 a 그 자체이다(분신술?). Address 도 같고, 내용도 같이 바뀐다.
  int & a_ref = a;
  std::cout << "a_ref is " << &a_ref << " pointing -> " << &a << "\n";
  std::cout << "a_ref is " << a_ref << ", while a is " << a << "\n";
  a_ref = a + 3;
  std::cout << "a_ref is " << a_ref << ", while a is " << a << "\n";
  // Program 중에 a의 분신을 적용할 필요가 있을때 사용할 수 있다.
}

// 함수 세가지를 가지고 이해를 해보면
// Pass-by-Value
int square_val (int n)
{
  // main 에서 n값을 주었지만, function 은 이를 복사해서 stack memory 에 넣고 작업한다.
  // 따라서 n 의 address 가 바뀌었다.
  std::cout << "address of n in square_val(): " << &n << "\n";
  n *= n;
  return n; // function은 종료전 약속된 장소 (register) 에 실행 결과값만 남기고, stack 을 지워버린다.
}

// Pass-by-Reference with Pointer Arguments
void square_ptr (int* n)
{
  // main 에서 n의 주소를 주었기에, function 은 그 주소의 data 에 작업을 한다.
  // 따라서 n 의 address 가 안바뀌었다.
  std::cout << "address of n in square_ptr(): " << n << "\n";
  *n *= *n;
  // data 에 직접 작업을 했기에 return 할게 없다
}

// Pass-by-Reference with Reference Arguments
void square_ref (int& n) // parameter 받는 부분에서 reference 를 만든다.
{
  // main 에서 n을 받으며, 그것의 분신을 만들어 작업을 한다. Function 은 원래 data 에 직접 작업을 한것이다.
  // 따라서 n 의 address 가 안바뀌었다.
  std::cout << "address of n in square_ref(): " << &n << "\n";
  n *= n;
  // data 에 직접 작업을 했기에 return 할게 없다
}

int main() 
/* driver program */
{ 
  addressHandlingPointer(); 
  std::cout << "\n";
  addressHandlingReference(); 
  std::cout << "\n";

  // value 로 함수를 call 하면 함수는 별개로 동작함을 알 수 있다.
  int nv = 8;
  std::cout << "before square_val(): value -> " << nv << " address -> " << &nv << "\n";
  square_val (nv); // value 를 넘겨준다
  std::cout << "after square_val(): value -> " << nv << " address -> " << &nv << "\n";
  std::cout << "\n";

  // pointer 로 함수를 call 하면 함수는 직접 작업을 함을 알 수 있다.
  int np = 8;
  std::cout << "before square_ptr(): value -> " << np << " address -> " << &np << "\n";
  square_ptr (&np); // address 를 넘겨준다
  std::cout << "after square_ptr(): value -> " << np << " address -> " << &np << "\n";
  std::cout << "\n";

  // reference 로 함수를 call 하면 함수는 직접 작업을 함을 알 수 있다.
  int nr = 8;
  std::cout << "before square_ref(): value -> " << nr << " address -> " << &nr << "\n";
  square_ref (nr); // value 를 넘겨준다
  std::cout << "after square_ptr(): value -> " << nr << " address -> " << &nr << "\n";

  return 0;
}