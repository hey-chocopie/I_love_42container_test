#include <stack>
#include "../../stack.hpp"
#include "../../vector.hpp"
#include "../define.hpp"


template<class T>
void print_stack(TESTED_NAMESPACE::stack<T> s) {
	std::cout << "stk" << std::endl;
	while (!s.empty()) {
		std::cout << s.top() << std::endl;
		s.pop();
	}
}

int main() {
	std::cout << "=====================================" << std::endl;
	std::cout << "==============[ STACK ]==============" << std::endl;
	std::cout << "=====================================" << std::endl;

	std::cout << "----------------------- Constructor " << std::endl;
	TESTED_NAMESPACE::stack<int> stk1;

	std::cout << " 1, 2, 3, 4, 5 push" << std::endl;
	for (int i = 0; i < 5; i++) {
		stk1.push(i + 1);
	}

	std::cout << "-----------" << std::endl;
	std::cout << "π stk  : " << std::endl;
	print_stack(stk1);


	std::cout << "----------------------- Empty " << std::endl;
	TESTED_NAMESPACE::stack<int> stk2;

	std::cout << "> λΉ μ€νμΈ κ²½μ°" << std::endl;
	std::cout << "π stk  : " << stk2.empty() << std::endl;
	
	std::cout << "> λΉ μ€νμ΄ μλ κ²½μ°" << std::endl;
	std::cout << "π stk  : " << stk1.empty() << std::endl;

	std::cout << "----------------------- Size " << std::endl;

	std::cout << "> μ¬μ΄μ¦ 0" << std::endl;
	std::cout << "π stk  : " << stk2.size() << std::endl;
	
	std::cout << "> μ¬μ΄μ¦ 5" << std::endl;
	std::cout << "π stk  : " << stk1.size() << std::endl;

	std::cout << "----------------------- Top " << std::endl;
	std::cout << "π stk  : " << stk1.top() << std::endl;

	std::cout << "----------------------- Push " << std::endl;
	std::cout << "> push 42" << std::endl;
	stk1.push(42);

	std::cout << "π stk.top()  : " << stk1.top() << std::endl;

	std::cout << "> push 100" << std::endl;
	stk1.push(100);

	std::cout << "π stk.top()  : " << stk1.top() << std::endl;

	std::cout << "----------------------- Pop " << std::endl;
	std::cout << "> pop" << std::endl;
	stk1.pop();

	std::cout << "π stk.top()  : " << stk1.top() << std::endl;

	std::cout << "> pop" << std::endl;
	stk1.pop();

	std::cout << "π stk.top()  : " << stk1.top() << std::endl;

	std::cout << "----------------------- Relational operators" << std::endl;
	std::cout << "> [1, 2, 3] == [1, 2, 3]" << std::endl;

	TESTED_NAMESPACE::stack<int> stk3;
	TESTED_NAMESPACE::stack<int> stk4;

	for (int i = 0; i < 3; i++) {
		stk3.push(i + 1);
		stk4.push(i + 1);
	}

	std::cout << "========= κ°μ μ€νμ κ²½μ° ========" << std::endl;
	std::cout << "> [1, 2, 3] == [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 == stk4) << std::endl;
	std::cout << "> [1, 2, 3] != [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 != stk4) << std::endl;
	std::cout << "> [1, 2, 3] < [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 < stk4) << std::endl;
	std::cout << "> [1, 2, 3] <= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 <= stk4) << std::endl;
	std::cout << "> [1, 2, 3] > [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 > stk4) << std::endl;
	std::cout << "> [1, 2, 3] >= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 >= stk4) << std::endl;

	stk3.push(4);

	std::cout << "========= μ¬μ΄μ¦κ° λ€λ₯Έ μ€νμ κ²½μ° ========" << std::endl;
	std::cout << "> [1, 2, 3, 4] == [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 == stk4) << std::endl;
	std::cout << "> [1, 2, 3, 4] != [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 != stk4) << std::endl;
	std::cout << "> [1, 2, 3, 4] < [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 < stk4) << std::endl;
	std::cout << "> [1, 2, 3, 4] <= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 <= stk4) << std::endl;
	std::cout << "> [1, 2, 3, 4] > [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 > stk4) << std::endl;
	std::cout << "> [1, 2, 3, 4] >= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 >= stk4) << std::endl;

	std::cout << "========= μ¬μ΄μ¦λ κ°κ³  κ°μ΄ λ€λ₯Έ μ€νμ κ²½μ° ========" << std::endl;
	stk3.pop();
	stk3.pop();
	stk3.push(4);

	std::cout << "> [1, 2, 4] == [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 == stk4) << std::endl;
	std::cout << "> [1, 2, 4] != [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 != stk4) << std::endl;
	std::cout << "> [1, 2, 4] < [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 < stk4) << std::endl;
	std::cout << "> [1, 2, 4] <= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 <= stk4) << std::endl;
	std::cout << "> [1, 2, 4] > [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 > stk4) << std::endl;
	std::cout << "> [1, 2, 4] >= [1, 2, 3]" << std::endl;
	std::cout << "π stk  : " << (stk3 >= stk4) << std::endl;

	std::cout << "========= string μ€νμ κ²½μ° ========" << std::endl;
	TESTED_NAMESPACE::stack<std::string> stk5;
	TESTED_NAMESPACE::stack<std::string> stk6;

	for (int i = 0; i < 3; i++) {
		stk5.push("aaa");
		stk6.push("aaa");
	}
	std::cout << "> κ°μ λ¬Έμμ΄ μ€ν" << std::endl;
	std::cout << "> [aaa, aaa, aaa] == [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 == stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] != [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 != stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] < [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 < stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] <= [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 <= stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] > [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 > stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] >= [aaa, aaa, aaa]" << std::endl;
	std::cout << "π stk  : " << (stk5 >= stk6) << std::endl;
	std::cout << std::endl;
	
	stk6.pop();
	stk6.push("aab");

	std::cout << "> κΈΈμ΄λ κ°μ§λ§ κΈμκ° λ€λ₯Έ λ¬Έμμ΄ μ€ν" << std::endl;
	std::cout << "> [aaa, aaa, aaa] == [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 == stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] != [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 != stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] < [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 < stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] <= [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 <= stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] > [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 > stk6) << std::endl;
	std::cout << "> [aaa, aaa, aaa] >= [aaa, aaa, aab]" << std::endl;
	std::cout << "π stk  : " << (stk5 >= stk6) << std::endl;

}
