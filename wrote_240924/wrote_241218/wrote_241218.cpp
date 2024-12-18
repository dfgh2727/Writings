﻿// wrote_241218.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
// CoInitializeEx()
// 다렉은 쓰레드 안정성을 보장하지 않는다.
// 
// GraphicDevice의 Release()는 main함수가 끝난 다음에 지워지는데 
// leak 확인은 main 함수까지이므로..
// 명시적으로 EngineEnd()에서 Device와 Context를 지워주겠다.

// CreateBackBuffer()
//
// BackBuffer...크기는 자유자재지만 윈도우창 크기로 만드는게 일반적이다.
// 
// 다렉에서 BackBuffer를 SwapChain이라 부른다.
// 백버퍼의 갱신 속력 = 렌더링 속력
// 다렉은 여러개의 백버퍼를 이용해 일부는 그리고 일부는 지우고 다시 그릴 준비를 한다.
// 
// BufferCount = 사용할 백버퍼 수
// OutputWindow = 윈도우 핸들
// Windowed = true일시 창화면, false면 전체화면
// 9전체화면일시 그래픽 카드의 처리 속력이 증가한다. 게임화면에만 집중할 수 있으니.)
// 
// ScInfo.BufferDesc.RefreshRate.Dominator = 1
// ScInfo.BufferDesc.RefreshRate.Numerator = 60 주사율, 모니터에 얼마나 빠르게 갱신할 것인가.
// 
// ScInfo.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM 
// 백버퍼의 색상범위                      RGBA 8비트씩, 32비트                  
// 
// ScanlineOrdering 
// 화면의 픽셀이 갱신되는 순서를 어떻게 할 것인가
// 위에서부터? 아래에서부터?
// 
// ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED 구분 않고 가장 빠른거로 선택한다.
// 
// ScInfo.BufferDesc.Scaling
// 화면 해상도에 맞춰서 이미지를 어떻게 늘릴것인가
// 
// ScInfo.BufferUsage = 용도 
// 다렉... 이미지를 바이트 덩어리로 생각하고 어떻게 사용할 지 결정한다.
//         
// ScInfo.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT | DXGI_USAGE_SHADER_INPUT;
//                      여기에 그릴 수 있고               쉐이더에서 데이터로도 사용할 수 있다 
//
