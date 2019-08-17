#!bin/bash

folders=$(ls -d */)
g++ file_parser.cpp -o file_parser

rm all_codes.txt
touch all_codes.txt
all_okay=true

for f in $folders; do
  cpp_name=${f%/}".cpp"
  parsed=true
  ./file_parser $f$cpp_name > temp || parsed=false
  if $parsed ; then
    echo -e '\e[32m[SUCCS]\e[0m '${f%/}
    echo ${f%/} >> all_codes.txt
    echo  >> all_codes.txt
    cat temp >> all_codes.txt
    echo ------------------------------------------- >> all_codes.txt
  else
    echo -e '\e[31m[ERROR]\e[0m '${f%/}
    cat temp
    echo
    all_okay=false
  fi
done

if $all_okay ; then
  echo -e '\e[32m[HUGE SUCCES]\e[0m '
else
  echo -e '\e[31m[COULD BE A LOT BETTER]\e[0m '
fi

if [ -f file_parser ]; then
	rm file_parser
elif [-f file_parser.exe ]; then
	rm file_parser.exe
fi

rm temp


