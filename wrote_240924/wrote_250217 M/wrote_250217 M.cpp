// wrote_250217 M.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

// 언리얼은 일종의 parsing 기능으로 코드를 인식하고 함수를 구현한다.
// (UPROPERTY, UFUNCTION)

// 블루프린트로 스폰하기
// 
// 블루프린트에서 템플릿을 사용할 수 없다.
// 또한 클래스를 값형으로 생성할 수 없다. 
// (class Monster ... Monster NewMonster; 이렇게 불가능)
// 
// 템플릿을 쓸 수 없으므로 spawn actor로 어떤 클래스를 만들어야 하는지 지정해야 한다. 
// 이때 UClass가 쓰인다. UClass를 지정하고, 블루프린트는 리스트화 된 UClass를 사용한다.
// 변수를 따로 만들 필요 없다. Make~로 검색해보면 변수들을 
// 
// Transform은 위치, 크기, 회전이 들어가 있는 구조체.
//   
// 언리얼 좌표계 :  (Z)  (X)
//                   |  /
//                   | /
//                   |/____ (Y)
// 
// Actor를 spawn할 때 첫번째 인자로 UClass를 넣어야 한다. 
// UClass를 CDO가 조사한 클래스 정보다. 따라서 spawn할 때 마다 클래스에 대한 정보를 요구한다.

// Actor를 어떻게 스폰할까?
// 
// 1) 지정된 UClass를 사용해서 스폰한다.
// 2) C++ native에서 블루 프린트의 경로를 사용한다. (-> 꽤나 번거로운 방법)
// 
// std::vector의 push_back = TArray의 Add()
//               size()               Num()
//               empty()              IsEmpty()
//               reserve()            Reserve()
//               resize()             SetNum()
//
// data table
// 
// UAsset (언리얼 에셋)
// 
