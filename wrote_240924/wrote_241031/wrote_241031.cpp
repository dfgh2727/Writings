// wrote_241031.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// 다음주부터 학생들이 요청한 걸 만든다.
// 다음주 월요일에 
// 사운드는 되도록 마지막에 한다.
// 
//

// 같은 이름의 이미지가 로드 되면 터지게 만들었다.
// 폴더명을 스프라이트 이름으로 만들었다.(key) 
// 
// LoadFolder, GetAllDirectory - 파일을 로드하고 가져와야 한다.
//
// bitmap 로딩하는 
// 
// Resource 파일 전체를 로딩하는건 좋지 않다.
// 
// 보여준 예시를 그대로 따라할 필요 없다.
// 

//Renderer?
// 
// 게임을 이루는 객체들의 구조는 단순하지 않다.
// 하나의 액터에 다양한 구성 요소(component)들이 존재한다
// std::list <Component> ComponenetList;
// 
// Component는 Actor 하위에 위치
// Ucomponent
// 
// 언리얼의 컴포넌트는 2가지로 나뉜다.
// ActorComponent(위치를 가지지 않는다. 기능만 있을 뿐)
// SceneComponent(어떤 actor를 기준으로 위치를 가지는 component)
// 
// 언리얼은 다음과 같은 구조를 가진다.
// UActorcomponent : public Uobeject
// UScenecomponent : public UActorcomponent
// 

//언리얼은 2D 게임을 만들기 불편하다.

//(API)
// 더 이상 Actor에 렌더링 기능을 만들지 않는다.
// Renderer를 따로 만든다.
// (SpriteRenderer -> SetSprite)
// Renderer가 애니메이션, 메쉬를 포함한 모든 렌더링을 담당한다.
// 
// Component하위에 Collision과 Rendering을 위치
// 
// SpriteRenderer: public SceneComponent (상속받는다)
// 
// FTransform이 SceneComponent를 가진다.
// 
// 추상 클래스는 객체화 할 수 없다.
// 소멸자를 virtual처리시켜서 객체화를 막는 방법
// virtual ~UObject();
// 
// component 소유도 삭제도 Actor가 한다.
// 오직 부모인 Actor(ParentActor)만이 접근 가능하다.
// ComponentPtr -> ParentActor = this;
// 
// component 지우는거 안된다. (언리얼은 그런거 없다.)
// 
// Component도 Tick이 있다. 
// ComponentTick
// 
// Player가 생성되면 그 안에서 Render도 생성된다.
// 
// Actor가 SpriteRender를 만들면
// Level로 알아야 한다.
// Level -> PushRenderer
// (Renderer가 Level안에 자신을 넣는다.)
// 
// PushRenderer 아무나 호출해서 안된다.
// private처리. Renderer만 호출할 수 있다. 
// 
// 부모 클래스를 호출하는걸 잊지 마라. (Super)
// 
// 오더링
// 뭐가 먼저 렌더링 되야할까?
// 순서를 생각해보자.
// int GetOrder();
// 
// World
//