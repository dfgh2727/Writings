// wrote_241211.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// ...어제에 이어서 직교투영을 보자.
//                  
            //(Width와 Height는 화면의 너비와 높이)
           // (카메라가 Near부터 Far까지의 범위 안에 있는 사물들을 본다.)
 void OrthographicLH(float _Width, float Height, float _Near, float _Far)
 {
     // (LH는 왼손이라는 뜻)
     //...결론적으로 World의 크기를 환산하는 행렬이다.
 

 }
// 카메라를 (0,0)으로 보자.
// 
//         __________________  Far                     __________________   
//        |                  |                        |                  |
//   (-1) |                  | (1)                    |                  |  
//        |                  |           --->         |                  |            
//        |                  |                        |                  |  
//         ------------------  Near                    ------------------    (딱 붙였다)
//                  ^                                 |      모니터      |
//                  |                                  ------------------
//                  |
//                  @ (카메라) (0,0)
// 
//  카메라와 Near사이에 거리가 존재한다.
//  그 거리만큼 앞으로 당겨서 모니터에 밀착시킨다.
//  따라서 Near와 카메라 사이의 물체들은 나타나지 않는다.
// 

// ViewPort
// 
// 좌표를 변환시키는 과정
// 즉 윈도우 좌표가 아닌 화면에 맞추어 좌표를 변환시킨다.
// (좌표축 변경, 중점 변경, y축 반전 등등...)
// 
//                                                        (보통 _ZMin과 _ZMax는 1.0으로 둔다)
//                    1280           720          640          360          1.0          1.0
 void ViewPort(float _Width, float Height, float _Left, float _Top, float _ZMin, float _ZMax)
 {
     // 엄청 작은 World를 화면 정중앙에 놓고 화면에 맞추어 늘리는 상상을 해보라...
     // 
     // Left와 Top은 화면 정중앙을 의미한다.
     // Z값이 작으면 앞에, 크면 뒤에 보이게 된다.
 }


//원근투영
//
//                              FovAngle = x축에서 바라봤을때 보이는 각도 (yz평면의 각도)
//       (여기서 쓰는 _Width와 _Height는 화면의 크기가 아닌 비율을 정의하기 위한 값이다.)
void PerspectiveFov(float _FovAngle, float _Width, float Height, float _Near, float _Far)
{                        
    //Fov를 반으로 나누어서 직각삼각형을 이용해 값을 사용.
}

// 3행([2])의 w는 변하기 전의 z값이다.
// 나중에 w를 1.0f로 바꾼다.
// https://openmynotepad.tistory.com/102
// 





// DX 시작
// 
// 출력 디렉토리 API것을 복붙하고 Build를 쓰고 중간(Build/Mid)과 실행파일(Build/Bin)의 출력폴더를 다르게 해준다.
// (실행파일은 남기고 싶을때 Mid만 삭제하면 됨)
// 
// 단순히 헤더만 첨가한다고 해당하는 내용(cpp)을 사용할 수는 없다.
// lib의 경우 pragma comment로 cpp의 내용을 사용 가능하게 만들어야 한다.
// 근데 dll은 다르다.
//
//

