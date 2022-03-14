// https://leetcode.com/problems/simplify-path/

class Solution {
public:
    string simplifyPath(string path) {
        
        // copy the path into a stringstream for easier handling
        istringstream path_ss(path);
        
        vector<string> dirs;
        string dirname;
        
        while (getline(path_ss, dirname, '/')) {
            
            if (dirname == "..") {
                
                if (!dirs.empty()) dirs.pop_back();
                
            } else if (dirname != "" && dirname != ".") {
                
                dirs.push_back(dirname);
            } 
        }

        string result;
        for (const string& d : dirs) result += "/" + d;
        
        return dirs.empty() ? "/" : result;
    }
};
