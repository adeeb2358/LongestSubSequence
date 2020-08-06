//
//  main.cpp
//  LongestSubSequence
//
//  Created by adeeb mohammed on 20/07/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

void printVector(std::vector<char> &input){
    for (auto ch : input) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
}

//time complexity is o(nm(min(n,m))) = space complexity
std::vector<char> longestCommonSubsequence(std::string str1,
                                           std::string str2) {
    std::vector<std::vector<std::vector<char>>>  lcs;
    for (int i = 0; i <= str2.size(); i++) {
        lcs.push_back(std::vector<std::vector<char>>());
        for (int j = 0; j <= str1.size(); j++) {
            lcs[i].push_back(std::vector<char>());
        }
    }
    for (int i = 1; i <= str2.size(); i++) {
        for (int j = 1; j <= str1.size(); j++) {
            if (str2[i-1] == str1[j-1]) {
                std::vector<char> copy = lcs[i-1][j-1];
                copy.push_back(str2[i-1]);
                lcs[i][j] = copy;
            }else{
                lcs[i][j] = lcs[i-1][j].size() > lcs[i][j-1].size() ? lcs[i-1][j] : lcs[i][j-1];
            }
        }
    }
    return lcs[str2.length()][str1.length()];
}

int main(int argc, const char * argv[]) {
    std::string str1="adeeb";
    std::string str2="aadeeb";
    auto result = longestCommonSubsequence(str1, str2);
    printVector(result);
    std::cout << "Longest Subsequence!\n";
    return 0;
}
