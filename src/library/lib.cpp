//
// Created by galex on 10/7/2022.
//

#include "lib.hpp"

#include <koyote/utilities.hpp>

namespace lib {
  void testing()
  {
    std::vector<std::string> strs{ "fubuki", "mio", "koyori", "okayu", "korone" };
    for (const auto& [i, str]: std::views::zip(std::views::iota(0, static_cast<int>(strs.size() - 1)), strs)) {
      std::cout << i << ", " << str;
    }
  }
} // lib