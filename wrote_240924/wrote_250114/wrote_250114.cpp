//wrote_250114.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// UI (어제에 이어서)
// 
// 이제 widget은 Actor와 별개다.
// HUD를 통해서 CreateWidget()이 가능하다.
// CreateLevel<모드, 폰, HUD>()로 level을 만들때 HUD를 만들거나
// 따로 contents에서 AHUD를 상속받는 HUD를 만들거나.
// 언리얼과 다르게 이번 프로젝트에서 GetWorld()->GetHUD()를 통해 가져올 수 있게 만들었다.
// 그러나 권장사항은 후자다.
// (언리얼에서는 HUD를 가져오는 방법이 따로 있다.)
// 
// 언리얼에서 모드, 폰, HUD 순서로 만들어진다.
// 
// CreateWidget()
// 생선되기 전에 이미 값이 셋팅되어 있는 구조
// Widget은 무조건 HUD가 셋팅되어 있다.
// 
// Widget은 Z값 없이 그려지는 순서로 보인다.
// 
// Renderer에 비해서 widget은 기능이 많지 않다.
// 필요한 기능이 있다면 요청하기...
// 
// widget이 render되기 위해서 

// 반복적으로 사용하는 상수들은 따로 모아놓자.
// 
// TransformObject != nullptr라면 기하구조를 가지고 있을것이다.
// 
// Primitive Component
// USceneComponent등...
// 
// UI Depth
// rendering 순서 = _ZOrder
// DepthBuffer를 아예 없애버린다.
// 

// 폰트캐싱
// (내일 계속)
