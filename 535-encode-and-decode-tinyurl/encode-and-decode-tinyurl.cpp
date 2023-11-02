class Solution {
private: 
    int codeValue = 0;
    unordered_map<string, string> mpp;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string encodedStr = "https://link//" + to_string(codeValue);
        codeValue++;
        mpp[encodedStr] = longUrl;

        return encodedStr;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mpp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));