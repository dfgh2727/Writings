// wrote_250108.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 이제 ImGUI에서 GetWorld()를 통해 class Level에 접근 가능하다.

// FreeCamera
// 
// FreeCamera 사용시 다른 Actor들은 움직이지 않는다.
// 즉 Tick을 돌리지 않는다.
// (예외로 particle의 Tick은 그래픽카드로 돌아가기 때문에
//  Camera를 FreeCamera로 전환해도 움직인다.)
// 
// FreeCamera 사용시 Actor가 정지하기 전에 Transform을 저장해 둔다. 
// (PrevTrans, Actor의 Transform을 백업해둔다.)
// 
// FreeCamera는 보통 Debug모드에서만 사용하게 만들지만
// 이번 프로젝트는 습작이므로 Debug, Release 모두 사용가능하게 만들었다.
// 
// CameraActor의 위치를 World를 기반으로 하게 만든다.
// (Local기반일 시 부모의 값이 기준이 된다. 가령 Local Right의 경우 부모 기준으로 오른쪽으로 움직인다.)
// 
// 마우스의 움직임을 따라서 FreeCamera가 회전하게 만든다.
// (회전...언리얼에서는 Rotator를 사용한다.)
// 예를 들면 다음과 같다.
// 마우스가 위로 올라간다면 Pos의 y값이 증가한다.
// 카메라는 x축을 기준으로 회전하는 것과 같다.
 

// Billboard
// 
// View 행렬을 통해서 이동과 회전을 반영해 이미지가 왜곡된다.
// View 행렬에서 회전만 무시해보자.
// 
// World 행렬의 회전을 무시한다면...
//

// Actor의 부모 존재 여부에 따라서 
// AllActor에서 Tick을 돌릴지 말지 결정한다. 

