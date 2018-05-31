#include "../h/Screen.h"

using namespace std;
inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;	//计算行的位置
	cursor = row + c;		//在行内将光标移动到指定的列
	return *this;
}
char Screen::get(pos r, pos c) const {		//在类的内部声明为inline
	pos row = r * width;
	return contents[row + c];
}
	
void Screen::some_member() const {		//即使在const成员函数内部也可以改变mutable的值
	++access_ctr;	//保存一个计数值，用于记录成员函数被调用的次数
	//todo
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r*width + col] = ch;
	return *this;
}

void Window_mgr::clear(ScreenIndex i) {
	Screen &s = screens[i];
	s.contents = string(s.height * s.width, ' ');
}

Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& s) {
	screens.push_back(s);
	return screens.size() - 1;
}