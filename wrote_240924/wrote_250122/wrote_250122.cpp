﻿// wrote_250122.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (빛 어제에 이어서...)
// 
// 빛을 만드는 연산 3종류
// 
// 1) 디렉션 라이트 (태양) <- 수업에서 다루는건 이것
// 
// 2) 포인트 라이트 (전구와 같이 일정 범위만 밝아진다.)
// 
// 3) 스팟 라이트 (손전등)
// 
// 
// 빛을 코딩으로 옮기게 되면 다렉에서 2가지 방법이 있다.
// (빛 자체를 코드로 쳐서 만든다.)
// 
// 쉐이더가 2가지.
// 버텍스 쉐이더 ->1) 면 플랫 쉐이딩 (주로 고전 게임에서 보이는 스타일) 
//                 2) 점 고로 라이트 쉐이딩
// 픽셀 쉐이더 -> 픽셀 퐁 라이트 쉐이딩 (phong shading)
// 이제 퐁을 제외하고 잘 쓰지 않는다.
// 
// 언리얼에서 빛은 컴포넌트.
// Light Component를 만들어보자.
// 
// 람베르트 조명 공식을 떠올려보자.
// N (법선 벡터) 내적 L(빛의 반대 방향 벡터)
// (빛도 SceneComponent... 즉 transform을 가지고 있다.)
// 
// 빛을 받는 면이 빨간색이면 (1.0f, 0.0f, 0.0f, 1.0f)
// (1.0f, 0.0f, 0.0f, 1.0f) + 빛의 강도
// 
// 빛을 계산할 때 카메라의 위치도 필요하다.
// specular light의 경우 조명의 위치도 필요하다.
// 
// light는 순서(order)가 없다.
// 빛의 최종 결과물은 모든 빛의 연산결과를 합한다.
// 
// view... 세상을 -1~1의 값으로 압축한 상태.
// 여기에서 빛을 계산하면 오차가 커질 수 있다.
// 따라서 world * view 에서 계산한다.
// 
// 사실 쉐이더에서 world * view 연산을 시키는 것 보다
// worldview (float4x4 wv)를 따로 만드는 게 훨씬 낫다.
// 한 픽셀마다 world * view 연산을 하면 매우 느려지니까.
// 
// directional light는 위치가 의미 없다.
// 엄청나게 강한 빛이 매우 먼 거리에 있다. 따라서 오차를 무시한다.
// 
// 게임에서 보통 main directional light은 하나다.
// 
// 어딘가에 light data가 있다면...
// 미리 resize로 정해놓고 연산을 해 둔 상태.
// push_back, 대입 연산이 없다.
// 빠르지만 직관적이지 않다.
// 다른 방식으로 진행한다.

