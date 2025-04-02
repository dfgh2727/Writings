// wrote_250402.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// Delegate
// 
// 먼저 함수 포인터에 대해 알아보자.
// TFunction<void()> Function;
// 위와 같은 일반 함수 포인터는 c++코드에서 잘 작동하지만 블루프린터는 아니다.
// (UPROPERTY()를 붙여도 의미 없다.)
// 
// void TempFunction(TFunction<void()> _Function)
// {
//   ->블루프린트에서 사용할 수 없다.
// }
// 
// Function = [this]()
// {
//    BlahBlah...
// }
// 위처럼 람다를 사용하는 방법도 있지만 
// 언리얼에서 메모리를 관리하는 GC(Garbage Collector)가 
// Function내부를 파악하지 못 하는 경우가 있어 에러가 발생할 수 있다.
// 따라서 Delegate를 사용한다.
// 
// 헤더에 Delegate를 선언한다.
// DECLARE_DELEGATE(Delegate이름)
// 선언된 Delegate는 구조체로 구성된다.
// 블루프린트나 네트워크 동기화를 원하면 
// DECLARE_DYNAMIC_DELEGATE(Delegate이름)로 Delegate를 선언하면 된다.
// 
// 선언한 Delegate를 멤버변수로 선언하고 바인드해주면 된다.
// (FDelegate Delegate이름;)
// UPROPERTY()를 붙여서 블루프린트에서도 사용할 수 있다.
// 
// Delegate와 연결될 수 있는(바인드 될 수 있는) 함수는 무조건 UFUNCTION()이 붙어야 한다.
// 바인드와 바인드된 함수 실행은 다음과 같이 한다.
// Delegate이름.BindFunction(this, TEXT("Bind될함수명"));
// Delegate이름.Execute();
// 
// 블루프린트에서 사용시 CreateEvent를 통해 함수를 바인드 할 수 있다.


// Lyra Project (라이라 프로젝트)
// 
// 언리얼이 새로운 기능을 업데이트 할 때 그에 대한 예제 프로젝트를 제공한다.
// 그 예로 Crop과 Lyra가 있다.
// 팹에 검색하면 나온다.


