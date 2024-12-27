// wrote_241227.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>


// static선언시 데이터 영역에 존재... main 종료 뒤 삭제
// leak 확인은 stack 까지만 가능하므로 static 선언된 경우는 정상적으로 삭제되어도
// leak으로 판단되어 보고될 수 있다. 

// Engineloop 
// 
// 
// 
// 
