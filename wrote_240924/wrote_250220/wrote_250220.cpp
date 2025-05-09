﻿// wrote_250220.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

 
// UI 모드
// 
// 언리얼의 UI모드는 3가지다.
// 입력을 처리하는 부분이 데이터를 pawn 또는 UI로 보내는지에 따라 달라진다.
// 
// 1. Game Only : 주인공을 조작하는데 집중한다. 아무것도 설정하지 않으면 이 모드로 시작한다.
// 2. UI Only   : UI 선택에 집중한다.
// 3. Game And UI
// 
// 컨트롤러가 UI 모드 전환 권한을 가지고 있다.
// 컨트롤러는 단순히 플레이어를 움직이는 용도가 아닌
// 전반적인 입력에 대하여 제어하는 중간 클래스다.
// 따라서 Title UI(대부분 UI Only) 같은 곳에서도 컨트롤러는 만드는 것이 좋다.
// 
// 블루 프린트에서 this는 self다.
// 블루프린트에서 클래스에 대한 인자는 값형을 안 쓴다. 반드시 포인터로 사용한다.
// 반대로 struct는 값형만 된다.
// 
// UI모드에서 컨트롤러의 ptr을 요구한다.
// 그러나 ptr을 넣어주지 않아도 터지진 않는다. 경고가 뜬다.
// 
// show mouse ... 마우스 커서를 표시한다.
// 
// 계층구조에서 위에 있는 것 부터 렌더된다.
// 드래그로 순서를 바꿔주거나
// 디테일 - 슬롯 - 정렬에서 Z순서에 값을 입력해 순서를 바꾸면 된다.
// 
// 편집 가능 텍스트를 디테일 - 변수 여부를 체크해서 변수로 만들어주자.
// 
// 에디터에서 만든 기능이 대략 어떤 함수인지 알겠다면...
// 비주얼 스튜디오에서 직접 코드를 확인해서 어떤 함수들을 가졌는지 확인하고
// 블루 프린트에서 직접 검색을 통해 사용할 수 있다.
// 
// 블루 프린트에 있는 값을 C++로 받아보자.
// C++로 변수를 선언한다. 그 다음 디테일을 확인하면 링크 아이콘을 볼 수 있다.
// 링크를 통해 변수를 연결할 수 있다.
// 디테일 - 이벤트에서 
// 
// 게임모드에서 아무것도 넣지 않으면 디폴트 폰이 생긴다.
// 
// UI모드는 레벨마다 초기화되지 않는다.
// 
// 언리얼 아이콘을 더블클릭해서 언리얼 에디터를 열면
// Development editor mode로 빌드한다.
// 비주얼 스튜디오에서 Debug editor mode로 빌드하는 것과 달리.
// 
// 포커싱 설정, 여러개의 위젯이 있을 때 선택된(포커싱 된) 위젯에 신호가 전달된다.

// struct
// class와 차이점은 기본 접근 제한 지정자.
// 즉, struct도 virtual, override 등등 모든게 가능하다.

// 디테일에서 옵션을 만지는데 아무것도 보이지 않으면 엔진 컨텐츠 표시 했는지 확인!

// C++에서 만들어진 컴포넌트는 에디터에서 삭제할 수 없다.
// 컴포넌트에서 오른쪽에 'C++에서 편집'옵션이 있는지 확인해보자.

// pawn 만들기
// 
//  상속구조:     Actor     -      Pawn        -      Character
// (가지는 기능)              (동기화, 입력)    (충돌, 물리, 애니메이션)
// 
// 
// Arrow Component: x축, 양의 방향을 가리키고 있다. '앞'이 어디인지 알려준다. 에디터 전용이다.
// 
// 에디터 전용 코드들은 
// #if WITH_EDITOR
// #if WITH_EDITORONLY_DATA 를 입력하지 않으면 빌드가 안 된거나 터진다.
// 
// 카메라 매니저
// 언리얼은 레벨이 시작되면 무조건 카메라 매니저를 만든다.
// 만들어진 카메라 매니저는 캐릭터에 아무런 설정이 없으면 기본적으로 앞을 향하게 카메라를 배치한다.
// (폰을 조사하고 그 폰에 카메라를 붙여준다.)
// 뷰포트에서 카메라 위치를 조작할 수 있다.
// 
// 카메라가 붙지 않길 원한다면 ... 2가지 컴포넌트를 기억하자.
// 카메라 컴포넌트, 스프링암(SpringArm)
// 
// SpringArm
// 캡슐 컴포넌트 아래에 위치해야 한다.
// 무언가를 기준으로 위치를 가지게끔 만드는 컴포넌트다.
// 캐릭터에 SpringArm 추가 후, 카메라를 달고 카메라의 위치를 초기화 하자.
// 그러면 캐릭터에서 카메라가 분리되지 않은 상태로 카메라의 위치나 각도 등을 조절할 수 있다.

// 네트워크
// 
// 회사 면접에서 클라이언트라도 네트워크에 대해 약간은 물어본다.
// 
// '...'에 넷모드를 눌러보면 네트워크 옵션이 있다.
// 
// 
//
//
