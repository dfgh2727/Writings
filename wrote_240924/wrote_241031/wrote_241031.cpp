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
//
// 
// 언리얼에서 
// CreateDefaultSubobject는 생성자에서만 만든다.
// 다른데서 호출하면 터진다.
// (캐쉬 적중률을 고려하여 디자인된 메모리를 맞춰서 쓰길 원한다.)
// (캐쉬 적중률...Actor를 쓴다면 Renderer와 Transform을 많이 쓰겠지?
//  관련있는 기능들은 한 곳에 묶어서 둔다.)
//
// BeginPlay는 원래 Actor가 생성될 때 만들어지지 않는다.
// 객체가 레벨에서 
// component에 넣어두기만 하자.
// Tick이 돌기 직전에 실행
// 
// Renderer는 Level안에 
// list의 second 부터 
// 
// 시점함수
// 언제 어떤 함수가 실행되는가...
// 
// Renderer에 크기를 정해주자.
// SpriteRenderer -> SetScale({n, m});
// 
// SetcomponentLocation
// Actor기반으로 한 위치라는것을 잊지마라!
// 
// GetActorTransform
// Actor의 위치를 반영하여 실제 component의 위치를 알 수 있게 했다.
// 크기는 변함 없으니 그대로.
// 

// FVector2D SetSpriteScale()
// Scale값을 return해서 
//  
// (ContentsEnum) 
// ERenderOrder
// 렌더 순서를 정한다.
// 
// USpriteRender
//

// CreateAnimation
//
//

//애니메이션 특정 개체 선택적으로 멈추기, 어떻게 만드는지 들어야 함!

// 이미지를 엔진에서 확대해서 쓰면 프레임이 떨어진다 
// (Transparent 연산 때문에 부하가 발생)
// 확대해 놓은 이미지를 render하자
//

// x값이 8칸(17칸 중)을 초과하면 카메라가 움직임
// (-)방향으로 움직이지 않는다.
// 
// 관성이 있다.
// 버튼을 눌렀다가 떼도 이동함.
// 
// 발이 떨어지면 바로 이미지 변함
//
//

