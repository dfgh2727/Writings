// wrote_241014.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


//F10, 프로그램 시작 위치로 간다.

//Design Pattern
//(: 클래스를 다루는 방식, 단어 자체는 그다지 중요하지 않다.)
//
//singleton: 단 하나의 객체를 만들고 더 이상 만들지 않는 방식
//           (면접에서 물어본다.)
//           (생성자를 private에 위치)
           
//코드 독해
//스택의 생명주기...언제 생성되고 언제 소멸되나를 파악해야 한다.
//처음 프로그램을 볼 때는 F10누르고 처음부터 끝까지 돌려보기.
// 
// 보통 핵심적인 것들(언제든지 사용 가능해야하는 것)은 전역변수에 가깝게 존재한다. 
// (전역이 아니면 static이라던가) 
// static 데이터 영역에 존재, 프로그램이 종료될 때 까지 파괴되지 않는다.
// 
// 
// 게임 엔진에는 루프가 존재한다.
// 준비하는 내용들(Init)... 보통 한 군데에 모여 있는 경우가 많다.
// 

//갤러그와 다형성(?)
// 
//플레이어, 몬스터, bullet 이 필요한데...
//(클래스의 종류가 많을수록 관리가 어려워진다. 따로 만들기보다 다형성으로 만들어야 한다.)
// 
// 몬스터, 플레이어, 불렛 모두 공통점? 위치가 있다 -> FintPoint
// ...AActor를 Super로 typedef.
// 
// 
// 몬스터와 불렛 수가 정해져 있나? 아니라면 동적할당
// AActor** AllActorList = new AActor* ();
// 포인터를 담을 수 있는 포인터의 집합... Player인지 Monster인지 상관없다.
// 게임에 나올 오브젝트가 다 여기에 담겨 있는데...수를 예상할 수 없다.
// AActor** AllActorList = new AActor*[100]; (X)  
//                                    이렇게 상수로? 안된다. 일단 문제가 없게 수를 정하지 말자.
// (new Player(); 이렇게 하면 메모리 잃어버린거다;; 항상 주소 받아야 쓴다)
// new를 선언했다 -> 힙에 메모리 영역 생김
// 
 

//074_
#include <iostream>

class AActor
{
public:
    virtual ~AActor()
    {

    }
};

// Monster Is A AActor
// Player* => AActor* => UpCasting
class Monster : public AActor
{
};

// Player Is A AActor
// Player* => AActor* => UpCasting
class Player : public AActor
{
};

AActor** AllActorList = nullptr;
int AllActorSize = 0;

// 이런식의 함수를 만듭니다.
void SpawnActor(AActor* _Actor)
{
    // 새로만든 플레이어를 받을공간이 없으므로

    AllActorList = new AActor*[AllActorSize + 1];

    AllActorList[AllActorSize] = _Actor;
    ++AllActorSize;
}


int main()
{
    // 그러면서도 leck은 없어야 합니다.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    SpawnActor(new Player());
    //AllActorList = new AActor * [1];
    //AllActorList[AllActorSize] = _Actor;
    //++AllActorSize;

    SpawnActor(new Player());
    //AllActorList = new AActor * [2];
    //AllActorList[AllActorSize] = _Actor;
    //++AllActorSize;
    
    // 터지는 이유 (그림 꼭 그려보기):
    // AllActorList = new AActor * [1];
    // AllActorList[AllActorSize] = _Actor;
    // ++AllActorSize; 
    // 
    // AllActorList = new AActor * [2]; 를 선언, 2칸짜리 배열 생성.
    // 이때 AActor[1]을 가리키던 AllActorList는 2칸 배열을 가리키면서 한칸짜리 배열을 위치를 잃어버림. (leak 발생)
    // 두칸짜리의 [1]에 ptr를 선언해줬다. [0]의 값은 알 수 없다. 근데 [0]의 값을 delete시도. 터진다.

    for (size_t i = 0; i < AllActorSize; i++)
    {
        delete AllActorList[i];
    }


    delete[] AllActorList;

}
//생각한대로 두번 생기고 한번만 삭제되는건 맞지만 
//구체적으로 터진 이유는 위치를 모르는 메모리를 제거하려 했기 때문이다.
//두칸짜리 배열의 생성을 생각했어야 했다. 

//
//
//
// 



