﻿// wrote_250221.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// ***함수를 사용할 때 에디터에서만 사용 가능한지 항상 확인하자***

// FModuleManager
// 언리얼에 있는 모듈들을 관리해주는 struct
// 일일히 경로를 쳐서 레벨에 들어가게 만들기엔 번거로우니까.
// 
// IsLoadingAssets()
// bool 값을 리턴한다. true면 에셋을 로딩중이다.

// 언리얼 입력
// 
// pawn
// 기본적으로 활동하는 몬스터나 주인공에 상속시키는 클래스.
// 보통 Movement 컴포넌트를 붙여준다. 이 때 키 입력을 통해 이동 및 회전등이 자동 동기화 된다.
// 
// 구버전에서는 입력에 따라 함수(포인터)를 직접 지정해야 했다.
// 요즘 버전은 행동(액션)에 키의 입력이 연결되어 있고, 키의 입력이 함수포인터와 연결되어 있다.
// 그리고 행동 - 키입력 - 함수포인터가 하나의 세트로 묶여있다. 
// 
// 입력 액션을 살펴보자.
// 

// 자기 자신이 controller가 아니라면 cast를 통해서 controller를 쓸 수 있다.
// IA_Look...
//
//