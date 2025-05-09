﻿// wrote_250318 T.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>



// TObjectPtr
// 에디터에서 기본적으로 레퍼런스 카운트로 관리되고 있음을 명시한다.
// 즉, TObjectPtr에 해당하는 주소는 레퍼런스 카운트 1을 보장한다.
// 이 경우 사용자의 의도와 상관없이 메모리가 살아있거나 삭제될 수 있다.
// 단, TObjectPtr<타입>은 UFUNCTION()이 붙은 함수에서 사용 불가능하다.
// 
// 언리얼은 TObjectPtr을 사용하길 권장하므로 
// 위 사항을 유의하면서 최대한 멤버변수에 TObjectPtr을 사용하자.
// 
// AActor* = LowPtr(원시 포인터)
// TObjectPtr<AActor> = TObjectPtr로 관리
// 
// UProperty를 붙인 포인터 변수는 언리얼이 자동적으로 에디터 환경에서 TObjectPtr로 바꾼다.


// 머티리얼
// 
// 언리얼에서 랜더링을 위한 최소 단위다.
// 
// (1) 머티리얼 도메인:
// 서페이스 순서가 실제 랜더링에 가장 많이 사용되는 순서다.
// DX로 생각하면 도메인 하나당 카메라가 하나라고 볼 수 있다.
// 
// Surface
// 메쉬를 그리는 단계
// 
// Differed Decal
// 어떤 메쉬위에 다른 메쉬를 덧씌운다.
// (벽 무늬 메쉬에 총알 자국 메쉬를 덧씌운다.)
// 
// Light Function
// 빛을 비춰서 음영을 나타낸다.
// 
// Volume
// 포스트 프로세싱 전에 영역을 정한다.
// 포스트 프로세싱을 위한 메쉬가 필요한데 이것을 volume mesh라고 한다.
// 
// Post Processing
// 지정된 영역에 효과를 적용한다.
// 
// User Interface
// UI다.
// 
// (2) 블렌드 모드:
// 
// Opaque
// 알파 블렌드다.
// 
// (3) 셰이딩 모델:
// 
// default lit
// 기본적인 빛 적용

