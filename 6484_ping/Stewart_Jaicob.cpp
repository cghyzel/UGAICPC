//
//  main.cpp
//  Ping!
//
//  Created by Jaicob Stewart on 5/18/14.
//
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(int argc, const char * argv[])
{
    vector<int> satelliteIntervals;
    string line;
    int pingAsInt,expectedPing,i =1,j=0;
    bool endOfInput = false;
    stringstream input;
    
    //take in input
    while(!endOfInput){
        getline(cin, line);
        if(line.length() > 1){
            input << line << "\n";
        }
        else{
            endOfInput = true;
        }
    }

    //iterate over each line in the input file
    while(getline(input,line)){
        for(auto ping = next(line.begin()); ping != line.end(); ++ping){
            pingAsInt = *ping - '0';
            expectedPing = 0;
            //see how many satellites are pinging on this interval
            for(j = 0; j < satelliteIntervals.size(); ++j){
                if(i % satelliteIntervals[j] == 0){
                    ++expectedPing;
                }
            }
            expectedPing = expectedPing % 2;
            if(pingAsInt != expectedPing){
                satelliteIntervals.push_back(i);
            }
            ++i;
        }
        //print the results
        for(auto canHear = satelliteIntervals.begin(); canHear != satelliteIntervals.end(); ++canHear){
            if(next(canHear) == satelliteIntervals.end()){
                cout << *canHear;
            }
            else{
                 cout << *canHear << " ";
            }
        }
        //reset for the next line
        satelliteIntervals.clear();
        i = 1;
        cout << "\n";
    }
    
    
}








