#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include <clang/Format/Format.h>

using namespace std;

int main(int argc, char *argv[]) {
  cout << "Hello World!" << endl;
  if (argc <= 1) {
    std::cout << "usage: " << argv[0] << "[file...]" << std::endl;
    return 0;
  }

  for (int i = 1; i < argc; ++i) {
    std::cout << "-- check '" << argv[i] << "'" << std::endl;
    std::ifstream ifs(argv[i]);
    std::string content((std::istreambuf_iterator<char>(ifs)),
                        (std::istreambuf_iterator<char>()));
    std::cout << content << std::endl;
    clang::format::FormatStyle style;
    style.Language = clang::format::FormatStyle::LK_Cpp;
    std::error_code ec = clang::format::parseConfiguration(content, &style);
    if (ec.value() != static_cast<int>(clang::format::ParseError::Success)) {
      std::cout << "error in clang-format configuration, what: " << ec.message()
                << endl;
    }
  }
  return 0;
}
