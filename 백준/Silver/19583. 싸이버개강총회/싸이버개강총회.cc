#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int to_timeint(const string& time) {
    return (time[0] - '0') * 1000 +
           (time[1] - '0') * 100 +
           (time[3] - '0') * 10 +
           (time[4] - '0');
}

int main() {
    string S, E, Q;
    cin >> S >> E >> Q;

    int s_time = to_timeint(S);
    int e_time = to_timeint(E);
    int q_time = to_timeint(Q);
    
    unordered_set<string> entered;
    unordered_set<string> exited;
    
    string time, name;
    
    while (cin >> time >> name) {
        int cur_time = to_timeint(time);
        
        if (cur_time <= s_time)
            entered.insert(name);
        else if (cur_time >= e_time && cur_time <= q_time)
            exited.insert(name);
    }
    
    int count = 0;
    for (const auto& name : entered) {
        if (exited.count(name))
            count++;
    }
    
    cout << count << endl;
    
    return 0;
}