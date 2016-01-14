#ifndef _chrisimos_stack_h
#define _chrisimos_stack_h

#include <cstdio>
#include <cstdlib>


namespace chrisimos
{
  
  /*
   *  This struct is used to create a linked list.
   *  The linked list created is then used as a stack.
   */
  template <typename T>
  struct s_stack {
    T value;
    struct s_stack *next;
  };
  
  
  template<class T>
  class stack {
    public:
      
      /*
        Constructor of the class.
        Initializes everything needed to be initialized before the use of
        the stack class.
      */
      stack()
      {
        this->linked_list=NULL;
      }

      /*
        Method push(T value)
        This method insert a new element on the stack.
        Complexity: O(1)
      */
      void push(T value)
      {
        struct s_stack<T> *neue = (struct s_stack<T>*) malloc(sizeof(T));
        neue->value = value;
        neue->next = this->linked_list;
        this->linked_list = neue;
      }

      /*
        Method pop()
        This method removes the top element of the stack.
        Complexity: O(1)
      */
      void pop()
      {
        if(this->empty()) return;
        
        struct s_stack<T> *temp = this->linked_list->next;
        free(this->linked_list);
        this->linked_list = temp;
      }

      /*
        Method top()
        This method returns the top element of the stack.
        Complexity: O(1)
      */
      T top()
      {
        return this->linked_list->value;
      }

      /*
        Method empty()
        This method returns true if the stack is empty, false otherwise.
        Complexity: O(1)
      */
      bool empty()
      {
        return (this->linked_list == NULL);
      }

    private:    
      struct s_stack<T> *linked_list;
  };
}

#endif
