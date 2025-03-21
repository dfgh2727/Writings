﻿// wrote_250228.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// ***주의***
// struct는 포인터형으로 블루프린트에서 사용할 수 없다.
// 그렇다고 값형으로 넣기엔 크기가 부담스럽고 null을 확인할 수 없다...
// 그래서 선생님은 C++을 선호한다.
// 
// UStaticMeshComponent* Component = Actor->GetComponentByClass<UStaticMeshComponent>();
// GetComponentByClass() 내부에 component를 찾기 위해(Find()) for문이 돌고 있다.
// 그러나 Component 수가 적으면 부담스럽지 않으므로 사용할만 하다.
// 경우에 따라 적절한 방법이 된다.
// 엔진 내부에 대한 이해를 바탕으로 코딩을 하자.
// 
// 위 방법 말고 새로 actor를 만드는 방식을 살펴보자.
// 아이템용 C++클래스를 만든다.
// 
// 에셋의 각도가 맞지 않는다면
// 메쉬 더블클릭...임포트 세팅 - 트랜스폼 - 회전 임포트로 설정 가능하다.
// 그러나 파일 경로로 전달해줄 원본 메쉬가 없다면 할 수 없다.
// 
// 원본 메쉬가 없을 경우 
// 소켓에 프리뷰 메쉬를 달아서 아이템(메쉬)이 캐릭터에 장착되었을 때 어떤 각도인지 확인하고 
// 아이템 데이터에 직접 각도를 입력해주는 방법도 있다.
// FQuat Rot = FQuat::MakeFromEuler(Item->GetItemData()->EquipAngle);
// Item->SetActorRelativeRotation(Rot);

// (오후에 UI 수업을 했다.) 
