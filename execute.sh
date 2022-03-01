#!/bin/bash -e

#!/usr/bin/env bash

H_RED="\033[31m"
H_GREEN="\033[32m"
H_YELLOW="\033[33m"
H_BLUE="\033[34m"
H_PURPLE="\033[35m"
H_CYAN="\033[36m"
H_WHITE="\033[37m"


EOC="\e[0m"
BOLD="\e[1m"
RED="\e[91m"
GREEN="\e[92m"
YELLOW="\e[93m"
DBLUE="\e[94m"
PURPLE="\e[95m"
CYAN="\e[96m"
DGREY="\e[1;90m"

tested_path="../"
incl_path="$tested_path"
test_srcs="test_srcs"

CC="clang++"
CFLAGS="-Wall -Wextra -Werror -std=c++98"

if false; then
	CFLAGS+=" -fsanitize=address -g3"
fi


introduce()
{
	echo -e $H_GREEN
	echo "by. hoylee, 21-02-18"
	echo "FT_container,start!"

	echo -e $H_WHITE
	echo -e $H_CYAN
	echo "=============================================================================================="
	echo -e $H_WHITE
	echo " 8888888888 88888888888          88        d88888b  8b   d8  88        88888888  8888888"
	echo " 888            888              88        88   88  88   88  88        88        88"
	echo " 888            888              88        88   88  88   88  88        88        88"
	echo " 8888888        888              8888888h  88   88  88   88  88        88888888  8888888"
	echo " 888            888              88888888  88   88  \"888888  88        88        88"
	echo " 888            888              88    88  88   88       8b  88        88        88"
	echo " 888            888              88    88  88   88      8b   8888888b  88        88"
	echo " 888            888   88888888   88    88  d88888b  8888b    88888888  88888888  8888888"
	echo -e $H_CYAN
	echo "=============================================================================================="
	echo -e $H_BLUE

	echo -e $H_CYAN
	echo -e $H_WHITE
}

compile () {
	# 1=file 2=define(ft/std) 3=output_file 4=compile_log
	$CC $CFLAGS -o "$3" -I./$incl_path -DTESTED_NAMESPACE=$2 $1 &>$4
	# - D옵션으로 define바꿈.
	return $?
}

getEmoji () {
	# 1=integer
	emoji='';
	case $1 in
		0) emoji="${GREEN}🚛 ok";;
		1) emoji="${RED}👹 fail";;
		2) emoji="${YELLOW}⚠️  warring";;
	esac
	printf "${BOLD}${emoji}${EOC}"
}

getYN () {
	# 1=integer
	res='';
	case $1 in
		0) res="Y";;
		1) res="N";;
	esac
	printf "${res}"
}

printRes () {
	# 1=file 2=compile 3=bin 4=output 5=std_compile
	printf "%-35s: COMPILE: %s | RET: %s | OUT: %s | STD: [%s]\n" \
		"$1" "$(getEmoji $2)" "$(getEmoji $3)" "$(getEmoji $4)" "$(getYN $5)"
}

# If diff_file empty, return 0 -> ok
# If diff is about max_size, return 2 -> warning
# Else, diff is something really important, return 1 -> error
compare_output () {
	# 1=diff_file
	if ! [ -s $1 ]; then
		return 0
	fi
	regex=$(cat <<- EOF
	^[0-9]*c[0-9]*
	< max_size: [0-9]*
	---
	> max_size: [0-9]*$
	EOF
	)

	cat $1 | grep -v -E "$regex" &>/dev/null
	[ "$?" -eq "0" ] && return 1 || return 2;
}

isEq () {
	[ $1 -eq $2 ] && echo 0 || echo 1
}

cmp_one () {
	# 1=path/to/file

	deepdir="deepthought"; logdir="logs"
	mkdir -p $deepdir $logdir
	container=$(echo $1 | cut -d "/" -f 2)
	file=$(echo $1 | cut -d "/" -f 3)
	# ex) echo $1 : srcs/vector/assign.cpp
	# ex) -f 2 : vector
	# ex) -f 3 : assign.cpp
	testname=$(echo $file | cut -d "." -f 1)
	# ex) srcs/vector/assign.cpp
	# ex) srcs/vector/assign
	ft_bin="ft.$container.out"; ft_log="$logdir/ft.$testname.$container.log"
	std_bin="std.$container.out"; std_log="$logdir/std.$testname.$container.log"
	std_compile_log="std.$testname.$container.compile.log"

	compile "$1" "ft"  "$ft_bin" /dev/null;  ft_ret=$?
	compile "$1" "std" "$std_bin" $std_compile_log; std_ret=$?
	same_compilation=$(isEq $ft_ret $std_ret)
	std_compile=$std_ret

	if [ $std_compile -ne 0 ] && \
		cat $std_compile_log | grep "$container/common.hpp:1" &>/dev/null; then
		rm -f $std_compile_log
		printf "${BOLD}${PURPLE}[$container/$testname] Cannot compile, please use \`./one\` to debug${EOC}\n"
		return;
	fi
	rm -f $std_compile_log

	> $ft_log; > $std_log;
	if [ $ft_ret -eq 0 ]; then
		./$ft_bin &>$ft_log; ft_ret=$?
	fi
	if [ $std_ret -eq 0 ]; then
		./$std_bin &>$std_log; std_ret=$?
	fi
	same_bin=$(isEq $ft_ret $std_ret)

	diff_file="$deepdir/$testname.$container.diff"
	diff $std_log $ft_log 2>/dev/null 1>"$diff_file";
	compare_output $diff_file
	same_output=$?

	rm -f $ft_bin $std_bin
	[ -s "$diff_file" ] || rm -f $diff_file $ft_log $std_log &>/dev/null

	printRes "$container/$file" $same_compilation $same_bin $same_output $std_compile
	rmdir $deepdir $logdir &>/dev/null
}

do_test () {
	# 1=container_name
	test_dir="$test_srcs/$1"
	test_files=`ls $test_dir | grep "cpp"`
	for file in ${test_files[@]}; do
		cmp_one "$test_dir/$file"
	done
}

function main () {
	introduce
	containers=("vector" "map" "stack")
	if [ $# -ne 0 ]; then
		containers=($@);
	fi

	for container in ${containers[@]}; do
		printf "%40s\n" $container
		do_test $container 2>/dev/null
	done
}
