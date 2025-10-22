#include "MutantStack.hpp"

// push fnction put a nev value ont the very top of the stack. (for stack and queue)
// push_back -||- (for vector, list, deque ) 
// pop function takes away the very last value.
// top function just looks on the very last value of the stack.
//size function checks the size of the stack.
//LIFO
//deque ican add and remove from the start and also from the end.

//main from subject
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << '\n' << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
  
    std::cout << "\n-------------------------------------\n" << std::endl;
// list konteiner
    std::list<int> l;
    l.push_back(5);
    l.push_back(17);
    std::cout << "First value is: " << l.back() << std::endl;
    l.pop_back();
    std::cout << "Size after pop_back(): " << l.size() << std::endl;


    l.push_back(3);
    l.push_back(5);
    l.push_back(737);
    l.push_front(999);
    l.push_back(0);
        
    std::cout << "Going through std::list with iterators:" << std::endl;
    std::list<int>::iterator list_it = l.begin();
    std::list<int>::iterator list_ite = l.end();

    ++list_it;
    --list_it;
    while (list_it != list_ite) {
        std::cout << *list_it << std::endl;
        ++list_it;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;
// std::vector
    std::vector<int> v;
    v.push_back(5);
    v.push_back(17);
    std::cout << "Vector back: " << v.back() << std::endl;
    v.pop_back();
    std::cout << "Vector size: " << v.size() << std::endl;

    v.push_back(3);
    v.push_back(5);
    v.push_back(737);
    v.push_back(0);
        
    std::cout << "--- Iterating through std::vector ---" << std::endl;
    std::vector<int>::iterator vec_it = v.begin();
    std::vector<int>::iterator vec_ite = v.end();
    ++vec_it;
    --vec_it;
    while (vec_it != vec_ite) {
        std::cout << *vec_it << std::endl;
        ++vec_it;
    }
    std::cout << "\n-------------------------------------\n" << std::endl;
    MutantStack<int, std::list<int> > mstack_on_list;
    mstack_on_list.push(5);
    mstack_on_list.push(17);
    std::cout << "Top value is: " << mstack_on_list.top() << std::endl;
    mstack_on_list.pop();
    std::cout << "Size after pop(): " << mstack_on_list.size() << std::endl;

    mstack_on_list.push(3);
    mstack_on_list.push(5);
    mstack_on_list.push(737);
    mstack_on_list.push(0);
    MutantStack<int, std::list<int> >::iterator it_list = mstack_on_list.begin();
    MutantStack<int, std::list<int> >::iterator ite_list = mstack_on_list.end();

    while (it_list != ite_list) {
    std::cout << *it_list << std::endl;
    ++it_list;
}
    return 0;
}
