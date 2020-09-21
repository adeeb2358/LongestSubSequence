//
//  LongSubOptBackTrack.h
//  LongestSubSequence
//
//  Created by adeeb mohammed on 11/09/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#ifndef LongSubOptBackTrack_h
#define LongSubOptBackTrack_h

class LongSubOptBackTrack {

    
public:
    void printVector(std::vector<char> &input){
         for (auto ch : input) {
             std::cout << ch << " ";
         }
         std::cout << std::endl;
     }
    // function for building the longest common subsequence using back tracking.
    std::vector<char> longestCommonSubsequence(std::string str1,
                                               std::string str2) {
        std::vector<std::vector<std::vector<int>>> lcs(str2.length()+1,
                        std::vector<std::vector<int>>(str1.length()+1
                        ,std::vector<int>(4,0))
                        );
        
        for (int i = 1; i <  str2.length()+1; i++) {
            for(int j = 1; j < str1.length()+1; j++){
                if (str2[i-1] == str1[j-1]) {
                    lcs[i][j] = {str2[i-1],lcs[i-1][j-1][1]+1,i-1,j-1};
                }else{
                    if (lcs[i][j-1][1] > lcs[i-1][j][1]) {
                        lcs[i][j] = {-1,lcs[i][j-1][1],i,j-1};
                    }else{
                        lcs[i][j] = {-1,lcs[i-1][j][1],i-1,j};
                    }
                }
            }
        }
        return buildSequence(lcs);
    }
    
    std::vector<char> buildSequence(std::vector<std::vector<std::vector<int>>> lcs){
        std::vector<char> sequence;
        int  i = (int)lcs.size() - 1; // final row in the lcs table
        int  j = (int)lcs[0].size() - 1; // final column in the lcs table
        while (i != 0 && j != 0) {
            std::vector<int> currentEntry = lcs[i][j];
            if(lcs[i][j][0] != -1){
                sequence.insert(sequence.begin(), currentEntry[0]);
            }
            i = currentEntry[2];
            j = currentEntry[3];
        }
        return sequence;
    }
};

#endif /* LongSubOptBackTrack_h */
