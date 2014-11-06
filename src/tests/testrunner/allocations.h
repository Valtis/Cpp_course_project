#pragma once

#include <map>
#include "custom_allocator.h"

enum class AllocationType : int { REGULAR, ARRAY } ;

class allocations {
public:
  void add_allocation(void *addr, const AllocationType type, const size_t bytes, const int line, const char *file);
  void remove_allocation(void *addr, const AllocationType type);

  bool has_errors();
  void print_errors();

  void clear();

private:

  // two maps so we can differentiate between new, new[], delete and delete[]
  std::map<const void *, size_t, std::less<const void *>, custom_allocator<std::pair<const void *, size_t>>> m_regular_allocations;
  std::map<const void *, size_t, std::less<const void *>, custom_allocator<std::pair<const void *, size_t>>> m_array_allocations;
};
