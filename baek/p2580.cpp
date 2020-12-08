#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
int sudoku_arr[9][9] = { 0 };
 
// 수도쿠 값을 출력해준다. 
void print_sudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku_arr[i][j];
            if (j != 8)
                cout<<  " ";
        }
        cout << endl;
    }
}
 
void sudoku_slove(int row, int col) {
    // 위치에서 가능한 값을 체크한다. (가능한 값을 배열에 넣자)
    int used_num_arr[9] = { 0 };
    vector<int> each_round_can_vec;
 
    // 가로 세로 체크 
    for (int i = 0; i < 9; i++) {
        if (sudoku_arr[row][i])        used_num_arr[sudoku_arr[row][i] -1 ] = 1;
        if (sudoku_arr[i][col])        used_num_arr[sudoku_arr[i][col] -1 ] = 1;
    }
 
    // 그룹의 첫번째 시작놈을 기준으로 인덱스 설정 
    int sub_row = row / 3, sub_col = col / 3;
    sub_row *= 3;  sub_col *= 3;
 
    // 그룹 체크 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudoku_arr[sub_row][sub_col + j ])        used_num_arr[sudoku_arr[sub_row][sub_col + j] -1 ] = 1; 
        }
        sub_row++; 
    }
 
    // 사용되지 않은 숫자들을 전부 벡터에 넣어준다. 
    for (int i = 0; i < 9; i++) {
        if (!used_num_arr[i]) each_round_can_vec.push_back(i+1);
    }
 
    // 사용되지 않은 숫자가 없으면 그냥 리턴하고, 있으면 해당 위치에 값을 넣고 재귀함수로 다음 단계로 간다. 
    if (!each_round_can_vec.size()) return;
 
 
    //  다음 단계로 넘어간다. 
    int next_row=row, next_col=col;
    while (true) {
        // 다음 컬럼이 9가 되면 
        if ((++next_col) == 9) {
            next_row++;
            next_col = 0;
            // 만약 모든 수가 끝났다면, 프린트하고 종료한다. 
            if (next_row == 9) {
                sudoku_arr[row][col] = each_round_can_vec[0];
                print_sudoku();
                exit(0);
            }
        }
        if (next_row == 9) break;
        if (sudoku_arr[next_row][next_col] == 0) break;
    }
 
 
    for (int i = 0; i < each_round_can_vec.size(); i++) {
        sudoku_arr[row][col] = each_round_can_vec[i];
        sudoku_slove(next_row, next_col);
        sudoku_arr[row][col] = 0;
    }
 
}
 
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku_arr[i][j];
        }
    }
    
    // 그룹 체크 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku_arr[i][j] == 0) {
                sudoku_slove(i, j);
            }
        } 
    }
    return 0;
}
