#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> genre_play_count;  // 장르별 총 재생 횟수
    unordered_map<string, vector<pair<int, int>>> genre_songs; // 장르별 (재생 횟수, 고유 번호)

    // 1️⃣ 장르별 총 재생 횟수 및 곡 리스트 저장 (O(N))
    for (int i = 0; i < genres.size(); i++) {
        genre_play_count[genres[i]] += plays[i];  // 총 재생 횟수 누적
        genre_songs[genres[i]].push_back({plays[i], i});  // (재생 횟수, 고유번호) 저장
    }

    // 2️⃣ 장르별 총 재생 횟수를 기준으로 정렬하기 위해 vector로 변환 후 정렬 (O(G log G))
    vector<pair<string, int>> sorted_genres(genre_play_count.begin(), genre_play_count.end());
    sort(sorted_genres.begin(), sorted_genres.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second > b.second;  // 총 재생 횟수 내림차순 정렬
    });

    vector<int> answer;

    // 3️⃣ 정렬된 장르 순서대로 곡을 정렬하여 선택 (O(N log N))
    for (const auto& g : sorted_genres) {
        string genre = g.first;

        // 장르 내에서 (재생 횟수 내림차순, 고유번호 오름차순) 정렬
        auto& songs = genre_songs[genre];
        sort(songs.begin(), songs.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.first == b.first) return a.second < b.second;  // 재생 횟수가 같으면 고유번호 오름차순
            return a.first > b.first;  // 재생 횟수 내림차순
        });

        // 최대 2개의 곡을 추가
        for (int i = 0; i < min(2, (int)songs.size()); i++) {
            answer.push_back(songs[i].second);
        }
    }

    return answer;
}
