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

//(EngineCore / USpriteRenderer)
// void SetAlpha(unsigned char _Value)
//
// 0이면 완전 투명...255면 불투명
// (다이렉트는 모든 색상을 0~1.0f로 표현한다.
//  다른 차원의 값으로 변경하기 쉽다.)
// 
// clamp ...값의 범위를 잡아준다.
// Clamp(_Value, 0.0f, 1.0f)
// 0.0f 보다 작을 수 없고 1.0f보다 클 수 없다.
// 
//
// BLENDFUNCTION ... 매우 옛날 함수
// 옵션이 하나 뿐이다;;
// 
// 이미지에서 채널이란...
// 이미지는 R, G, B, A로 이루어져 있다. 이 각각을 컬러채널이라고 한다.
// 0이면 검은색, 255면 흰색이다.
// 
// 알파 블렌드는 알파 채널을 이용해서 알파를 적용시킨다. (단, 255인 부분만 적용.)
// 채널은 포토샵의 채널창에서 확인할 수 있다.
// (BMP는 32비트로 설정! PNG는 알파채널이 잘 적용되어 있으니 별다른 설정 필요 없음)

// TimeEvent
// 
// IsUpdate == true ... n초 동안 계속 실행
// float FadeValue
// 
// FadeChange()...DeltaTime으로 움직이게 값을 가져온다. GetCore()->GetDeltaTime();
// 
// FadeIn()과 FadeOut()을 잘 구분해서 호출하자!
// TimeEventer.push (2.0f, std::bind(AFade::, this),true, flase) 2초 동안, 함수들을 한번만 실행
// (IsUpdate는 true, loop는 false)

// CicleToRect 충돌 추가
// (RectToCircle은 위 함수를 반전시킨다.)
// 
// Transform으로 충돌범위를 고려한 도형을 구현한다.
// 원을 점으로 취급해서 생각한다.

// 앞으로는 직접 구현하지 않고 수학 라이브러리를 이용해서 함수를 만든다.
