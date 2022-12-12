#include "input.h"

#include <algorithm>
#include <fstream>
#include <ranges>

using namespace std;

Grid readLineByLine(const string &input) {
  string line;
  ifstream myfile;

  myfile.open(input);

  if (!myfile.is_open()) {
    perror("Error open");
    exit(EXIT_FAILURE);
  }

  Grid Result;
  while (getline(myfile, line)) {
    std::ranges::copy(line.begin(), line.end(),
                      std::back_inserter(Result.data));
  }
  Result.x_width = line.size();
  Result.y_width = Result.data.size() / Result.x_width;
  return Result;
}
