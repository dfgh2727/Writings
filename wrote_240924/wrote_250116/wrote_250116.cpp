


// (엔진구조)
// 
// widget을 추가하면서 Renderer의 shared_ptr를 ptr로 바꿔서 생긴 문제...
// shared_ptr의 Ref count가 사라져서 함수가 사라지면 당연히 지역변수 ptr도 없어진다.
// 해결을 위해 Component 관리 구조를 만든다.
// std::list<std::shared_ptr<class UActorComponent>> ActorComponent
// template <typename Comtype>
// {
//		...
// }
// 
// static UEngineInputLayOutInfo& GetInfo();
// 실제 static 함수는 어디 있는가.

#include <thread>

// 쓰레드는 여분의 cpu에 연산을 맡기는 것.
// 
// cpu를 얼마나 점유하고 있나?
// 100퍼를 점유한다면 n개의 코어가 전부 BusyThread 상태.
// 
// BusyThread? MainThread?
// 
// 쓰레드...실행 흐름의 메모리 영역. 스택과 같다고 봐도 무방.
// 멀티 스레드 = 스택 영역이 많아지는 것.
// 스택 영역이 커진다는 것이 아니라 많아진다는 것을 쓰레드라고 한다.
// 
// thread, OS의 문제이지만 최근 버전의 C++은 어디서든 쓰레드를 사용할 수 있게 되어있다.
// 
// 쓰레드를 사용해서 로딩한다?
// 
// 다른 쓰레드에 일을 넘겨도 쓰레드 만들기, 작업 넘기기, 로딩 끝날때까지 기다리기...
// 즉 싱글쓰레드보다 무조건 느려진다.
// 로딩쓰레드 시간을 단축하려면? 
// 최대치의 쓰레드를 만들어서 분산시켜서(병렬처리) 시간을 단축시켜야 한다.
// 
// 스택의 크기를 정해줄 수 있다.
// _beginthread(윈도우OS), std::thread ... 선생님은 편의성 좋은 std 선호.
// 
// 공유된 메모리의 접근 문제가 있다.
// 여러개의 쓰레드를 쓰면 동기화 문제가 발생한다.
// 
// NewThread.join()
// 쓰레드가 완료될 때까지 기다린다.
// 
// int Value = 0;
//
// for (size_t i = 0; i < 100; i++)
// {
//     Value++;
// }
// 
// 쓰레드는 코드 한 줄씩 실행하지 않는다.
// 디스어셈블리를 확인해본다면...
// 
// 1) 임시 변수 Value 생성
// 2) 변수 Value에 1을 더한다.
// 3) Value를 반환한다.
// 
// 단계들이 있는데 여러 core들이 실행할 때 실행 순서가 랜덤이다(?!?!) ( = 데이터 영역에 충돌 발생)
// 따라서 쓰레드는 그냥 쓰면 안 된다.
// 
// 다수의 쓰레드가 접근하는 영역을 임계영역(critical section)이라 한다. (위 예시에선 int Value = 0;)
// 이 접근을 어떻게 조절할 수 있을까?
// 
// std::atomic <int> Value = 0;
// InterlockedIncrement()
// Window에서 제공, 메모리 크기 128비트 까지 보호해준다. 빠르다.
// 
// 그러나 잘못 사용하면 속도가 느려질 수 있다.
// 
// atomic은 자료구조를 사용할 수 없다. (list, vector,...)
// push_back을 생각해보자. 잘못하면 중간에 터진다. 안 터질수도 있고. 어디서 터지는지 정해져 있지 않다. 
// (new는 가능하다.)
// 
// 
// 
// join()을 하지 않으면...
// 메인 쓰레드가 종료되면서 메모리가 삭제되는데 아직 쓰레드들이 작업중이라 터질 수 있다.
// 
// 
//