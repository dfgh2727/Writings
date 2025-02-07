﻿// wrote_250207.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// (...어제에 이어서 GM2DX에 네트워크 기능 구현)
// 패킷을 위주로 개발할 예정.
// 
// StartUp은 한번만 실행하면 되니까
// if(true == NetInit)
// {
//     StartUp을 이미 실행한 상태면 다시 실행 안 함
// }

// crtl + Alt + P ->실행시킨 프로그램에 한해서 연결을 하면 동시에 디버깅이 가능하다. 

// 토큰, 일종의 권한이다. 
// 클라와 연결된 서버 둘만이 알고 있는 값이다. 사용자를 식별하는데 사용한다.
// 연결이 끊어지면 토큰은 의미가 없어진다. 재접속할 때 마다 새로운 토큰을 발급한다.
// 특히 UDP 같은 경우 소켓이 없기 때문에 토큰으로 사용자를 구분한다.
// 모바일의 경우 기지국이 계속 바뀌므로 토큰으로 재접속자를 확인한다.
// 동일한 토큰을 가진 유저가 2명 이상이면 튕기기도 한다.

// 제이슨(JSON), XML
// string을 parsing으로 파악한다.
// 직접 눈으로 봐도 어떤 데이터인지 파악하기 쉬운 언어다.
// 구글은 XML을 채택했다.
// 
// 그러나 게임의 경우 위와 같은 언어는 쓰지 않는다.
// 패킷 용량이 매우 크기 때문에 비효율적이다.

