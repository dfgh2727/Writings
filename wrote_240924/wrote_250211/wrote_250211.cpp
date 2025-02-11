﻿// wrote_250211.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 111_Hash (with unordered map)
// 
// unordered map:
// 해쉬를 키로 사용하는 배열형 혹은 복합형(노드 + 배열) 자료구조다.
// 어떤 메모리 영역의 값을 정수로 만드는 것을 해쉬로 본다.
// void* int size로 이루어진 특정 메모리 영역을 정수로 만든다.
// hash는 복호화가 안 된다.
// 
// hash함수의 효율이 곧 unordered map의 효율이다.
// 
// 원소의 수가 200개 이하면 map과 unordered map은 속도면에서 큰 차이가 없다.
// 오히려 100개 이하면 map이 더 빠르다.

// 자기가 만든 클래스를 map의 키로 사용하고 싶다면
// : map 내부에서 Left의 키와 Right의 키의 값을 비교한다.
//   따라서 만들어낸 class에 operator >, < 가 필요하다.
//   또는 해쉬함수가 들어있는 구조체를 만들면 된다.
//   RTTI 


// 해쉬 함수의 주의점
// : 만약 다른 string인데 해쉬 값이 같다면?
	std::string Text0 = "AAA"; // = 5
	std::string Text1 = "BBB"; // = 5
// 
//  1) 체이닝을 이용해서 해결한다.
// 
// 	2) 해쉬를 통한 자료구조를 만들 때 배열의 크기에 맞는 키가 나온다.
//     이와 같은 방식은 배열의 전제 크기가 늘어나면 재설정이 필요하다.
// 	   그다지 좋은 방법이 아니다.
//   
// DB 프로그램이 해쉬 분야의 끝판왕이다.

// 112_TemplateVar
// 
void VarFunction(int Value, ...)
{

}
// 가변인자의 단점?
// 인자의 갯수를 찾을 수 없다.
// 
// 템플릿 가변인자는 가변인자의 불확실성을 제거한 것이다.
// 자료형을 체크해준다. 
// 그러나 컴파일 시간이 늘어난다는 단점이 있다.
template<typename ...Arg>
void TemVarFunction(Arg ... _Arg)
{

}
// 템플릿은 '함수를 만드는' 함수다.
// template 자체의 의미는 없고 override 하듯이 함수가 만들어진다.
// Arg도 마찬가지다.
// 
// 템플릿 가변인자는 2가지 방식으로 사용할 수 있다.
// 1. 인자를 그대로 전달한다.
//    이 경우 인자를 확장시킨다고 한다. (그대로 집어넣음)
//    서버에서 지양하는 방법이다. 컴파일 시간이 너무 오래 걸리기 때문이다.
      template<typename ...Arg>
      void TemVarFunction(Arg ... _Arg)
      {
      	
      	   NewTestFunc(_Arg...);
      }
//    TempVarFunction(10, 20);
//    이 경우 NewTestFunc(10, 20)이 된다.
// 
// functional에서 bind를 살펴보면 R-Value Ref로 템플릿 가변인자가 있음을 확인할 수 있다.
// 
//
