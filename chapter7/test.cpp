#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;
int main(int argc, const char** argv) {
  // vector<string> ints{istream_iterator<string>(cin),
  //                     istream_iterator<string>()};
  // for (auto& e : ints) {
  //   cout << e << endl;
  // }

  int data[] = {1, 2, 3, 4};
  std::vector<int> a(std::begin(data), std::end(data));
  std::copy(std::begin(a), std::end(a),
            std::ostream_iterator<int>(std::cout, ", a"));
  std::cout << std::endl;
  return 0;
}