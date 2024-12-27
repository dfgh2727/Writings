// wrote_241227.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// static선언시 데이터 영역에 존재... main 종료 뒤 삭제
// leak 확인은 stack 까지만 가능하므로 static 선언된 경우는 정상적으로 삭제되어도
// leak으로 판단되어 보고될 수 있다. 

// ImGUI관련 에러는 messageloop 문제였음.
// break 처리함

// 언리얼에서 SetActorLocation()을 쓰는 이유...
// Actor는 무조건 Root이므로 월드와 로컬의 구분이 없다.

// 컨텐츠는 직접 짜야한다.
// 새로운 shader를 만들어서 Renderer로 렌더하기

// RenderUnit
// 렌더링의 최소단위
// Renderer가 여러개의 RenderUnit을 가지는 구조를 만든다.


// 106_Static
// 
// 헤더에 전역변수 선언? 안된다.
// extern혹은 static을 선언해야 한다.
// 
// 근데 dll의 경우 static을 선언하면 메모리영역이 전부 따로 생기므로 주의해야 한다.
// 해결방법은 다음과 같이 생각해 볼 수 있다.
// 
// 1. static 선언한 멤버변수를 private처리하고 접근을 위한 함수 만들기
// 
// 2. 전역변수로 만들기(cpp선언)

// 쉐이더는 형태, material은 색을 담당
// 
// 점과 관련된 요소들... 매쉬
// 색상과 관련된 셋팅... material
// 
// map, 다렉을 통해서 그래픽 카드를 정지시킨다
// 
// 기성엔진들은 같은 셋팅을 가진 renderer들 끼리 모아놓는다. 
// (드로우콜을 줄이기 위해서)
// 
// 유니티의 albedo... 상수버퍼와 같다
// 
// 왜 Renderer가 생길 때 마다 상수 버퍼를 만든걸까?
// map, unmap 횟수를 줄이기 위해서.
// 만약 모든 Renderer가 하나의 상수 버퍼를 쓴다면
// 한 Renderer의 색상 설정을 바꿀때마다 map, unmap해야 한다.
// (기존의 material 설정 후 변경된 material 설정을 해야 한다.)
// 
// 아틀라스...텍스처를 여러번 로딩하지 않게 만든다.
// 메모리 부담을 덜 수 있다.
//
