// wrote_241101.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

void main()
{
    std::cout << "Hello World!\n";
}

//(API)
// 
// C++은 클래스를 나눠서 선언할 수 없다.
// (C#의 partial 같은건 없다.)
// 
// 디버그용 text를 OutPutString 말고 창에 띄우는 기능을 만든다.
// 
// 선언과 구현을 분리했다. (namespace UEngineDebug)
// void WinAPIOutPutString ()
// Engine의 낮은 단계(중심)로 갈 수록 함수의 인자수가 많다...
// 
// void PrintEngineDebugText()

// 디버깅 기능은 느려도 상관없다. 출시에 필요한 기능이 아니니까.
// 대신 release 할 때 기능 끄는거 잊지 말기!
// (키고 끄는 기능도 넣었다. SwtichDebug() )
 
// 프레임 위치와 FPS(frame per sec)를 띄우는 기능도 추가
// 
// FVector를 string으로 쓰는 기능 추가
// (EngineMath) std::string ToString ()
// to_string()이라는 함수를 쓰자 (std strstream은 최신 C++에서 제거됐다.)
// 
// 선생님 컴으로 확인해보니 엔진 내의 TransparentBlt를 사용해서 이미지를 편집하니 
// 프레임이 40배 이하로 떨어진다! 와!
// 그러니 편집된 이미지를 쓰자.
// 
// 
// 
// 
//