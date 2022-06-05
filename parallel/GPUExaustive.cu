#include <thrust/device_vector.h>
#include <thrust/host_vector.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <fstream>
#include <random>
#include <string>
using namespace std;

struct Index{
    int incicial;
    int final;
    int size;
};

struct scoreMatch
{
    __host__ __device__

        double operator()(const char &a, const char &b) {
            if (a==b){
                return 2;
            }else{
                return -1;
            }
        }
};

vector<Index> findAllSubstrings (string A,int size){
    vector<Index> allStrings;
    Index temp;

    for(int i =0;i <= size; i++){
        for(int j = i+1; j<= size;j++){
            temp.incicial = i;
            temp.final = j;
            temp.size = j-i;
            allStrings.push_back(temp);
        }
    }
    return allStrings;
}

int main(){
    vector <char> dnaA_vector;
    vector <char> dnaB_vector;

    string dnaA,dnaB;
    int n,m;
    cin >> n;
    cin >> m;
    cin >> dnaA;
    cin >> dnaB;

    
    for (auto&A:dnaA){
        dnaA_vector.push_back(A);
    }
    for (auto&B:dnaB){
        dnaB_vector.push_back(B);
    }

    
    thrust::device_vector<char> dnaA_gpu(dnaA_vector);
    thrust::device_vector<char> dnaB_gpu(dnaB_vector);

    thrust::device_vector<int> tempResult(n);


    int maxScore = 0;
    int score = 0;
    int indexInicialA;
    int indexInicialB;
    int sizeMax;
        
    vector<Index> subStringsA = findAllSubstrings(dnaA,n);
    vector<Index> subStringsB = findAllSubstrings(dnaB,m);

    for (auto&subA:subStringsA){
        for (auto&subB:subStringsB){

            if(subA.size == subB.size){

                // cout << subA.size << endl;
                // cout << subB.size << endl;

                thrust::transform(dnaA_gpu.begin()+ subA.incicial , dnaA_gpu.begin()+ subA.final, dnaB_gpu.begin()+subB.incicial, tempResult.begin() , scoreMatch());
                score = thrust::reduce(tempResult.begin(),tempResult.begin()+subA.size,(int)0,thrust::plus<int>());
                // cout << score << endl;
                if (score > maxScore){
                    maxScore = score;
                    indexInicialA = subA.incicial;
                    indexInicialB = subB.incicial;
                    sizeMax = subA.size;
                }
            }
        }    
    }


    cout << maxScore << endl;
   
    cout << dnaA.substr(indexInicialA,sizeMax) << endl;

    cout << dnaB.substr(indexInicialB,sizeMax) << endl;\



    return 0;

}