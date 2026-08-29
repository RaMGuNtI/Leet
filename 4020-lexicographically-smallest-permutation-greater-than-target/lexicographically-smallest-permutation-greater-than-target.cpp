class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        map<char, int> freq;

        for (char c : s) {
            freq[c]++;
        }

        string result = "";

        for (int i = 0; i < target.size(); i++) {

            if (freq.contains(target[i])) {

                result += target[i];

                freq[target[i]]--;

                if (freq[target[i]] == 0) {
                    freq.erase(target[i]);
                }
            }

            else {
                auto it = freq.upper_bound(target[i]);

                if (it != freq.end()) {

                    result += it->first;

                    it->second--;

                    if (it->second == 0) {
                        freq.erase(it);
                    }

                    for (auto &[ch, count] : freq) {
                        result += string(count, ch);
                    }

                    return result;
                }

                break;
            }
        }

        for (int i = result.size() - 1; i >= 0; i--) {

            freq[result[i]]++;

            auto it = freq.upper_bound(target[i]);

            if (it != freq.end()) {

                string answer = result.substr(0, i);

                answer += it->first;

                it->second--;

                for (auto &[ch, count] : freq) {
                    answer += string(count, ch);
                }

                return answer;
            }
        }

        return "";
    }
};