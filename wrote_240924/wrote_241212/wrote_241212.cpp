﻿// wrote_241212.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (프레임 워크 만들기, 어제에 이어서... )
// 
// 확인할 수 없는 외부기호( = cpp의 내용을 모른다)
// 
// 1. 함수 선언만하고 구현 안 함
// 2. lib나 dll을 사용하겠다고 선언하지 않음
// 3. 프로젝트 참조하기로 했으나 참조 안 함
//    (lib의 경우 pragma comment를 쓰지 않는다던가)
// 
// 왜 발생할까?
// 

// dll?
// 
// dll은 lib에 비해 사용하기 까다롭지만 한번만 로드된다는 장점이 있다.
// lib는 사용되는 곳마다 로딩된다. 따라서 중복되어 메모리를 낭비하기 쉽다.
// 
// lib가 dll보다 용량이 훨씬 작다면 
// 보통 dll의 모든 내용을 가진게 아니라 다른 무언가를 통해 내용을 쓸 수 있게끔 만들어진 경우가 많다.
//
// dll은 프로젝트와 개별적으로 존재한다. 즉 분리된 다른 코드 영역에 존재한다.
// 따라서 잘 설계하면 중간에 코드를 바꿀 수 있다는 장점이 있다.
// (파일 실행중에, 그리고 디버깅 중에 코드 내용을 변경해서 바로 적용할 수 있다.)
// 
// 게임 엔진 대부분은 dll을 사용한다.
//

// dll을 로드하는 방법을 알아보자.
// 
// 1. 동적 로딩
// 2. 정적 로딩
// 
// 위 둘은 메모리적으로 차이가 있다.
// 
// 동적 로딩
// : LoadLibrary() 함수를 통해 로딩한다. (함수가 실행될 때 로드된다.)
//   직접 경로를 찾아서 (...경로...).dll을 로드한다.
//   
//   dll은 외부 코드 영역에 존재하니 그 위치를 알 방법이 필요하다.
//   윈도우가 핸들을 통해 포인터로 그 위치를 전달해준다.
//   
//   조금 더 편리하게 쓰기 위해...
//   dll의 함수에 virtual을 선언하면 컴파일러가 자동으로 가상함수 테이블에서 dll의 함수(부모)를 호출해준다.
//   (virtual 선언시 자식이 만들어질 때 부모가 호출된다.)
//   쓰는 함수에만 virtual을 선언하고 사용하지 않는 함수는 선언하지 않는다.
//   
//   언리얼에서는 아예 동적 로딩을 관리하는 'MODULE'이 있다.
// 
// 정적 로딩
// : 파일로써 로딩한다.
// 
//   dll로 로딩하고 싶은 클래스의 함수에 __declspec(dllexport)쓰기 -> dll을 로드할 수 있는 lib 생성
//   (언리얼에선 define ENGINEAPI __declspec(dllexport)가 쓰여있다.)
//   그리고 pragma comment(lib, "~.h")를 쓴다.
//   (프로그램이 시작될 때 로드된다.)
// 
//   
// 
// 