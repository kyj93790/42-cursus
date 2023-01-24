#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void) {

	std::cout << "-----MutantStack-----\n";
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(3);

	std::cout << "top : " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "size : " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(737);
	mstack.push(-9);
	mstack.push(100);
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

	std::cout << "--MutantStack Reverse--\n";

	std::stack<int> s(mstack);

	MutantStack<int>::reverse_iterator r_it = mstack.rbegin();
	MutantStack<int>::reverse_iterator r_ite = mstack.rend();

	++r_it;
	--r_it;
	while (r_it != r_ite)
	{
		std::cout << *r_it << std::endl;
		++r_it;
	}

	std::cout << "--------LIST-------\n";

	std::list<int> lstack;

	lstack.push_back(1);
	lstack.push_back(3);

	std::cout << "back : " << lstack.back() << std::endl;

	lstack.pop_back();

	std::cout << "size : " << lstack.size() << std::endl;

	lstack.push_back(3);
	lstack.push_back(737);
	lstack.push_back(-9);
	lstack.push_back(100);
	lstack.push_back(0);

	std::list<int>::iterator it_l = lstack.begin();
	std::list<int>::iterator ite_l = lstack.end();
	
	++it_l;
	--it_l;
	while (it_l != ite_l)
	{
		std::cout << *it_l << std::endl;
		++it_l;
	}

	std::cout << "-----LIST Reverse----\n";

	std::list<int> s_l(lstack);

	std::list<int>::reverse_iterator r_it_l = lstack.rbegin();
	std::list<int>::reverse_iterator r_ite_l = lstack.rend();
	
	++r_it_l;
	--r_it_l;
	while (r_it_l != r_ite_l)
	{
		std::cout << *r_it_l << std::endl;
		++r_it_l;
	}
	return 0;
}