#include "../h/Screen.h"

using namespace std;

char Screen::get(pos r, pos c) const {		//������ڲ�����Ϊinline
	pos row = r * width;
	return contents[row + c];
}
	
void Screen::some_member() const {		//��ʹ��const��Ա�����ڲ�Ҳ���Ըı�mutable��ֵ
	++access_ctr;	//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
	//todo
}

Screen::pos Screen::size() const
{
	return height * width;
}

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s) {
	screens.push_back(s);
	return screens.size() - 1;
}

