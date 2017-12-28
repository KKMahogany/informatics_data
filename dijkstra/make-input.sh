#!/bin/bash

# Compile generators
cd gen-dijkstra/

g++ -std=c++11 gen-line.cpp -o ../gen-line
g++ -std=c++11 gen-empty.cpp -o ../gen-empty
g++ -std=c++11 gen-max-queue.cpp -o ../gen-max-queue
g++ -std=c++11 gen-equality-breaker.cpp -o ../gen-equality-breaker
g++ -std=c++11 gen-clique.cpp -o ../gen-clique
g++ -std=c++11 gen-anti-reflexive-breaker.cpp -o ../gen-anti
g++ -std=c++11 gen-multi-line.cpp -o ../gen-multi-line

cd ..

hun=$((10**5))
tho=$((10**3))

DIJK_SEED=78462

# Test minimal answer
./gen-line 2 0 0 $((++DIJK_SEED)) > test-minimal-answer.in

# Test one edge, random weight
./gen-line 2 0 $hun $((++DIJK_SEED)) > test-one-edge-random-weight.in

# Test maximal answer
./gen-line $tho $hun $hun $((++DIJK_SEED)) > test-maximal-answer.in

# Test priority_queue often being empty
./gen-empty 333 $((++DIJK_SEED)) > queue-empty-a-lot.in

# Test maximum things in queue
./gen-max-queue 1000 50000 1 $hun $((++DIJK_SEED)) > max-things-in-queue.in

# Test expand on equality to minimum distance
./gen-equality-breaker 1000 20 0 $hun $((++DIJK_SEED)) > break-expand-on-equality.in

# Break "modifying" inserted intems into the priority queue
./gen-clique 1000 50000 100 10 $((++DIJK_SEED)) > break-modify-insert.in

# Break anti-reflexive comparator
./gen-anti 1000 50000 20 0 $hun $((++DIJK_SEED)) > break-anti-reflexive.in

# Break poor handling of multiedges 1
./gen-multi-line 1000 50 0 $hun $((++DIJK_SEED)) > break-multi-edges-1.in

# Break poor handling of multiedges 2
./gen-multi-line 2 50000 0 $hun $((++DIJK_SEED)) > break-multi-edges-2.in


# Delete compiled generators.
rm gen-line
rm gen-empty
rm gen-max-queue
rm gen-equality-breaker
rm gen-clique
rm gen-anti
rm gen-multi-line
