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
// ScInfo.SampleDesc.Quality = 0    퀄리티는 필료없다. 
// ScInfo.SampleDesc.Count = 1      점을 한개로
// 
// ScInfo.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD
// 백버퍼가 여러개 있을 때 순서는 지정하지 않고 준비가 빠른 순으로
// 
// ScInfo.Flag
// 선생님은 신경도 안 씀. 궁금하면 검색해보라.
//


// 핸들을 주는 인터페이스...왜 release 해야할까?
// 
// 결론적으로 지우지 않으면 leak이 발생한다.
// 
// void CreateDevice(Device** _Device)
// {
//     (*_Device) = new Device();
// }
// 
// 동적할당이므로 안 하면 leak 발생.
//

// 샘플링
// 
// 어떤 해상도의 모니터에 도형을 놓는다고 생각해보자.
// 그 도형에 닿은 픽셀의 색깔을 지정하는 것을 말한다.
// 이때 픽셀이 도형에 닿은 정도로 색의 농도를 지정한다.
// 
// 도형이 픽셀의 샘플링 체크점과 많이 닿을수록 농도가 진하다.
// 
// 원하는 스타일에 따라 샘플링의 정도를 조절해야 한다.
// (가령 도트겜은 샘플링을 사용하기엔 부적절하다.)
// 
// 렌더링 파이프라인 연관 키워드
// : mxaa, fxaa, anti-aliasing, pixel shader


// CreateSwapChain()
// 무언가를 만든다...Device에서 불러온다.
// Device가 생성된 뒤에 실행되어야 한다.
// 
// SwapChain도 leak 발생을 막기 위해 Release();
// 
// SwapChain은 일종의 HDC라고 할 수 있다.
// HDC는 bitmap에 대한 수정권한.
// (bitmap은 색의 배열들... FColor Arr[100][100];)
// 
// 다렉의 bitmap은 id3d11texture2d*
// SwapChain내부에 id3d11texture2d*가 있다.
// id3d11texture2d* 자체로는 할 수 있는것이 많지 않다.
// 수정 권한을 얻어야 한다.
// 
// ID3D11RenderTargetvView* RTV
// 
// SwapChain안의 Texture가 백버퍼다.
// Texture의 수정권한을 만들어야 한다.
// 
//          winAPI로 생각하면...       HBITMAP                   HDC
// Device->CreateRenderTargetView(DXBackBufferTexture, nullptr, &RTV)
// 
// 렌더링하기 전에 백버퍼를 채운다.
// 리소스를 만드는게 아니라 그리는 것이므로 Context를 통해서.
// 
// RenderStart();
// {
//    Context->ClearRenderTargetView(RTV, ClearColrer.Arr1D) 
//    화면을 파란색으로 채워보자.
// }
// 
// 
// RenderEnd();
// {
//     HRESULT Result = SwapChain->Present(0, 0);
//     내가 지정한 hwnd에 다렉 렌더링 결과를 출력해라.
// }
// 
// 그리고 ULevel::Render()를 실행시키면
// 파란 화면이 뜬다. 

// HDC를 직접 쓴 적은 없다. WinAPI에서는 EngineWinImage를 통해 관리했다.
// 이번 DX도 마찬가지...관리하는 클래스를 만든다...언젠가

// 렌더링 파이프라인
// 
// 렌더링 관련 함수는 최종적으로 Draw어쩌구()를 제외하고 순서 의미 없다.
// 
// URenderer::BeginPlay()
// {
//     IASetVetexBuffer()   버텍스 버퍼 셋팅 (input assembler)
//     RSSetState()         레스터라이저 셋팅
//     .
//     .
//     .
//     위 함수들...순서 의미 없다. 일종의 옵션처럼.
//     최종적으로 Draw()가 실행된다는 것만 고정.
// 
//     렌더러가 몇개인가 = DrawCall 횟수
// }
// 
// 만들어지는 리소스는 전부 그래픽카드에 저장된다.
// 
// 렌더링 파이프라인...일부는 필수고 나머지는 선택적이다.
// (필수) Input Assembler1⋅2, Vertex, 레스터라이저, Pixel, OutputManager
// (선택사항) Hull Shader, ..., Geometry Shader 
// 

// Input Assembler
//
// 결론적으로, Input Assembler1은 점을 셋팅하는 단계
// 
// 셋팅되기 위해 만들어진 점을 vertexBuffer라고 한다.
// 점을 최적화하기 위한 IndexBuffer
// 그리고 점의 구성을 알아야 한다.
//