// wrote_241029.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}


// 
// 값형...메모리는 만들어져 있지만 초기화 되어 있는지는 알 수 없다.
// 
// WindowImage는 랩핑 클래스, Create()로 호출해서 HDC가 만들어져야 의미가 있다.
// 
// 
// (화면 크기가 바뀌면 엄청나게 느려지는겜? 백버퍼를 전체화면에 맞춘 로직으로 짠 경우다.)
// 우리는 창 크기를 정하고 버퍼는 그걸 따라간다.
// if (WindowSize != )
// 
// float은 비교가 매우 위험하다.
// bool CompareToInt 소수점을 버리고 비교하거나 
// bool Compare (,float _limit = 0.0f) 제한을 둬서 비교
// 
// const가 붙은 함수, const가 붙은 함수만 호출 가능하다.
// 
// HBITMAP
// 
// UEngineImage, ptr로 넣어줄 시 null일 경우 터지게.
// 
// GetObject() 정보를 얻어오는 함수
// 
// FVector2D WindowSize 
// 
// 좋은 엔진은 줄줄이 사탕모양으로 만들지 X
// 오히려 랩핑을 해서 사용자가 엔진 근본에서 멀어지게 만든다.
// 
// BackBuffer -> CopyTo(windowImage)로 결정!
// 
// 
// class FTransform       이미지 크기와 위치를 정할 수 있는 클래스
// {                      일일이 값으로 정하기 힘드니까
// }
// 
// WindowImage의 가운데에 놓고 크기를 맞추는 방식으로 간다.
// 
// 
// BitBlt...SRCCOPY 덮어서 그리는 옵션으로
// 
// DoubleBuffering에 ScreenClear()를 만든다.
// 화면 크기만한 직사각형을 만든다. 지우는 것 같이...
// Render를 시작할 때 그리면 화면이 깨끗하게 보인다. 
// 

// 12시 30분에 질문 받는다 