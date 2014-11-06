#pragma once

#include <map>
#include "custom_allocator.h"

enum class AllocationType : int { REGULAR, ARRAY } ;

class allocations {
public:

  void add_allocation(const void *addr, const AllocationType type, const size_t bytes, const int line, const char *file);
  void remove_allocation(const void *addr, const AllocationType type);

  bool has_errors();
  void print_errors();

  void clear();

private:

  struct pointer_info {
    size_t bytes;
    int line;
    const char *file;
  };

  // two maps so we can differentiate between new, new[], delete and delete[]
  std::map<const void *, pointer_info, std::less<const void *>, custom_allocator<std::pair<const void *, pointer_info>>> m_regular_allocations;
  std::map<const void *, pointer_info, std::less<const void *>, custom_allocator<std::pair<const void *, pointer_info>>> m_array_allocations;
};
