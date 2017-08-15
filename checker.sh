#!/bin/bash

testsNumber=10
executable=codewar
total=0
test=0

make 

if test ! -x $executable; then
    echo "Executable file missing."
    exit 1
fi

for (( test=1; test<=$testsNumber; test++ )) do
	cp ./inputs/$test ./codewar.in
	./$executable <codewar.in >codewar.out
	if test ! -x $executable; then
    	echo "Output file missing."
    	exit 1
	fi
	head -n 1 ./codewar.out >first
	head -n 1 ./outputs/$test >first.ref
	if diff -q first first.ref >/dev/null;  then
		echo "Test $test TASK 1.................... passed."
		((total = $total + 4))
	else 
		echo "Test $test TASK 1.................... failed."
	fi
	rm first
	rm first.ref

	head -n 2 ./codewar.out | tail -n 1 >first
	head -n 2 ./outputs/$test | tail -n 1 >first.ref
	if diff -q first first.ref >/dev/null;  then
		echo "       TASK 2.................... passed."
		((total = $total + 3))
	else 
		echo "       TASK 2.................... failed."
	fi
	rm first
	rm first.ref

	tail -n +1 ./codewar.out >second
	tail -n +1 ./outputs/$test >second.ref
	if diff -q second second.ref >/dev/null;  then
		echo "       TASK 3.................... passed."
		((total = $total + 3))
	else 
		echo "       TASK 3.................... failed."
	fi
	rm second
	rm second.ref
done
echo "TOTAL $total / 100"



