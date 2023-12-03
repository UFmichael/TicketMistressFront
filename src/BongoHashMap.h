#ifndef PERSONALGITFRONT_BONGOHASHMAP_H
#define PERSONALGITFRONT_BONGOHASHMAP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BongoHashMap {
private:
    int numStates = 50, numMakes = 49, numModels = 23, numColors = 18, numTimes = 1440;
    int powerIterator = 50;
    int containerSize = 1460592000;
    vector<vector<int>> bongoContainer;
public:
    BongoHashMap();

    void addCase();
    vector<int> getCase();
    vector<vector<int>> getAllCases();
    int hashFunction(int state, int make, int model, int color, int time);
};


#endif //PERSONALGITFRONT_BONGOHASHMAP_H
