#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  // 使用 istream_iterator 从 std::cin 读取浮点数
  std::istream_iterator<double> start(std::cin);
  std::istream_iterator<double> end;  // 默认构造函数表示结束的迭代器

  // 使用 copy 函数将输入流中的浮点数复制到 vector 中
  std::vector<double> numbers(start, end);

  // 打印 vector 中的浮点数
  std::cout << "You entered the following numbers:" << std::endl;
  for (const auto& num : numbers) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  return 0;
}
