﻿// wrote_241018.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{

}

// API를 공부의 연장선으로 바라봐야 할듯 (쳐준다고 설명이 없는건 아님)
// API동안 나에게 주어진 시간은 6.5시간
// API...정적 라이브러리
// 다렉...동적 라이브러리와 운영체제
// 그리고 c++ 문법 수업은 8개월 내내 진행된다.

//MAP
//(map 공부할 때는 중단점 걸어놓고 보면서 하자)
// 
// map에 사용된 알고리즘은 레드블랙 알고리즘 바이너리서치 트리
// 메모리 구조는 노드 구조, 시퀀스 연관
// 
// ************ std와 stl 용어설명 ***************
// std (Standard Library)
// c++ 표준 위원회가 공인한 코드
// 분야별로 헤더로 구분되어 있다.
// 
// stl (Standard Template Library)
// std 중에 템플릿을 사용하는 모든 코드를 말한다. 
// *************************************************
// 
// vector, list, map은 모두 같은 인터페이스를 가지고 있다. 
// (즉, vector도 순회자가 있다. 인덱스가 있어서 잘 안 쓰겠지만.)
//

// 어제 과제 풀이 : leak 막기
// 
// i) while문
// 아예 Clear라는 새로운 함수를 만들었다;;
// while문을 통해 노드를 순회하게 만들었다.
// UList* Nextnode = Curnode -> Next  ...지워지기 전에 저장하게 만들고 
// (지워질 노드로부터 다음으로 이어지는 위치를 따로 받아 놓는다.)
// 
// 그리고 Start와 END를 지워준다.
//
//
// ii) 재귀
// 지우는 함수(선생님은 Redelete)를 만드는건 같다. 
// Next가 null인 노드를 찾아 계속 돌린다. 그 전엔 Delete 되지 않는다.
// 모든 노드에 Redelete가 걸려 있는 상황
// Next가 null인 Endnode를 발견하면 delete실행.
// 
// 
// iii) delete this?
// 

//079_Stack
// (OS가 보통은 1메가를 할당해준다.)
// 
// 과제에서와 같이 계속 재귀함수를 돌린다? 
// 메모리 부담이 커서 좋지 않다. 잘못하면 stack overflow 발생해서 터진다.
// (스택을 확장시킬 수는 있지만 굳이...쓰진 않는다.)
// 
// 꼬리 재귀
// 마지막에 리턴하는 순간에 재귀할 함수를 만드는 것
// 컴파일러가 while과 비슷하게 변경해 준다.
// 재귀함수를 만들때는 가능한한 꼬리재귀로 만드는 것이 좋다.
// 

// 다시 shooting으로 돌아가서...
// EngineCore의 프레임워크를 바꾼다. 
// 
// Render()
// 만약 벡터였다면 추가 코드를 쳐야한다.
// if(nullptr == AllActorvector[i])
// {
//    continue;
// }
//
// Tick도 list로 만들고 return을 Actor로.
// 
// 
// *************엔진 삭제 로직(ppt)***************** 
// 
// listnode는 실체를 가리키고 있을 뿐
// 따라서 listnode와 실체 둘 다 지워야 한다.
// 
// Iterator가 dangling ptr 가 되는걸 막기 위해
// erase를 하면 리턴값을 받아야 한다.
// 
// 불릿이 파괴되고  몬스터 노드가 앞으로 이동
// 그 후에 증감문 실행...결국 Endnode로 Iter가 위치
// 에러가 발생한다.
// 따라서 증감문은 조건에 넣지 않는다.
// 
// (문법에서 설명했다시피 while과 for는 서로 대체될 수 있다. 반복문은 가능. 근데 조건문은 아니야.)
// *************************************************
// 

