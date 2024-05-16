// #Team4T's compact template, by AkiLotus.
// Powered by Alice Engine.

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define endl '\n'

void readadj(vector<vector<int>> &adj, int vertex, int edge);
template <typename T> void readwadj(vector<vector<pair<int, T>>> &adj, int vertex, int edge);
template <typename T> void read1d(vector<T> &vec, int dim);
template <typename T> void read2d(vector<vector<T>> &vec, int dim1, int dim2);

namespace soln {
    const int friends = 3;
    vector<int> demand(friends), supply(friends);
    
    void Preprocess() {
        
    }
    
    void Input(int testcase) {
        read1d(demand, friends);
        read1d(supply, friends);
    }
    
    void Solve(int testcase) {
        int total_supply = 0;
        for (int i=0; i<friends; i++) {
            total_supply += supply[i];
            if (total_supply < demand[i]) {
                cout << "No\n";
                return;
            }
            total_supply -= demand[i];
        }
        cout << "Yes\n";
    }
};

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    soln::Preprocess();
    int T = 1;
    // cin >> T; cin.ignore();
    for (int testcase=1; testcase<=T; testcase++) {
        soln::Input(testcase); soln::Solve(testcase);
    }
    return 0;
}

template <typename T> void read1d(vector<T> &vec, int dim) {
    vec.clear(); vec.resize(dim);
    for (auto &z: vec) cin >> z;
}

template <typename T> void read2d(vector<vector<T>> &vec, int dim1, int dim2) {
    vec.clear(); vec.resize(dim1, vector<T>(dim2));
    for (auto &row: vec) for (auto &z: row) cin >> z;
}

