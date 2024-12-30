// wrote_241230.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 주인공 APawn 상속받기
// 
// 요즘은 index size를 4바이트로 주로 쓴다.
// 
// ccw 컬모드?

// 블렌드
// alpha값에 대한 오해
// 
// 0이면 렌더가 안 된다 (X)
// -> 무조건 렌더된다.
// 
// 1보다 작은 값이면 배경의 색과 섞인다(X)
// -> 옵션을 설정해야 한다. 
// 
// 다렉은 어떤 픽셀에 다른 픽셀이 
// 

// 
// FF = 255
// UINT Mask = 0x00FFFF; (16진수)
//             R G B alpha
//
//
// 알파 블렌드...엔진마다 함수 이름이 다르다.
// Transparent~라는 함수도 있다.
// (단 ColorBlend를 다른 Blend와 혼동해선 안 된다.)

// 한가지 셋팅을 다수의 RenderTarget에 적용할 수 있다.
// D3D11_COLOR_WRITE_ENABLE_ALL
//
// 알베도 컬러 (Albedo Color), RGB와 alpha값을 말한다.
// D3D11_Blend_OP_ADD = SourceFactor와 DestFactor를 더한다.
// src_alpha = 소스컬러의 알파값을 사용한다.
// INV_SRC_ALPHA = 소스컬러의 알파값의 반전 (= 1 - 소스알파값)
// 
// 위와 같이 셋팅하면
// 텍스처 중에 알파값이 0인 부분은 소스컬러는 
// 언리얼은 material에서 blend셋팅을 한다.
//