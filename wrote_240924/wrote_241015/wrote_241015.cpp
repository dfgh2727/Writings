﻿// wrote_241015.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>

int main()
{
    std::cout << "Hello World!\n";
}

//엔진에 대해서 계속 설명하자면
// ActorVector
// 
// Renderer포인터로 할까, 값형으로 가질까?
// 그려질수도 안 그려질수도있다...포인터로.
// 
// 언리얼...한번 만들어진 Renderer는 지울 수 없다.
// 
// 엔진과 컨텐츠는 분리하는게 엔진 재사용에 유리하다.


//몬스터가 플레이어를 가져다 쓰게 만들어라

//형이 다르면 포인터로 사용할 수 없다.
// 예) Player* PlayerPtr = &ActorVector BulletVector;
//클래스 내의 멤버 자체로는 외부에서 쓸 수 없다. 그러면 static으로 전역 변수로 만들면 된다. 
//static은 반드시 초기화 해야함
//클래스 자체로는 사용 불가능, 객체를 만들고 멤버를 사용할 수 있다.

//075_StaticEx
//
// static 함수는 객체 없이도 쓸 수 있다. 따라서 this가 없다.
// (일반 멤버함수는 인자로 반드시 this가 들어간다.)
// 


// 클래스...누가 누구를 알아야 할까?
// 생각하면서 구조를 짜야한다.
// 
//직접 만든 벡터가 아니라 std벡터를 쓴다
//관리가 어렵다.

//자료구조
// 
// 메모리적 분류 2가지 배열형, 노드형
// 형태적 분류 3가지 시퀀스, 연관, 어댑터
// 
// vector 배열형 시퀀스
//
// std::vector
// 언리얼에선 std::vector 안쓴다


//TemplateEx
//
// 템플릿 인자추론 작업:
// 템플릿이 자료형이 무엇인지 추론한다
// 
// main의 크기는 컴파일 단계에서 정해진다, 가령 아래와 같은 경우 크기를 정할 수 없어 에러가 난다.
// int Value;
// char Arr[Value];
// 명확하게 템플릿의 타입을 명확하게 지정해줘야 한다.
// 템플릿 클래스의 이름은 TClass<자료형>인데 만약 구현을 안 해놓을 경우
// 코드를 주객전도로 치게 되는 현상이 발생..
// 템플릿 클래스는 선언과 구현이 분리되기 어렵다. 처음부터 크기를 명시할 수 있어야 한다.
// 
// 템플릿 클래스는 컴파일러가 코드를 
// 그 예시로 헤더가 없어도 에러가 나지 않는다.

//(헤더... 값형? 포인터? 참조?
// 값형을 사용하려면 반드시 헤더 필요)
 
//다시 vector로 돌아와서,
// vector의 핵심은 공간과 데이터의 분리
// 공간의 크기가 커도 영향은 작다. 문제는 할당 자체(공간을 만드는 것)가 시간이 오래 걸린다.
// 그러니 여러번에 나눠서 하지 말고 한번에 최대치를 할당하는 것이 제일 빠르다.
// 그러나 정적 배열은 게임 개발에서 잘 안 쓴다. 더 빠르다고 할지라도...
// 
// 정적 배열이 들어갈 위치에 벡터를 사용한다.
// 
// push_back...여러번 선언하면 new와 delete를 반복하니 부담스럽다.
// 공간을 나타내는 capacity(), 배열의 크기
// 자료를 나타내는 size(), 
// 공간을 할당하고 다시는 할당하지 않는 것이 벡터를 사용하는 최고의 방법
// (애초에 삭제하는 기능을 쓰면 잘 못 사용한 수준)
//

std::vector<char> stdvector;
stdvector.reserve(10);       //미리 공간 할당하기 
//(reserve를 통해 미리 큰 공간을 할당한 후 다시 작은 공간을 할당하려 해도 기존의 큰 공간을 사용한다.)

for (size_t i = 0; i <10; i++)
{ 
   //capacity를 먼저 확장, 

}

// vector는 cpacity가 최소한으로 변하는 것이 잘 사용한 것 
// 

// leak 없애고 uvector를 template로 바꾼다 


}



