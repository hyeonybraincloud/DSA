#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<string, vector<string>> team_to_members;
    unordered_map<string, string> member_to_team;
    
    for (int i = 0 ; i < N; i++) {
        string team_name;
        int member_count;
        cin >> team_name >> member_count;
        
        vector<string> members(member_count);
        for (int j = 0; j < member_count; j++) {
            cin >> members[j];
            member_to_team[members[j]] = team_name;
        }
        
        sort(members.begin(), members.end());
        team_to_members[team_name] = members;
    }
    
    for (int i = 0; i < M; i++) {
        string name_or_team;
        int quiz_type;
        cin >> name_or_team >> quiz_type;
        
        if (quiz_type == 0) {
            for (const string& member : team_to_members[name_or_team])
                cout << member << endl;
        }
        else if (quiz_type == 1)
            cout << member_to_team[name_or_team] << endl;
    }
    
    return 0;
}