// wrote_241022.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    
}

//Get Message는 사용하지 않는게 좋다.
//window에 메시지가 발생할 때 까지 기다린다.
// 
// *********shooting게임dml Console Engine을 다시 보면************ 
// 엔진을 보면 Tick-Render-Tick-Render-...를 반복하는 구조
// 근데 움직임이 없어서 Tick에 중단점이 걸리면 Render되지 않음.
// 
// kbhit를 사용한 이유..입력유무 구분을 위해서.
// getch 입력버퍼를 비워준다 but 입력버퍼가 없으면 무한대기
// ****************************************************************
// 
// BOOL
// typedef
// (C에는 bool이 없다. 근데 코드는 C 스타일...
//  C에서도 bool처럼 쓸 수 있게끔 만든것)
// 
// 함수포인터로 윈도우에 전달
//

//stdString
// 
// 다른거 제쳐두고 basic string만 본다면 (나머지는 Map의 less 같은것 추후에)
// 
// (배열...불편하다. 대입도 안 되고, 크기도 한정적.)
// 
// std::string Text;
// 형태는 std vector와 거의 비슷하다 
// but 몇가지 함수를 더 만들어서 문자열 처리에 도움이 되게 만든 자료형
// 
char Test[10] = "AAAA";
if (Test == "AAAA")  // false
{                    //Test == char[]
                     //"AAAA" == const char*
                     // casting이 일어난다.(형변환)
                     // 둘이 주소값(8바이트 정수)이 달라서 false 
}
// string은 문자열 한 자씩 비교를 해준다. 
// Test == "AAAA"는 원래 성립할 수 없지만, operator== 지정해 놨다.
// (replace는 나중에)

void Test(const std::string Text) //이렇게 쓰면 안된다!
{                                 //레퍼런스로 써야 한다.(8바이트)
                                  

}
// 일단 크기가 몇인줄 알고;;
// std::string Text = "AAAA" new가 4번 일어난다.
// (std::vector = {0,1,2,3} push_back 4번...new 4번)
// 레퍼런스로 받으면 복사 생성자 호출, 
// string 값형을 그대로 받으면 new가 다시 발생 (대입연산자)
//


//Map에서 사용한 operator를 다시 생각해보자.
// 
// key를 비교해서 노드를 배치했지...
// Class도 >, ==를 사용해서 비교할 수 있나? 
// 직접 지정해야 가능하다. 
// 
// std::string은 내부에 비교하는 함수들이 있으니 비교 가능.
//

// 이후 API framework...

//옮기고 나서 질문하기

//필터랑 프로젝트명은 마음대로

//lib로 진행

 
