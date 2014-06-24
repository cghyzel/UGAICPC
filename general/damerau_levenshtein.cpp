#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

// This is comparing the two words, word1 and word 2, and the array d_L_Matrix


int minimum(int & num1, int & num2, int & num3){
    return std::min(std::min(num1, num2), num3);
}

int minimum(int & num1, int & num2){
  return std:: min(num1,num2);
}
int main(){
  // Damerau Levenshtein Matrix
  int ** d_L_Matrix;
  char * word1;
  char * word2;
  // For sake of simplicity, we will consider the length of word1 as length of word1Length
  int word1Length;
  int word2Length;
  // We take in the input for word1 and word 2 and then the lengths
  cin >> word1;
  cin >> word2;
  cin >> word1Length;
  cin >> word2Length;
  d_L_Matrix = int*[word1Length];
  for(int i = 0; i < word1Length; ++i){
    d_L_Matrix = int[word2Length];
  }
  for(int i =0; i< word1Length;++i){
    d_L_Matrix[0][i] = i;
  }
  for(int i =0 ;i < word2Length; ++i){
    d_L_Matrix[i][0] = i;
  }
  int cost = 0;
  for(int i =0; i< word1Length; ++i){
    for(int j =0 ;j< word2Length; ++j){
      // If the letter in the word at word1[i] is the same as word[j] we will set the cos to be 0, if not then 2,
      // In terms of the problem spell checker, icpc, in the regular implementation they use 1,
        if(word1[i] == word[j]){
          cost = 0;
        }else{
          cost = 2;
        }
      
      
        d_L_Matrix[i][j] = minimum(d_L_Matrix[i-1][j] + 2, // THis is a deletion mistake
                                d_L_Matrix[i][j-1] + 2, // THis is the insertion mistake
                                d_L_Matrix[i-1][j-1] + cost}; // this last comparison is a substitution mistake
                                
        if(cost == 0){
                      
        }else{
          cost = 1;
        }                                }
        if(i > 1 && j > 1 && word1[i] == word2[j-1] && word1[i-1] == word2[j]){
          d_L_Matrix[i][j] = minimum(d_L_Matrix[i][j], d_L_Matrix[i-2][j-2] + cost); // Comparison between transposition and the other three mistakes, 
        }
      
      }
  }
 cout << d_L_Matrix[word1Length][word2Length]; // Prints the damerau-Levenshtein distance in accordance to the penalties
                                                // of spell checker, you can change the penalties to 1 to make it 
                                                // work in accordance with the regular damerau-Levenshtein formula
}
