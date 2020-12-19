#ifndef HEAPPROCESS_PROCESS_H
#define HEAPPROCESS_PROCESS_H

#include <iostream>
#include <limits>

using namespace std;

class Process
{
public:
    string processName;
    int deadLine;
    int duration;

    Process() 
    {
        this->processName = "\0";
        this->deadLine = INT_MIN;
        this->duration = INT_MIN;
    }

    Process(string pN, int dL, int d) 
    {
        this->processName = pN;
        this->deadLine = dL;
        this->duration = d;
    }

    Process &operator=(const Process &p) 
    {
        if (this != &p) {
            this->processName = p.processName;
            this->deadLine = p.deadLine;
            this->duration = p.duration;
        }
        return *this;
    }

    bool operator>(const Process &p) const 
    {
        return this->deadLine > p.deadLine;
    }

    bool operator<(const Process &p) const 
    {
        return this->deadLine < p.deadLine;
    }


    friend ostream &operator<<(ostream &out, const Process &p) 
    {
        out << p.processName;
        return out;
    }

};

#endif
