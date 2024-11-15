// wrote_241115.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
}

// 코드 공유
// 
// 헤더와 lib(dll)을 공유하는 경우
// lib코드는 빌드된 결과물...
// lib만 들고 있다고 프로그램을 실행할 수는 없다.
// 헤더가 필요하다. 
// 
// Mysql의 경우
// 상대경로에 dll, lib만 공개
// = 앱에서 뜯어가렴

// C++ 헤더의 정식 명칭은 .hpp (header plus plus)

// 사운드 라이브러리?
// 
// FMOD
// 멀티플랫폼 사운드 라이브러리
// FMOD 로고를 표기하면 상업용으로도 사용 가능
// 
// C스타일의 전역함수를 호출하면 되는데
// 클래스로 랩핑한 것 뿐이므로... .h를 쓴다.
// 
// 사운드를 EnginePlatform에 넣어준다.
// FMOD도 초기화가 필요하다.


// i) dll과 lib로 분류해서 배포하는 경우
// ii) lib를 배포하는데 그 안에 dll과 연결하는 코드를 넣어서 배포하는 경우
//     (즉 pragma comment하면 자동으로 실행된다. lib를 include함.)
// 
// i)과 ii)를 구분하는 방법...용량을 본다.
// ii)의 경우 lib를 삭제하면 dll을 쓸 수 없다.
// FMOD는 ii)의 경우.
// 
// GitHub를 쓰는 경우 문제가 생길 수 있다.
// dll은 ignore 된다.
// (dll와 lib는 커밋 대상이 아니다.)
// 따라서 dll과 lib를 프로그램 안에 넣고 '무시한 파일 추가' 누르기.


// FMOD...사운드 포맷 왠만한건 다 된다.
// 
// 리소스 사용시 경로를 알아야 한다.
//
// UEngineSound : public UEngineResources
// (UEngineResources : public UObject)
// 사운드 관리자가 사운드에 대한 모든 기능을 관리한다.
// 
// 싱글톤을 좋아하지 않는 선생님...
// 그냥 자료구조를 static 한다.
// 
// static void Load()
// 이름과 경로를 넣어서 쓴다.
// 
// 명시해서 지운다. 
// static void Release()
// 
// FMOD는 최신코드...
// 따로 바꿔줄 필요는 없지만 만약 안된다면 UTF-8로 인코딩해서 넣어보자.
// 
// bool ResLoad()
// 리소스 로드 성공여부...bool값으로 리턴
// 
// 사운드를 쓸려면 무조건 초기화를 해야하므로...
// FMOD::System* SoundSystem = nullptr (핸들)
// 
// 결과물들은 FMOD가 내부에 enum으로 넣어놨다.
// 
// FMOD는 사운드 카드에 직접 접근한다.
// 에러 나는 경우는 거의 없지만 나는 경우... 사운드 카드 문제일 수 있다.
// 
// 레벨이 삭제 된 후 사운드를 제거해준다. 
// 직접 new를 선언했다면 leak가 없게끔 로드가 끝나면 release(delete)를 한다.
// (메모리를 직접 삭제)
// 
// error와 log를 구분할 줄 알아야 한다.
// 디버그 모드로 실행하면 FMOD에 벌어지는 일을 출력창에 띄워준다. 이를 log라고 한다.

// FMOD_Loop_NORMAL 지정된 루프 횟수만큼 재생

// class USoundPlayer
// 
// 채널이 재생 권한을 가지고 있다. 채널을 통해 속력이나 피치, 볼륨 등을 조절할 수 있다.
// FMOD::Channel* Ch = nullptr;
// 
// UEngineSound::Find로 포인터를 찾는다.
//
// USoundPlayer는 값형복사를 할거야!
// 안에 포인터 하나밖에 없으니까...
//
 
// 동시재생을 하고 싶다면 FMOD도 system 업데이트를 해줘야 한다. 
// Tick을 돌리듯이.
// void UEngineSound::Update()
