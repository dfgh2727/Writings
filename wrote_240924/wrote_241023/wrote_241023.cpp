// wrote_241023.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


//Rvalue
// 
int Test() 
{

}
// Rvalue는 이름이 없다.
// 대표적으로 함수 리턴값
// 
// 동적할당 받은 Rvalue...
// 깊은 복사시 메모리가 두번이나 생성되어야 한다.
// 최적화를 위해서 아래와 같이 메모리를 한번만 생성하고 그걸 넘겨받는다.
//

int main()
{
    std::cout << "Hello World!\n";
}
//
//
class IntTest
{

};

IntTest& operator = (const IntTest&& _Testval)
{
    // _Test 메모리를 가진채로 파괴된다.
    // 이 함수만 끝나면 지워지고 사라진다.
    // 낭비다. 

    Value = _Testval.Value;
    _Testval = nullptr;

    //이렇게 넘겨받는다.
}

//088_Try & Catch (그리고 noexcept)
// 
// (선생님은 선호하지 않는다. 어디서 문제가 생겼는지 파악하기 어렵다.)
// 
// 함수에서 에러가 나면 throw라는 구문으로
// 에러 처리를 바깥에 넘긴다.
//
// 에러를 알리는 방식은 보통 return 값이지만
// throw는 함수 중간에 던질 수 있다. 
// 
// noexcept
// no except 즉, 예외를 밖으로 던지지 않고 
// 내부에서 전부 처리한다는 의미다.
// (throw 처리하면 에러난다.)
// 