#include <string>
#include <vector>
#include <stack>

using namespace std;

int find_top(vector<vector<int>> board, int move)
{
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i][move-1] != 0) return i;
    }
    return -1;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int basket_top = -1;
    stack<int> s_basket;

    for(int move : moves)
    {
        int board_top = find_top(board, move);
        if(board_top == -1) continue;

        int grab_doll = board[board_top][move-1];
        board[board_top][move-1] = 0;

        if(s_basket.empty()) basket_top = -1;
        else basket_top = s_basket.top();

        if(basket_top == grab_doll)
        {
            answer++;
            s_basket.pop();
        }
        else s_basket.push(grab_doll);
    }

    return answer * 2;
}