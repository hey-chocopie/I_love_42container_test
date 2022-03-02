# contribute, 테스트 케이스 추가해주세요🐶

* tsetsrc의 파일에 vector, map, stack중 파일로 들어가 테스트하고 싶은 케이스를 넣어볼수 있습니다. 
* 기존 map_test.cpp파일에 추가해도 되고, test_srcs/vector 경로에 cpp형태로 파일을 넣으면 ./checker에 반영됩니다.
* 많은 관심 부탁드립니다. 


# 1. 프로젝트 소개 🚛
### 소개 :
* 제작한 ft container(vector, map, stack)와 std container를 비교하는 testerkit 입니다.
### 기간 : 
* 2022.02.15
### 요약 :  
* C++ standard(표준,std) 의 Container(vector, map, stack)와 제작한 ft의 container를 비교합니다.
* 정상적으로 컴파일 되고 출력이 되면, 화면에 ok를 출력합니다.
* 실패한다면, 컴파일 또는 출력 중 어느곳에서 std와 다른지 출력합니다.		
* log에 출력되는 값이 저장됩니다. deepthought에 std와의 diff값이 저장됩니다.

# 2. 프로젝트 구조
```
.
├── READMD.md
├── checker.sh
├── deepthought
├── execute.sh
├── logs
├── one
└── test_srcs
    ├── define.hpp
    ├── map
    │   └── map_test.cpp
    ├── stack
    │   └── stack_test.cpp
    └── vector
        └── vector_test.cpp

6 directories, 8 files
```
* deepthought : 차이값 저장
* logs : std 와 ft로 출력된 값 저장
* test_srcs : 테스트 파일 목록

# 3. 프로젝트 실행
```
git clone https://github.com/hey-chocopie/I_love_42container_test.git

cd I_love_42container_test

./checker.sh

//or

./one test_srcs/vector/vector_test
```


