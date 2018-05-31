#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <vector>
#include <iostream>

class Window_mgr {
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
private:
	//这个Window_mgr追踪的Screen
	//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
	std::vector<Screen> screens{ Screen(24, 80, ' ') };	//vector的列表初始化
};


class Screen {
public:
	using pos = std::string::size_type;	//C++11中新的类型别名定义法
	Screen() = default;
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) {}	//隐式使用cursor的类内初始值，初始化为连续ht*wd个c组成的字符串
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
	
	char get() const { return contents[cursor]; }	//读取光标处字符，隐式内联
	inline char get(pos, pos) const;			//显式内联
	Screen &move(pos, pos);						//在之后被设为内联

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

	friend class Window_mgr;	//将Window_mgr指定为友元类
};

#endif // !SCREEN_H


