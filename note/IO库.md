# 1. IO库中包含的类
* iostream
* fstream
* sstream

## 1.1. IO流的条件状态
## 1.2. 输出缓冲
## 1.3. IO流的关联

# 2. 文件的输入与输出
## 2.1. 操作文件的方法
* 创建fstream流的时候指定
* open close函数
## 2.2. 自动构造与析构
## 2.3. 文件模式
<img src="pics/_1528967396_24232.jpg" width=50% height=50% /><br>

```cpp
ofstream out("file1", ofstream::app);
```
# 3. string流
把string类型转换为IO流