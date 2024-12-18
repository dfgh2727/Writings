// wrote_241218.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// 다렉...
// 
// GetHigherPerformanceAdapter()
// ...더 큰 video memory 선택 (RAM이 더 큰 그래픽 카드 선택)
// MaxVideoMemory값이 작은 그래픽 카드는 Release();
// (단위는 바이트)
// 
// ResultAdapter = 성능이 가장 좋은 그래픽 카드
// 
// D3DCreateDevice()
// ******************* 인자 의미 **********************
// 
// D3D_DRIVER_TYPE_HARDWARE 컴퓨터가 자동적으로 그래픽 카드를 찾는다.
// D3D_DRIVER_TYPE_UNKNOWN 유저가 직접 그래픽 카드를 선택한다.
// D3D_DRIVER_TYPE_SOFTWARE 그래픽 카드를 사용하지 않는다. 연산을 CPU에게 맡긴다.
// 
// 
// ****************************************************
// 
// int iFlag = 0; 특별한 옵션 없이 사용
//           = D3D  
// 
// DEBUG ...비트로 옵션 선택
// 
// D3D_FEATURE_LEVEL = 다렉의 레벨 지정 (다렉11인가, 다렉9인가...)
// (Window OS가 제공하는 옵션 안에서 사용할 것이므로 D3DCreateDevice()의 인자는 nullptr)
// 
// D3D11_SDK_VERSION  현재 다렉의 sdk 버전
// 
// 
// 
