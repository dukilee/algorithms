#!bin/bash

g++ diff.cpp -std=c++11 -o diff

if ! [ $1 ]; then
  echo Please inform the folder to check
fi

f=${1%/}"/"
flag=true
cpp_name=${f%/}".cpp"
if ! [ -f $f$cpp_name ]; then
  echo There is no cpp in ${f%/}.
  flag=false
else
  g++ $f$cpp_name -std=c++11 -o temp_exec

  inputs=$(ls -d $f*.in)
  for i in $inputs; do
    o=${i/.in/.out}
    if ! [ -f $o ]; then
      echo There is no answer in test $i for ${f%/}.
      flag=false
    else
      ./temp_exec < $i > temp.out
      if [ $(./diff $o temp.out || echo fail) ]
        then
          echo Test $i for ${f%/} is not working.
          flag=false
      fi
    fi
  done
fi

if [ -f diff ]; then
	rm diff #Ubuntu
elif [ -f diff.exe ]; then
	rm diff.exe #Windows
fi

if [ -f temp_exec ]; then
	rm temp_exec
elif [ -f temp_exec.exe ]; then
	rm temp_exec.exe
fi

if [ -f temp.out ]; then
	rm temp.out
fi

if $flag; then
  echo -e '\e[32m[SUCCS]\e[0m '${f%/}
   exit 0
else
  echo -e '\e[31m[ERROR]\e[0m '${f%/}
  exit 1
fi
