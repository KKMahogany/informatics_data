#include <iostream>
#include <algorithm>
#include <cassert>
#include <vector>
#include <random>

using namespace std;


struct edge {
    int startVertex, endVertex;
    edge(int nStart, int nEnd) : startVertex{nStart},
                                 endVertex{nEnd} {}
};

// Prints:
// V E
// a_1 b_1
// a_2 b_2
// .
// .
// .
// a_E b_E
void printData(int V, vector<edge> e) {
    cout << V << " " << e.size() << "\n";
    for(auto x: e) {
        cout << x.startVertex << " " << x.endVertex << "\n";
    }
}


mt19937 generator;
bool generatorInitialised;
bool initialiseGenerator(int seed) {
    generatorInitialised = true; 
    generator = mt19937(seed);
}

int randint(int a, int b) {
    assert(generatorInitialised && "randint called before generator was initialised");
    uniform_int_distribution<int> distribution(a, b);
    return distribution(generator);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <vertices> <seed>\n", argv[0]);
        exit(1);
    }
    int V = stoi(argv[1]);
    int seed = stoi(argv[2]);
    initialiseGenerator(seed);

    vector<edge> e;
    for(int i = 1; i <= V-1; i++) {
        e.emplace_back(i, i+1);
    }
    printData(V, e);

    return 0;
}
