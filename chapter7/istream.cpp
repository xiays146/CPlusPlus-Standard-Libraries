#include <fstream>
#include <iostream>
#include <iterator>

int main() {
  std::ifstream file("test.cpp");               // 打开文件
  std::istream_iterator<std::string> it(file);  // 使用文件作为输入流
  std::istream_iterator<std::string> end;  // 默认构造函数表示结束的迭代器

  while (it != end) {  // 读取文件直到遇到结束
    std::cout << *it;
    ++it;  // 移动到下一个输入值
  }
  std::cout << std::endl;
  file.close();  // 关闭文件

  return 0;
}
