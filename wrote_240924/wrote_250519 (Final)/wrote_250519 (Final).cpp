// wrote_250519 (Final).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 총정리.xlsx
// (일부분만 필기함. 자세한 내용은 원문을 참고하자.)

// 템플릿 특수화
//
// 특정 인자에 대해서만 작동 방식이 다르길 원할 때
// 
// template<typename T>
// void Test(T Value)
// {
// }
// 
// template<>
// void Test(int Value)
// {
// }
// ->int의 경우 작동하는 방식
// 

// friend
// 
// 함수도 friend가 가능하다.

// 언리얼에서 GC(Garbage Collector) 사용하는 방법 ( = 메모리 개념 응용)
// 
// 사용하지 않는 메모리를 찾아내어 delete 해주는 엔진 객체.
// 최신 엔진들이 제공한다.

// 가상함수 테이블
// 
// 함수포인터의 2차원 배열을 클래스 자신이 가지게 된다.
// 일반적인 함수는 클래스 크기에 영향을 미치지 않지만 
// virtual을 붙이는 순간 8바이트가 된다.
// 
// class TestClass
// {
//		virtual void Test();  -> 8바이트
// }
// 
// 내부에 void** 개념으로 함수 포인터를 모아놓는 2차원 배열. (vfptr = virtual function ptr)
// 자식 생성자가 호출될 때 이 함수포인터의 배열을 바꾼다.

// 수업에서는 std::queue와 std::stack을 다루지 않았다.
// 사용하는 데이터 수가 적어서 std::list로 대체 가능했기 때문이다.
// queue와 stack을 직접 사용해보길 바람

// 플랫폼
// 
// 프로그래밍에서 플랫폼이란 OS를 의미한다.
// 
//