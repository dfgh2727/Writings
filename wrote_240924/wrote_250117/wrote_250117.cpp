﻿// wrote_250117.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// (쓰레드)
// 윈도우에서 제공하는 기능을 통해 스레드에 이름을 부여할 수 있다.
// Job System
// sleep() 
// 일정시간 이 스레드를 재운다. 단위는 mS.
// 언제 깨울 수 있을까?
// Window에서 Event와 WaitForSingleObject라는 함수를 제공한다.
// 
// IOCP는 최종병기? 윈도우에서 쓰레드를 통합관리할 시 무조건 사용하게 된다.
// 
// SetThreadDescription()
// std::thread()에서 호출할시 어떤 스택안에 있는 코드라도 그 스택과 완전히 메모리가 다른 영역이다.
// 
// 쓰레드 점유...무슨 의미일까.
// 프로그램이 명령을 통해 캐쉬를 차지한다.
// 이 명령을 sleep()을 통해 정지시킬 수 있다.
// c++ 기초함수를 통해 쓰레드를 조절할 수 없다. 무조건 OS의 지원을 받는 함수를 사용해야 한다.
// 
// (...프로젝트로 돌아와서)
// 엔진에 있어서
// EngineBase, OS의 영향을 받지 않는 것이 좋다.
// EnginePlatform 부터 OS의 영향을 받는다.
// 
// UEngineThread
// 언리얼 방식은 아니다. 언리얼에서 native thread를 사용하려면 run...어쩌구를 사용해야 한다.
// 
// 게임중에 검은 화면...그 때 Core가 동작한다. (레벨준비, 어쩌구...)
// 보통 로딩 화면이 뜨는 시점에 Graphic은 준비되어 있지 않다. 
// 즉 로딩화면의 이미지는 따로 만들어야 한다.
// 
// thread안에서 사용하는 숫자는 간단하더라도 보호해주는 것이 좋다.
// 동시에 접근하는 문제가 발생할 수 있기 때문에.
// bool값인 loadingEnd를 atomic으로 보호.
// 
// 한번 로드한 이미지를 언로드하지 않는다...
// 별로 좋지 않다.
// 
// if(true == LoadingEnd)
// {
//   UEngineCore::CreateLevel(...)
// }
// loadingEnd가 끝나면 level이 만들어지게 한다.
// 
// 그러나 무조건 로딩을 사용해야 한다는 것은 아니다.
// 어쨌든 thread를 사용하면 시간이 걸리니까.
// thread...delta타임 사용할 수 없다. 
// main thread와 시간을 동기화 시켜야 하는데 그러면 thread를 사용하는 의미가 없다.
// 
// joinable() 
// bool값으로 끝난 쓰레드인지 아닌지 확인할 수 있다.
// UEngineThread::Start()
// 쓰레드 start 여부를 알린다.
// 
// SetThreadDescription()
// 쓰레드 이름을 정하는 것은 그 쓰레드 내에서만 가능하다.
// ...그러나 사용하기 힘든 구조니 
// 

// 소멸자에 virtual...dynamic cast를 사용하기 위해서. 

// 그래픽스와 클라이언트는 엄연히 다른 분야라...디퍼드고 뭐고 관심없다...
 
// 
// 
// 
// 
// 
// 
