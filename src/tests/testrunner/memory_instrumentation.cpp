#include "memory_instrumentation.h"

// global override new\delete

void * operator new(std::size_t n) throw(std::bad_alloc)
{
  auto alloc = get_allocations_list();
  auto ptr =  malloc(n);

  if (ptr == nullptr) {
    throw std::bad_alloc{};
  }

  alloc.add_allocation(ptr, AllocationType::REGULAR, n, __LINE__, __FILE__);
  return ptr;
}
/*
void * operator new[](std::size_t n) throw(std::bad_alloc)
{
  auto alloc = get_allocations_list();
  auto ptr =  malloc(n);

  if (ptr == nullptr) {
    throw std::bad_alloc{};
  }

  alloc.add_allocation(ptr, AllocationType::REGULAR, n, __LINE__, __FILE__);
  return ptr;

}*/


void operator delete(void * p) throw()
{
  auto alloc = get_allocations_list();
  alloc.remove_allocation(p, AllocationType::REGULAR);

  free(p);
}

/*
void operator delete[](void * p) throw()
{
  auto alloc = get_allocations_list();
  alloc.remove_allocation(p, AllocationType::REGULAR);

  free(p);
}*/


allocations &get_allocations_list() {
  static allocations alloc;
  return alloc;
}