#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <iostream>

using namespace std;

bool compareGenre(const pair<string,int> &a, const pair<string,int> &b) {
    return a.second > b.second;
}

vector<string> sortGenres(map<string, int> playTimePerGenre) {
    vector<pair<string,int>> playTimePerGenreVec(playTimePerGenre.begin(), playTimePerGenre.end());
    sort(playTimePerGenreVec.begin(), playTimePerGenreVec.end(), compareGenre);
    vector<string> ret;
    for (auto iter : playTimePerGenreVec) {
        ret.push_back(iter.first);
    }
    return ret;
}

bool comparePlays(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second) return a.first < b.first;
    else return a.second > b.second;
}

vector<int> getMostTwoPlays(vector<pair<int,int>> playsPair) {
    sort(playsPair.begin(), playsPair.end(), comparePlays);
    vector<int> ret;
    int size = (playsPair.size() >= 2)? 2 : 1;
    for (int i = 0; i < size; i++) {
        ret.push_back(playsPair[i].first);
    }
    return ret;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    // for (auto gen : genres) {
    //     cout << gen << " ";
    // } cout << endl;
    // for (auto play : plays) {
    //     cout << play << " ";
    // } cout << endl;
    map<string, int> playTimePerGenre;
    map<string, vector<pair<int,int>>> playsPerGenre;
    for (int i = 0; i < genres.size(); i++) {
        auto found = playTimePerGenre.find(genres[i]);
        if (found == playTimePerGenre.end()) {
            playTimePerGenre[genres[i]] = plays[i];
        } else {
            playTimePerGenre[genres[i]] += plays[i];
        }
        playsPerGenre[genres[i]].push_back(make_pair(i, plays[i]));
    }
    vector<string> sortedGenre = sortGenres(playTimePerGenre);
    for (auto genre : sortedGenre) {
        vector<int> mostPlays = getMostTwoPlays(playsPerGenre[genre]);
        for (auto play : mostPlays) {
            answer.push_back(play);
        }
    }
    return answer;
}

int main() {
    vector<string> genres {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays {500, 600, 150, 800, 2500};
    vector<int> answer = solution(genres, plays);
    for (auto iter : answer) {
        cout << iter << " ";
    } cout << endl;
}