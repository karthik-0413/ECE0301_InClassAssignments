#ifndef SORTABLEARRAY_H
#define SORTABLEARRAY_H
#include <fstream>
using namespace std;

//Declaring Class for SortableArray
class SortableArray
{
private:
    double* data;
    unsigned int size;

public:
    SortableArray();
    SortableArray(unsigned int);
    ~SortableArray();
    double* getData() const;
    unsigned int getSize() const;
    void zeroArray();
    void random();
    void textFile(ofstream&, bool);
};

#endif