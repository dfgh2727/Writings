// wrote_250110.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// list로 만들어서 vector로 return한다?
// 

// 하나의 Actor가 여러개의 Renderer를 가질 수 없다.
// (적어도 다렉에서는)
// 
// Isometric TileMap
// -> Z sorting이 필요하다!
// 
// 타일을 깔 때 여러개의 Renderer를 쓰지 않는다. (list에 너무 많은 Renderer가 들어가기 때문)
// 
// alpha값을 쓰지 않는다면... shader에서 plus color와 mulcolor를 없애자.
// 
// 타일맵의 인덱스는 겹칠 수 없다. 즉, 어떤 위치에 두개의 타일이 존재할 수 없다.
// 
// unordererd map
// hash 기반의 map. 기존의 map보다 빠르다.
// 
// void CreateTileMap(int _X, int _Y)
// 먼저 TileMap의 크기를 정한다.
// unordered map 사용시 중간에 map의 크기를 키울 수 있다. 확장에 용이.
// 
// 사용할 이미지와 실질적으로 render되는 크기가 다르므로
// SetTileSetting()의 _Tilesize와 _Imagesize 변수를 따로 받는다.
// 
// Tile의 자전은 무시
// 
// 타일이 옆으로 움직이는것은 필요 없으니 plusUVValue는 제거
// 
// ImtextureID 가서 보면 __int64다.
// ImGui::ImageButton
// 
// ImGui::SameLine 
// 줄바꿈을 안 하게.../n을 사용하지 않는 것과 같다.
// 
// (스크롤바도 넣을 수 있다. ImGui::ScrollBar) 
// (좌표가 음수면 이상하게 찍힌다.
//  코드 보강을 하던가...)
// 
// 

// USceneComponent는 추상 클래스다.
// 

// 하나의 코드에 몰아넣지 않을 수 있는게 객체지향의 장점
// 현재 GM2DX의 TitleGameMode.ccp와 같은 상태는 바람직하지 않다.
 

// 
// 
// 
// 
// 
