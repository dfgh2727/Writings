// wrote_241113.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// (API)
// 
// Fade In, Fade Out (알파값 이용)
// ...필요하진 않지만 DeathCount 화면이 나타나게 하는 기능은 필요함.
// 
// BMP는 32비트
// 
// class AFade :public AActor
// LevelChangeStart() 레벨이 바뀔 때마다 실행되므로 
// 
// static...게임 내부에서 딱 한번만 생길 때 선언한다.
// 

// LevelChangeStart() 
// 실행 안되는 오류 수정...
// BeginPlay 실행 전에 BeginPlayList가 만들어지고 있었음.
// 시점 함수를 수정한다.
// 
// BeginPlayCheck()를 만들어서 Tick()과 LevelChangeStart()에 넣는다.
// ...게임 실행시 List에 Gamemod, MainPlayer, Fade 잘 들어오는거 확인함.
// 

//
//
//
