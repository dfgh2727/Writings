﻿// wrote_250218.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 데이터 테이블
// 
// 데이터 테이블이 특정 레벨에 속해 있으면
// 해당 레벨이 플레이 되는 동안만 데이터 테이블을 사용할 수 있다.
// 다른 레벨이 실행될 때 사용할 수 없다.
// 따라서 레벨을 가지는 월드와 별개로 게임 인스턴스(Game Instance)를 만든다.
// 게임 인스턴스가 데이터 테이블을 가진다.
// 
// 플레이어가 어떤 레벨에서 가진 값을 다른 레벨에서 그대로 적용할 수 없다.
// 데이터는 레벨에 복붙되어 적용되는 것과 같다.
// 어떤 레벨에서 가진 값을 다음 레벨에도 적용시키고 싶다면 
// 퍼시스턴트 레벨(persistent level)이라는 별도의 레벨을 만들어야 한다.
// 
// 데이터 테이블을 여러개를 가진다면...
// 데이터 테이블들을 모아놓은 상위 데이터 테이블을 만들 수도 있다.
// 
// 선생님은 관리의 편의성을 위해서
// 게임 인스턴스의 생성자에 상위 데이터 테이블의 경로를 입력시켜 놓는다.
// (블루 프린트에서 셋팅하지 않는다.)
// 그리고 상위 데이터 테이블을 로드하면 전체 데이터 테이블을 로드한 것과 같다.
// 
// FindRow<>(, 두번째 인자는 사용하지 않을 것이니 nullptr을 입력하자)
// 
// 
//

// 선생님의 경우 Actor를 spawn하는 경우 C++로 한다.
// 훨씬 빠르다.

// 데이터 테이블 사용시 에러가 발생했을 때 로그를 띄우는 방법
// UE_LOG(로그 카테고리, 출력 옵션, TEXT);
// (로그 출력 옵션들: Error, Warning, Fatal...)
// 
// 모듈 메인 헤더에 다음과 같이 만들고
// DECLARE_LOG_CATEGORY_EXTERN(카데고리, 로그 용도, 로그 표시 제한);
// 메인 cpp에 다음과 같이 쓴다.
// 
// 보통 로그에서 함수명과 라인 수를 알고 싶으니 다음과 같이 가변인자를 사용한다.
// UE_LOG(로그 카테고리, 출력 옵션, TEXT("%S(%u)> 어쩌구"), __FUNCTION__,__LINE__)
// 
// 출력 로그에서 검색창을 통해 원하는 키워드로 로그를 찾을 수 있다.
// 


// EOS (네트워크 플러그인)... 
// 언리얼은 네트워크를 기본으로 하기 때문에 접속된 상태가 아니면 자꾸 로그를 띄운다.
// 큰 문제는 아니다.

// 언리얼에서 헤더중에 generated가 제일 아래에 있어야 한다. 

// 언리얼 구버전의 경우 Integration tool을 직접 설치했었다.


// 언리얼에서 사용하는 문자열
// 
// FString
// std::string과 유사하다
//
//
// 
// 
// 
// 
// 
