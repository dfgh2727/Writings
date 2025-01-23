// wrote_250123.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//


// Diffuse Light (어제에 이어서...)
// 스위즐링(swizzling) (HLSL) 
// 
// (언리얼) 광도 ... 빛의 세기
// 
// ResultColor.xyz *= Diffuse Color
// 
// CalDiffuseLight
// 
// Normal은 이미 view가 곱해져 있으므로(view 공간으로 보냄)
// LightRevLight도 view를 곱해야 한다.
// 공간이 같아야지 공식이 성립한다.
// 
// LightDir은 회전에 관련된 것... Normalize되어 있고 이동관련 수치가 적용되면 안된다. (w = 0)
// w = 1이라면 이동값이 적용된다. 주의!
 

// Specular Light
// 내적을 두 번 해준다.
// 빛의 방향에 대해서 그리고 내가 바라보는 방향에 대해서, 총 두 번 연산한다.
// 내가 바라보는 방향과 평행인 빛이 내게 가장 많이 도달한다. 즉, 가장 밝아 보인다.
// 내가 바라보는 방향의 단위 벡터 = normalize(CameraPos - ViewPos)
// 
// vertex... 모니터 공간까지 갔으니 빛의 연산에 사용할 수 없다.
// 
// Camera의 pos에 view를 곱하면 0이 된다... 곱하면 안 됨.


// Differed Light
// 
// 빛이 여러개가 된다면 
// for (int i = 0; i < length; i++)
// {
//    DiffuseLight += CalDiffuseLight()
//    SpecularLight += CalSpecularLight()
// }
// 위와 같이 연산을 해준다.
// 
// Ambient Light는 더하지 않고 고정시킨다. 너무 밝기 때문에.
// 
// 근데 mesh가 여러개라면???
// 어떤 메쉬가 다른 메쉬에 의해 가려지는 부분을 연산할 필요가 없는데...
// 그렇다고 가려지는 부분을 따져가면서 연산하면 더 복잡하다.
// ...빛 연산을 마지막에 하자!
// 
// 빛 연산을 할 때 필요한 요소:
// Pos, Normal이 필요하다.
// normal target(Result로 normal만 나옴)과 position target(Result로 position만 나옴)두 가지를 준비한다.
// 위 둘을 G-buffer라고 한다.
// normal target과 position target을 종합해서 최종적으로 
// 
// 즉 데이터만 모아 놨다가 나중에 빛 연산을 한다.
// 이 방식을 Differed Lighting이라 한다.
// 
// 반면 오브젝트 단위로 렌더링하는 것을 포워드 라이팅이라 한다.

// 범프 맵핑
// 범프와 노말의 차이?
// 빛은 normal에 의해 반사된다. 그리고 normal에 의한 결과는 균등해서 오브젝트가 반질반질한 느낌이 난다.
// 따라서 일반적인 라이팅은 입체감이 떨어진다.
// 직접 굴곡을 구현하기 위해 면의 수를 늘려서 버텍스 수를 늘리면 연산이 부담스러워진다.
// 그러므로 normal을 기록해 놓은 텍스처를 맵핑해서 그 텍스처를 노말로 반사한다.
// (빛이 반사되는 방향을 바꿔서 굴곡을 표현한다. 오브젝트의 표면을 보면 사실 굴곡이 없음을 알 수 있다.)
// 색을 그냥 x, y, z에 넣어버리는데 이때 R, G, B이므로 맵이 정면을 향하므로 
// z축은 B 즉, 맵이 전반적으로 파란색을 띠게 된다.
// 
// 반면 텍스처에 기록된 것을 기반으로 mesh를 표현한 것을 displacement라 하는데 잘 안 쓴다. 
// 연산이 부담스러워서.
// 
// 탄젠트 공간...
// 어떤 면이 회전했을 때 그 값을 반영한 공간.
// 

// view에서만 빛을 계산한다는 점을 명심!