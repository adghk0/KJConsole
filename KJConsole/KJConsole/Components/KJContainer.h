#pragma once
#include "KJComponent.h"
#include "../System/ArrayList.h"

//TODO: KJContainer - 완성
namespace KJConsole {
	class KJContainer : public KJComponent {
	private:
		ArrayList<KJComponent*>* components;

	public:
		//TODO: KJContainer - 생성자
		KJContainer();

		//TODO: KJContainer - 추가, 삭제 메소드

		//TODO: 컴포넌트 출력
		
	};
}