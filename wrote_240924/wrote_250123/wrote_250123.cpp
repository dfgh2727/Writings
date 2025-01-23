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
// 내가 바라보는 방향의 단위 벡터 = normalize(ViewPos - CameraPos)
// 
// vertex... 모니터 공간까지 갔으니 빛의 연산에 사용할 수 없다.
// 
