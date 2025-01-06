// wrote_241104.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

//오전에는 타일맵 수업 진행. 
//해당되지 않아 듣지 않았다.

// 이번주
// 수학, collision, sound까지 한다.
// (UI는 따로 만들지 않는다.)

// (API)
// (EngineBase...Math)
// UEngineRandom
// 
// 랜덤은 seed를 기반으로 만들어진다.
// but 모든 경우가 seed가 동일하진 않다. 각각 다른 seed를 적용하는 경우가 있다.
// 
// std랜덤은 generator를 시작으로 한다.
// 난수를 뽑는 인터페이스는 같지만 알고리즘만 다를뿐 (메르헨 트위스터, well512...) 
// (d20 Random dungeon generator를 검색해보자)
// 
// int RandomInt()
// Min에서 Max값 까지의 int형 난수를 뽑는다.
// float이면 실수...
// 
// !주의!
// UEngineRandom
// seed를 for문 안에서 돌리지 말기!

// Actor를 없애면 그 안의 Renderer도 삭제되어야 하는데...
// 둘을 분리해서 관리중이니 삭제하기 까다롭다.
// 
// *********** Release *************
// 
// 언리얼을 베끼자

bool IsActive()
{

}

 bool IsDestroy ()
{
     return IsDestroyValue;
}
 
 bool IsDestroyValue (float _Time)
 {
     DeathTime = _Time;  // 지정된 시간 뒤에 죽게 한다.
     IsDestroyValue = true;
 }

// list를 도는 중에 제거되는게 아니라
// 마지막으로 돌면서 지우게끔 만든다.
// 
//  사실 삭제나 멈추는 개념은 다양하지만...
//  헷갈리니 SetActive 하나만 만들겠다. 
// 
 bool setActive(bool _IsActive)
 {
     IsTickable = _IsActive;  // 모든 기능을 정지한다. 내부에선 해제 불가. 외부에서 해제해야 한다.
  
 }
// 
// 
// CurActor -> LevelChangeStart();
// 레벨을 이동하고 돌아오면 리셋된다. 
// 
// Actor가 꺼지면 Renderer도 꺼지게 만든다.
 bool IsActive() override
 {

 }
// 
//  순서, Tick이 돌고 Render가 돈 다음 Release가 돈다.
// 
//  부모(Actor)가 사라지면 자식(Renderer)도 사라진다.
// 
//  참고로 Renderer는 지울 필요 없다.
//  지울 권한은 Actor에 있기 때문
//  (Level은 Actor로부터 Renderer를 잠깐 가져올 뿐이다)
// 
//  component가 파괴되지 않았다면 (== false)
//  iterator가 돌고
//  파괴되었다면 erase
// 
//  시간 지나면 죽는 기능 
//  float CurDeathTime = 
// 
//  virtual void 
// 
//  바로 삭제되지 않게 DeathTime이 0보다 크면 삭제 가능
//

// 템플릿은 빌드 순서가 아예 다르다.
// 
//  컨텐츠 어딘가에 FVector를 만들어 놓는다?
//