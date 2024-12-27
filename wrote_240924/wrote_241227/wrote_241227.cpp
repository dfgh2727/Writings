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
// 
// 
// 
