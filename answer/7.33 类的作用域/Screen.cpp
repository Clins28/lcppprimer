#include "../h/Screen.h"

using namespace std;

char Screen::get(pos r, pos c) const {		//在类的内部声明为inline
	pos row = r * width;
	return contents[row + c];
}
	
void Screen::some_member() const {		//即使在const成员函数内部也可以改变mutable的值
	++access_ctr;	//保存一个计数值，用于记录成员函数被调用的次数
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

