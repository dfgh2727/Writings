﻿// wrote_250102.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// 레스터라이저에서 viewporttransformation처리
// (뷰포트 셋팅)
// 
// 모니터는 그대로니 셋팅은 잘 바꾸지 않는다.
// 
// UV좌표계와 샘플러를 통해 이미지를 비율에 맞춰서 색깔을 가져온다.
// (버텍스에 있는 UV값을 확인)
// 
//  0,0 _____________ 1,0 (UV값)
//    |              |
//    |   (이미지)   |
// 
// 그리고 샘플러의 옵션을 통해 이미지를 어떻게 보이게 할지 설정한다.
// 위와 같은 원리로 UV값을 조절하여 이미지가 반복해서 나타나게 할 수 있다.

// 자체 쉐이더를 만들어도 ShaderInit()으로 파일을 추가해야 한다.
// 
// 함수 이름을 넣어야 컴파일 된다...
// 쉐이더 이름의 규칙을 정하자. 끝을 _VS, _PS로 하자.
// 파일을 찾지 못하면 std::string은 npos가 나온다.
// substr, 텍스트를 자른다.
// 
// 모든 쉐이더는 EntryName을 가진다.
// 
// ...여차저차 쉐이더 컴파일을 위한 코드를 짰다.
// 그 다음은 쉐이더의 리소스를 확인하게 만들자.


// 쉐이더의 리소스 확인하기
// 
// Reflection (주로 C#와 같은 최신언어에서 보인다.)
// 일종의 RTTI(Run Time Type Information)다.
// 예를 들면 C#은 Reflection으로 클래스의 정보를 파악할 수 있다. 
// (멤버함수의 갯수 등...)
// 
// shader에 적용시켜서 리소스 정보를 확인하자.
// (상수 버퍼의 갯수 등)
// 
// 컴퓨트 쉐이더, 반복되는 연산을 그래픽 카드에게 맡긴다.
// 
// 중복되는 쉐이더가 많아지면 VRam값 상승
// (게임에서 나무가 많다던가...)
// 
// 상수 버퍼를 여러개 만들어야 할까?
// 크기가 같으니 중복 생성되지 않게 하나로 돌려쓰자. (그러나 바이트 크기가 다르면 따로 만들어야 한다.)
// 일종의 최적화다.
// UEngineConstantBuffer::CreateOrFind(), 만들어진 상수버퍼를 찾거나 없으면 만든다.
// 
// 특정 크기의 상수버퍼가, 특정 이름으로 만들어졌다면(contains())
// return BufferMap[_Byte][_Name.Data];
// 없다면 만든다.
// std::shared_ptr<UEngineConstantBuffer>NewRes = std::make_ptr<UEngineConstantBuffer>();
// 
// EngineDeviceBuffer
// BufferInfo를 가지게끔 부모를 만들어서 상속시켰다.

// 보통 이미지 n가지를 렌더링 하고 싶다면 n개의 material을 만들어야 한다.
// 즉 Renderer가 n개 있다면 material도 n개 있어야 한다.
// 
// UEngineShaderResources안에 material에 대한 정보가 있다.
// 
// 인스턴싱...동일한 material을 쓰는 n개의 사물을 한꺼번에 그린다.
// 결과는 사물들의 위치도 동일하다... 어떻게 해결할까
// n개의 transform 데이터를 만들어서 보내야 한다. 
// 
// 행렬을 쓰지 않겠다고 struct를 수정하면
// 수정할 때마다 새로운 struct를 만들어야 하니...메모리 낭비다.
// 수정하지 않는 것을 권한다.


// emplace_back()
// 
// 내부에서 placement new를 통해서 복사를 안해도 되게 최적화를 해주는 문법.
// c++14부터 가능.

// Renderer는 셋팅만, 실질적인 설정은 하위 리소스에서 해야 한다. 
//

// AlignedByOffset 
// format들을 나열한다고 생각해보자.
// 0바이트, 16바이트, 32바이트...
// (Position, textcoord, color가 모두 16바이트니까)
// 
// 유일하게 inputlayout은 material과 mesh 둘 다 셋팅되었을때 설정할 수 있다.
//
//