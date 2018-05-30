#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>

class Screen {
public:
	using pos = std::string::size_type;	//C++11���µ����ͱ������巨
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}	//��ʽʹ��cursor�����ڳ�ʼֵ����ʼ��Ϊ����ht*wd��c��ɵ��ַ���
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	
	char get() const { return contents[cursor]; }	//��ȡ��괦�ַ�����ʽ����
	inline char get(pos ht, pos wd) const;			//��ʽ����
	Screen &move(pos r, pos c);						//��֮����Ϊ����

	Screen &set(char);
	Screen &set(pos, pos, char);

	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }


	void some_member() const;

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;

	void do_display(std::ostream &os) const { os << contents; }
	mutable size_t access_ctr;
};


class Window_mgr {
private:
	//���Window_mgr׷�ٵ�Screen
	//Ĭ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };	//vector���б��ʼ��
};

#endif // !SCREEN_H


