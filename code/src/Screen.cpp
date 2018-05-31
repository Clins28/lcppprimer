#include "../h/Screen.h"

using namespace std;
inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;	//�����е�λ��
	cursor = row + c;		//�����ڽ�����ƶ���ָ������
	return *this;
}
char Screen::get(pos r, pos c) const {		//������ڲ�����Ϊinline
	pos row = r * width;
	return contents[row + c];
}
	
void Screen::some_member() const {		//��ʹ��const��Ա�����ڲ�Ҳ���Ըı�mutable��ֵ
	++access_ctr;	//����һ������ֵ�����ڼ�¼��Ա���������õĴ���
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