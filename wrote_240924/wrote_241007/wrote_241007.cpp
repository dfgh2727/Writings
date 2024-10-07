#include <iostream>




//자료구조
 
// 공식적으로는 3가지 컨테이너로 분류한다.
// list vector map 
// 
// 
// 연관 (대표적으로 map)
// 시퀀스 (list, vector)
// 어뎁터 
// 

//넣은대로 위치한다? vector
// list와 vector는 동일한 자료구조에서 다룸


// ************* world.cpp와 Zone.cpp, TextRPG003ClassFile을 같이 보라 ***************

//공식은 아니지만 2가지로 메모리를 구분한다
// 노드형과 배열형
// 배열형은 그냥 Array 생각하면 된다.
// 
// 노드형
// 게임에서 가장 많이 사용되는 데이터 처리 형태
// 한 클래스 안에 참조형으로 n개를 가지고 있는 경우, 노드형이다.
// 
class Zone
{
private:
	
	//Zone SetOfZones [10];
	//값형으로 가지고 있으면
	//Has a 즉, 이 클래스 안에 온전히 갖고 있게 된다. 연결이 안 됨

	Zone* LinkZone[5] = {}; //이렇게 참조형으로 만들어야 하나의 zone이 있고 연결해서 사용가능
	                        //(참고로 노드형 구조다.)
    
	// 정적 바인딩
	// 코드가 실행되고 난 뒤에 바꿀 수 없기 때문에
	// 5개의 공간을 선언하고 하나만 사용한 경우 남은 4개의 메모리가 낭비된다.
	

	//누군가 상수를 말하면...변수로 생각하고 짜야한다. 기획자들을 믿지마(?)
	//언제든지 바뀔 수 있어야 해
	// 
	//예상 가능한 문제를 막을 줄 알아야 한다.
	//코드를 쳐보고 꼭 돌려서 확인해보기


public:
	void Link(Zone* _Link)
	{

	}

};

class FightZone : public Zone
{

};


class Town : public Zone
{
public:
	void InPlayer()
	{
		// FightZone Zone;  위에서 값형으로 선언되었을 경우 플레이어가 존재해야 zone이 생성되어버림;; 즉 플레이어가 존을 가지게 됨

	}
};


int main()
{
	Town TZone;
	FightZone FZone;

}


//(클래스로 선언했는데 주석처리한 이유... 누군가가 또 만들어서 낭비할까봐
//아예 전역 변수로 만들어버림)


//swtich가 아닌 업캐스팅을 통해서 코드를 간결하게

//함수 안에 함수를 쓸 수 없다.
//