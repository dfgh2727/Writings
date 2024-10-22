﻿// wrote_241022.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//Get Message는 사용하지 않는게 좋다.
//window에 메시지가 발생할 때 까지 기다린다.
// 
// *********shooting게임dml Console Engine을 다시 보면************ 
// 엔진을 보면 Tick-Render-Tick-Render-...를 반복하는 구조
// 근데 움직임이 없어서 Tick에 중단점이 걸리면 Render되지 않음.
// 
// kbhit를 사용한 이유..입력유무 구분을 위해서.
// getch 입력버퍼를 비워준다 but 입력버퍼가 없으면 무한대기
// ****************************************************************
// 
// BOOL
// typedef
// (C에는 bool이 없다. 근데 코드는 C 스타일...
//  C에서도 bool처럼 쓸 수 있게끔 만든것)
// 
// 함수포인터로 윈도우에 전달
//

//stdString
// 
// 다른거 제쳐두고 basic string만 본다면 (나머지는 Map의 less 같은것 추후에)
// 
// (배열...불편하다. 대입도 안 되고, 크기도 한정적.)
// 
// std::string Text;
// 형태는 std vector와 거의 비슷하다 
// but 몇가지 함수를 더 만들어서 문자열 처리에 도움이 되게 만든 자료형
// 
char Test[10] = "AAAA";
if (Test == "AAAA")  // false
{                    //Test == char[]
                     //"AAAA" == const char*
                     // casting이 일어난다.(형변환)
                     // 둘이 주소값(8바이트 정수)이 달라서 false 
}
// string은 문자열 한 자씩 비교를 해준다. 
// Test == "AAAA"는 원래 성립할 수 없지만, operator== 지정해 놨다.
// (replace는 나중에)

void Test(const std::string Text) //이렇게 쓰면 안된다!
{                                 //레퍼런스로 써야 한다.(8바이트)
                                  

}
// 일단 크기가 몇인줄 알고;;
// std::string Text = "AAAA" new가 4번 일어난다.
// (std::vector = {0,1,2,3} push_back 4번...new 4번)
// 레퍼런스로 받으면 복사 생성자 호출, 
// string 값형을 그대로 받으면 new가 다시 발생 (대입연산자)
//


//Map에서 사용한 operator를 다시 생각해보자.
// 
// key를 비교해서 노드를 배치했지...
// Class도 >, ==를 사용해서 비교할 수 있나? 
// 직접 지정해야 가능하다. 
// 
// std::string은 내부에 비교하는 함수들이 있으니 비교 가능.
//

// 이후 API framework...

//옮기고 나서 질문하기

//필터랑 프로젝트명은 마음대로

//lib로 진행

//Bin에 빌드 결과물이 올라가도록

//선생님은 typedef 안 좋아한다. 잘 안 쓴다.
//금요일 필기시험, 계획서 및 이미지 검사

//와 오픈북 1시간 스무문제! 객관식!
//다음주 목요일 전까지 png이미지를 띄울것 
// 이번주 입력 다음주 이미지
//11월 29일 까지 개발 
//다음주 월요일(12/2) 발표
// 
//API 다렉 다렉팀 언리얼팀 (언리얼 개인)
// 
//엔진을 제대로 파악해야 한다. 클래스 멤버변수 함수 자료구조 등...

//가끔 어떤 프로그램은 종료가 안 되는 경우가 있다. 
//찾기 힘들수도 있다. 그럴땐 그냥 재부팅 하는게 낫다

//window.h
//
// 클래스 객체가 복사되면 부하가 커지고 위험하므로 참조로 쓴다.
// 그리고 쓸지 안 쓸지 모르니
// 복사생성자, 연산자 delete 미리 써 놓는다.
// 
// Visual Studio Template
// 클래스가 만들어지면 내가 원하는 함수들이나 정의가 존재하는 상태로 만들어지게 하는 기능
// 항목 템플릿 = 파일 만들기
// 
// ADefaultClass 만들기
// 표본 클래스를 하나 만든다.
// 메뉴 - 프로젝트 - 템플릿 내보내기 - 항목 템플릿 선택
// 압축파일이 생긴다. 압축을 풀면 사용 가능
// .h 템플릿과 .cpp 템플릿을 각각 만들고 압축을 풀어서 쓴다
// 한번에 한 파일씩 만들 수 있지만 합칠 수 있다.
// 
// 실수로 복사하는걸 막기 위해 delete를 입력해놓은 것
// 실수했다는걸 알거나 or delete를 제거하고 구현하거나
// 
 
// ctrl shift A - 새 항목 추가
//
// $변수$  $사이의 내용은 변수 취급한다.


//087_DoubleRef
// 
// 크기가 큰 클래스가 있다고 가정하자.
// 값형으로 클래스를 리턴한다면...
// 
// 파괴될 지역변수(객체)가 리턴된다. 그럼 메모리를 한번 더 만든다?
// 
// 생성된 메모리를 받고 이전 포인터는 null 처리,
// 즉 메모리가 두번 생성 되는걸 막는다.

// HACCEL hAccelTable ... 단축키 설정
//
//Alt F4 는 윈도우 외부 단축키라
//윈도우창에 단축키 설정을 안 해도 적용된다.
// 
// 기본 메시지 루프는 엔진윈도우에 넣는다.
//
 
