#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <fstream>
#include <random>
#include <string>
using namespace std;


int score(char a, char b)
{
    if (a == b)
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int calculateTotalScore(string dna1, string dna2, int size){
    int totalScore = 0;
    for (int i = 0; i <= size; i++){
        totalScore += score(dna1[i], dna2[i]);
    }
    return totalScore;
}

vector<string> findAllSubstrings (string A,int size){
    vector<string> allStrings;

    for(int i =0;i <= size; i++){
        for(int j = i+1; j<= size;j++){
            allStrings.push_back(A.substr(i,j));
        }
    }
    return allStrings;
}


int main(){
    string dnaA,dnaB;
    int n,m;
    cin >> n;
    cin >> m;
    cin >> dnaA;
    cin >> dnaB;


    vector <string> allSubsDnaA = findAllSubstrings(dnaA,n);
    vector <string> allSubsDnaB = findAllSubstrings(dnaB,m);

    int currentScore = 0;
    int maxScore = 0;

    string maxDnaA;
    string maxDnaB;

    for (auto&A:allSubsDnaA){
        for (auto&B:allSubsDnaB){
            if (A.length() == B.length()){
                currentScore = calculateTotalScore(A,B,A.length());
                if(currentScore >= maxScore){
                    maxScore = currentScore;
                    maxDnaA = A;
                    maxDnaB = B;
                }

            }
        }
    }

    cout << maxScore << endl;
    cout << maxDnaA << endl;
    cout << maxDnaB << endl;


    return 0;
}