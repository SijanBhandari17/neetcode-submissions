class Solution {
    public:
        vector<int> countBits(int n) {
                vector<int> out;
                        for(int i = 0; i <= n; i++){
                                    int count = 0;
                                    int temp  = i;
                                                while(temp){
                                                                count++;
                                                                                temp = temp & (temp - 1);
                                                                                            }
                                                                                                        out.push_back(count);
                                                                                                                }
                                                                                                                        return out;
                                                                                                                            };
                                                                                                                            };

