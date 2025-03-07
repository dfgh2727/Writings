﻿// wrote_250307.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// (어제는 애니메이션 마무리와 블렌드, 섹션에 대한 수업을 했음. 따로 필기는 안 함. ppt 참고)

// 동기화 문제
// (폴가이즈 프로젝트를 예시로 들어서)
// 
// 1. 서버와 클라이언트 단 둘이 있을 경우:
// 
// 우선 동기화 순서를 살펴보자.
// 
// RPC함수를 통해 서버에서 클라이언트의 설정이 적용되게 만든다.
// 
// 2. 서버와 다수의 클라이언트:
// 
// 클라이언트의 정보를 다른 클라이언트에게 전달해야 한다.
// 즉, 서버가 어떤 클라의 정보를 다른 클라들에게 전달해야 한다.
// 이것을 멀티 캐스트라 한다.

// AI (behavour tree)
// 
// 사실 behavior tree(BT)는 회사에서 잘 안 쓴다.
// 프레임 문제가 있고 기능이 비대해지기 때문이다.
// (보통 FSM을 tick에서 실행시킨다.)
// 
// 애시당초 노드 형태의 트리 구조는 프로그래머가 아닌 사람들을 대상으로 한다.
// 프로그래머들에게 상당히 의미 없다.
// 즉, 언리얼의 스테이트 트리는 잘 안 쓰고 C++로 만든다. 
// 복잡한 노드 형식을 기반으로 만들어도 결국 FSM으로 돌아온다.
// 
// 따라서 BT를 사용해서 게임을 만들면 외려 사용한 이유에 대해 질문 받을 수 있다.
// 
// 
// 
// 
// 
