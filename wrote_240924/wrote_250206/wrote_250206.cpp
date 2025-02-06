﻿// wrote_250206.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (어제에 이어서)
// 서버에 대해서 좀 더 알아보자.
// 
// closesocket() 통신이 종료된다.
// 
// recv()의 return값은 int. 나에게 도착한 바이트 수다.
// 이때 return값이 -1이면 통신이 끊긴것이다.
// 
// (참고로 실제 서버라면 비동기 리시브까지 해야 한다.
// WSARecv를 사용해서 콜백 기반으로 처리할 수도 있다. 
// IOCP를 사용하는 것이 좋다. RIO라는 기술도 있다.)
// 
// ping 
// : (ping pong에서 유래) 
//   UDP 패킷을 이용해서 상대에세 지속적으로 패킷을 보내는 행위.
//   상대는 나에게 지속적으로 응답을 해줘야 한다.
// 가령 비정상적인 방법으로 컴퓨터가 종료됐을 때 상대방에게 종료된 사실이 전달되지 않을 수도 있다.
// 즉, 서버에 접속된 상태로 남아있을 수도 있다. 따라서 접속 여부를 확인하기 위해 작은 크기의 패킷을 지속적으로 보낸다.
// 이 때 보낸 ping에 대해 응답이 없으면 접속하지 않은 상태임을 확인할 수 있다.
// 
// 서버는 종료 leak을 신경쓰지 않는다.
// 아예 종료했다가 재부팅 하는 경우가 많다. 컴퓨터의 시작 프로그램에 아예 서버를 박아 놓는다.
// 잘 만든 서버의 경우 재부팅 해도 유저들의 정보를 유지시키기도 한다.
// (물론 play할 시 발생하는 leak은 다른 얘기다.)
// 
// 여차저차 서버만 생각한다면 그래픽스와 무관해진다. 리소스가 필요 없으니까.
// 그래픽 카드가 필요없기 때문에 CPU의 성능이 곧 서버의 성능이었다.
// 리눅스가 개조하기 쉬운 OS라서 한 때 리눅스 서버가 유행했다.
// 
// 리슨서버, 코옵서버
// 게임도 실행시키면서(그래픽) 서버역할도 한다.
// 코옵 게임이 해당된다. (4~5명의 소수인원이 플레이 하는 경우)
// 인디겜의 경우가 많다.
// 
// 네이티브 서버
// C++ 네이티브로 만든 서버. 그래픽을 무시하고 오로지 서버만 실행시킨다.
// 
// 데디케이트 서버
// 
// 서버는 멀티 프로세스와 멀티 스레드를 잘 해야 한다.
// 많은 유저들을 접속시키기 위해서 하나의 고성능 컴퓨터보다 적당한 성능의 컴퓨터 여러대가 적합하다.
// 하나의 메인 스레드에서 오브젝트 5000개가 돌아가는 엔진보다
// 1000개가 돌아가는 프로그램 5개를 돌리는 것이 프레임 수가 더 높다.
// 따라서 온라인 게임에서 채널형식이 유행하고 있다. (컴퓨터 한 대에 n 개의 채널을 관리하는 플레이서버를 운영)
// 
// 유동 IP
// 컴퓨터를 껐다 켜면 IP가 바뀐다.
// 반대로 게임 서버의 경우는 IP가 고정되어 있는데 
// 고정 IP를 사용하는 경우 통신사에 요금을 지불해야 한다.
// 
// 서버 통신
// 호출하는 함수(listen)는 같지만 방식이 다양하다.
// 게임서버는 지속적으로 상대의 서버 접속여부를 확인한다.
// 
// 도메인 서버(웹서버)
// 웹서버 도메인 = 도메인 서버 주소다.
// 도메인 서버는 웹페이지 주소를 IP 주소로 만든다.
// 한때 다양한 프로토콜이 있었지만 현재 HTTP 프로토콜이 표준으로 남았다.
// (https로 시작하는 프로토콜. /기준으로 분해해서 주소를 읽어낸다.)
// 
// 여차저차 모두 http 프로토콜을 사용하니
// 웹서버를 만들기 위한 언어도 생겼다. node.js(C언어 기반), 스프링 등등의 프레임워크들이 나왔다.
// 
// 웹서버는 실시간 온라인 게임을 만들기 힘든 통신방식이다.
// 홈페이지를 주고 받는 것을 기본으로 하기 때문이다. 
// (게임과 달리 연결을 계속 유지하지 않는다. 통신 확인 후 끊는다.)
// 따라서 웹서버 게임은 실시간이 아니거나 pvp가 없다.
// 
// 예전에 안드로이드는 통신이 불안정했다. (핸드폰 게임)
// 핸드폰을 계속 이동하면서 플레이 하는데 
// 기지국이 바뀌면(통신 연결 회선이 바뀌면) ip가 바뀌기 때문이다.
// 이 점을 파악해서 실시간으로 통신하지 않고 클라이언트가 게임을 다 돌린다.
//  
// 브라우저는 일종의 접속 프로그램이다.
// 웹서버에서 전송된 패킷을 화면에 표시해준다.
// 
// 멀티스레드 서버 ... 접속자 1명당 쓰레드 하나를 만든다.
// (구조가 명확하다 보니 ASIO 같은게 생겼다. ASIO, boost의 서버를 만들고, 쓰레드 관리가 쉬운 라이브러리.)

