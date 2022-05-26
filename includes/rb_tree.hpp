#ifndef RB_TREE_HPP

# define RB_TREE_HPP

# include <iostream>
# include "iterator.hpp"
# include "type_traits.hpp"
# include "utility.hpp"

namespace ft
{


	template <typename value>
	struct node_base
	{
		typedef node_base*			ptr_base;
		typedef const node_base*	const_ptr_base;

		bool		_color;
		ptr_base	_parent;
		ptr_base	_left;
		ptr_base	_right;
		value		_value;
		//
		// ptr_base minimum(ptr_base node) {
		//   while (node->_left != TNULL) {
		// 	node = node->_left;
		//   }
		//   return node;
		// }
		//
		// ptr_base maximum(ptr_base node) {
		//   while (node->_right != TNULL) {
		// 	node = node->_right;
		//   }
		//   return node;
		// }
		//
		// const_ptr_base minimum(const_ptr_base node) {
		//   while (node->_left != TNULL) {
		// 	node = node->_left;
		//   }
		//   return node;
		// }
		//
		// const_ptr_base maximum(const_ptr_base node) {
		//   while (node->_right != TNULL) {
		// 	node = node->_right;
		//   }
		//   return node;
		// }
	};

	template<typename _Key, typename _Val, typename _KeyOfValue, typename _Compare, typename _Alloc = std::allocator<_Val> >
    class rb_tree
    {

	    protected:
		  typedef node_base<_Val>												base;
	      typedef node_base<_Val>*												ptr_base;
	      typedef const node_base<_Val>*										constPtr_base;

		private:
			ptr_base root;
			ptr_base TNULL;

	    public:
	      typedef _Key															key_type;
	      typedef _Val															value_type;
	      typedef value_type*													pointer;
	      typedef const value_type*												const_pointer;
	      typedef value_type&													reference;
	      typedef const value_type&												const_reference;
	      // typedef node<_Val>*													_Link_type;
	      // typedef const node<_Val>*												_Const_Link_type;
	      typedef size_t														size_type;
	      typedef ptrdiff_t														difference_type;
	      typedef _Alloc														allocator_type;

			rb_tree()
			{
				TNULL = new base;
				TNULL->_color = false;
				TNULL->_left = TNULL;
				TNULL->_right = TNULL;
				root = TNULL;
			}

			   template<typename _Tp>
			     struct rb_tree_iterator
			     {
			       typedef _Tp  value_type;
			       typedef _Tp& reference;
			       typedef _Tp* pointer;

			       typedef std::bidirectional_iterator_tag iterator_category;
			       typedef ptrdiff_t                  difference_type;

			       typedef rb_tree_iterator<_Tp>        rb_iterator;
				   typename node_base<_Tp>::ptr_base current_node;

			       rb_tree_iterator()
			       : current_node() { }

			       explicit
			       rb_tree_iterator(node_base<_Tp>* x)
			       : current_node(x) { }

			       reference
			       operator*() const
			       {
					   return static_cast<node_base<_Tp>*>(current_node)->_value;
				   }

			       // pointer
			       // operator->() const
			       // {
					//    return std::__addressof(static_cast<node_base<_Val>*>
			       //           (current_node)->_value);
				   // }

			       rb_iterator&
			       operator++()
			       {
				     current_node = current_node.successor(current_node);
				     return *this;
			       }

			       rb_iterator
			       operator++(int)
			       {
				     rb_iterator __tmp = *this;
				     current_node = current_node.successor(current_node);
				     return __tmp;
			       }

			       rb_iterator&
			       operator--()
			       {
				     current_node = current_node.predecessor(current_node);
				     return *this;
			       }

			       rb_iterator
			       operator--(int)
			       {
				     rb_iterator __tmp = *this;
				     current_node = current_node.predecessor(current_node);
				     return __tmp;
			       }

			       bool
			       operator==(const rb_iterator& x) const
			       {
					   return current_node == x.current_node;
				   }

			       bool
			       operator!=(const rb_iterator& x) const
			       {
					   return current_node != x.current_node;
				   }

			   };

