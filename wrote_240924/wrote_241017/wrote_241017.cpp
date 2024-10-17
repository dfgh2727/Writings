﻿// wrote_241017.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{

}

//인텔리센스(용어정리)
// ! 반드시 파일은 프로그램(VS, 언리얼 등)에서 지운 뒤 삭제하기 !
// 인텔리센스 기록 초기화, .vs 파일 지우기
// 기록이 너무 많이 쌓이면 VS가 코드가 바뀐걸 빠르게 반영 못할수도 있다.

//Shooting (게임)
//
// 여태 게임에서 Vector 쓴 경우를 생각해보면...
// ConsolEngine.h 에서 class AActor*...AActor를 삭제하진 않는다.
// 근데 슈팅게임에서 총알은? 쓴 총알들을 다 알고 있는건 비효율적이다.
// 
// List를 사용하자!
// 
//  에러가 났는데 뭐가 문제인지 잘 모르겠다? 호출 스택을 뒤로 돌려보자
//  배열 0부터인거 잊지말고.
// 
//  지우는 기능은 프로그램에서 노출시키고 싶어하지 않지만 private으로 할 수도 없다.
//  인터페이스를 만든다. (함수로 따로 만든다.)
// 
//  Tick과 렌더링이 돌아가는게 달라질 수 있기 때문에...
//  tick에서 바로 delete하지 않음
//  
//  Destroy(제거와 같은)와 같은 함수는 최대한 마지막에 호출하는게 좋다.
//  이후에 다른 함수는 호출하지 않는게 좋다.
//  return;
// 
//  vector로 사용해서 필요없는 값의 위치를 nullptr로 만드는건
//  직관적이지 못하고 코드를 더 짜야한다. 빠르다고 해도 별로다.
//


//  벡터가 왜 더 빠를까?
// (배열형이 노드형보다 자료 처리가 빠르다)
//
//  CPU의 처리과정에 대해 대략적인 설명을 해보자면
//  캐쉬, 명령이 대기하는 장소
//  힙에서 필요한 데이터와 기타 데이터를 째로 캐쉬에 가져간다.
//  그리고 필요한 데이터의 위치를 알아낸다. 그리고 메모리가 삭제된다.
//  다시 이 과정을 반복...
// 
//  만약 필요한 데이터들이 연속으로 위치한다면 과정이 훨씬 빨라진다. (캐쉬적중률)
//  따라서 배열이 처리 속도가 훨씬 빠르다.
//  그러나 vector를 사용하고 '중간의 값을 삭제'한다면
//  메모리가 분리되고(메모리 단편화) 적중률이 떨어져 속도가 느려진다. (vector에 구멍이 뚫린다고 표현한다.) 
//  (new도 메모리 단편화 발생, 노드가 느린 이유.)
// 
//  vector를 써서 new와 delete를 반복하면 메모리단편화도 일어나지만
//  할당 가능한 메모리 영역을 찾는데 에너지가 소비된다.
//  
//  AActor는 벡터이니까 메모리친화적인가? 아니다. 
//  각각의 데이터 위치를 알 수 없다. (애시당초 new인걸)
// 
//  ****** 결론: 괜히 속도 조금 올린다고 vector 쓰지 말고 가독성이 높은 List를 쓰자. ******
//

// 이미지도 결국 배열데이터 덩어리다.

// 로직을 한번에 다 짜지 말고 중단점 걸고 한번씩 확인해야 한다.

// switch 지역변수 선언 불가

//077_InnerClass
// 
// 사실 밖에 있는 것과 다름 없다.
// private으로 지정해서 공개를 안 할 수 있다는 점만 빼고.
// 
// Inner가 Outter에 속한 개념이라고 표현할 수 있을뿐
// 서로 다른 클래스다.
// 
// iterator 순회자
// 노드는 숨기되 노드가 가진 데이터만 알 수 있게 만듦
//

//078_Friend
// 
// 특정 클래스에게만 private을 public으로 공개.
// private:
//   friend class B;
// 
// 함수 프렌드, 특정 함수에 friend 적용 가능
// 근데 코드 짜기 까다로워짐 (먼저 클래스가 존재한다는걸 알아야 한다던가)
// 그래서 함수 프렌드는 잘 안 쓴다.
// 
// 여차저차 위의 방법으로
// main 함수에만 공개하게끔 만들 수 있다.
//

//List
// 
// 더미 노드를 만드는 방식...
// 임의의 노드 Start와 End을 만들어 준 뒤 그 사이를 연결한다.
// 더미 노드인 start 다음을 Begin 이라고 한다.
// 
// remove
// list 랜덤인덱스 같은게 없으니... 일일이 for문을 돌면서 해당하는 위치를 찾는다.
// 따라서 부담이 큰 함수다. 잘 안 쓰고 erase를 쓴다.
// 
// erase
// 노드를 그냥 제거하면 이터레이터는 아무것도 아닌 곳을 가리키게 된다.
// 반드시 받아줘야한다.
// C++은 end를 지우는걸 막지 않았다. 그래서 직접 만들었다.
// leak 없앨때 쓰기엔 너무 무거운 함수다.
// 


// leak 없애기... while or 재귀함수
// list를 template로 바꾸기


//중요한 자료구조 3개: vector, list, map
// (저 셋은 모두 iterator가 있다.)
//
// ! 목적을 잊으면 안된다 ! (어디에서 썼는지 기억해보자.)
// 
// vector, 
// 데이터가 고정되어 있고 미리 크기를 알 수 있는 경우 사용.
// 미리 사이즈를 확장시켜 놓으면 추가 할당은 일어나지 않는다.
// 특정 위치의 원소에 바로 접근 가능하다.
// (ConsoleImage
// 
// list
// 중간 접근이 불가능하다.
// 