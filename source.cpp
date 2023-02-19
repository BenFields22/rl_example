#include <iostream>
#include "Utils.hpp"
#include <vector>
#include <cstdlib>
#include <ctime>

int sortObject(int objClass, std::vector<int> weights){
    int max = -99999999;
    int index = 0;
    int maxind = 0;
    for(int i = 5*objClass;i<5*objClass+5;i++){
        if(weights[i]>max){
            maxind=index;
            max=weights[i];
        }
        index++;
    }
    return maxind;
}
int updateWeights(int correct,int guessed, std::vector<int> &weights){
    int ans = 0;
    if(correct==guessed){
        weights[5*correct+guessed]++;
        ans=1;
    }
    else{
        weights[5*correct+guessed]--;
    }
    return ans;
}
int main(int argc, char** argv){
    std::vector<int> weights = parseIntVec();
    srand(time(NULL));
    int numcorrect = 0;
    int stopCondition = 100;
    int step = 0;
    while(numcorrect<stopCondition){
        int randnum = (rand()%5);
        std::cout << "Class is "<<randnum << std::endl;
        int selection = sortObject(randnum,weights);
        std::cout << "Model selected "<<selection << std::endl;
        int res = updateWeights(randnum,selection,weights);
        if(res){
            numcorrect++;
        }
        else{
            numcorrect=0;
        }
        step++;
        printVecNum(weights);
        std::cout  << std::endl;
    }
    std::cout << "Took "<<step<<" steps to complete with final weights:" << std::endl;
    printVecNum(weights);    
	return 0;
}
