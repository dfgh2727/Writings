// wrote_241223 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//*** (그래픽스...펄어비스를 제외하고 잘 안물어봄) ***

// 2D에선 방향과 무관하게 Culling을 none으로 설정하는 경우가 많다.
// (D3D_CULL_NONE)
// 
// LoadFromWICFile()...DirectTex 라이브러리에서 가져와서 사용.
// (원래 PNG,JPG도 버전이 있고 읽는 방법이 다르므로... 직접 이미지 파일을 가져오는것은 힘들다.)

// UV (Text Coord) Space
// 텍스처를 맵핑시키기 위한 공간
// 도형을 이루는 점에 비율을 적용한다.
// 
// Input Assembler를 확인해보면 UV 값을 직접 입력한 것을 볼 수 있다.
// (CPU 초기 데이터)
// InputLayout은 UV값(데이터)의 위치를 나타낸다.
// 
// 전체 이미지를 1x1로 취급하고 
// 도형과 겹치는 픽셀을 0~1의 값으로 계산한다.
// 
// D3D11_FILTER_MIN_MAG_MIP_POINT
// POINT는 최단입점 (정수배로만 확대)
// LINEAR는 주변 값들을 적용하여 보간한다. (이미지 내부의 색깔들이 부드럽게 섞이는 것을 볼 수 있다.)
// https://quasarzone.com/bbs/qc_plan/views/27938
// 
// 렌더링은 메쉬의 한계를 벗어날 수 없다.
// 즉, 선택된 픽셀이 아니면 그려질 수 없다.
// 

// float4 PixelToWorld()
// {
//     ImageTexture.Load(); 샘플러의 영향 없이(보간 없이) 픽셀의 색상 값을 가져온다.
// }
// 
// SampInfo.AddressU = D3D11_TEXTURE_ADDRESS_MODE::D3D11_TEXTURE_ADDRESS_CLAMP;
// CLMAP, 이미지의 테두리를 고려하지 않고 렌더한다.
// (AddressU = x, AddressV = y, AddressW = z)
// 
// address 모드
// : UV값이 0보다 작거나 1보다 클 때 어떻게 처리할 것인가...
// - Wrap
// - Mirror 선대칭으로 범위 밖의 칸을 채운다. 칸마다 대칭시킨다.
//   (Mirror_Once는 0~1의 범위만 고려한다.)
// - Border 0~1사이만 고려한다. 나머지는 설정된 값으로 채운다. (BorderColor로 설정할 수 있다.)
// - Clamp 0~1밖의 값은 삭제한다.
// 
// SampleInfo.ComparisonFunc = D3D11_Comparison_NEVER;
// 다렉은 샘플링할 때 이미지를 자동으로 최적화를 한다. 이 때 이미지가 뭉개진다.
// Never = 최적화를 사용하지 않는다. 처리 속력이 증가할 수 있다.
// 
// SampleInfo.MaxLod  Lod최대범위
// SampleInfo.MinLod  Lod최소범위
// Lod...z값이 멀어지면 어느 정도로 색을 가져올 것인가.

// Image Loading...MipMap
// 이미지 크기가 실제와 다르게 로드된다?
// 자동 최적화 옵션이 켜져있다. 이미지의 수치가 애매하면 2의 제곱값에 크기를 맞춰서 로드한다. 
// (2의 제곱값일때 처리 속도가 빠르다. 연산 최적화 - MIN_MAG_MIP)
// 
// NEVER = 이미지에 어떤 변형도 가하지 않는다. 
// 
// 아틀라스...
// 밉맵을 고려해서 이미지를 모아놓은 것
//
// Material
// 샘플링이나 쉐이더 설정 값이 같은 것들을 모아서 사용

// 템플릿은 static이라도 헤더에서 초기화 가능하다.


// 텍스처 부분과 렌더러 부분을 분리시켰다.
// 대신에 shred_ptr로 Texture를 쓰게 만들었다. 


// dll에 있어서 static의 문제점
// 
// ResMap... Find할 때와 Load 할 때가 서로 다른 값??
// 
// dll파일과 연결된 다른 파일에서 자체적으로 static을 인식한다.
// 즉, contents가 core에 존재하는 static을 읽을 때 새로운 static을 만든다. 
// 2개의 static 메모리가 생긴 것과 같다.
// 
// allocator 자료구조에서 메모리 할당할 때 방식을 정한다.
// allocator를 통해 해결할 수 있으나 고려해야 할 사항이 많아 복잡하다.
//