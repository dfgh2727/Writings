﻿// wrote_250227.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// 오브젝트가 움직이지 않는다면 모빌리티 - 무버블로 설정했는지 확인하자.
// 옵션이 static이라면 움직이지 않는다는 뜻이다.
// 따라서 static인 오브젝트 들을 빌트 인 데이터에 같이 저장해 놓는다.
// (빛과 같은 연산들을 미리 계산해놓고 저장한다. 즉, 언리얼을 실행할 때 값이 미리 정해진 상태다.)
// 문제가 발생할 수 있기 때문에 모빌리티 옵션을 바꾸지 않는 편이 좋다.

// ********* 에디터를 만들 때 필요한 것들을 배워보자. *********

// 모듈 만들기 
// 
// 에디터를 만들거나 특정 리소스를 언리얼에 로드 가능하게 만들고 싶을때 한다.
// (언리얼은 메쉬 로드가 까다로운 편이다.)
// 
// 프로젝트명.cpp, 프로젝트명.h, 프로젝트명.build.cs
// 위 세개의 파일이 모듈 생성에 필수다.
// 그리고 모듈의 폴더명과 폴더 내부의 파일들과 이름이 같아야 한다.
// (프로젝트명/프로젝트명.cpp,...)
// 
// 모듈을 사용하길 원하는 프로젝트의 .uproject 파일에 모듈명을 입력한다.
// "Modules" : [
// {
//	"Name":"모듈명",
//	"Type":"어쩌구",
//	"LoadingPhase":"Default",
// 
// },
// ...
// 
// 모듈의 Type이 Editor일 때 출시 버전에서는 삭제된다.
// 따라서 출시 버전으로 빌드하고 런타임 중에 Editor 코드를 치면 터진다.
// 
// 모듈들의 상관관계, 로딩 순서를 고려해 LoadingPhase를 설정해준다.
// Default로 설정할 시 언리얼이 알아서 한다.
// 
// 위와 같이 설정했다면 모듈을 사용할 프로젝트를 다시 빌드한다.
// 그리고 프로젝트에 모듈이 추가된 것을 확인하자.
// 
// 프로젝트와 사용될 모듈 사이의 관계 설정을 확인하자.
// 
// 언리얼을 켜서 C++클래스에 모듈이 있는지 확인하자.
// (모듈 내부에 의미있는 코드가 없을 경우 보이지 않을 수 있다.)
// 
// 모듈 initialize 구조체
// 
// class 프로젝트명_API F프로젝트명Module : public IModuleInterfce
// {
//	public:
//		virtual void StartupModule() override;
//		virtual void ShutdownUpModule() override;
// }

// 본격적으로 에디터 만들기를 배워보자. 
//
// 2가지 변수를 계산을 통해 프로그램에 반영한다면...
// 계산해서 아이템 데이터에 입력해주는 코드는 런타임 코드에 필요 없다.
// 
// #if WITH_EDITOR
// #endif
// 위 코드를 통해 에디터일 때만 빌드되게 입력하자.
// 
// 에디처에서 리소스를 건드리는 일을 하면 Modify()를 호출하여 
// 리소스가 수정되었을음 알려야 한다.
//

// Tag
// Actor나 component에 달아주는 문자열
// 블루프린트에서 디테일에 tag를 검색하거나
// 
//