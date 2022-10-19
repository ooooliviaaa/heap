#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <algorithm> 
#include <vector>
#include "stack.h"


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  std::vector<T> v; 
  //two node compare 
  int two; 
  PComparator c_;
};


//size
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return v.size();
}

//empty
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(v.size()==0){
    return true;
  }
  else{
    return false;
  }
}



// We will start top() for you to handle the case of 
// top: calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(!empty()){
    return v[0];
  }
  else{
    //return the first value of the vector 
     throw std::underflow_error("Be aware ! Heap is empty!!");
  }
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
//for pop, we swap the first and the last node and then delete the last nod
//and then heapify from the chanegd node 
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  //if empty, throw underflow error 
  if(empty()){
    throw std::underflow_error("Be aware, Heap is empty!");
  }
  //swap the firts na dthe last one first 
  std::swap(v[0], v[v.size()-1]);
  //then delete the last node
  v.pop_back();
  //then delete the last node, call the pop back from vector
  //check if im in my leaf node
  // while(not at leaf node){
  // loop through m children and select the smallest amount them
  //by doing comp and see who is smaller
  //index number is 0 because it is trickle down 
  unsigned int ind_num = 0; 
  while(ind_num < v.size()){
    unsigned int current = ind_num ; 
    unsigned int smallest_node = ind_num;
    /*unsigned int current = ind_num * two + 1;
    unsigned int smallest_node = ind_num * two + 1;*/
    for(int i = 0; i < two; i++){
      current = ind_num * two + i;
      //make sure it is not out of scope 
      if(current < v.size()){
        // i got it wrong here at the beginning, i was confused about 
        // the order of the c_ comparator, so i swapped them but now i switched it !
        if(!c_(v[smallest_node], v[current])){
          smallest_node = current;
        }
      }
    }
      //if they are the same dont do anything, base case basically 
    if(smallest_node != ind_num){
      std::swap(v[ind_num], v[smallest_node]);
      ind_num = smallest_node;
    }
    else{
       return;
    }
  }
}


//push: basically adding one node at the very end and then 
//heapify from the last one again 
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){
  //add one node at the very end and the trickle up 
  //current position is also at the end 
  v.push_back(item);
  //starting from the last index, which should be v.size() - 1; 
  unsigned int ind = v.size()-1;
  //as long as we don't go out of scope 
  while(ind > 0){
    // for any givin node, the parent node is (index -1 )/m, in this case i use two 
    unsigned int parent = (ind - 1) / two;
    if(!c_(v[parent],v[ind])){
      std::swap(v[parent],v[ind]);
      ind = parent;
    }
    else{
      return;
    }
  }
}


//constructor and destructor 
template<typename T,typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c): two(m), c_(c){}

template<typename T,typename PComparator>
Heap<T, PComparator>::~Heap(){
}



#endif

