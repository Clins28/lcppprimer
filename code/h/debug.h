#pragma once
class Debug {
public:
	constexpr Debug(bool b = true) : hw(b), io(b), other(b){}
	constexpr Debug(bool h, bool i, bool o):
									hw(h), io(i), other(o){}
	constexpr bool any() const { return hw || io || other; }	//常成员函数保证调用此函数的对象不会被改变
	constexpr void set_io(bool b) { io = b; }
	constexpr void set_hw(bool b) { hw = b; }
	constexpr void set_other(bool b) { hw = b; }
private:
	bool hw;
	bool io;
	bool other;
};