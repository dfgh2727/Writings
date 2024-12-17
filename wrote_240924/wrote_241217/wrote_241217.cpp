// wrote_241217.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

// 102_replacementNew
// (...어제에 이어서)
// 
// ...생성자가 호출되지 않으면 가상함수 테이블이 만들어지지 않는다.
// 
// AMonster* Actor = new(mempool) AMonster();
// 
// 정적배열(array)이 아닌 메모리는 느려지게 만든다.
// (캐시적중률이 낮으므로)
// 
// (유니티의 ECS 엔티티)
// 
// 흩어져 있는 메모리들이 아닌 하나의 정적배열처럼 위치시킨다.
// FTransform ArrTrans[1000];
// FTransform* Trans = &ArrTrans[2];


// Level이 셋팅되기 전에 
// Level->spawnActor()할 수 없으나... 먼저 메모리를 만든다면?!
// 
// AMonster* MonsterMemory
// 
// !주의!
// 생성되면서 리터럴 초기화도 실행되니 초기화 시키지 않기.


// 103_ 
//
// Compile Time Assertion은 컴파일 타임에 이미 결정되어 있는 결과를 말한다.
// 런타일에서 연산량을 줄이는 데 사용된다.
// 
// 상속 여부를 확인할 수 있는 문법
// std::is_base_of<classA, classB>::value 
// 혹은 std::is_base_of_v<classA, classB>
// 
// 컴파일러는 어떻게 상속 여부를 확인할 수 있는걸까?
// 클래스 내에 존재하는 bool 값을 상속여부에 따라 바꾼다. 
// 
// sizeof는 함수가 아닌 상수다. 이미 코드 영역에 저장되어 있다.
// 
// class My_Is_Base_Of
// {
//     static short Test(void* Test);
//     static char Test(AActor* Test);
//     
//     static Monster* Ptr;
//     static const bool value = sizeof(My_Is_Base_Of::Test(Ptr));
// }
// 
// AActor가 호출될까, void가 호출될까... (short로 리턴될까, char로 리턴될까)
// Monster는 AActor를 상속받았다. 업캐스팅 된 쪽이 먼저다.
// 
// ...근데 굳이 if로 bool값을 확인해야 하나? 바로 에러나게 만들자 
// static_assert(상수 메모리(const)인 변수, 메세지);
// static_assert(std::is_base_of<classA, classB>::value, "ClassA is not a classB.");


// 104_TypeID 
// 
// 컴파일 타임에 결정된 구조체는 코드영역에 만들어진다.
// 그걸 가져다 쓰는 방법이다.
// 
 class MyClass
 {
     
 };
// 
 const type_info &Info = typeid(MyClass);
// 위 값은 컴파일 타임에 결정되므로 수정할 수 없다.
// 
 std::cout<< Info().name << std::endl;
// 
// ...결론적으로 내가 만든 클래스의 정보를 가져올 수 있다.
// 
// 해쉬코드는 어떤 데이터에 부여된 값. 해쉬코드들은 전부 다 값이 다르다.(중복되지 않는다.)
// 


// (다시 엔진으로 돌아가서...)
// 
// new가 아닌 어떤 클래스 크기의 메모리 덩어리를 만들자.
// 
// if (false == std::is_base_of_v<AActor, ActorType>)
// {
//     (경고 문자)
// }
// 
//  Actor.h안에 ActorComponent헤더 추가. 
//  (순환 참조 주의)
// 
//  SceneComponent를 상속받는 클래스는 shared
//  ActorComponent를 상속받는 클래스를 list로 관리.


//  헤더... 해당하는 클래스의 멤버함수를 썼는가가 중요하다.
//  만약 포인터만 쓴다면 헤더를 추가할 필요 없다. 전방 선언만으로도 충분하다.
//
 class Renderer
 {

 };

  Renderer TheRenderer /*= Renderer()*/; //->클래스의 함수를 불러낸다. 헤더가 필요.
 
  Renderer* ThePtr; //8바이트로 크기가 정해져 있다. 헤더 필요 없다.
 
  ThePtr->Component = this*; // Renderer 안에 Component가 있는지 확인해야 한다. 헤더가 필요.

//
//  템플릿은 헤더에 구현해야 한다.
//  인라인과 헤더 템플릿...
// 
//   define과 inline?
//   스택이 생성되면 느려진다...
//   새로 함수를 만들면 스택이 생성된다.
//   define은 단순히 함수 치환이기 때문에 새로운 메모리 영역을 만들지 않는다.
// 
//   inline은 복붙한다. 함수를 실행시키지 않는다.
// 

// Renderer
// Render()는 아무나 쓸 수 없게 private으로.
// 
// ActorComponent
// BeginPlay 이전에 InitializeComponent 실행
// 
// pair...map 안에 key와 class를 한데 묶어 보관하는 클래스
// 
// Actor의 BeginPlay 이후 Component의 BeginPlay 실행
// 시점 함수는 엔진이 실행시켜주는 엔진. 내가 직접 실행시키면 안 된다.
// 
// shared_ptr을 지울 때는 일반 ptr로서 지울 수 없다. shared_ptr를 지워야 한다. 
// dynamic cast는 일반 포인터를 변환시킨다. shared_ptr은 아니다.-> dynamic_pointer_cast 사용
// 
// shared_ptr은 map과 비슷한 구조로 ptr를 관리...따라서 느리다.
// int가 내부에 자신의 Ref를 세는 값을 가질 수 있나? 아니다.
// 클래스는 가능하다.  = 침습형. 자기 자신 안에 카운트가 존재한다. 
// 
// class UObject : 
// {
//    template <>
//      ...UObject가 아닌 shared_ptr를 return하게 만든다.
//    
// };
// 

// DirectX 시작
// 
// device? 함수에 대한 포인터를 말한다.
// 
// 진정한 멀티플랫폼이 되고 싶다면...DirectX가 코드에 없게 만들어야 한다.
// 매우 힘들다.
// 
// #include <d3d11_4.h> 다렉11 ver.4 헤더
// #include <d3dcompiler.h> 쉐이더 컴파일러용 인터페이스
// 
// 다렉 초기화 - 블루 스크린(단색 스크린)
// 
// 다렉11은 인터페이스가 분리되어 있다.
// Device-> Load();  로드한다.
// Context-> Draw(); 렌더된다. 
// (다렉9은 Device가 로드와 렌더 모두 담당한다.)
// 
// EngineCore에서 EngineGraphicDevice를 관리한다.
// 
//   1D3D11Device* Device
//   1D3D11DeviceContext* Context 
// 
// (참고 - 다렉의 클래스들...new를 선언하는게 아니기 때문에 shared_ptr로 관리하지 않는다. comptr이란걸 사용.)
// (차피 지우지 않을 것이니 딱히 안 쓴다.)
// 
// GPU와 CPU의 차이?
// CPU가 수행하는 다수의 연산 처리 과정을 GPU는 병렬로 한번에 처리
// 가령 CPU가 점 한 개를 화면에 여러번 찍을 때 GPU는 여러개를 한 번에 찍는다.
// CPU는 다양한 일처리, 기본적인 기계어 명령어가 많다. 
// GPU는 수학적 연산에 관련된 코어로 구성되어 있다. 병렬처리에 특화되어 있다.
// 
//
