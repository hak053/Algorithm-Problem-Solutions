#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ /** DONE */
  BSTIterator(BSTNode<Data>* curr) {
    /** Assign global var curr to local var curr */
    this->curr = curr; 
  }

  /** Dereference operator. */
  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {

    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /** Equality test operator. */ /** DONE */
  bool operator==(BSTIterator<Data> const & other) const {
    return this->curr == other.curr;
  }

  /** Inequality test operator. */ /** DONE */
  bool operator!=(BSTIterator<Data> const & other) const {
    return this->curr != other.curr;
  }

};

#endif //BSTITERATOR_HPP
