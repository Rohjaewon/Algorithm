#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int wnum, snum;
vector<string> words(502, "");
vector<double> startProb(502, 0.0);
vector<vector<double> > probMetrix(502, vector<double>(502, 0.0));
vector<vector<double> > probMetrix2(502, vector<double>(502, 0.0));
vector<vector<string> > sentences(102);
vector<vector<double> > cache(102, vector<double>(502, -1.0));
vector<vector<int> > choices(102, vector<int>(502, -1));
vector<string> picked;

int findIdx(string word){
    for(int i = 0; i < wnum; i++){
        if(words[i] == word) return i;
    }
    return -1;
}

double OCR(int prev, int curr, int sth){
    if(curr == sentences[sth].size()) return 1.0;
    int wIdx = findIdx(sentences[sth][curr]);
    
    int bestIdx = -1;
    for(int i = 0; i < wnum; i++){
        double cand = 0.0;
        if(curr == 0){
            double predictProb = startProb[i]*probMetrix2[i][wIdx] / startProb[wIdx];
            // if(originalProb <= predictProb){
                cand = OCR(i, curr+1, sth) * predictProb;
            // }
        } else {
            double predictProb = probMetrix[prev][i]*probMetrix2[i][wIdx] / probMetrix[prev][wIdx];
            // if(originalProb <= predictProb){
                cand = OCR(i, curr+1, sth) * predictProb;
            // }
        }
        if(cand > ret){
            ret = cand;
            bestIdx = i;
        }
    }
    if(bestIdx != -1)
        picked.push_back(words[bestIdx]);
    return ret;
}

int main(){
    cin >> wnum >> snum;
    for(int i = 0; i < wnum; i++){
        cin >> words[i];
    }
    for(int i = 0; i < wnum; i++){
        cin >> startProb[i];
    }
    for(int i = 0; i < wnum; i++){
        for(int j = 0; j < wnum; j++){
            cin >> probMetrix[i][j];
        }
    }
    for(int i = 0; i < wnum; i++){
        for(int j = 0; j < wnum; j++){
            cin >> probMetrix2[i][j];
        }
    }
    for(int i = 0; i < snum; i++){
        int temp; cin >> temp;
        for(int j = 0; j < temp; j++){
            string w; cin >> w;
            sentences[i].push_back(w);
        }
    }
    for(int i = 0; i < snum; i++){
        OCR(-1, 0, i);
        for(int j = picked.size()-1; j >= 0; j--){
            cout << picked[j] << " ";
        } cout << endl;
        picked.clear();
    }
    return 0;
}