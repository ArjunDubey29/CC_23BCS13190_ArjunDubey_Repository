class Solution {
public:
    
    void buildLPS(string &pat, vector<int> &lps) {
        int m = pat.size();
        int len = 0; // length of previous longest prefix suffix
        lps[0] = 0;

        int i = 1;
        while (i < m) {
            if (pat[i] == pat[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i++] = 0;
                }
            }
        }
    }

    vector<int> search(string &pat, string &txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        buildLPS(pat, lps);

        vector<int> result;

        int i = 0, j = 0;

        while (i < n) {
            if (txt[i] == pat[j]) {
                i++;
                j++;
            }

            if (j == m) {
                result.push_back(i - j); // found match
                j = lps[j - 1];
            }
            else if (i < n && txt[i] != pat[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return result;
    }
};