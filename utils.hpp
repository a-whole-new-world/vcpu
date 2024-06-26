#pragma once

#include <vector>

#include "common.hpp"
#include "memory.hpp"

void write_program(Memory mem, word_t address, std::vector<uint64_t> prog) {
  word_t cur_address = address;
  for (auto inst: prog) {
    if ((inst >> 16) == 0) {
      mem.write_hword(cur_address, inst);
      cur_address += 2;
    } else if ((inst >> 32) == 0) {
      mem.write_word(cur_address, inst);
      cur_address += 4;
    } else {
      std::cout << "write_program is broken" << std::endl;
    }
  }
}