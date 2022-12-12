#include <assert.h>
#include <string>
#include <vector>

struct Point {
  int x;
  int y;
  auto operator<=>(const Point &) const = default;
};

struct Grid {
  std::vector<char> data;
  int x_width{};
  int y_width{};
  char get(Point p) const {
    assert(p.x < x_width);
    assert(p.y < y_width);
    return data.at(p.x + p.y * x_width);
  };
};
Grid readLineByLine(const std::string &input);
