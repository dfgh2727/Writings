﻿// wrote_250212.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// (언리얼)
// 
// 모듈
// 일련의 코드들을 묶어서 모듈이라 한다.
// 언리얼에서 코드량을 줄이기 위해 모듈을 dll로 만들어 동적로딩으로 사용한다.
// 
// 언리얼에서 모르는 단어를 보면 unreal document로 찾아보자.
// 이 때 Reference를 확인해야 한다.
// 
// Source - Build.cs
// 모듈을 로드하지 않으면 그 모듈.h를 사용하는 모듈들도 무시된다.
// (헤더 오류 혹은 외부기호 참조 오류 발생)
// 
// PublicDependencyModuleNames()
// 언리얼이 설정을 통해 lib를 추가해서 빌드시킨다.
// 
// (프로젝트명).h 즉, 모듈 main 파일을 확인해보면 파일이 모듈로서 작동하게 만드는 코드를 확인할 수 있다.
// IMPLEMENTARY_GAME_MODULE()
// 
// 마이그레이션이 잘 안 될 경우 (프로젝트명).Target.cs를 수정해야 할 때도 있다.


// 새삼스럽지만 언리얼 엔진의 오브젝트 구조는 다음과 같다
// 
//   __________(Level)__________
//  |                           | 
//  |     _____(Actor)_____     | 
//  |    |                 |    | 
//  |    |   (Component)   |    | 
//  |    |_________________|    | 
//  |___________________________| 
//

// 비주얼 스튜디오에서 프로그램을 중지시키지 말고
// 언리얼을 정상적으로 종료시켜야 한다.
// 안 그러면 언리얼에서 설정한 값들이 날아갈 수 있다.
// 
// 탐색기에서 편집하기 보다 언리얼에서 수정해야 한다.
// 언리얼에서 인식하지 못하는 문제가 발생할 수도 있다.
