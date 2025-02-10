﻿// wrote_250210 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (저번주에 이어서...)
// 
// 클라이언트가 패킷을 보관하고 싶다면?
// UUserAccessPacket Packet 
// 지역변수로 만들면 보관할 수 없으니
// std::shared_ptr<UUserAccessPacket> Packet = std::make_shared<UUserAccessPacket>();
// 위와 같이 동적으로 할당한다.


// 오브젝트 토큰은 서버만 부여할 수 있다. 클라는 안 된다.
// 
//    A (서버)              B (클라)
//  _____________         _____________
// |   [플(1)]   |  ---  |   ...[플(1)]|
// |_____________|       |_____________|
//        |
//        |
//  _____________ 
// |   [플(1)]   |  
// |_____________|
//     C (클라) 
// :오브젝트 토큰 == 1인 플레이어가 B 컴퓨터에서 움직였다.
// 
// 서버 베이스의 경우
// 클라이언트 B에서 플레이어가 움직이면 서버인 A에게 전달되고, 
// A가 그 데이터를 다른 클라이언트에게 전달한다.
// 
// 오브젝트 토큰이 겹칠 수 없도록
// if(AllNetObject.contains(ObjectToken))
// {
//		MSG_ASSERT("오브젝트 토큰이 겹친다.");
// }
// 
// 동기화가 필요없는 오브젝트는 NetObejct를 상속시키지 않는다.
// 오브젝트가 조금이라도 복잡해지만 동기화 시키지 않는다.
// (가령 시체라던가.)
// 게임에서 영향력을 발휘하지 않는 오브젝트들은 동기화를 멈춘다.
//
// 서버를 만들기 전 오브젝트들의 토큰은 음수, 
// 서버에 접속된 후 토큰의 값이 0이상이 되고 서버에 의해 클라이언트의 오브젝트 토큰값은 동기화 된다.
// (여담으로 클라의 접속 실패 후 과정도 클라이언트가 개발해야 한다.)

// Queue
// : FIFO(first in first out) 자료구조. 선입선출.
//   list로 완전히 대체 가능하다.
//   서버는 일(패킷)이 쌓일 때 먼저 쌓인 것을 처리하는 방식을 주로 사용한다.

// 패킷은 메인 프레임에서 처리한다. (전체 프레임 사이에서 처리)
// (가령 렌더링 중에 오브젝트를 삭제를 할 수 없으니...)
// 
// 하나의 패킷이 여러 쓰레드를 거쳐서 처리된다.
// _Net->SetUserAccessFunction()
// {
//	
// }
// 위 내용이 실행되는 부분이 UEngineNet에서 곧바로 처리되는 게 아니라
// main 스레드로 이동시켜 처리되어야 한다.
// 
// 언리얼은 게임모드에서 네트워크 관리를 한다.

// 디스페처
// 패킷이 들어오면 어떻게 처리할지 구분한다.
// 
// 패킷 종류마다 std::map을 만들 수 없으므로...
// 템플릿으로 만들자.
// 
// template<typename PacketType>
// void AddHandler(int _Type, std::function<>_callback)
// 따라서 어떤 타입의 패킷이든 받을 수 있다.

// TCP이기 때문에 데이터를 일부만 받을 수도 있다.
// 프로토콜에 의하면 16까지 받아야 데이터를 처리할 수 있으므로
// 16바이트 보다 작으면 continue.
// 
// if(16 > Ser.GetWriteOffSet())
// {
//		continue;
// }
// (반대로 UDP는 데이터를 한번에 받으므로 버퍼의 크기는 받을 데이터 크기 이상이어야 한다.)
// 
// 다시 TCP로 돌아와서...
// 패킷의 총 데이터 크기가 버퍼보다 클 경우 
// 패킷을 처리하고 버퍼에서 그 만큼 데이터를 밀어낸다.
// 
// int TempPacketSize = Ser.SeekData<int>(4);
// 프로토콜에 의해 패킷 중 앞에 있는 패킷 타입, 패킷 크기, 세션 토큰, ...등을 읽어낸다.
// 그리고 이전에 읽은 패킷의 크기를 고려해 오프셋 관련 함수를 만든다.
// 
void UEngineSerializer::ReadOffsetRemain()
{
	//가령           32바이트 중   4바이트 만큼 읽었다.
	int RemainSize = WriteOffset - ReadOffset;
	memcpy_s(&Data[0], RemainSize, &Data[ReadOffset], );
}
//       ______________ _____________________________
// 버퍼:    읽은 패킷      앞으로 읽어야 할 패킷
//       |_____________|_____________________________|  
//                     ^
//           (WriteOffSet의 위치)
// 그리고 다시 데이터는 WriteOffset 위치 부터 읽는다.
//

// 직접 움직여야 할 캐릭터와 서버폰의 입력 분리를 위해 언리얼에서는 컨트롤러가 처리한다.
// 게임모드, 컨트롤러... 모두 네트워크 때문에 생긴 개념이다.
// 
// 현재 프로젝트에 컨트롤러가 없으므로 다음과 같이 처리한다.
// void NetObject::SetControl();
// {
//		IsControlValue = false;
// }
// 
// if(true == IsControl()) ...IsControlValue가 true일 때 입력을 받는다.
// {
//		움직임 입력 
// }
// 
// NetObject가 없으면 만들어버린다. 
// (서버에 동기화 될 존재가 없으면 만든다.)
// 
//

