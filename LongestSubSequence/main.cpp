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
#include "LongSubOptBackTrack.h"

int main(int argc, const char * argv[]) {
    std::cout << "Longest Subsequence!\n";
    std::string str1="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string str2="CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG";
    LongestCommonSubs longSubs;
    LongSubOpt longSubOpt;
    LongSubOptBackTrack longSubOptBackTrack;
    auto result = longSubs.longestCommonSubsequence(str1, str2);
   // longSubs.printVector(result);
    auto result2 = longSubOpt.longestCommonSubsequence(str1, str2);
    longSubOpt.printVector(result2);
    auto result3 = longSubOptBackTrack.longestCommonSubsequence(str1, str2);
    longSubOptBackTrack.printVector(result3);
    return 0;
}
