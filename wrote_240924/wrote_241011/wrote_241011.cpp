﻿// wrote_241011.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    
}

//ConsoleGame
// (게임을 시작할 때 준비할 내용들은 BeginPlay에 만든다. 그리고 한번만 실행되게 한다.)
// 
// 초기화를 안 하면 값을 알 수 없다.
// 예측하지 말고 확인해 볼 것.
// 
// 클래스도 배열이 될 수 있다(?)
//
//프레임구조
// 프레임, 화면의 갱신률을 의미...대부분 while(반복문)이다.
// 움직이고 띄운다, 움직이고 띄운다...를 n번 반복하면 n프레임
// 
// 게임내용은 대부분 [오브젝트, 랜더링, 충돌, 릴리즈] 이렇게 4가지 구조로 이루어져 있다.
// 
// Release
// 
// 빌드하다가 실행창을 닫으면 정상적인 종료가 아니기 때문에 leak가 남는다.
// 
// BackBuffer를 플레이어에게 노출시키고 싶지 않겠지? private ㄱㄱ
// 
// OS 이야기
// 
// _getch()는 입력버퍼에서 입력을 하나 빼는 함수
// 만약 입력된게 없으면 _getch()가 실행되면 입력이 생길때까지 기다린다
// _kbit()는 입력버퍼에 입력이 존재하는지 확인하는 함수
//  



//070_NewTest
// 
// 
//
//

const int A = 5;
char Arr[A] = {}; //const 안 쓰면 변수는 사용하지 못 한다.

//071_DeleteEx
//
// delete를 두번하면 터진다.
// 따라서 safe delete를 하면 ok
// (nullptr이 되면 if에 해당되지 않아서 괜춘)
// 
// 
// Dangling Ptr
// new한 메모리에 2개의 ptr을 할당하고 하나만 삭제하면 남은 포인터는 빈 메모리를 가리키게 된다
// 
// 여차저차 터지는걸 막기위해서 보장하기 어렵다면 무조건 nullptr로 만들자
// 

//072_DefaultParameter
// 
// 디폴트 파라미터는 cpp에 있으면 에러난다.
// 그래서 선생님은 주석처리 해 놓는다.
//


//073_ListInit
// 
// 멤버변수가 public이라면 특수한 초기화 방식을 사용할 수 있다.
// 이를List Initializer라고 한다.
// 


