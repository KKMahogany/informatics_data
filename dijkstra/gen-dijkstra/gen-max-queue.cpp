#include <iostream>
#include <cassert>
#include <vector>
#include <random>

using namespace std;


struct edge {
    int startVertex, endVertex, weight;
    edge(int nStart, int nEnd, int nWeight) : startVertex{nStart},
                                              endVertex{nEnd},
                                              weight{nWeight} {}
};

// Prints:
// V E
// a_1 b_1 c_1
// a_2 b_2 c_2
// .
// .
// .
// a_E b_E c_E
void printData(int V, vector<edge> e) {
    cout << V << " " << e.size() << "\n";
    for(auto x: e) {
        cout << x.startVertex << " " << x.endVertex << " " << x.weight << "\n";
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
    if(argc != 6) {
        fprintf(stderr, "Usage: %s <vertices> <edges> <minWeight> <maxWeight> <seed>\n", argv[0]);
        exit(1);
    }
    int V = stoi(argv[1]);
    int E = stoi(argv[2]);
    int minW = stoi(argv[3]);
    int maxW = stoi(argv[4]);
    int seed = stoi(argv[5]);
    initialiseGenerator(seed);

    int S = E/V+2;

    vector<edge> e;
    for(int i = 2; i <= S; i++) {
        e.emplace_back(1, i, minW);
    }
    
    for(int s = 1; s <= S; s++) {
        for(int v = s+1; v <= V; v++) {
            if(e.size() >= E) {
                break;
            } else {
                int w;
                if(v == V) {
                    w = maxW;
                } else {
                    w = randint(minW, maxW-1);
                }
                e.emplace_back(s, v, w);
            }
        }
    }

    printData(V, e);
}
