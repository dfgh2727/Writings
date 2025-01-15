// wrote_250115.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (...폰트캐싱)
// UTF-8 인코딩
// 
// UniCodeToUTF8()
// 멀티바이트를 UTF8로 변환한다.
// 먼저 size를 확인해야 한다.
// ...알 수 없는 텍스트라고 나올 것이다.
// 
// AnsiToUTF8()
// 
// 서버의 경우 변환(conversion)이 매우 중요하다.
// 
// FW1FontWrapper
// Wrapper가 직접 mesh를 만들어서 Geometry shader로 글자를 띄워주는데...렌더링 과정중 blend에 문제가 있는듯. (렌더링 파이프를 다시 확인해보자.)
// FontWrapper는 빌드 대상이 아니다!
//
// 언리얼이나 유니티는 글자 모양 그대로 mesh를 만들어버린다;; (Rich Text Block)
// 
// 라이브러리...릴리즈와 디버그는 코드가 다르다.
// 빌드는 릴리즈가 더 빠르다.그래서 언리얼은 릴리즈된 것으로만 빌드한다.
// 웬만하면 릴리즈와 디버그 같이 빌드하는 것이 좋다. 
// 
// 로드할 때 필요한건? 핸들
// 
// Factory를 먼저 만들어야 한다.
// 
// 코드가 유니코드로 짜여있기 때문에 유니코드로 변환해줘야 한다.
// 출력할 수 있는것도 wstring뿐이다.
// 
// CreateFontWrapper()
// 
// Font 파일을 열어서 이름(글꼴이름)을 확인해야 한다.
// 
// geometry shader는 필수이므로 셋팅만 한다.
// 
// Font를 Widget을 상속받게 만들려고 했다가...
// widget에 있는 설정을 만들어 줄 필요가 없으니 (FontWrapper가 다 가지고 있다.)
// Widget을 FontWidget과 ImageWidget로 나누고 FontWidget을 상속받게 한다.
// 

// shared_ptr도 순환참조를 조심해야 한다.
// (일반적으로 이런 경우에는 weak_ptr을 사용했을 것이다.)
// 따라서 구조를 파악하고 생각하면서 shared_ptr을 사용해야 한다. 
