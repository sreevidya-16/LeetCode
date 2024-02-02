class Solution {
public:
    // unordered_set<string> path;

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        int rows=board.size();
        int cols=board[0].size();
        int n=word.size();
        

        if(i==n) return true;
        if(
            r<0 || c<0 ||
            r==rows || c==cols ||
            word[i] != board[r][c] 
        ){
            return false;
        }
        // save the char before change it:
        char tmp=board[r][c];
        // change to a number:
        board[r][c]='0';

        bool res = dfs(board, word, r+1, c, i+1) || dfs(board, word, r-1, c, i+1) || dfs(board, word, r, c+1, i+1) || dfs(board, word, r, c-1, i+1);
        // return the cell to it's char 
        board[r][c]=tmp;

        return res; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        /*
        word=SEE
        
        [1][3]
        Adyacents: 
        [0][3]
        [2][3]
        [1][2]
        [1][4] x

        [i][j]
        Adyacents: 
        up [i-1][j]
        down [i+1][j]
        left [i][j-1]
        right [i][j+1] x
        
        [
        ["s","e","s","e"],
        ["e","s","e","s"],
        ["e","s","e","s"],
        ]

        Iterate through the matrix
        find the first letter
        find in adyacents the next letter until we found all letter:
            [i][j]
            Adyacents: 
            up [i-1][j]
            down [i+1][j]
            left [i][j-1]
            right [i][j+1] x

        O(mxnxk) k=size of word
        
        */
        int rows=board.size();
        int cols=board[0].size();
        int n=word.size();
        bool found=false;

        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(dfs(board, word, r, c, 0)){
                    return true;
                }              
            }
        }

        return found;
    }
};