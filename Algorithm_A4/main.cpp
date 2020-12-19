#include "MinHeap.h"
#include <chrono>  //Simple clock library.
#include <fstream>
#include <sstream> //Used for String stream.
#include <vector> 

using namespace std::chrono;

int main() 
{
    auto* minHeap = new MinHeap(1000);
    ifstream in("inputFile");
    if (!in) 
    {
        cerr << "can’t open ctof for reading\n";
        return 1;
    }

    string prog;
    getline(in, prog, '\n');
    while (prog != "\0") 
    {
        vector<string> tokens;
        stringstream check1(prog);
        string intermediate;
        while (getline(check1, intermediate, ' ')) 
        {
            tokens.push_back(intermediate);
        }

        if (tokens[0] == "schedule") 
        {
            std::cout << minHeap->internalTime << ": adding " << tokens[1] << " with deadline " << tokens[2]
                << " and duration " << tokens[3] << "-----";
            Process tmp(tokens[1], stoi(tokens[2]), stoi(tokens[3]));
            auto start = high_resolution_clock::now();
            minHeap->insert(tmp);
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<microseconds>(stop - start);
            cout << "Time taken by insert is: "
                << duration.count() << " microseconds" << endl;
        }
        else if (tokens[0] == "run") 
        {
            int time = stoi(tokens[1]);
            while (time > 0) 
            {
                auto start = high_resolution_clock::now();
                Process tmp = minHeap->remove();
                auto stop = high_resolution_clock::now();
                auto duration = duration_cast<microseconds>(stop - start);
                cout << "Time taken by remove is: "
                    << duration.count() << " microseconds" << endl;

                if (tmp.processName != "\0") 
                {
                    std::cout << minHeap->internalTime << ": busy with " << tmp.processName << " with deadline "
                        << tmp.deadLine
                        << " and duration " << tmp.duration << std::endl;
                    if (tmp.duration > time) 
                    {
                        tmp.duration = tmp.duration - (stoi(tokens[1]) - minHeap->internalTime);
                        minHeap->internalTime = minHeap->internalTime + time;
                        std::cout << minHeap->internalTime << ": adding " << tmp.processName << " with deadline "
                            << tmp.deadLine
                            << " and duration " << tmp.duration << std::endl;
                        time = 0;
                        minHeap->insert(tmp);
                    }
                    else 
                    {
                        minHeap->internalTime = minHeap->internalTime + tmp.duration;
                        time = time - tmp.duration;
                        if (minHeap->internalTime > tmp.deadLine)
                        {
                            std::cout << minHeap->internalTime << " :done with " << tmp.processName << " (late)"
                                << std::endl;
                        }
                        else
                        {
                            std::cout << minHeap->internalTime << " :done with " << tmp.processName << std::endl;
                        }
                    }
                }
                else 
                {
                    time = 0;
                }
            }
        }
     
        getline(in, prog, '\n');
    }
    return 0;
}