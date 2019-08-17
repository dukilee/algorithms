#!bin/bash

folders=$(ls -d */)
all_okay=true

for f in $folders; do
  bash verifier.sh $f || all_okay=false
done

if $all_okay ; then
  echo -e '\e[32m[HUGE SUCCES]\e[0m '
else
  echo -e '\e[31m[COULD BE A LOT BETTER]\e[0m '
fi
