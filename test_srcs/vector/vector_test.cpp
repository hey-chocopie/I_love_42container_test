#include <iostream>
#include <vector>
#include <string>
#include "../define.hpp"
#include "../../../vector.hpp"
#include "../../../vector_iter.hpp"
//#include "iterator.hpp"

template<typename T>
void print_vector(TESTED_NAMESPACE::vector<T>& v) {
	typename TESTED_NAMESPACE::vector<T>::const_iterator iter;
	
	std::cout << "[ ";
	for (iter = v.begin(); iter != v.end(); ++iter) {
		std::cout << *iter;
		if (iter + 1 != v.end()) {
			std::cout << ", ";
		}
	}
	std::cout << " ]" << std::endl;
}

int main() {

	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ VECTOR ]=============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	{
		std::cout << "  [ default constructor test ]" << std::endl;
		TESTED_NAMESPACE::vector<int> ft1;
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ fill constructor test ]" << std::endl;
		TESTED_NAMESPACE::vector<int> ft2(5, 3);
		std::cout << "π ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ range constructor test ]" << std::endl;
		std::cout << "> first(begin + 1), last(end - 1)" << std::endl;
		TESTED_NAMESPACE::vector<int> ft3(ft2.begin() + 1, ft2.end() - 1);
		std::cout << "π ft  ( size : " << ft3.size() << " )" << std::endl;
		print_vector(ft3);
		std::cout << std::endl;
	}
	std::cout << "  [ Assign test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 42);
		TESTED_NAMESPACE::vector<int> ft2;

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 2 = 1 λ‘ ν λΉ" << std::endl;
		ft2 = ft1;

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 2.push_back(2) λ‘ κΉμλ³΅μ¬ μ²΄ν¬" << std::endl;
		ft2.push_back(2);
		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Iterator " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1;
		for (int i = 0; i < 5; i++) {
			ft1.push_back(i);
		}

		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "π ft  begin() : " << *ft1.begin() << std::endl;
		std::cout << std::endl;
		std::cout << "π ft  end() - 1 : " << *(ft1.end() - 1) << std::endl;
		std::cout << std::endl;
		std::cout << "π ft  rbegin() : " << *ft1.rbegin() << std::endl;
		std::cout << std::endl;
		std::cout << "π ft  rend() + 1 : " << *(ft1.rend() - 1) << std::endl;
		std::cout << std::endl;

		std::cout << "> begin λΆν° end κΉμ§ μΆλ ₯" << std::endl;
		print_vector(ft1);

	}
	std::cout << "----------------------- Capacity " << std::endl;
	{
		std::cout << "  [ size test ]" << std::endl;
		std::cout << "> λΉ λ²‘ν° μμ±" << std::endl;
		TESTED_NAMESPACE::vector<int> ft1;

		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> μ«μ 100 μ΄ 4κ° λ€μ΄κ° λ²‘ν° μμ±" << std::endl;
		TESTED_NAMESPACE::vector<int> ft2(4, 100);

		std::cout << "π ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ max_size test ]" << std::endl;
		std::cout << "π ft  : " << ft2.max_size() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ resize test - (2) ]" << std::endl;
		// λμ€μ μΆκ° νμ
		std::cout << "> 2μΉΈμΌλ‘ resize" << std::endl;
		ft2.resize(2);
		std::cout << "π ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 10μΉΈμΌλ‘ resize, 42λ‘ μ±μ°κΈ°" << std::endl;
		ft2.resize(10, 42);
		std::cout << "π ft  ( size : " << ft2.size() << " )" << std::endl;
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ empty test ]" << std::endl;

		std::cout << "> λΉλ°°μ΄μ κ²½μ°" << std::endl;
		std::cout << "π ft  : " << ft2.empty() << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> λΉλ°°μ΄μ΄ μλ κ²½μ°" << std::endl;
		ft2.push_back(1);
		std::cout << "π ft  : " << ft2.empty() << std::endl;
		print_vector(ft2);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Element access " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(1, 100);

		std::cout << "  [ operator[] test ]" << std::endl;
		std::cout << "π ft  : ";
		print_vector(ft1);
		std::cout << "ft[0]  : " << ft1[0] << std::endl;
		std::cout << std::endl;

		std::cout << "> push_back(12)" << std::endl;
		ft1.push_back(12);
		std::cout << std::endl;

		std::cout << "π ft  : ";
		print_vector(ft1);
		std::cout << "ft[1]  : " << ft1[1] << std::endl;
		std::cout << std::endl;

		std::cout << "  [ at test ]" << std::endl;
		std::cout << "π ft.at(1)  : " << ft1.at(1) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ front test ]" << std::endl;
		std::cout << "π ft.front()  : " << ft1.front() << std::endl;
		std::cout << std::endl;

		std::cout << "  [ back test ]" << std::endl;
		std::cout << "π ft.back()  : " << ft1.back() << std::endl;
		std::cout << std::endl;
	}

	std::cout << "----------------------- Modifiers " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 100);
		TESTED_NAMESPACE::vector<int>::iterator ft_iter;

		std::cout << "  [ assign test ]" << std::endl;
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 2, 77 assign" << std::endl;
		ft1.assign(2, 77);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> 5, 42 assign" << std::endl;
		ft1.assign(5, 42);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
		std::cout << "> (begin() + 1, end() - 1) iterator assign" << std::endl;
		ft_iter = ft1.begin() + 1;
		ft1.assign(ft_iter, ft1.end() - 1);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ push_back test ]" << std::endl;
		std::cout << "> push_back(100)" << std::endl;
		ft1.push_back(100);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ pop_back test ]" << std::endl;
		std::cout << "> pop_back" << std::endl;
		ft1.pop_back();
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ insert test ]" << std::endl;
		std::cout << "> insert begin(), 1" << std::endl;
		ft1.insert(ft1.begin(), 1);
		std::cout << "π ft  ( size : " << ft1.size()  << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 1, 2, 2" << std::endl;
		ft1.insert(ft1.begin() + 1, 2, 2);
		std::cout << "π ft  ( size : " << ft1.size()  << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> insert begin() + 3, iter(begin), iter(end)" << std::endl;
		std::cout << "> iter : [3, 3, 3]" << std::endl;
		TESTED_NAMESPACE::vector<int> add2(3, 3);
		ft_iter = add2.begin();
		ft1.insert(ft1.begin() + 3, ft_iter, add2.end());
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "  [ erase test ]" << std::endl;
		std::cout << "> erase begin + 3" << std::endl;
		ft1.erase(ft1.begin() + 3);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase end() - 1" << std::endl;
		ft1.erase(ft1.end() - 1);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;

		std::cout << "> erase first(begin), last(begin + 3)" << std::endl;
		ft1.erase(ft1.begin(), ft1.begin() + 3);
		std::cout << "π ft  ( size : " << ft1.size() << " )" << std::endl;
		print_vector(ft1);
		std::cout << std::endl;
	}
		std::cout << "  [ swap test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 1);
		TESTED_NAMESPACE::vector<int> ft2(3, 99);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 1.swap(2)" << std::endl;
		ft1.swap(ft2);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "  [ clear test ]" << std::endl;
		std::cout << "> clear()" << std::endl;

		ft1.clear();
		ft2.clear();
		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}

	std::cout << "----------------------- Allocator " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft;

		std::cout << "> get_allocator" << std::endl;
		std::cout << "> allocate(5)" << std::endl;
		int *p2 = ft.get_allocator().allocate(5);

		std::cout << "> construct(0 ~ 4)" << std::endl;
		for (int i = 0; i < 5; i++) {
			ft.get_allocator().construct(&p2[i], i);
		}

		std::cout << "π ft  : ";
		for (int i = 0; i < 5; i++)
			std::cout << p2[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "----------------------- Non-member function " << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(5, 5);
		TESTED_NAMESPACE::vector<int> ft2(5, 5);

		std::cout << "  [ operator == test 1 ]" << std::endl;
		
		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  == ft2  : " << (ft1 == ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator == test 2 ]" << std::endl;

		ft1.push_back(1);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  == ft2  : " << (ft1 == ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator != test 1 ]" << std::endl;

		ft1.pop_back();

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  != ft2  : " << (ft1 != ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator != test 2 ]" << std::endl;

		ft1.push_back(1);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  != ft2  : " << (ft1 != ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator < test 1 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  < ft2  : " << (ft1 < ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator < test 2 ]" << std::endl;
		TESTED_NAMESPACE::vector<std::string> ft3(3, "a");
		TESTED_NAMESPACE::vector<std::string> ft4(2, "a");

		ft4.push_back("b");

		std::cout << "π ft1  : ";
		print_vector(ft3);
		std::cout << "π ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "π ft1  < ft2  : " << (ft3 < ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator <= test 1 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft3);
		std::cout << "π ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "π ft1  <= ft2  : " << (ft3 <= ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator <= test 2 ]" << std::endl;

		ft1.pop_back();

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  <= ft2  : " << (ft1 <= ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator > test 1 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  > ft2  : " << (ft1 > ft2) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator > test 2 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft3);
		std::cout << "π ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "π ft1  > ft2  : " << (ft3 > ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator >= test 1 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft3);
		std::cout << "π ft2  : ";
		print_vector(ft4);
		std::cout << std::endl;

		std::cout << "π ft1  >= ft2  : " << (ft3 >= ft4) << std::endl;
		std::cout << std::endl;

		std::cout << "  [ operator >= test 2 ]" << std::endl;

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "π ft1  >= ft2  : " << (ft1 >= ft2) << std::endl;
		std::cout << std::endl;

	}

	std::cout << "  [ swap test ]" << std::endl;
	{
		TESTED_NAMESPACE::vector<int> ft1(3, 1);
		TESTED_NAMESPACE::vector<int> ft2(3, 99);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;

		std::cout << "> 1.swap(2)" << std::endl;
		ft1.swap(ft2);

		std::cout << "π ft1  : ";
		print_vector(ft1);
		std::cout << "π ft2  : ";
		print_vector(ft2);
		std::cout << std::endl;
	}

}
