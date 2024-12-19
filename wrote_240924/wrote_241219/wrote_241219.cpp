// wrote_241219.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// (...렌더링 파이프라인)
// 
// void URenderer::InputAssembler1Setting()
// { 
//     UINT Offset = 0;
//     버텍스 버퍼가 여러개일 때 n번째부터 셋팅한다.
//     보통 0이다.
// 
//     점을 셋팅하자.
//     UEngineCore::
// }
// 
// Input Layout
// EngineVertex의 데이터들....(FVector Color, FVector Pos 등)
// 그래픽 카드는 정보의 위치를 알 수 없다. 알려줘야 한다.
// VertexShader가 필요하다.
// 
// VertexShader
// 행렬을 통해 Vertex를 변형시킨 것.
// HLSL(인터프리터 언어)로 직접 짜야 한다.


// EngineShader
// (빌드 안 한다!)
// 
// Vertex에 World행렬 처리를 한다.
// CPU에서 for문을 돌려가서 실행할 것을 그래픽 카드에 맡기는 것.
// (InputAssembler를 통해 Vertex(점)를 만들고 VertexShader에 전달한다.)
// Shader에 만든 함수는 거의 대부분 최대한의 쓰레드 효율로 동시에 실행된다.
// 
// Shader는 C++이 아닌 HLSL로 쳐야 한다.
// 
// 먼저 텍스트 파일을 만든다.
// (일반적으로 .fx, .hlsl, .hlsli을 쓴다.)
// (...생각해보면 .h와 .cpp도 기본적으로 텍스트 파일이다.)
// 
// struct EngineVertex
// {
//     float4 COLOR : COLOR;   ...뒤에 붙인걸 시맨틱(semantic)이라고 한다.
//     float4 POSITION : POSITION;
// };
// 
// 버텍스 쉐이더는 다음 단계(InputAssembler2)로 넘길 return값이 반드시 있어야 한다.
// 
// struct VertexShaderOutput
// {
//     float4 SVPOSITION : SV_POSITION;
//     float4 COLOR : COLOR;
// };
// 
// void VertexToWorld(EngineVertex _Vertex)
// {
// 
// 
// }
// 
// (VertexShader5.0을 사용한다.)
// 
// #ifdef _DEBUG
// Flag0 = D3D10_SHADER_DEBUG;
// 다렉11이더라도 디버그는 10이다. 따로 바뀌지 않은 듯 하다.
// 
// #endif
// Flag0 |= D3DCOMPILE_PACK_MATRIX_ROW_MAJOR;
// 행렬을 집어 넣는다. 근데 전치행렬(Transpose)로 넣음.
// 따라서 뒤집지 않게 설정을 해준다.
// 
// ID3DBlob.ShaderCodeBlob
// ID3DBlob.ErrorCodeBlob
// 
// Blob 중간 결과물...(주석 삭제, 공백 제거 등)
// 
// 중간 빌드가 실패한다면 에러 메시지 창이 뜬다.
// 
// 

// HLSL을 VisualStudio가 인식하길 원한다면...확장관리에서 서포터를 설치하자.

// ComPtr
// Ref 카운팅을 기반으로 Release를 자동으로 해준다.
// nullptr 처리만 해주면 된다.
//

// 헤더 파일을 객체로 만들 수 있다.
// (BigSizeShader)
// 
// #ifdef... 어딘가에 '...'가 정의되어 있다면 실행됨
// #elseif '...'을 안 쓰는 경우 실행됨
// 
// 위의 방식으로 외부에 조건을 정의하면
// 조건에 따라 설정을 활성화하거나 비활성화 시킨다.
