// wrote_241217.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// 102_replacementNew
// (...어제에 이어서)
// 
// ...생성자가 호출되지 않으면 가상함수 테이블이 만들어지지 않는다.
// 
// AMonster* Actor = new(mempool) AMonster();
// 
// 정적배열(array)이 아닌 메모리는 느려지게 만든다.
// (캐시적중률이 낮으므로)
// 
// (유니티의 ECS 엔티티)
// 
// 흩어져 있는 메모리들이 아닌 하나의 정적배열처럼 위치시킨다.
// FTransform ArrTrans[1000];
// FTransform* Trans = &ArrTrans[2];


// Level이 셋팅되기 전에 
// Level->spawnActor()할 수 없으나... 먼저 메모리를 만든다면?!
// 
// AMonster* MonsterMemory
// 
// !주의!
// 생성되면서 리터럴 초기화도 실행되니 초기화 시키지 않기.


// 103_ 
//
// Compile Time Assertion은 컴파일 타임에 이미 결정되어 있는 결과를 말한다.
// 런타일에서 연산량을 줄이는 데 사용된다.
// 
// 상속 여부를 확인할 수 있는 문법
// std::is_base_of<classA, classB>::value 
// 혹은 std::is_base_of_v<classA, classB>
// 
// 컴파일러는 어떻게 상속 여부를 확인할 수 있는걸까?
// 클래스 내에 존재하는 bool 값을 상속여부에 따라 바꾼다. 
// 
// sizeof는 함수가 아닌 상수다. 이미 코드 영역에 저장되어 있다.
// 
// class My_Is_Base_Of
// {
//     static short Test(void* Test);
//     static char Test(AActor* Test);
//     
//     static Monster* Ptr;
//     static const bool value = sizeof(My_Is_Base_Of::Test(Ptr));
// }
// 
// AActor가 호출될까, void가 호출될까... (short로 리턴될까, char로 리턴될까)
// Monster는 AActor를 상속받았다. 업캐스팅 된 쪽이 먼저다.
// 
