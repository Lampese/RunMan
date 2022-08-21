/*
This project was under the GPL-2.0 License.
Copyright(c) 2022 Lampese.
Copyright(c) 2022 nu11ptr.
*/
#ifndef _LAMAOPT_H_
#define _LAMAOPT_H_
#include <map>
#include <string>
#include <vector>

namespace LampOpt {
typedef struct Arguments {
  std::map<std::string, std::string> args;
  Arguments() {}
  explicit Arguments(const std::vector<std::string>& arg,
                     const std::map<std::string, std::string>& alias =
                         std::map<std::string, std::string>()) {
    for (size_t i = 0; i < arg.size(); i++) {
      size_t p = arg[i].find_first_of('=');
      if (p == std::string::npos) {
        if (alias.find(arg[i]) != alias.cend())args[alias.at(arg[i])] = "true";
        else args[arg[i]] = "true";
      } else {
        std::string&& x = arg[i].substr(0, p);
        if (alias.find(x) != alias.cend())
          args[alias.at(x)] = arg[i].substr(p);
        else args[x] = arg[i].substr(p);
      }
    }
  }
} Arguments;
};  // namespace LampOpt
#endif