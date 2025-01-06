// wrote_250106.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 이번 프로젝트 엔진에서는 stencil을 사용하지 않는다. 
// 대체 가능한 다른 기능들이 많기 때문이다.
// 
// SRV(shader resource view)
// 
// ClearDepthStencilView(깊이 버퍼, 지우는 방법, DSV 초기화 값, Stencil 초기화 값)
// 
// RTV와 DSV를 합친 개념을 랜더타겟이라고 한다.
// 랜더타겟을 다수로 사용하면 멀티랜더타겟이라고 한다.
// 
// 깊이를 다룰때 Depth값이 작은 것을 우선으로 렌더한다...사실 이것도 설정값이다.
// Context->OMSetDepthStencilState();
// (OM, Output Merger 최종적으로 값을 적용시킨다.)
// BlenderState와 유사한 함수다.
// 
// Desc는 만들때 반드시 초기화하기.
// 
// (깊이 값을 비교하는걸 테스트만 하고 적용하지 않을수 있다 = D3D11_DEPTH_WRITE_MASK_ZERO)
// Desc.DepthFunc = D3D11_COMPARISON_LESS;
// 깊이 값이 더 작으면 통과.
// (LESSEQUAL일 경우 실수값의 오차로 인해 깜빡임이 발생할 수 있다. (여러 색깔이 동시에 적용되는 경우))
// Desc. StencilEnable = false;
// Stencil값은 무시한다.
// 
// Depth값을 사용하지 않는 경우를 위해 (UI)
// Shared_Ptr로 사용하자.
// 
// 앞에 위치한 텍스처의 투명한 부분때문에 뒤에 있는 텍스처가 가려진다면
// Z sorting을 사용하자.
// (3D에서는 alpha값을 잘 안 쓰기 때문에 딱히 고려할 필요가 없다.)
// 
// SetZSort(int _Order, bool _Value)
// order가 아닌 Z값으로 분류한다.
// (Renderer를 list로 관리하니 sorting이 가능하다.) 
// 
// 단, 렌더러의 z값이 완전히 동일한 경우(완전히 겹쳐져있는 경우), 다툼현상이 발생하는 것은 어쩔 수 없다.

// SetTexture()는 AutoScale 사용 여부를 bool값으로 설정해야 한다.
// AutoScale사용시 비율을 float으로 넣어주자.

// 복사 생성자, 기본 생성자? 
// 
// 템플릿 가변인자를 통해 생성자의 무작위 패턴에 대응할 수 있게 만들어져 있다.
// 그러나 선생님은 안 좋아하기 때문에 안 씀.

// TimeEvent를 Actor와 따로 있게 만들었다.
// UpdateEvent와 EndEvent를 따로 만들었다.
// 
// 부모의 Tick을 돌려줘야 실행된다는 것을 명심!

// 이미지를 정 가운데에 위치시키고 y값을 반전시킨다. 
// 