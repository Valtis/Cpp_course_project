#pragma once
#include <memory>
#include <cstdlib>
#include <limits>

template <class T>
class custom_allocator {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef T* pointer;
  typedef const T* const_pointer;
  typedef T& reference;
  typedef const T& const_reference;
  typedef T value_type;

  template <class U>
  struct rebind {
    typedef custom_allocator<U> other;
  };

  custom_allocator() throw() {

  }
  custom_allocator(const custom_allocator&) throw() {

  }

  template <class U> custom_allocator(const custom_allocator<U>&) throw() {

  }

  ~custom_allocator() throw() {

  }

  pointer address(reference x) const {
    return &x;
  }

  const_pointer address(const_reference x) const {
     return &x;
  }

  pointer allocate(size_type s, void const * hint = 0) {
      if (s == 0) {
          return nullptr;
      }
      pointer temp = (pointer)malloc(s * sizeof(T));

      if (temp == nullptr) {
        throw std::bad_alloc();
      }

      return temp;
  }

    void deallocate(pointer p, size_type n) {
        free(p);
    }

    size_type max_size() const throw() {
        return std::numeric_limits<size_t>::max() / sizeof(T);
    }

    void construct(pointer p, const T& val) {
        new((void *)p) T(val);
    }

    void destroy(pointer p) {
        p->~T();
    }
};
