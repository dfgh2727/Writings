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
// 
//
