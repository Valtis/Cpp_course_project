#include "allocations.h"
#include <iostream>

void allocations::add_allocation(const void * addr, const AllocationType type, const size_t bytes, const int line, const char* file) {

  switch (type) {
    case AllocationType::REGULAR:
      m_regular_allocations[addr] = bytes;
    break;

    case AllocationType::ARRAY:
      m_array_allocations[addr] = bytes;
    break;
  }

}

void allocations::remove_allocation(const void * addr, const AllocationType type) {
  switch (type) {
    case AllocationType::REGULAR:
      m_regular_allocations.erase(addr);
    break;

    case AllocationType::ARRAY:
      m_array_allocations.erase(addr);
    break;
  }
}


bool allocations::has_errors() {
  return m_regular_allocations.size() != 0 || m_array_allocations.size() != 0;
}

void allocations::print_errors() {
  for (auto pair : m_regular_allocations) {
    std::cout << "Memory leak at address " << pair.first << ". " << pair.second << " bytes lost\n";
  }

  for (auto pair : m_array_allocations) {
    std::cout << "Array memory leak at address " << pair.first << ". " << pair.second << " bytes lost\n";
  }
}

void allocations::clear() {
  m_regular_allocations.clear();
  m_array_allocations.clear();
}
