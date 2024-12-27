﻿// wrote_241226.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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

// 자식을 설정할 때 무조건 부모를 고려해야 한다? 상당히 귀찮다...
// DefaultSceneComponent (크기가 1, 1, 1)
// 자식의 크기에 영향을 안 주는 부모를 만든다.
// 
// 함수가 보통 2가지다.
// (월드)
// 입력한 값이 결과다.
// 예) SetActorRelativeScale(50, 50)
//     부모의 크기가 (50, 50)일 경우 실제 자식의 크기는 (1, 1)이다.
//     결과적으로 자식의 크기는 (50, 50)이다.
// 
// Relative(로컬)
// 입력한 값을 처리하여 결과가 나온다.
// 예) SetActorScale(50, 50)
//     부모의 크기가 (50, 50)일 경우 자식의 크기는 (2500, 2500)이 된다.
//
// Root의 경우 월드와 로컬 구분 없다.
// 영향을 줄 부모가 없다.
// 
// bool IsAbsolute;
// 부모 유무와 무관하게 반드시 설정된 값으로 만들게 한다.
// -> 결과가 (월드)로 나오게 한다.
// 
// 크기 회전 이동을 알려주는 함수가 있다. 
// void Decompose(FVector& Scale, FQuat& RotQuarternion, FVector& Pos)
// 
// 쿼터니온(Quarternion)은 복소수로 이루어진 1x4 행렬을 말한다.
// 짐벌락 현상과 같은 오류를 해결한다. 
// 쿼터니온을 사용하면 굳이 회전행렬을 따로 계산할 필요 없다.
// (근데 이번 프로젝트에선 만들었다.)
// (쿼터니온으로 부터 각도를 알아내는 함수도 만들었다. QuarternionToEulerRad(), QuarternionToEulerDeg())
// 
// 언리얼에서
// 한 축의 값에 기반한 코드는 치지 않는게 좋다.
// 눈으로 보기엔 일정 각도만큼 회전한 것 같지만, 실제 쿼터니온에 의해 나온 값은 다를 수 있기 때문에
// 위험하다.
// 쿼터니온에서 값을 추출할 때 결과가 예상과 다를 수 있다. 
//