//트리 
// 
// 상하관계가 있는 노드구조
// 
// 레벨(뎁스 depth)
// 루트: 0레벨에 존재하는 트리 시작점
//       만약 루트가 없다면 먼저 들어온 키가 루트가 된다.
// 
// 모양, 자식 갯수, 규칙에 따른 분류가 있다.
// 자식 갯수: 옥트리, 쿼드트리, 바이너리 트리...
// (실사용 예로는 옥트리는 3차원 지형 표현, 쿼드트리는 2차원 지형 만들기에 쓰인다. KD 트리는 gps)
// 모양: 분류, 편향, 완전 균형
// 규칙: 서치트리, 레드블랙 트리
// 
// (트리가 포화되어 있을수록 잘 적재했다고 한다.)
// 
// 완전 이진 트리?
// 자료가 들어갈 때 레벨에 맞춰서, 좌에서 우로 순서대로 쌓이는 트리
// 
// 서치트리
// 탐색을 용이하게 만든 트리
// 어떤 규칙에 맞춰서 자료를 적재한다.
// 
// 예) 17은 어디에 위치해야 하나?
// 
//             [10]       (10보다 크다, 오른쪽)
//            /     ＼
//          [2]     [15]  (15보다 크다, 오른쪽)
//         /  ＼    /   ＼
//       [ ]  [ ]  [ ]  [17]
// 
// (데이터가 많아질수록 맵이 서치횟수가 적어져 탐색이 빠르지만...
//  벡터는 통째로 캐쉬에 올리기 때문에 엄청난 양의 데이터가 아닌 이상 벡터가 빠르다.)
// 
//  편향트리는 적재 규칙도 없고 노드를 하나씩 캐쉬에 올려서 탐색하기 때문에 좋지 않다.
//
// 레드블랙 트리
// 회전이라는 함수를 사용해서 편향트리가 되는 걸 방지,  루트를 바꿔 자가균형 트리가 되는...
// (rotate라는 함수를 통해서... left 혹은 right)
// 레드블랙트리까지는 몰라도 된다.


// !기본이 가장 중요하다. 문법을 잘 숙지하자 !


// 다시 Map으로 돌아와서...(수업은 편향 트리를 예시로 진행)
// 
// (set은 map과 동일하지만 인자가 key만 있는 자료구조)
//  make pair는 그냥 return 이 pair일 뿐인 함수
// 
// <int,int> 그냥 예시일 뿐, 어떤 클래스라도 들어갈 수 있다.
// 
// 객체와 클래스는 정확하게 구분하자.
// const char* Ptr = "Orc"
// {"Orc", AActor()} AActor의 객체를 넣은거다. 
// "Orc" ... 포인트 즉, 8바이트 정수를 넣었다. 주소값을 비교하여 트리의 규칙에 따라 적재 가능

// 게임은 이런 환경이 아니면 잘 안 만든다.
// 포폴을 최우선으로 하자

// (...map...)
// 
// find
// 값형인줄 알았는데 ->가 된다? 
// 컴파일러가 알아서 operator를 만들었군.
// 
// map의 키들이 숫자 순서대로 나온다면 무슨 일이 벌어진걸까?
// 작은 값을 찾아 왼쪽으로, 큰 값을 찾아 오른쪽으로...
// 가장 작은 값은 가장 왼쪽 중 leftchild가 없는 leftchild
// 
// [map은 지우기가 까다롭다. 그래도 한번 짜본다.
// 
// 노드를 어떻게 지울까
// 1.자식이 없는 노드(리프노드)는 지워져도 문제 없다.
//   단, 지워졌을 경우 부모에게 알려야 한다. (danling ptr 방지)
// 2.한쪽만 자식이 있다면 그대로, 양쪽에 있을 경우...(코드 확인)] 


// map의 순회
// 
// 2진트리는 전위순회, 중위순회, 후위순회가 있다.
// 
// 일단 노드제거는 전위순회를 하면 안된다.
// this를 없애고 나면 그 다음 노드를 삭제할 수 없다.
// 
// 중위순회는 크기대로 정렬하게 된다.
// 
// 트리를 삭제할 때는 후위순회로 
//

//map에서 좌, 우에 노드를 위치시킬때 부등호를 뒤집으면 결과가 반대로 나온다...
//중위순회로 확인해보면 오름차순과 내림차순 정렬을 확인할 수 있다. 
// map의 3번째 인자
//  
// less
//
// 함수 객체
// ()연산자를 겹지정한 클래스를 함수객체라 한다.
// 
// greater와 less
// 맵을 정렬하는데 쓴다.
//