void readadj(vector<vector<int>> &adj, int vertex, int edge) {
    adj.clear(); adj.resize(vertex);
    for (int i=0; i<edge; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
}

template <typename T> void readwadj(vector<vector<pair<int, T>>> &adj, int vertex, int edge) {
    adj.clear(); adj.resize(vertex);
    for (int i=0; i<edge; i++) {
        int u, v; T w;
        cin >> u >> v >> w; u--; v--;
        adj[u].emplace_back(make_pair(v, w));
        adj[v].emplace_back(make_pair(u, w));
    }
}

/*
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢋⢥⢼⣞⣬⡑⢎⣹⣏⠁⡨⠣⠰⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠑⠍⡙⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢋⣺⢗⣪⣧⢼⣻⡯⡽⢾⣯⣟⣺⡟⢫⡯⣟⣶⣙⡆⡀⡀⡀⡀⡀⡀⡀⡀⠓⣈⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢏⡗⣥⣿⡿⣛⣺⡯⢽⣞⣯⣝⡮⣽⠿⠋⡁⡀⡀⠂⡀⠑⡀⠂⡀⡀⡀⡀⡀⡀⡀⠳⡄⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢏⡯⣼⣿⡟⢾⠵⣢⣾⡿⣿⣿⢿⣿⢁⢊⢘⠁⣨⠊⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠈⡦⠈⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣽⣜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣽⡽⣽⣱⢫⣳⢽⢙⣾⣿⣋⣺⣿⣿⣿⡀⡂⢁⢀⣐⡻⡀⡀⡀⡀⡀⡀⡀⡀⢀⡀⡀⡀⡀⡀⡀⠙⠉⠢⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡆⣿⣬⣿⣯⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⣽⣺⣷⡯⣯⡝⣵⣛⣋⣲⣿⣿⣿⣛⠟⣤⣺⣾⣻⣇⣷⠢⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣄⡀⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣶⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⣽⣿⣿⢹⢅⡿⣝⢗⣿⣟⣿⣿⠋⠔⣴⡟⣾⢵⣭⠟⡴⠁⠢⠄⢪⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢳⣣⣤⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⡁⢿⣷⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢱⢣⣿⣿⡏⠍⡟⣮⣎⣿⣿⢿⡿⡠⠅⣾⢋⣿⣻⡷⣡⠏⠎⠃⡐⢑⠎⠄⡃⡀⡀⡀⡀⠢⣇⡀⡀⡀⡀⢀⡀⡀⢷⣿⣧⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⢻⣿⡌⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠯⡟⣿⣿⣿⡜⡾⣜⣕⡾⠁⢀⣾⣧⠁⣾⣋⣽⣟⡿⣰⡣⡴⠂⢆⠊⢸⢐⡢⠈⡀⡀⡀⡀⡀⢿⡀⡀⡀⡀⡀⡀⡀⡀⣿⣷⡆⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣾⣿⣿⢱⢏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣸⣸⢱⣿⢇⢰⢱⣗⣿⡀⢀⣿⣟⢿⢼⢵⡷⣵⣷⣰⢃⣰⠈⢆⡀⢀⣿⠄⠰⠢⠆⡀⠂⡀⡀⠘⡀⡀⡀⡀⡀⡀⡀⡀⠈⣿⢸⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣮⠻⣿⡇⣻⢻⣿⣿⣿⣿⣿⣿⣿⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⡏⡏⣿⣿⡎⢇⣝⣻⡇⡀⣿⣿⡟⣟⣽⣿⣸⣿⢡⡱⣴⠁⡜⠃⢀⣿⢺⢢⠢⢅⢐⡀⡇⡂⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡸⣿⣿⣿⣧⠉⡇⠸⣿⣹⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣸⢠⢀⣿⡗⣯⢺⡿⣗⠅⢠⣿⣿⣼⠅⣿⣿⣿⢏⣱⡰⠃⡀⠃⣈⠟⢣⡘⡀⡆⠁⡀⠄⡅⢇⡀⡀⢰⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡈⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⣿⣇⣷⣿⡈⠡⠣⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⢮⡟⢢⣾⡺⢺⠇⣷⠁⢸⡟⢣⡟⣪⡯⡃⣿⠂⡵⡞⡀⡀⡿⠁⢀⣼⡇⡀⡇⡀⡇⡊⡇⢸⡀⡀⡌⡀⢀⡀⡀⢠⡀⠈⡀⡀⡀⢘⢣⡀⢿⣿⣿⣿⣿⣿⣿⣿
⣇⣸⣾⣿⣿⡟⡔⠂⢻⣿⡺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢈⡱⢎⡩⡿⡿⣿⡀⣿⡀⣿⢘⡟⣾⣯⣽⢪⡟⡾⣺⡀⡀⠈⡀⢠⠇⢀⢠⡀⡇⣾⠃⠑⡇⢸⡀⠈⡇⡀⢸⡀⡀⢸⡀⡀⡀⢀⡀⢸⡀⠹⣄⠙⣿⣿⣿⣿⣿⣿
⣿⣿⢨⣿⣿⣿⠙⣧⢀⢻⣧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢸⣇⣘⣴⣳⢘⣿⢠⢿⡀⣷⣫⠟⣿⡺⡻⣸⡇⢇⠇⡀⡐⠔⣠⡝⡀⡺⠎⡀⡇⣷⢸⠈⡇⢸⡀⡀⡀⡀⣝⡀⠇⣿⡇⡀⡀⢸⡀⢸⢆⠁⠹⣿⣶⣽⣿⣿⣿⣿
⣿⣏⣸⣿⣿⢿⡧⠘⣧⡄⢿⣎⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⣱⡇⡯⡏⣼⣿⣨⣞⣭⠿⣋⣾⠇⣡⢯⢼⠁⢸⡀⡀⠥⡼⡍⢠⠸⠃⡰⡀⠃⠃⠏⠄⡀⣾⡀⡸⡀⡀⡛⡀⡀⠿⣿⣤⡀⣸⡀⢸⡃⣦⡀⠙⣿⣿⣿⣿⣿⣿
⣿⠹⣿⡿⣿⡦⢿⢣⢻⡸⢈⢿⣮⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⡥⣗⢻⠅⡏⢸⠨⣦⠐⢹⣼⢫⢣⣿⡣⢸⢸⣿⡀⠁⡼⠞⠴⠇⢜⢐⠿⢸⡀⢰⡀⠈⡀⢿⡀⡀⡸⡼⠾⡀⠾⢾⣽⣿⢠⠅⠎⢸⠇⡏⣦⠡⠳⢿⣿⣿⣿⣿
⣿⡇⢹⣿⣿⡟⣿⢓⣼⣻⢫⠂⣿⣜⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⣇⢭⡜⡀⡇⠸⡀⣱⣉⣵⣱⡽⣾⣻⣎⠸⡇⡏⡀⢋⢃⣒⡀⡠⡉⠚⣳⡎⡄⢁⠨⠨⢐⣺⡀⠁⠁⢋⠄⣠⣁⣉⢉⠃⡀⠞⠂⡇⢀⡇⣿⣿⣿⣦⣙⣿⣿⣿
⣿⣿⢲⣿⣿⣿⣾⣇⡸⣝⣎⣎⡜⣿⣎⣿⣿⣿⣿⣿⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣿⢸⠑⡀⡇⡀⣗⣠⣿⡾⡕⣼⣿⡼⢫⣕⣧⣏⡎⣿⠁⢰⡜⢠⣿⣿⣶⠠⡀⡰⡔⡘⠢⡇⡞⡀⡇⢻⠜⣿⢿⡇⡟⢀⢀⢇⡀⢸⠄⡃⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⡞⡌⣿⣿⣿⣿⢜⣏⠞⡯⣗⢳⣿⡼⣿⣿⣿⣿⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡇⣿⡀⡆⡀⣷⡀⣏⡏⡀⡼⠘⡎⣏⣷⣇⣻⡽⢸⢸⣌⢛⠶⣖⣛⡹⣬⠁⣾⡀⢣⡀⠃⠏⡇⢀⣯⣣⠤⣟⠯⡪⢧⢁⠃⢸⠏⡀⣿⡆⢸⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣷⣿⣏⣯⣿⣟⣷⣻⠐⠽⡹⡕⣿⣿⣟⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢸⢻⡄⣿⡀⢸⡀⠸⣝⡌⢐⠐⣷⣿⠹⣿⣍⠳⣧⡀⡄⣿⣤⣓⢜⡝⣗⢾⡇⡀⡀⣨⠏⡼⢰⣿⣻⣞⣻⣟⡾⣳⡵⠁⡸⠃⣼⢀⣿⢸⣼⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⡜⣿⣿⣿⣦⢿⠐⠨⣷⣯⠍⣿⣿⡽⢿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠠⡆⣿⠘⣿⡀⡄⡀⡆⠳⣓⣦⢻⡸⡀⠹⣿⣶⡈⢆⠈⠻⣿⣿⣿⣷⡫⣞⡥⡀⠜⠔⣼⡇⣹⡻⣫⣝⣪⣽⡪⠈⡔⠠⡀⣾⠃⣾⣿⡂⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣷⣿⣿⣻⢿⣧⢧⠤⢿⠸⣟⡄⡿⣿⣿⣻⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢻⡀⢷⠘⣿⡹⠘⠘⠠⢠⠛⠈⣷⡇⡀⠘⣧⡯⢦⡀⠦⡹⣿⣿⡿⡣⣪⠟⠤⢁⡾⢾⠂⡗⢷⢏⢽⣿⣲⢎⠞⢀⣢⣿⣏⣺⣿⢇⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⢹⣻⡗⣷⣿⣧⢧⡮⡧⢳⢿⡈⣝⣿⣿⢿⣿⣿⣿⣿⣿⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣿⣮⣝⣄⠻⣧⡀⠳⡀⠣⡀⢿⣿⡀⡀⡀⢿⣿⣯⣆⢌⢿⣿⣿⢟⣥⣡⣾⣟⢝⣿⣼⡺⢹⢾⣮⢽⠷⢁⣨⣾⣿⣿⣳⣿⢟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⡧⣿⣷⢾⣿⣿⣧⢫⣧⣜⡧⢛⣜⣵⣿⣿⡻⣿⣿⣿⣿⣿⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣳⡀⠙⣄⡀⠙⣿⡆⡀⡀⠠⡙⠿⣿⣷⡤⠙⢷⡮⢝⣫⣗⢗⣺⣺⣾⡯⢾⣗⡲⣻⣏⢏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣷⣎⣷⣇⣿⣿⣿⣦⢞⡼⡺⣇⡄⠊⣿⣿⣿⡻⣿⣿⣿⣿⣿⣜⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⣿⢋⢿⢲⢷⣤⣿⣿⢸⡄⡀⢸⠨⣅⢉⡯⣙⣶⣍⡳⢯⡗⡪⢽⣻⣯⣽⣳⣏⡵⢏⢟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⢿⢹⣿⡞⣿⣿⣿⡔⣻⢷⢟⣶⢄⡀⢿⣿⣷⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇⣿⡘⢸⠇⢻⢹⣾⡄⣿⡀⠸⢄⢿⣷⠸⢲⢮⣹⣕⣝⢧⡾⡯⣯⡶⣖⣽⡻⠓⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣺⣺⣿⣿⣿⣿⣿⣯⠣⣿⡕⢪⡽⠿⣤⡿⣿⣷⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢯⢸⣿⠃⡼⢸⠈⣧⣷⣧⣿⡀⡀⡀⠉⠿⣧⡱⢯⢗⣕⢵⡳⣻⢗⡫⣺⣮⣿⠋⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣧⢺⣿⢎⣧⢾⣸⣗⣮⢿⣿⣿⣯⢿⣿⣿⣾⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣫⣿⣿⠁⣼⠃⣃⡰⠟⣾⣿⢻⡆⡀⠻⣄⡐⡠⠉⠫⣮⣺⡷⡮⢝⢽⡺⣾⠋⡀⣸⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣧⠸⡪⡝⡮⢿⡈⢯⣧⡽⣿⣿⣿⡿⣿⣿⣯⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢈⣴⣷⣟⣟⣿⢸⡌⣿⡘⡀⡀⠃⡀⠈⠱⡢⢕⡂⡉⠓⡛⠮⡽⠟⠠⡀⡀⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣷⡳⢟⣎⡎⡹⡳⡢⡺⡻⣿⣿⣿⣯⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣭⣿⢿⣿⣵⡿⠫⠘⠚⢿⡇⡀⡀⢀⠐⡀⠑⣀⠃⡄⠂⢸⣿⣿⣹⡜⡀⡀⡀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢀⠹⣿⣿⡟⡕⢟⡮⠣⢜⣮⣄⠻⣳⣿⣿⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⡾⠛⠛⢉⠚⢀⣰⠟⡀⡀⡀⡁⡀⡀⡀⢄⡀⠁⡀⠑⢢⡂⣿⣿⣿⡿⣷⡀⢥⢀⠈⣿⣿⣿⣿⢿⣿⣻⣷⣟⣼⢿⣿⠟⣾⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣇⣦⢺⣾⣿⠽⣗⣇⡙⡇⡱⢇⡻⣦⣬⡿⣿⣿⣿⣿⣽⣻⡻⣻⣿⣿⣿⣿⣿⣿⣿⠟⠉⠠⠂⢠⠊⡀⡀⡀⡀⡀⡀⡀⡀⣇⡀⡀⠄⠄⠉⡀⠂⡀⡀⡀⠄⠻⣿⣿⣿⠃⢽⣼⢠⣏⣿⣿⣿⣋⣾⣠⢰⢸⢝⣧⣿⣾⡿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡌⡦⢾⡿⣻⣽⣿⡹⢮⡕⢇⡎⢬⣦⡛⠿⣿⣿⣿⣿⣷⣿⡻⣎⣿⣿⣿⣿⣿⣤⣤⡠⣄⠜⡀⡀⡀⡀⡀⡀⢀⠠⠂⡎⢸⡀⡀⠡⡀⡀⢀⡀⡀⡀⡀⡀⡀⠈⠻⣿⡆⣼⢿⡆⣌⣿⣿⣭⢢⠇⣽⠛⡄⡕⠸⣕⣐⣱⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢷⢳⡯⠯⣿⣿⡯⢪⡞⣻⡺⠷⢮⣏⡻⡲⢆⢙⢿⣿⣿⣿⣜⣜⣿⣿⣿⣿⣿⣿⡇⢮⡀⡀⡀⡀⡀⡀⡀⡀⡀⠉⢧⡼⡀⡇⠐⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠈⢿⡸⢯⣇⣿⣿⣿⠌⡗⣯⣦⢴⣫⡆⣴⣿⣏⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣕⡢⢿⢳⢻⡿⣞⢹⢝⢱⡑⢭⣭⣞⣮⡩⢾⣻⣦⠻⣿⣷⣿⣿⣴⣿⣿⣿⣿⠏⣴⠉⡀⡀⡀⡀⡀⡀⡀⢠⡀⢀⡀⣇⡇⠸⠠⠠⡀⡀⡀⠄⡀⠉⠒⡀⡀⡀⡀⡀⠈⢷⡼⣸⣋⠿⣦⣈⠿⡾⢧⣩⣾⢁⣾⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⡎⡪⡧⢎⡻⣻⡸⢽⡯⢸⢪⡕⣹⣓⢎⡪⡺⢯⡝⢦⠚⣿⣿⣿⣷⡻⡿⢡⠋⡀⡀⡀⣠⠎⡀⡀⡀⣠⡿⡀⡀⢰⡀⠇⡀⠆⡀⡀⡀⡀⡀⡀⠁⠸⡆⠠⡀⡀⡀⡀⡀⠉⣿⣟⡓⣖⡵⣴⡿⠉⠲⣨⠍⠋⡾⠿⠿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡿⣳⡎⣎⣜⣻⢯⡳⡳⢣⢼⡶⡃⢵⣗⡱⡮⢕⡫⠽⣀⣞⠛⣿⣿⣿⣄⡀⢸⠨⢝⣰⠃⡀⡀⡀⡴⠁⣠⠶⢛⣩⠽⢻⠛⠈⢇⡀⡀⡀⡀⡀⡀⡀⢿⡄⠑⡀⡀⡀⡀⡀⠈⡿⠿⠽⡋⠤⣈⡥⠉⣾⡀⠉⠛⣷⣄⡀⠹⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢘⢻⣿⢸⡱⣖⣷⣕⣻⢳⣏⣺⣥⠖⠭⢏⣻⣎⣱⢸⡿⡪⢮⢮⣍⣟⣿⡞⣘⣇⣷⠁⡀⡀⡀⡀⣾⠏⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠈⠸⡀⠡⡀⡀⡀⠌⡀⢻⣿⣿⣿⣿⡉⣴⣿⣿⡀⡀⡀⠘⣿⣿⣔⡻⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣿⡄⢼⢿⣧⣷⢿⣹⡜⡇⢿⢩⠭⣩⣦⡵⡎⢸⢜⢣⡮⣟⡇⡝⣝⣮⣷⣍⢷⣎⣿⠁⡀⡀⡀⡀⢞⠁⡀⡀⡀⡀⡀⡀⡀⢧⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣇⠥⡀⡀⡀⡀⡀⡀⡀⠻⣿⣿⣯⣿⠛⣛⠿⡀⠁⢙⠁⣿⣿⣿⣿⣌⢻⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢻⡇⢣⣕⢷⢯⢝⣻⣻⢸⡮⣧⡼⢳⡮⢽⣮⣵⡪⢼⣛⡙⢍⡜⡪⠹⡬⠻⣿⢝⣿⣷⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢀⠐⠈⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡇⡀⡄⡄⡀⡀⢀⡀⡀⡀⠂⣿⣿⠇⡀⡀⣠⣿⣄⠈⢐⠿⣿⣿⣿⣿⣧⢻⣿
⣟⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣗⣿⣇⣚⡪⡎⡎⢬⣷⣧⢼⣣⣮⢝⡱⢾⣻⢕⢢⠿⣛⡳⡍⢱⣚⡵⠭⢕⡿⣟⣷⠹⡸⡄⡀⡀⡀⡀⡀⡀⡀⡀⢀⡁⠌⡀⠱⡀⡀⡀⡀⡀⡀⡀⡀⡀⡇⢢⢸⡇⡀⡀⡀⠈⠑⡀⡀⠹⣿⡀⡀⣾⣿⣿⠡⠰⡀⢸⢸⣿⣿⣿⣿⢸⣿
⣿⣿⣿⣧⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢿⢽⢗⣱⢽⣿⢺⣏⢻⣆⡯⡓⡜⡓⢪⣕⡫⠵⡜⣽⢧⡪⢜⡮⢲⡖⣮⡙⣿⠿⡆⣇⠇⠠⡀⡀⡀⡀⡀⡀⡀⡣⡀⡀⡀⠇⠱⡀⡀⡀⡀⡀⡀⡀⢀⡀⢣⡀⡇⡀⠨⡀⡀⡀⡀⡀⢀⡇⢀⣿⣿⣿⢁⣓⡇⡸⢸⠆⣆⡸⣿⣿⣸⣿
⣿⣿⣿⣿⡌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣌⠲⡺⢯⣷⣇⣝⡳⢻⡌⡺⢹⣎⡸⢵⢎⡱⣇⠨⢕⡪⢆⡬⣵⡵⡢⡙⡏⣣⣿⢸⡀⠐⠃⡀⡀⡀⢀⢫⣸⠁⡀⡀⢀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢸⡀⡇⠃⡀⡄⡀⡀⡀⡀⠁⢧⣿⣿⡿⡰⢧⡾⡀⡧⣨⢀⡀⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣷⣎⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣓⣯⣾⢫⢽⢧⢧⡜⡻⢳⣎⡸⡏⡕⣾⡡⢝⡪⢫⢫⢇⣜⣿⣇⢸⢿⢸⠸⡀⢐⡀⡀⢠⢲⡪⢥⡀⡀⡀⡀⠃⡀⡀⡀⡀⡀⡀⡀⠠⡀⡀⡀⠸⡀⡷⠐⡀⠰⡀⡀⡀⡀⡀⡀⣿⡿⣗⣺⢂⡀⡀⡎⢋⡞⣰⣠⠢⢀⣿⣿
⣿⣿⣿⣿⣿⢸⡦⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣶⡹⢟⢽⣳⢒⢌⡜⣳⡎⢜⡣⢜⣜⡳⡎⢢⢺⡧⣞⣶⡍⢉⢸⣿⡾⡀⡀⠨⡀⡀⡏⣹⣷⠁⡀⡀⡀⢐⡀⡀⡀⡀⡀⡀⡀⡀⠐⡀⡀⡀⡀⡀⡇⢀⡀⡀⡀⡀⡀⡀⠨⠘⠘⣧⡿⡇⡀⡢⢀⠉⡞⠳⡰⢌⡴⠙⠿⣿
⣿⣿⣿⣿⣿⡗⣻⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣽⣿⣷⣿⣶⡘⢜⣻⡣⢼⣏⣳⡯⢱⡧⢜⡕⢎⡣⢜⡜⡵⠟⡖⢪⠸⣾⠁⡀⡀⠐⡀⡀⢵⣎⠃⡀⠠⡀⡀⠂⡀⡀⡀⡀⡀⡀⡀⡀⡀⠄⡀⡀⡀⡀⡇⠂⡀⡀⡄⡀⡀⡀⡀⠂⠳⢿⡏⢸⡪⡀⠊⢠⢟⣿⠖⠉⣽⣿⡷⢼
⣿⣿⣿⣿⣿⣷⡿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣷⣻⣿⣿⣿⣷⣙⢟⡍⢌⡮⡳⡻⢯⢜⢪⢎⣝⣎⣹⢐⢊⡱⣪⡵⠻⡀⡀⠆⠈⡀⢀⢇⡟⡀⠠⠄⡀⢀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢀⡀⡀⡀⡀⡀⡀⠈⡇⡍⠅⣀⣾⣟⡷⢁⣶⣿⣿⣿⣕⣸
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⣿⡼⣿⣿⣿⣿⣿⣷⣝⢕⡸⡎⢻⡩⠭⠆⢱⡗⢯⡟⡢⡜⡕⢸⡀⠂⡀⡀⠃⡀⡀⣸⣺⡀⡀⡼⡇⢀⠁⡀⡀⡀⡀⡀⡀⡀⡀⡀⡇⡀⡀⡀⡀⡀⡀⠄⡀⡀⢘⡀⡀⡀⡀⡀⡎⡀⡧⠪⢰⣷⣾⣩⣶⣟⣷⣿⢽⢏⡿⠸
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢿⣿⢿⣿⣿⣿⣿⣿⣾⣷⣕⢿⣧⡜⣣⣇⡢⡯⢭⠇⠡⠅⣇⣸⢀⡀⡀⡀⡂⡀⡀⠹⠏⡀⣰⡊⠃⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠅⡀⡀⡀⡀⢸⡀⡂⡀⡀⡀⡀⡀⡀⡀⡀⠘⣣⠸⠈⣿⢿⣾⣟⣿⣿⢯⢫⢝⣳⣱⣳
⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⢿⣏⣿⣿⣿⣿⣿⣿⣿⣿⣿⣌⢎⣝⣜⡊⣇⣯⡀⢅⡅⢵⢼⠐⡀⡀⡀⢹⡀⡀⡀⡀⠂⡣⡞⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠁⡀⡀⡀⡀⡀⡀⡀⢀⡀⢝⡀⡇⢏⣟⣿⣿⢟⡟⢫⣝⢯⢕⡳⣺
⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣎⡛⣿⣿⣿⣿⣷⣉⢚⡀⣗⡏⡀⢝⡇⠊⠐⡀⠄⡀⡀⢂⡀⡀⡀⡀⢔⠘⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡌⡀⡀⡀⠰⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠉⠄⣦⢸⡣⡧⣿⢯⡿⢜⡧⢝⢇⡼⣳⠫
⣿⣿⣿⣿⣿⣿⢯⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⡰⡉⠿⣿⣿⣿⣷⡑⢕⡱⠁⡎⡇⡀⡀⠠⡀⡀⡀⠈⡀⡀⡀⢃⠅⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣰⡀⡀⡀⡀⡂⡀⡀⡀⢀⡀⡀⡀⡀⡀⠈⢄⡀⢺⢸⡊⢿⡟⡯⠵⡳⣫⢳⢮⡊⢱⢃
⣿⣿⣿⣿⣿⣿⡸⣻⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣮⣃⠂⠙⢿⣿⣿⣆⠚⠑⡏⡣⡀⡀⠎⡀⡀⡀⡀⡀⡠⣅⣰⡀⠈⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡇⡀⡀⡀⡀⠅⡀⢐⡀⢐⡀⡀⡀⡀⡀⡀⡀⠢⢀⢸⡎⢸⣱⠵⣎⡪⢝⢝⢞⡅⠂⣿
⣿⣿⣿⣿⣿⣿⡇⣺⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⡀⠙⢿⣿⣿⣦⠹⢿⡀⠈⡀⡀⡀⡀⡀⠌⡀⡀⡀⠈⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢀⠠⡀⡀⡀⡀⡀⡀⡀⢀⣞⡣⢜⢳⣜⢃⢨⣸⡍⠸⡃⣛⣾
⣿⣿⣿⣿⣿⣿⡇⢽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢦⡙⢤⡈⠻⣝⠿⣦⡀⠅⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠈⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠐⠂⡀⢳⡐⡪⢱⡌⠬⢙⡣⣨⣾⣿⣿
⣿⣿⣿⣿⣿⣿⡇⣺⡾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣕⣄⠈⠐⡙⠒⡀⡀⡀⡀⡀⡀⡀⣀⡤⡤⡤⣀⡀⢀⠁⡀⡀⢀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠂⡀⠨⡀⡀⢀⡀⡀⠁⡀⡀⡀⡀⠹⡅⡂⡰⢎⢱⢾⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣄⠙⡀⠁⡀⠐⡀⡀⡀⢈⠙⠛⠉⠁⡀⡀⠉⠓⠦⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⠂⡠⠪⢔⠊⡀⡀⡀⡀⡀⡀⡀⠹⢔⠊⣑⣼⡈⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡇⣾⣽⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⢔⢅⢌⠅⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡗⣩⣶⣿⣧⢿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡳⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⣀⠠⠔⠒⠒⠒⠂⠅⠈⠁⡀⡀⠈⡀⠂⡀⡀⡀⡀⠂⡀⡀⡀⡀⢀⠴⠏⠅⢢⠎⠁⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⡀⣘⣿⣿⣿⣿⠸⣿⣿⣿
*/