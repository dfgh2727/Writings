﻿// wrote_241008.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 060_OperatorEx2
// 
class MyInt
{

};

int main()
{
	MyInt MyInValue = 0;
}
// 레퍼런스를 리턴한다? 분명한 메모리 영역이 존재하게 된다. 즉 LValue가 될 수 있다.
// ++NewInt 와 NewInt++ 를 비교해보자.
// 후자는 LValue가 될 수 없다. 전치와 후치는 다르다.
// 
// Result = NewInt++;
// ++연산 전의 값이 Result에 리턴된다.
// 후치의 모양은 다음과 같이 생겼다.
// int operator++(int _Value) {} //int 를 리턴한다. 
// (속력은 전치가 빠르지만...최적화에 별 의미 없으니 신경 ㄴㄴ)
// volatile, 컴파일어 임의대로 최적화 하는 것을 막는다.
// 
// 코드영역, 스택영역
// 


//061_Debug
// 디버그 모드는 최적화가 되지 않은 코드를 살펴보는 것.
// 릴리즈는 쓸데없는 코드를 삭제한다. 눈에 보이는 코드 그대로가 아니기에 중단점이 의미가 없다.
// 
// 릴리즈 해볼때는 작업하고 있는 파일이 아니라 새로 받아서 해봐야한다.
//  
// 포폴의 설정들은 남들에게 설명할 수 있어야 한다.


//062_
// x86 빌드하면 포인터가 4바이트. 그 정도만 기억하자. 
 
//**************** MSDN에 필기를 기록해놓자! **********************

//063_Static
// 
// 헤더에 전역변수 선언시 cpp마다 하나씩 생겨서(#include) 에러가 나겠지만
// static을 붙이면 이름이 변경되서 사용 가능하다. (가령 Player.cpp에선 'Player.cpp::전역변수'로 이름이 바뀐다.)
// (cpp마다 이름이 달라진다는 의미다.)
// 근데 전역변수를 쓰는 이유? 다시 선언하지 말라고 쓰는건데... static을 쓰면 의미가 없다;;
// 그럼 extern을 쓰자! (근데 잘 안 쓰는 문법이다. 그냥 의미를 알자.)
// (static을 쓴 경우와 extern 을 쓴 경우 주소를 비교해 보면
//  static은 변수마다 다 다르지만 extern은 주소가 같다.)
//
// static, extern 보다는 클래스의 멤버변수를 쓰자.
// 전역변수를 사방팔방 다 쓰지 말고 클래스를 만들어서 쓰는걸 권한다.
// 
// 변수가 어디에 있는게 좋을까...는 스스로 생각해서 쓰자.
// 가령 몬스터 수를 세는 경우는 몬스터가 생성될 때 마다 불러쓰는 생성자에 쓴다던가.
// 근데 변수가 그대로 노출되면(public) 위험하니까 멤버함수 static을 사용한다.
// 
// static 함수는 객체없이 사용할 수 있다. 
// 클래스가 아니면 this가 없다? 멤버함수라도 this 없다?
// 
 

//064_FunctionCall (함수호출규약)
// 
// __cdecl?
// main에서 함수가 호출된 수 정리될 때.
// 전역함수들은 대부분 cdecl이 붙는다.
// (일반적으로 명시하는 경우는 거의 없다. 자세하게 알 필요 없다. 어셈블리어에 가깝다.)
// 
// class멤버함수들은 thiscall이 자동으로 붙는다.

class Test
{
public:
	void __thiscall Function()
	{

	}
};

//함수포인터를 넣을 때 명시하는 경우가 있긴 하다. 만약 본다면 맞춰줘라.


//065_Enum
// 
// 정수형 상수를 정의하는 문법
// (사용자 정의 자료형: class, struct, enum, union)
// 
// 매칭방식...
// 문자열은 에러나기 쉬워서 안 쓴다. 그리고 int 가 비교하는데 훨씬 빠르다.

// enum
// 
enum Jobtype 
{
	//아무것도 입력하지 않으면 자동으로 첫번재 이름에 0이 붙는다.
	Fighter, // = 0
	Mage = 'a' //어쨌든 정수에 불과하니까

};
// 
// 사용자 정의 자료형을 생략할 수 있지만 정체를 알 수 없으니 권장 ㄴㄴ 
// 
// !!!형변환 하지마라. 할거면 명시적으로 !!!
//

//enum class (최신 문법)
// 이름을 제대로 명시해야 한다.
// enum보다 되도로 이걸 쓰자.

enum class TestEnumClass
{ 
	Value0,
	Value1,
	Value2,
	Value3
  
};
//enum과 enumclass는 명시하지 않으면 기본적으로 4바이트다.
// enum class JobTypeClass : __int8 (명시 방법)


// 참고로 enum 안에 함수 못 넣는다.
// 함수 안에 enum 선언할 수 있지만 이렇게 안 쓸거다. (쌤 방식이 아니다.)
// 클래스 안에 클래스 쓸 수 있다. 
// enum은 헤더나 cpp 어디에도 가능
// static을 extern 같이 생각하라
//클래스 안에서 멤버변수에 static 못 붙이지만 static const는 된다.

// ********* 용어 설명 추가됨 ************

//
// 
//








