// wrote_241220.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// Renderer는 UScenecomponent
// 결과적으로 UScenecomponent가 가진 FTransform 값을 그래픽 카드에 전달시키는 과정이다.

// 픽셀 쉐이더 보간(interpolation)
// 
// 픽셀 쉐이더는 픽셀마다 실행되고 있다.
// Color와 같은 값을 넣으면 픽셀 쉐이더가 자동적으로 값을 계산해 
// 다른 픽셀들의 값을 보간한다.
// 
// SVPOSITION 뷰포츠 행렬이 곱해지는 포지션
// -> 결과적으로 윈도우 좌표계가 적용된다.
//
// NEWPOSITION 원래 값


// FTransform::TransformUpdate()
// vertex를 FTransform의 값대로 변형시키는 함수
// 
// SIMD 연산... x, y, z를 동시에 처리한다.
// 전용 자료형이 있다. 
// XMVECTOR, XMMATRIX
// 
// 위치, 크기, 회전...
// 이 중 하나만 변형 되어도 바로 World 행렬을 만들어서 적용시킨다.

// View와 Projection은 Renderer가 아닌 Camera 담당.
// 
// Camera는 어디에 있어야 할까.
// Camera는 모든 단계중 최종적으로 실행되게 만든다.
// 
// 개념은 '카메라가 포착하기 때문에 Renderer가 보인다.'에 가깝다.
// 이젠 Renderer를 실행시키는게 아니라 Camera들을 실행시킨다.
// 
// UEngineCamera
// 카메라가 바라보는 Renderer들을 관리한다.
// 
// 0번 카메라(main camera)는 기본적으로 만들어진다.
// 
// 
// Camera는 Tick을 돌리긴 하지만 Actor는 아니다. UScenenComponent를 상속 받는다.
// Render전에 Tick을 돌린다. 
// view와 Projection
// 
// CameraActor
// EngineCamera를 Component로 가진다.
// CameraActor를 통해 Camera를 실행시킨다. 


// 게임모드에서...
// 반드시 카메라의 위치를 정해줘야 한다.
// 
// URenderer::Render()
// {
//     Renderer는 Camera로부터 view와 projection을 받아 계산한다.
// }

// 상수버퍼
// 
// CPU에서 값을 쉐이더에 전달하기 위해서 쓴다.
// 크기 제한이 있다. 
//
// cbuffer FTransform : register(b0)  - 슬롯의 위치
// 
// 쉐이더마다 버퍼가 따로 정해져있다.
// 
// void URenderer::ShaderResSetting()
// {
//     D3D11_MAPPED_SUBRESOURCE =  
//      
//     어떤 데이터를 사용하는 렌더링을 잠깐 정지시킨다.
//     그래픽 카드를 멈춰서 그래픽 카드의 있는 상수버퍼를 수정한다.
//     UEngineCore::Device.GetContext()->Map(..., &Data);
// 
//     그리고 다 쓴 다음에는 반드시 Unmap 해야한다.
// 
// }
//

// 텍스처
// 쉐이더의 리소스를 만들려면 쉐이더 리소스 뷰(=셋팅할 권한)가 필요하다. 
// 
// DirectX::CreateShaderResourceView()
// 내부에서 동적할당이 일어나고 있다.
// 만드는 과정이므로 Device를 이용해야 한다.
// 
// TexMetadata 몇비트인가?
// 
// ...여차저차 이미지 띄웠다.
//
