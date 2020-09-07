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
#include "LongestCommonSubs.h"
#include "LongSubOpt.h"

int main(int argc, const char * argv[]) {
    std::string str1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str2="CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG";
    LongestCommonSubs longSubs;
    LongSubOpt longSubOpt;
    auto result = longSubs.longestCommonSubsequence(str1, str2);
   // longSubs.printVector(result);
    auto result2 = longSubOpt.longestCommonSubsequence(str1, str2);
    longSubOpt.printVector(result2);
    std::cout << "Longest Subsequence!\n";
    return 0;
}