// 다시 OSI계층, TCP/IP 프로토콜을 살펴보면
// HTTP, DNS, 각종 게임 회사의 프로토콜 등은 응용 계층임을 알 수 있다.
// 세션계층, 표현 계층, 응용계층은 유저가 조절할 수 있는 부분이다.

// TCP/UDP
// 
// TCP
// :연결 지향형
//  하나의 socket에서 send를 하면 상대에게 무조건 도달한다.
//  그리고 전송된 패킷 순서가 바뀌지 않는다.
//  설령 늦게 보낸것을 먼저 받아도 보여주지 않는다. (recv()에서 return되지 않는다.)
//  연속으로 전송해도 먼저 보낸 패킷을 받은 것을 확인하고 다음 패킷을 보낸다.
// 
//  먼저 패킷을 보낼 때 SYN 전송, 상대가 SYN을 받으면 SYN과 ACK를 보낸다. 그리고 패킷을 보낸측이 SYN과 ACK를 받으면 
//  다시 ACK를 보낸다.(실패하면 다시 보낸다.헤더에 TTL이 있다. TTL, 실패 횟수를 기록한다.)
//  위 방식을 3-way HandShake라고 한다. 종료시엔 4-way HandShake를 한다.
// 
//  보낸 전체 패킷중에 일부만 받을 수도 있다. 나머지는 이어서 받는다.
//  
// 
// UDP
// :비연결 지향형
//  서버라는 개념이 따로 없다. 연결을 지속하지 않기 때문에 누구든 자유롭게 보낸다.
//  별도의 확인 없이 패킷을 전송하고 바로 받는다.
//  recv()할 때 주소는 필요 없다.("0.0.0.0")
//  listen()도 필요 없다.
//  sendto()를 통해 버퍼에서 바로 전송한다.
//  
//  패킷을 못 받을 수도 있다. 가령 크기가 매우 큰 패킷을 보낼 때 TCP는 분할해서 받는 반면
//  UDP는 받는 데 실패한다.
//  통신 프로토콜과 OS, 기지국 등등이 분할해서 전송한다. 이렇게 분할하는 것을 데이터 프레임이라 한다.
//  분할해서 전송하는 것은 TCP, UDP 모두 같다. 단, UDP는 중간에 전송 실패한 프레임이 있으면 중단하고 
//  기존에 받은 것도 무시한다. UDP 분할해서 받는다는 개념이 없다.
//  UDP는 순서도 무시한다. 어떤 패킷이 언제 도착할지 모른다.
//  (Reliable UDP라도 TCP보다 못하다.)
// 
//  그러나 헤더가 작기 때문에 속도가 빠르다.
// 
// 대부분의 게임사는 TCP와 UDP 모두 사용한다. 보통 금전과 관련된 서버는 TCP 기반이다.
// 이동, 스킬 사용 등은 UDP를 기반으로 한다고 한다.
// 빠르다는 장점 때문에 플레이 서버를 UDP로 만들기도 한다.
// 
// 서버와 클라이언트가 1대1로 연결되어 있지 않다. 
// 다수의 서버와 다수의 클라이언트가 서로 연결되어 있다.

// 서버 베이스 구조
// 
// 가장 일반적인 구조.
// 받은 패킷을 보낸 사람을 제외한 모든 사람들에게 패킷을 보내야 한다. (채팅에 대해 생각해보라)
// send()를 위해서 SOCKET이 필요하다. 그리고 모두의 SOCKET을 아는 것은 서버다.
// 
// 세션(연결)관리 ... 클래스 등을 만들어서 SOCKET을 관리한다.