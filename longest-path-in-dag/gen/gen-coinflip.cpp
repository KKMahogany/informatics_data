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
        fprintf(stderr, "Usage: %s <edges> <seed>\n", argv[0]);
        exit(1);
    }
    int E = stoi(argv[1]);
    int seed = stoi(argv[2]);
    initialiseGenerator(seed);

    vector<edge> e;
    int V = 1;
    while(e.size() < E) {
        int v1 = V++;
        int v2 = V++;
        int v3 = V++;
        int v4 = V++;
        int v5 = V++;
        int v6 = V;
        e.emplace_back(v1, v2);
        e.emplace_back(v1, v3);
        e.emplace_back(v4, v5);
        e.emplace_back(v5, v6);
        if(randint(1, 2) == 1) {
            e.emplace_back(v2, v5);
            e.emplace_back(v3, v4);
        } else {
            e.emplace_back(v2, v4);
            e.emplace_back(v3, v5);
        }
    }
    while(e.size() > E) {
        e.pop_back();
    }
    printData(V, e);

    return 0;
}
