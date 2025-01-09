// wrote_250109.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// BillBoard 
// 기존의 행렬들의 연산에서 View 행렬의 이동만 무시한다.

// z sorting 사용시...Far값이 클때 Z값의 차이가 크지 않으므로 (Z/Far) 실수의 오차가 생겨
// 문제가 생길 수 있다.

// TileMap
// (일단 인스턴싱 안하고)
// 
// (1) MapEditor
// MapEditor를 사용할 때 ImGUI를 최대한 활용하는 방향으로 진행.
//
// 무언가를 만드는 것과 띄우는 것은 별개다.
// WindowOpen()으로 ImGUI창을 연다.
// 
// 다음 레벨로 넘어갈 시 레벨과 무관한 창들은 꺼지도록 AllWindowOff()를 만든다.
// 
// (되도록 GUI 클래스는 별개의 .h에 선언, .cpp에 구현하자.)
// 
// 모든 레벨들을 가져올 수 있는 기능을 만들었다.
// EngineCore::GetAllLevelMap()
// 복사된 LevelMap을 return한다.
// (...map에 const를 붙여도 key, 는 변경 가능하기 때문에 의미가 없다.)
// 
// ImGUI창에서 버튼으로 레벨 이동을 가능하게 만든다. 
//
// 
// (ImGUI의 인코딩에 문제가 생길수 있다. 영어나 한글을 인식하지 못하는 경우 (????로 뜨는 등)...UTF-5 추가 필요)
//
// 
// OpenFileDialog
// 깊게 들어가진 않는다. 다만 파일을 저장할 수 있다는 것만 알아둬라.
// oplpstrdata = "확장자이름" ...저장할 파일의 확장자 이름을 넣을 수 있다.
// 
// ImGUI창을 focus한 상태일 때 윈도우 창을 무시하게 만든다.
// WM_KILLFOCUS
// 
// 현재 WndProc은 static 함수...
// 
// 