			ft::pair<typename rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::rb_tree_iterator<_Val>, bool>
			insert(const _Val& v)
			{
				ft::pair<typename rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::rb_tree_iterator<_Val>, bool> it;
				if ((it.first = searchTreeHelper2(this->root, v.first)) != rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::rb_tree_iterator<_Val>(TNULL))
				{
	  				it.second = false;
	  		        return (it);
				}
		      ptr_base node = new base;
		      node->_parent = TNULL;
		      node->_value = v;
		      node->_left = TNULL;
		      node->_right = TNULL;
		      node->_color = true;

		      ptr_base y = TNULL;
		      ptr_base x = this->root;

		      while (x != TNULL)
			  {
		        y = x;
		        if (node->_value < x->_value)
		          x = x->_left;
				else
		          x = x->_right;
		      }

			  node->_parent = y;
			  if (y == TNULL)
				root = node;
			  else if (node->_value < y->_value)
				y->_left = node;
			  else
				y->_right = node;

		      if (node->_parent == TNULL)
			  {
		        node->_color = 0;
				it.first = rb_tree_iterator<_Val>(y);
				it.second = true;
		        return (it);
		      }

		      if (node->_parent->_parent == TNULL)
			  {
				it.first = rb_tree_iterator<_Val>(y);
  				it.second = true;
  		        return (it);
			  }

		      // insertFix(node);

			  it.first = rb_tree_iterator<_Val>(node);
			  it.second = true;
			  return (it);
		    }

			ptr_base successor(ptr_base x)
		   {
		     if (x->right != TNULL)
		     {
		  	  return minimum(x->right);
		     }

		  	ptr_base y = x->parent;
		  	while (y != TNULL && x == y->right)
		     {
		  	  x = y;
		  	  y = y->parent;
		  	}
		  	return y;
		   }

		   ptr_base predecessor(ptr_base x) {
		  	if (x->left != TNULL) {
		  	  return maximum(x->left);
		  	}

		  	ptr_base y = x->parent;
		  	while (y != TNULL && x == y->left) {
		  	  x = y;
		  	  y = y->parent;
		  	}

		  	return y;
		   }


	   private:
		   ptr_base searchTreeHelper(ptr_base node, int key) {
		     if (node == TNULL || key == node->_value.first) {
		       return node;
		     }

		     if (key < node->_value.first) {
		       return searchTreeHelper(node->_left, key);
		     }
		     return searchTreeHelper(node->_right, key);
		   }

		   rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::rb_tree_iterator<_Val> searchTreeHelper2(ptr_base node, int key) {
		     if (node == TNULL || key == node->_value.first) {
		       return rb_tree<_Key, _Val, _KeyOfValue, _Compare, _Alloc>::rb_tree_iterator<_Val>(node);
		     }

		     if (key < node->_value.first) {
		       return searchTreeHelper2(node->_left, key);
		     }
		     return searchTreeHelper2(node->_right, key);
		   }
	   // public:
	   //

	   //
		//    void leftRotate(ptr_base x) {
		//      ptr_base y = x->right;
		//      x->right = y->left;
		//      if (y->left != TNULL) {
		//        y->left->parent = x;
		//      }
		//      y->parent = x->parent;
		//      if (x->parent == nullptr) {
		//        this->root = y;
		//      } else if (x == x->parent->left) {
		//        x->parent->left = y;
		//      } else {
		//        x->parent->right = y;
		//      }
		//      y->left = x;
		//      x->parent = y;
		//    }
	   //
		//    void rightRotate(ptr_base x) {
		//      ptr_base y = x->left;
		//      x->left = y->right;
		//      if (y->right != TNULL) {
		//        y->right->parent = x;
		//      }
		//      y->parent = x->parent;
		//      if (x->parent == nullptr) {
		//        this->root = y;
		//      } else if (x == x->parent->right) {
		//        x->parent->right = y;
		//      } else {
		//        x->parent->left = y;
		//      }
		//      y->right = x;
		//      x->parent = y;
		//    }
	   //
		//    ptr_base getRoot() {
		//      return this->root;
		//    }
	   //
		//    void deleteNode(int data) {
		// 	 deleteNodeHelper(this->root, data);
		//    }

		void printHelper(ptr_base root, std::string indent, bool last) {
	      if (root != TNULL) {
	        std::cout << indent;
	        if (last) {
	          std::cout << "R----";
	          indent += "   ";
	        } else {
	          std::cout << "L----";
	          indent += "|  ";
	        }

	        std::string sColor = root->_color ? "RED" : "BLACK";
	        std::cout << root->_value.first << "(" << sColor << ")" << std::endl;
	        printHelper(root->_left, indent, false);
	        printHelper(root->_right, indent, true);
	      }
	    }
	public:
		void printTree() {
		  if (root) {
		    printHelper(this->root, "", true);
		  }
		}
   };

} // namespace ft

#endif
