#include <iostream>

struct tMy
{

};

class CMy
{
	// 접근 제한 지정자
	// private, protected(상속), public

private:
	int		m_i;
	float	m_f;

public:
	void SetInt(int i)
	{
		m_i = i;
		//this->m_i = i; //생략
	}

	// 대입 연산자
	CMy& operator = (const CMy& _Other)//반환타입 = CMy&
	{
		m_i = _Other.m_i;
		this->m_f = _Other.m_f;

		return *this;//this의 원본객체를 참조해서 반환
	}

public:
	// 생성자
	// 이니셜라이져
	CMy() 
		: m_i(100)
		, m_f(0.f)
	{
		//m_i = 100;
	}

	// 소멸자
	~CMy()
	{

	}
};



int main()
{
	// C++ 클래스 특징
	// 접근데한 지정자
	// 클래스 내의 멤버변수 or 멤버함수의 접근 레벨
	
	// 생성자, 소멸자
	// 객체 생성, 소멸 시 자동으로 호출
	// 직접 만들지 않으면 기본 생성자, 기본 소멸자가 만들어짐

	// 멤버 함수
	// 해당 클래스가 사용하는 전용 함수
	// 해당 클래스의 객체가 필요함
	// 멤버함수를 객체를 통해서 호출하면, 해당 객체의 주소가 this 포인터로 전달된다.

	{
		// 레퍼런스
		// 자료형 * 변수명;	포인터 변수 선언
		// *포이터변수;		포인터로 주소 역참조
		// &변수;			변수의 주소값
		// 자료형& 변수명;	레퍼런스 변수 선언

		// C++ 에 추가된 기능
		// 포인터와 유사
		// 원본을 참조한다.
		// 참조변수를 통해서 직접적으로 원본을 수정 할 수 있다.

		int a = 10;

		int* const  p = &a;
		*p = 100;

		int& iRef = a;
		iRef = 100;


		const int* const p2 = &a;
		//*p2 = 10;

		const int& iRefConst = a;
		//iRefConst = 10;
	}



	// CMy::SetInt(10); // 객체가 있어야 함

	CMy c;
	c.SetInt(10);

	CMy c2;
	c.SetInt(100);

	CMy c3;
	c.SetInt(1000);

	
	c3 = c2;

	c = c2 = c3;//void로 반환하면 반환되는것이 없어 불가 -> c = ;

	int i = 0;
	int i2 = 5;
	int i3 = 10;

	i = i2 = i3;// 전부 10
	
	return 0;
}