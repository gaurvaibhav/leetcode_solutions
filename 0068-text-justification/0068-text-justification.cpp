#define FAST_IO ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        FAST_IO;
        vector<string> result;
        int wordCount = words.size();
        int i = 0;
        while(i < wordCount) {
            int lineLength = words[i].size();
            int j = i + 1;
            while(j < wordCount && lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }
            int numberOfWords = j - i;
            int remainingSpaces = maxWidth - lineLength;
            string line;
            if(numberOfWords == 1 || j == wordCount) {
                line = words[i];
                for(int k = i + 1; k < j; ++k) {
                    line += ' ' + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            }
            else {
                int spacesBetweenWords = remainingSpaces / (numberOfWords - 1);
                int extraSpaces = remainingSpaces % (numberOfWords - 1);
                line = words[i];
                for(int k = i + 1; k < j; ++k) {
                    line += string(spacesBetweenWords, ' ');
                    if(extraSpaces > 0) {
                        line += ' ';
                        --extraSpaces;
                    }
                    line += words[k];
                }
            }
            result.push_back(line);
            i = j;
        }
        return result;
    }
};
