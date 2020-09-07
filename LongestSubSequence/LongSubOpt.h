//
//  LongSubOpt.h
//  LongestSubSequence
//
//  Created by adeeb mohammed on 14/08/20.
//  Copyright © 2020 adeeb mohammed. All rights reserved.
//

#ifndef LongSubOpt_h
#define LongSubOpt_h

class LongSubOpt {
   
public:
    void printVector(std::vector<char> &input){
        for (auto ch : input) {
            std::cout << ch << " ";
        }
        std::cout << std::endl;
    }
    
   std::vector<char> longestCommonSubsequence(std::string str1,
                                                 std::string str2) {
       // small string and large string
           std::string small = str1.length() < str2.length() ? str1 : str2;
           std::string large = str1.length() >= str2.length() ? str1 : str2;
           
                   std::vector<std::vector<char>> evenLcs;
           std::vector<std::vector<char>> oddLcs;
                   
                   // array initialization
           for(int i = 0; i < small.length()+1; i++ ){
               evenLcs.push_back(std::vector<char>());
               
           }
                   
                    for (int i = 0; i < small.length()+1; i++) {
               oddLcs.push_back(std::vector<char>());
           }
                   
                     for (int i = 1; i < large.length() +1; i++) {
               std::vector<std::vector<char>> *currentlcs;
               std::vector<std::vector<char>> *previouslcs;
               if (i % 2 == 1) {
                   currentlcs = &oddLcs;
                   previouslcs = &evenLcs;
               }else{
                   currentlcs = &evenLcs;
                   previouslcs = &oddLcs;
               }
               for (int j = 1; j < small.length() + 1; j++) {
                   if (large[i-1] == small[j-1]) {
                       std::vector<char> copy = previouslcs->at(j-1);
                       copy.push_back(large[i-1]);
                       currentlcs->at(j) = copy;
                   }else{
                       currentlcs->at(j) =
                                           previouslcs->at(j).size() > currentlcs->at(j-1).size()
                                           ? previouslcs->at(j)
                                           :currentlcs->at(j-1);
                   }
               }
           }
                   
          return large.length() % 2 == 0 ? evenLcs[small.length()] : oddLcs[small.length()];
   }

};


#endif /* LongSubOpt_h */
