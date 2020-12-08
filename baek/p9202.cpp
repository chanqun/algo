#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    TrieNode* children[26];
    bool isEnd;
    bool isHit;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
    TrieNode* getChild(char c) {
        return children[c - 'A'];
    }
    void clearHit() {
        isHit = false;
        for (int i = 0; i < 26; i++)
        {
            if (children[i] != NULL) {
                children[i]->clearHit();
            }
        }
    }
    bool hasChild(char c) {
        return children[c - 'A'] != NULL;
    }

};

struct Trie {
    TrieNode* root = new TrieNode();

    void insert(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            int index = c - 'A';
            if (current->hasChild(c) == false) {
                current->children[c - 'A'] = new TrieNode();
            }
            current = current->getChild(c);
        }
        current->isEnd = true;
    }

    bool checkWord(string word) {
        TrieNode* current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (current->hasChild(c)) {
                current = current->getChild(c);
            }
            else {
                return false;
            }
        }
        return current->isEnd;
    }

};
int M, W;
char map[4][4];
bool visited[4][4];
int score[] = { 0,0,0,1,1,2,3,5,11 };
int dy[] = { -1,-1,-1,0,0,1,1,1 };
int dx[] = { -1,0,1,-1,1,1,0,-1 };
int Count = 0, sum = 0;
vector <char> sol;
string temp;
string answer;

bool cmp(string args0, string args1) {
    if (args1.size() == args0.size()) {
        int n = args0.compare(args1);
        if (n > 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return args0.size() < args1.size();
    }
}

void dfs(int y, int x, int length, TrieNode* node) {
    //1. 체크인
    visited[y][x] = true;
    //sb.append(map[y][x]);
    sol.push_back(map[y][x]);
    //2. 목적지인가
    if (node->isEnd == true && node->isHit == false) {
        //단어 끝 도달 hit를 한 적 없음 목적지이다.
        node->isHit = true;
        sum += score[length];
        Count++;
        string foundWord = "";
        for (int i = 0; i < sol.size(); i++) {
            foundWord += sol[i];
        }
        if (cmp(answer, foundWord) > 0) {
            answer = foundWord;
        }
    }
    //3. 갈 수 있는 곳을 순회
    for (int i = 0; i < 8; i++)
    {
        int ty = y + dy[i];
        int tx = x + dx[i];
        //4. 갈 수 있는가?
        if (0 <= ty && ty < 4 && 0 <= tx && tx < 4) {
            if (visited[ty][tx] == false && node->hasChild(map[ty][tx])) {
                //5. 간다
                dfs(ty, tx, length + 1, node->getChild(map[ty][tx]));
            }
        }
    }
    //6. 체크 아웃
    visited[y][x] = false;
    //sb.append(map[y][x]);
    sol.erase(sol.begin() + length - 1);
}




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "r", stdin);
    Trie tr;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        tr.insert(s);
    }
    cin >> W;
    tr.root->clearHit();
    for (int k = 0; k < W; k++)
    {
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        answer = "";
        sum = 0;
        Count = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                char a;
                cin >> a;
                map[i][j] = a;
            }
        }
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (tr.root->hasChild(map[y][x])) {
                    dfs(y, x, 1, tr.root->getChild(map[y][x]));
                }
            }
        }
        tr.root->clearHit();
        cout << sum << " " << answer << " " << Count << "\n";
    }


    return 0;
}