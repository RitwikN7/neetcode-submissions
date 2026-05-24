/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
private:
    unordered_set<string> vis;
    string startHost;

    string getHostName(const string& url)
    {
        int pos = min(url.size(), url.find('/', 7));
        return url.substr(7, pos - 7);
    }

    void dfs(const string& url, HtmlParser& htmlParser)
    {
        string host = getHostName(url);
        if (host != startHost)
            return;

        vis.insert(url);
        for (const auto& link : htmlParser.getUrls(url))
        {
            if (vis.find(link) != vis.end())
                continue;
            
            dfs(link, htmlParser);
        }
    }

public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        startHost = getHostName(startUrl);
        dfs(startUrl, htmlParser);
        return vector<string>(vis.begin(), vis.end());
    }
};
