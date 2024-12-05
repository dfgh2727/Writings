﻿// wrote_241204.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

// static은 객체 없이 만들 수 있다.
// 호출하기 편하다.
// 
// 어제의 도형 회전들은 z축을 회전시킨 것
// (2D는 z축 회전이 대부분)
// 
// Copy로 값을 대입시킨다.
// 
// 월드 변환 순서는 보통 크기, 자전, 이동, 공전, 부모 순이다.
// (크자이공부 무엇...)
// 
// 로컬 스페이스 -> 월드 스페이스 (크자이공부) -> 뷰 스페이스 (카메라)-> 프로젝션 스페이스 (투영)-> 뷰포트 스페이스 (모니터) 


// 람베르트 조명공식
// 
// 법선에 대하여 각도가 R인 벡터만큼의 빛이 들어온다.
// 빛(벡터)과 법선에 대한 내적 = 반사된 빛의 세기
// 여차저차 표면에 수직 즉, 법선과 평행(R = 0)할 때 빛의 세기가 제일 강하다.
// 

//오늘 한 것
// 
// x,y,z축으로 회전 시키기.
// 정육면체 만들기
// 벡터 내적과 외적, 그의 응용(내적...정사영을 통한 충돌 체크, 람베르트 조명 공식 )
//