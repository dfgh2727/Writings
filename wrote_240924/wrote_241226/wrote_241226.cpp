// wrote_241226.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// ImGUI는 뷰포트를 여러개 만드는 방식으로 작동한다.

// Root는 엔진의 기하구조에서 최상위 부모를 말한다.
// 보통 Root 하위에 child(자식)들이 트리 구조로 존재한다.
// 
// !DX 프로젝트 엔진 사용시 주의사항!
// Component를 만들고 작동시키길 원하면 Root Component에 직접 넣어줘야 작동한다.
// 그리고 child의 값은 모두 부모(Root Component)를 기준으로 설정된다.
// 가령 부모의 크기를 10, 자식의 크기를 10으로 설정했다면
// 실제 자식의 크기는 100(= 10 x 10)이다.
// 
// 부모의 BeginPlay가 실행될 때 자식의 BeginPlay가 실행된다.
// 
// 크자이공부... 공전 행렬은 따로 만들지 않는다.
// 부모가 회전하면 자식도 회전값이 곱해지면서 자연스럽게 회전하기 때문이다.
// 
// 언리얼에는 회전시키는 함수가 없다.
// 이번 프로젝트에는 추가한다.
// void SetRotation(const FVector& _Value)
// {
// }
// 
// void AddActorLotation(const FVector& _Value)
// {
// }
// 
// 
