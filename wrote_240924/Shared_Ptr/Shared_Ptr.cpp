// 100_shared_ptr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>

// 면접 단골문제중 하나

class Monster
{

};

typedef Monster PtrType;

// template<typename PtrType>
class MyShared_ptr
{
private:
    static std::map<void*, int> Check;

public:
    PtrType* Ptr;

public:
    MyShared_ptr(PtrType* _Ptr)
    {
        if (nullptr == _Ptr)
        {
            return;
        }

        if (true == Check.contains(_Ptr))
        {
            int& Value = Check[_Ptr];
            ++Value;
        }
        else
        {
            // 몇명이 이 주소값을 사용하고 있냐?
            Check.insert({ _Ptr, 1 });
        }
        Ptr = _Ptr;


        int a = 0;
    }

    MyShared_ptr()
        : Ptr(nullptr)
    {

    }

    ~MyShared_ptr()
    {
        if (true == Check.contains(Ptr))
        {
            int& Value = Check[Ptr];
            --Value;
            if (0 >= Value)
            {
                delete Ptr;
            }
        }
    }
};

// template<typename PtrType>
// std::map<void*, int> MyShared_ptr<PtrType>::Check;
std::map<void*, int> MyShared_ptr::Check;

// template<typename PtrType>
MyShared_ptr Mymake_shared()
{
    MyShared_ptr NewPtr = new Monster();
    return NewPtr;
}

class Player
{
public:
    std::shared_ptr<class Orc> OrcPtr;

};

class Orc
{
public:
    std::shared_ptr<class Player> PlayerPtr;

};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // 헤더 순환참조처럼
    // 쉐어드 Ptr도 순환참조 문제가 있다.
    // 

    // 힙에 <100번지, 1> player
    std::shared_ptr<Player> NewPlayer = std::make_shared<Player>();

    // 힙에 <200번지, 1> Orc
    std::shared_ptr<Orc> NewOrc = std::make_shared<Orc>();;

    // 힙에 <200번지, 2> 
    NewPlayer->OrcPtr = NewOrc;

    // 힙에 <100번지, 2> 
    NewOrc->PlayerPtr = NewPlayer;

    //// 무조건 릭이 날 것이다.
    //std::shared_ptr<Monster> NewMonster = std::make_shared<Monster>();

    {
        MyShared_ptr MyNewMonster = Mymake_shared();
        //    MyNewMonster = nullptr;
        //    int a = 0;
    }

    {
        int Value = 100;

    }

    // Monster* MonPtr = new Monster();

}
