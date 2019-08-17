#!bin/bash

folders=$(ls -d */)
all_okay=true

for f in $folders; do
	if ! [ $f == "auxiliar_codes/" ]; then
		bash verifier.sh $f || all_okay=false
	fi
done

if $all_okay ; then
  echo -e '\e[32m[HUGE SUCCES]\e[0m '
else
  echo -e '\e[31m[COULD BE A LOT BETTER]\e[0m '
fi
