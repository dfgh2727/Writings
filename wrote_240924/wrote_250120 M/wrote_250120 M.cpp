﻿// wrote_250120 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 프로그래머들...의외로 기술을 안 좋아한다?
// 이유없이 기술을 적용하는 것을 그다지 선호하지 않는다.
// 효율이 떨어지니까...
 
// UEngineCore::GetThreadPool().WorkQueue(FiiePath()[
// 스프라이트...텍스처가 로딩되어야 만들 수 있다.
// 그러나 쓰레드에 텍스처 로딩을 맡기면 미처 로딩이 되기 전에 내려올 수 있다.
// 따라서 스프라이트를 만드는 단계의 위치를 바꾼다.
// 
// bool LoadingEnd를 int LoadingCount로 바꿨다.

// 인스턴싱
// 셋팅이 같은 것 n개를 한번에 drawcall로 그린다.
// (상수버퍼, 텍스처, 템플러 모두 같아야 한다.)
// 
// 그러나 엔진의 material 기반으로 셋팅이 된다고 해도 transform 세팅이 같을 수 없다.
// 위치는 모두 다르니까.
// 따라서 n개의 이미지를 그리면 n개의 트랜스폼을 넣어줘야 한다.
// 그리고 인스텅신 되는 쉐이더들은 내부에서 자신이 몇번째로 그려지는지 알게 해야 한다.
// 
// ScreenOut... 창의 바깥에 있어서 렌더가 안 되는 부분
// 드로우 콜,
// 드로우 계열 함수
// 
// 상수버퍼는 용량제한이 있다.
// StructuredBuffer<Transform> ... 텍스처 기반의 대용량 버퍼
// 
// 
// 
// 
