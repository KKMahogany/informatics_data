#!/bin/bash

# Compile generators
cd gen/

declare -a generators

for i in *.cpp; do
    g++ -std=c++11 $i -o ../${i%.cpp}
    generators+=(${i%.cpp})
done

cd ..

hun=$((10**5))

SEED=92872

# max-in
./gen-max-in $hun $((++SEED)) > max-in.in

# max-out
./gen-max-out $hun $((++SEED)) > max-out.in

# Break move closest
./gen-close $hun $((++SEED)) > close.in

# Line
./gen-line $hun $((++SEED)) > line.in

# Coin flips
./gen-coinflip $hun $((++SEED)) > coinflip.in

# Delete compiled generators.
rm ${generators[*]}
