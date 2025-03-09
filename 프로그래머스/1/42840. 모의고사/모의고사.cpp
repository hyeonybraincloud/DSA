#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> high_scorer;
    
    vector<int> idiot_1 = {1, 2, 3, 4, 5};
    vector<int> idiot_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> idiot_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int correct_idiot_1 = 0;
    int correct_idiot_2 = 0;
    int correct_idiot_3 = 0;
    int max_score;
    
    for (int i = 0; i < answers.size(); i++) {
        if (idiot_1[i % idiot_1.size()] == answers[i])
            correct_idiot_1++;
        if (idiot_2[i % idiot_2.size()] == answers[i])
            correct_idiot_2++;
        if (idiot_3[i % idiot_3.size()] == answers[i])
            correct_idiot_3++;
    }
    
    max_score = max(correct_idiot_1, correct_idiot_2);
    max_score = max(max_score, correct_idiot_3);
    
    if (max_score == correct_idiot_1) high_scorer.push_back(1);
    if (max_score == correct_idiot_2) high_scorer.push_back(2);
    if (max_score == correct_idiot_3) high_scorer.push_back(3);
    
    return high_scorer;
}