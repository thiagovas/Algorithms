#ifndef _chrisimos_queue_h
#define _chrisimos_queue_h

#include <cstdio>
#include <cstdlib>

namespace chrisimos
{
  
  /*  */
  template<typename T>
  struct s_queue {
    T value;
    struct s_queue *next;
  }
  
  
  template <class T>
  class queue {
    public:
      
      /*  */
      queue<T>()
      {
        
      }
      
      
      /*  */
      void push(T value)
      {
        
      }
      
      
      /*  */
      void pop(T value)
      {
        
      }
      
      
      /*  */
      T front()
      {
        
      }
      
      /*  */
      bool empty()
      {
        
      }
      
    private:
      struct s_queue<T> *linked_list;
  };
}

#endif
