﻿// wrote_240926.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
   
}

//상속
 
class Parent  
{

};

class child : public Parent  // 접근지정자 생략하면 마찬가지로 private
{

};

//접근이 고민되면 일단 private 으로. 먼저 결정할 필요 없다.But 변수는 대부분 public.
// 
// 로직 클래스 -> 행동 함수들
// 

//클래스를 그냥 입력하면 크기가 너무 커서 에러난다.
// 따라서 레퍼런스를 쓰는게 좋다. (포인터는 -> 이렇게 써야 하니까 귀찮)
//

//컴포넌트 방식?
//다이아몬드 상속 하지마!
//

// Has A Is A

//
// 디버깅?
//출력창 보고 경고 확인. 경고를 무시해선 안 됨. 없애려고 해야지.

//방어 코드!
// 
// Assert?
// window가 제공하는 프로그램 파괴 방법. 사태 발생시 인지할 수 있게 만든다.

#include <assert.h>
assert();   //(false)일 시 터진다.
//'중단' 누르면 문제 발생 지점을 알 수가 없음. 절대 누르지 마라.
//'다시 시도'를 눌러야 정지시켜서 확인할 수가 있다. 습관을 들이자!
//근데 이것만으로는 부족하니까

OutputDebugStringA();
// ()안의 내용이 에러시 출력창에 나타난다.

MessageBoxA(); //이걸 주로 사용할 것이다.
//확인을 눌러야 다음으로 진행한다. 그리고 터지게 만들자.
//nullptr?


//
// typedef와 using은 의미가 같은 문법이지만
// 수업에서는 typedef를 주로 쓸 것이다...
// 

//const char* == LPCSTR
//const char* == PCSTR
//같다고 함...뭐지;;;;;

#define AAA int // define AAA 스페이스 뒤로 전부 복붙. 마침(;) 표시를 할 필요 없다. 게다가 ;쓰면 에러나기 쉬워짐.
//#은 전처리문을 의미한다. #define은 복붙이다. 아주 긴 문장을 축약하고 싶을때 쓴다.
// \(백슬래시)를 치면 여러줄의 문장도 복붙 가능하다.
// 근데 가독성이 떨어져. F12로 확인하자.

//매크로 함수
//
#define MUL (VALUE) // VALUE*VALUE
//

//class 
// 멤버변수와 멤버함수는 필수가 아니다.
// TextRPG002inheritance.cpp를 확인해보자.
// 

//
//