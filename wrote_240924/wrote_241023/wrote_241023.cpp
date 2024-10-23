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

//089_StringView
// (C++14에는 없다)
// 
std::string Text = "Apple";
// 문자열 상수는 데이터 영역에 이미 메모리가 있는데
// 또 힙에 할당 시키는건 낭비, 근데 함수는 쓰고 싶고...
// 
std::_String_view 
//
// 
//단순히 레퍼런스 썼다고 메모리 아꼈다고 생각하면 안된다.
// string& _Value ... string이 생겨야 참조가 가능하기 때문에 한번 생긴것이다.
//

// (API로 돌아와서)
// 
// EngineWindow.cpp
// 
// window창을 하나만 만들겠다.
// 2개 만들면 터트린다.
// (window 클래스를 이용해 윈도우 창을 만들 수 있다. 이름을 지정하지 않으면 Default로 자동지정됨)
//
//c_str, ErrorText const char*를 리턴하는 함수
//std::string 안에 char*가 존재한다.
//
// map에서 find 함수는 iterator를 리턴한다.
// contains는 유무를 확인하는 함수. (bool 리턴)
// 이걸로 window클래스가 존재하는지 확인하는 걸 만들었다. 
// (find와 contains 모두 잘 숙지해야 한다)
//

//VS 주석 지우는 방법 
// (주의! 한 페이지에서만 하기!)
// ctrl F 누른 후 //.*로 검색 
