﻿// wrote_241213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// virtual ... = 0;
// instance가 될 일이 없다.(객체화 안 함)
// 엔진코어는 추상 클래스가 된다.
// 
// API에서는 싱글톤을 썼지만 DX에서는 쓰지 않을것이다.
// 선생님 취향이 아니기에...;;

// 무조건 윈도우 창이 하나라도 띄워져 있어야 루프가 돌아간다.
// while ( 0 != WindowCount)
// {
//     
// }
// 
// EngineStart에서 HINSTANCE를 받아서 EngineWindow가 쓴다.
// UEngineWindow...Create와 Open이 따로 있는 상태. 
// 그대로 진행한다.
// WindowHandel이 nullptr이 아니라면 return. 윈도우 창을 여러개 띄우지 않는다.
// 
// 

// (이번 기회에 람다를 익히자... )
// 101_Lamda
// 
// 일종의 즉석함수다.
// return값은 return~로 명시. 
// 
// !주의사항!
// 람다캡쳐는 대부분 복사다. 
// 람다캡쳐에 메모리 영역을 넣으면 그것을 복사해서 자신만의 영역을 만든다.
// 
// 지역변수는 함수가 실행종료되면 파괴되므로 
// 외부에 존재하는 메모리들을 가져다 써야함을 명시하는 것이 람다캡쳐의 의미
// 
// [=]?
// 이름이 같을지라도 별개의 지역변수가 생긴다.
// 
// [&]는 레퍼런스로 넘기기 때문에 같은 지역변수가 생긴것이다.
// 그러나 함수가 종료되어도 람다로 인해 지역변수가 살아남으니 위험하다.
// 
// 일반 함수포인터는 bind하기 어렵다.
// 전역함수만 써야 한다.
// function은 인자와 리턴값만 맞춰주면 된다.
// 람다는 전역함수인지 아닌지 따지지 않는다. 
// 


// 결합성 (객체지향)
// 
// 다른 클래스에 대한 의존도를 말한다.
// 의존도가 높을 수록 결합성이 높은 클래스라고 한다.
// 결합성이 낮을 수록 좋다.

// IContentsCore 
// 인터페이스, 어떤 함수를 구현해야하는지 알려주는 정도의 구조
// 객체와 되지 않는다.
// UContentsCore가 상속받는다.( = 엔진이 제공하는 인터페이스 상속받음)
// 
// void UContentsCore::EngineStart()에서 윈도우 창의 크기를 설정했다.
// mainwindow를 건들 수 없게끔 만들되 위치와 크기만 조절할 수 있게 만든 것.
// 
// UEngineCore::EngineStart()에서 상대경로를 사용해 dll을 로드한다.
// 직접 dll 이름을 넣어야 한다.
// 
// CreateContentsCoreDefine(UContentsCore); 
// (...GetProcAddress를 한번은 해야 한다.)
// 
// ContentsCore를 만드는 함수의 이름은 CreateContentsCore로 정해졌다
// 
// ...결국 EngineCore와 ContentsCore를 분리시킨거다.
// 컨텐츠 부분을 동적 로딩하기 위한 구조. (중간에 수정하기 용이하게)
// -> 따라서 컨텐츠 dll 경로가 필요하다. 
// 
// Core는 Shared_ptr을 통해 관리되니 nullptr로 만들면 소멸자 호출된다.
// 
//
