﻿// wrote_241021 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
   
}

//API란 무엇인가? (ppt)
//:Application Programming Interface
// 
// window API
// window를 사용하는데 도움이 되는 함수 집합
// 
// lib, dll
// 
// 오픈소스는 직접 빌드 가능한 
// API는 결과물 중심으로 공개, 배포된다.
// (요즘 게임들은 엔진 내부 코드를 공개하지 않는다.
//  그래도 궁금한가? 언리얼 코드를 봐라. 유저친화적이지 않지만.)
// 
// 결과 파일들은 아래 4가지.
// .exe, .pdb, .lib, .dll (.h까지 공개하는 경우도 있다.)
// (오픈 소스의 경우 프로젝트를 빌드하면 자연스럽게 결과 파일 생성이 가능)
// 
// .exe  OS에서 동작할 수 있는 실행파일
//      :코드영역을 구성하는 내용과 메모리 구성하는 함수들
//       
// .lib  : .exe 에서 OS에서 실행되는 기능만 제외된 파일
//       cpp 내용이 다 빌드되어 완전히 2진으로 이루어진 상태, 
//       헤더가 필요하다.
//       
//       헤더를 넣어서 빌드하면, 선언만 있고 구현(cpp)이 없다고 뜬다. (확인할 수 없는 외부 참조)
// 
// .exe는 lib를 가진 상태로 나온 결과물, 따라서 lib를 삭제해도 .exe는 실행된다. 
// 즉, 게임 플레이어 입장에서 lib는 필요 없는 파일이다.
// 
// 실제 클라이언트의 경우 엔진의 내용을 알 수 없다.
// (언리얼 같이 오픈소스 엔진이 아닌 경우 제외)
//
// sdk, 개발자용 API? 
// 
// .dll  필요할 때만 연결할 수 있는 빌드 결과 파일
//      : .exe 파일 내부의 함수를 통해 사용해야 실행된다.
//       OS에 로드해서 사용한다. 즉,.exe에 일일히 포함되어야 하는 .lib와 달리 
//       하나만 존재해도 OS를 통해 여러 프로그램에 사용 가능. 
//       (이 때문에 예전에는 lib보다 dll이 선호되었다.)
// 
// .pdb, .idb (기호파일)
//      : 디버깅용 네임맹글링 정보를 기록해 놓은 파일
//        (현재 교육 과정에선 큰 의미가 없다.)
//        번역 과정을 기록해 놓은 파일...lib 보다 용량이 훨씬 크다.
//       
//  
//        
// 

//        
// 
//
