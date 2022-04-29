#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <fstream>
#include <random>
using namespace std;

/*
1. Gerar uma subsequencia sb=b[j,j+1,...,j+k] de b, de tamanho aleatório k, 1<=k<=m, e 0<=j<=m 
2. Gerar um número aleatório inteiro positivo p
3. Gerar p subsequencias sa=a[i,i+1,...,i+k] de a, com tamanho k calculado no passo (1), 0<=i<=n
4. Calcular os scores de cada par (sa,sb) com os pesos wmat, wmis e wgap
5. Devolver o score máximo m entre os scores do passo (4) e as subsequencias associadas a ele
*/

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
    for (int i = 0; i < size; i++){
        totalScore += score(dna1[i], dna2[i]);
    }
    return totalScore;
}

string subDnaB(string dna2, int m, int k, int j){ 
    int count = 0;
    string newSeq;

    while(count < k){
        newSeq += dna2[count + j];
        count++;
    }
    return newSeq;

}

string subDnaA (string dna1, int n, int k, int i){
    int count = 0;
    string newSeq;

    while(count < k){
        newSeq += dna1[count + i];
        count++;
    }
    return newSeq;
    

}

int main(){

    //reading input data
    string dnaA,dnaB;
    int n,m;
    cin >> n;
    cin >> m;
    cin >> dnaA;
    cin >> dnaB;
    // string dnaB = "SSAss";
    // string dnaA = "SSBss";
    // int n = 11;
    // int m = 11;
    int i,j,k,p;
    default_random_engine generator;
    generator.seed(0);
    string dnaAsub, dnaBsub;
    int max_score = -2147483648;
    int current_score = -2147483648;
    string max_scoreA, max_scoreB;
    int stop = 0;
    while (stop < 200){
        // cout <<"--------------------------------------" << endl;
        uniform_int_distribution<int> kAleatorio(1, m);
        k = kAleatorio(generator);
        while (k > m || k > n ){
            k = kAleatorio(generator);
        }

        uniform_int_distribution<int> jAleatorio(0,m-k);
        j = jAleatorio(generator);

        dnaBsub = subDnaB(dnaB,m,k,j);

        // cout<< "k aleatorio eh" << k << endl;
        // cout<< "J aleatorio eh" <<j << endl;
        // cout << "seguencia do DNAB eh" << dnaBsub << endl;

        


        uniform_int_distribution<int> pAleatorio(1,100);
        p = pAleatorio(generator);
        // cout << " o valor de p eh" << p << endl;
        int count = 0;
        while (count < p){
            uniform_int_distribution<int> iAleatorio(0,n-k);
            i = iAleatorio(generator);
            // cout << "n:" << n << endl;
            // cout << "k:" << k << endl;
            // cout<<" numero teoricamente aleatorio" << i << endl;
            dnaAsub = subDnaA(dnaA,n,k,i);
            // cout << "A sequencia do dnaA eh " <<dnaAsub << endl;

            current_score = calculateTotalScore(dnaAsub,dnaBsub,k);
            // cout << current_score << endl;
            // if (current_score == 0){
            //     cout << " -------------" << endl;
            //     cout << dnaAsub << endl;
            //     cout << dnaBsub << endl;
            // }
            if (current_score >= max_score){
                max_score = current_score;
                max_scoreA = dnaAsub;
                max_scoreB = dnaBsub;
            }
        
        count ++;
        }
        stop ++;
    }

    cout << max_score << endl;
    cout <<"A sequencia motrix eh "<< max_scoreA << endl;
    cout <<"A sequencia motrix eh "<< max_scoreB << endl;
}