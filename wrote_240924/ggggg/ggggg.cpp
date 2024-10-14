// 074_VirtualInstanceEx.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

// 게임에서 나올 모든 눈에 보이는 오브젝트가 여기안에 담겨있을 것이다.
// 게임마다 달라. 예상할수 있다고
// 유저는 항상 개발의 상상력을 깹니다. 상식적으로 유저를 접근하면 안됩니다.
// 그래서 항상 가장 다형적인 측면으로 접근해도 된다.
// 일단 문제가 없게 접근해야 합니다.
// 일단 상수가 절대로 가능하지가 않아요.

// 최초에 몇개를 만들지 정하지 않아요. 일반적으로

AActor** AllActorList = nullptr;
int AllActorSize = 0;

// 이런식의 함수를 만듭니다.
void SpawnActor(AActor* _Actor)
{
    // 새로만든 플레이어를 받을공간이 없으므로

    AllActorList = new AActor * [AllActorSize];

    AllActorList[AllActorSize] = _Actor;
}


int main()
{
    // 그러면서도 leck은 없어야 합니다.
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    //// 10마리 10마리를 만든다음 다음과 같이 해야한다.
    //Player NewPlayer[10];
    //Monster NewMonster[10];

    //// 당연히 됩니다.
    //// 참조형이기 때문에 아주 간단
    //Player* Ptr = new Player[10];
    //Monster* Ptr0 = new Monster[10];

    // 플레이어를 잃어버린것이다.
    // AActor* Ptr = new Player();

    SpawnActor(new Player());
    SpawnActor(new Player());

    // 왜터지는지 설명할수 있나요


    for (size_t i = 0; i < AllActorSize; i++)
    {
        delete AllActorList[i];
    }


    delete[] AllActorList;

    //SpawnActor(new Player());
    //SpawnActor(new Player());
    //SpawnActor(new Player());


}
