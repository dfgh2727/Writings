// wrote_240927.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>

//operating
//
// operator =()
// 연산자를 대체하는 새로운 함수를 만든다.
// 수학적인 클래스에서 주로 사용.
//

class MyInt
{
public:
    MyInt& operator =(const int& _Other)
    {
        Value = _Other;

        return *this; //여기서 *this는 정확하게? MyInt* const 다.
    }
    //...MyInt로 썼다면 이 MyInt로 들어가는게 아니고 새로운 MyInt 메모리 영역에 값이 들어간다.


    MyInt(int Value)
    {
    }

protected:
private:

};

class InPtr
{
public:
protected:
private:

};

//함수 객체
//객체를 함수처럼 사용
//

//생성자
//일종의 제약이다?
//
// MyInt[10] = { 1,  }; // 랜덤으로 호출. 만약 생성자 없다면 에러난다. 
// MyInt(), MyInt(), MyInt(),...

int main()
{
    int NewValue = int(0);
    int TestValue = int(20);

    // const int = 33
    (NewValue = TestValue = NewValue = 10) = 33;

     //MyInt NewMyInt = MyInt(0);
    MyInt NewMyInt = 0; //int를 받는 생성자가 없으면 바로 에러남.
     NewMyInt.operator=(10) = 20;

    // NewMyInt[10];
}

//cout
//std::cout << "Hello World!";
//std는 네임스페이스.
//"Hello World!" 는 cosnt char*
//cout은 전역객체 즉, 데이터영역에 존재하는 전역변수
// << 는 operator << 이다. (연산자 겹지정)
//
// 
// namespace
// 같은 이름의 클래스 선언 안 된다. 
// 근데 쓰고 싶다? 별명을 붙여주자. namespace!
// 팀작업에서 좀 쓴다.
using namespace std::
//std:: 생략한다는 의미. 선생님은 싫어한다.


//전역 operator (global operator)
MyInt NewInt; 
NewInt - 10; 
10 - NewInt; // 안된다? 만들자!
int operator-(const int Value, MyInt _NewInt)
// 좌항에서 우항을 빼는 operator (좌항과 우항의 관계)
// 보통 내가 만든 사용자 정의 자료형을 우항으로 둘때 
// 
//

//class의 크기? 1바이트. 가상 변수를 넣어서 1바이트로 만들었다. 0바이트면 문제가 생긴다.
//가령 포인터 문법에서 int* Ptr; Ptr + 1; 0이면 어떻게 움직여?

//중간에 왠만하면 프로젝트 이름을 바꾸지 말자.

//문법을 안다는건 코드 안에서 무언가를 집어서 물어볼때 대답할 수 있어야 한다


//*******************************************************
//API 최종 결정은 10월 11일까지
//UI가 힘들다...화면(시스템)을 새로 짜야한다는 것
// 
// ******************************************************


//파일 나누기
// 특정부분들을 각 파일별로 나누어 놓는 작업
// (사실 컴 입장에서 불필요하다. 오히려 합쳐야 하기 때문에 빌드가 느려진다. 근데 사람이 봐야하니까...)
// 
// 필터? 리소스, 소스, 헤더파일
// 선생님은 .cpp를 파일 밖으로 빼낸다.(ppt 참고)
//


//선언과 구현을 명확하게 구분할 수 있어야 한다.

void Test(); // 선언

void Test()  // 선언과 구현이 동시에 된 경우
{

}

int a = 0;  // 선언과 구현

//왜 선언과 구현을 구분할까?
void Test0();
void Test0()
{
    Test1(); //이렇게 사용 불가능, 그러나...

}

void Test1();
void Test1()
{

}
//선언과 구현을 분리해하면 함수의 순서는 중요하지 않다.
// 
// 선언은 .h, 구현은 .cpp
// 선언과 구현을 합치면 문제가 많이 생긴다.
//
// #pragma once
// 한 파일 내에서 헤더 중복 제거
// 안 쓰면 같은 이름으로 중복선언되서 에러(재정의 에러)가 발생한다던가...문제가 생긴다. 

class Player  //클래스 '선언'
{

};

int a = 0;  //선언과 구현. 진짜 int a가 존재한다. 

extern int a; //가상의 a가 존재할거야-라고 선언.
              //실체가 존재하는게 아니다. 따라서 대입이 안 된다.

void Test3();
void Test3();
void Test3(); //선언은 중복되도 아무 상관 없다. 선언만 하면 컴파일러가 무시한다.

int main()
{
    Test3();  //선언만 하고 구현을 안 한 경우, main에 쓰면 외부기호 오류가 난다. 
}

//실체 즉, 구현을 .h파일에 해선 안 된다! 재정의 에러 발생한다.
//선언은 아무데나 뿌려놔도 뭐...
// 
// 클래스 선언은 나뉘어진 파일에서 중복은 문제가 안 된다.
//