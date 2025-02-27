﻿// wrote_250213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// gitignore는 그것이 위치한 곳에서 기능한다.
// (하위 폴더는 영향이 미치지 않는다.)
// 
// GameInstance
// Level과 무관하게 엔진 하나당 반드시 존재하는 클래스, static과 유사한 느낌의 구조
// 
// 언리얼에서 항목제한을 걸었기 때문에 추가 포함 디렉터리를 바로 설정할 수 없다.
// Build.cs에서 작성해야 설정 가능하다.
// 모듈의 경로를 추가하자.
// PublicIncludePaths.Add(ModuleDirectory);
// 이전 프로젝트들에서 '추가 포함 디렉토리'에 '../(혹은 ..\)'을 입력한 것과 같다.
// 
// 클래스 삭제를 원하면 비주얼 스튜디오에서 삭제, 탐색기에서 파일들을 직접 삭제한 뒤
// 언리얼에서 툴 - visualstudio 새로고침을 눌러줘야 한다.
// 혹은 파일 삭제후 UProject에서 우클릭으로 generateProfile을 누른다.
// ...여차저차 위 과정에서 문제가 생기면 필수 파일 제외하고 모두 삭제한 뒤 UProject를 다시 빌드하자.

// 클래스를 만들때 public, private 옵션을 선택할 수 있다.
// private 폴더 내부의 헤더는 다른 모듈에서 사용할 수 없다.

// 블루프린트
// 
// C++ 클래스를 상속받아 만들어진 새로운 클래스다. 시각화 된 C++클래스라고 볼 수 있다.
// 
// class TestProject_API BPInstance : 
// {
//		<, void*>
// 
// }
// 실제로 bool값을 리턴하는 함수가 아니라 bool을 대체 가능한 메모리 영역을 가진 함수를 만든다.
// 내가 만든 기존의 모듈을 사용하는 블루 프린트 전용 모듈이 생긴 것 뿐이다.
// 
// 단점은 C++네이티브에 비해 속도가 느리다.
// C++로 어떤 함수를 만들었을 때 블루프린트에서 호출할 경우
// 그 함수를 다른 함수로 감싸서 호출하는 방식을 쓰기 때문이다.
// void Function() -> void BP_NodeFunction()
//                     {     Function();    }


// CDO (Class Default Object)
// 언리얼이 엔진을 실행하기 전 클래스를 조사하는 단계
// 일종의 최적화다.
// 
// 클래스의 생성자에 중단점을 걸고 언리얼을 작동시키면
// 프로그램이 실행되지 않았는데도 생성자가 호출되는 것을 확인할 수 있다.
// 대략 서너번 호출된다.
// 언리얼이 클래스들의 사양을 확인하고 클래스의 크기를 알아낸다.
// 앞서 알아낸 정보를 바탕으로 클래스 복사본을 만들고, 메모리 풀을 만들어 그곳에 클래스들을 복붙한다. (Object Initializer)
// 한 곳에 관련있는 메모리들이 모여있게 되므로 캐쉬 적중률*이 증가해 프로그램이 빨라진다.
// 결국 CPU 친화적으로 만든다.
// 
// *프로그램은 어떻게 빨라질까?
//  관련 있는 메모리들이 붙어 있어야 한다. (= 캐쉬 적중률이 상승하면 된다.)
// 
// Prototype Pattern
// 결과가 정해져 있는 연산 과정의 메모리를 계속 올렸다 내렸다 할 필요가 있을까?
// 연산 과정의 메모리를 만들어서 복붙하면 된다.
// 
// 가령 언리얼은 SpawnActor를 할 때 CDO가 클래스를 조사해서 나온 정보(= subclass)를 요구한다.
// 아래와 같이 사용한다.
// TSubClassOf<AActor> ActorSubclass;
// GetWorld()->SpawnActor<AActor>(ActorSubclass);

// 라이브 코딩 신뢰도 떨어져... 차라리 비주얼 스튜디오 껐다 키고 F5 누르는게 낫다.
// 헤더에 추가된 함수 같은건 반영도 안 된다고 카더라.