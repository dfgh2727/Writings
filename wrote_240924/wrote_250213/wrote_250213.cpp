﻿// wrote_250213.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// gitignore는 그것이 위치한 곳에서 기능한다.
// (하위 폴더는 영향이 미치지 않는다.)
// 
// GameInstance
// Level과 무관하게 엔진 하나당 반드시 존재하는 클래스, static과 유사한 느낌의 구조
// 
// 언리얼에서 항목제한을 걸었기 때문에 추가 포함 디렉터리를 바로 설정할 수 없다.
// Build.cs에서 작성해야 설정 가능하다.
// 모듈의 경로를 추가하자.
// PublicIncludePaths.Add(ModuleDirectory);
// 이전 프로젝트들에서 '추가 포함 디렉토리'에 '../(혹은 ..\)'을 입력한 것과 같다.
// 
// 클래스 삭제를 원하면 비주얼 스튜디오에서 삭제, 탐색기에서 파일들을 직접 삭제한 뒤
// 언리얼에서 툴 - visualstudio 새로고침을 눌러줘야 한다.
// 혹은 파일 삭제후 UProject에서 우클릭으로 generateProfile을 누른다.
// ...여차저차 위 과정에서 문제가 생기면 필수 파일 제외하고 모두 삭제한 뒤 UProject를 다시 빌드하자.
// 
// 

// 
// 
// 
// 
// 
