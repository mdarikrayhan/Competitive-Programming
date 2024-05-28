// https://codeforces.com/contest/66/problem/C
 
#include <bits/stdc++.h>
using namespace std;
 
#define MAX 10000
 
struct node {
    int key;
    string name;
    struct node* next;
};
 
struct node* createNode (int key, string name) {
    struct node* newNode = new node();
    newNode->key = key;
    newNode->name = name;
    newNode->next = NULL;
    return newNode;
}
 
struct node* insert (struct node* head, int key, string name) {
    struct node* newNode = createNode(key, name);
    if (head == NULL) return newNode;
    struct node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}
 
void dfs (struct node** graph, int vertex, int files[]) {
    struct node* p = graph[vertex];
    while (p) {
        dfs (graph, p->key, files);
        files[vertex] += files[p->key];
        p = p->next;
    }
}
 
void dfs2 (struct node** graph, int vertex, int folders[]) {
    struct node* p = graph[vertex];
    while (p) {
        dfs2 (graph, p->key, folders);
        folders[vertex] += folders[p->key] + 1;
        p = p->next;
    }
}
 
int main () {
    string path;
    // vector<string> paths;
    int i, j = 0, start = 0, index = 0, vertex;
 
    struct node** graph = new struct node*[MAX];
    for (i=0; i<MAX; i++) graph[i] = NULL;
 
    int files[MAX] = {0}, folders[MAX] = {0};   // Number of files, folders in each directory
    files[0] = files[1] = files[2] = files[3] = files[4] = -1; // DISK C, D, E, F, G
 
    struct node* p;
    index = 4;
 
    // while (getline(cin, path)) {
    //     paths.push_back(path);
    // }
 
    // paths.push_back("C:\\folder1\\folder2\\folder3\\file1.txt");
    // paths.push_back("C:\\folder1\\folder2\\folder4\\file1.txt");
    // paths.push_back("D:\\folder1\\file1.txt");
    // paths.push_back("");
 
    // make graph
    while (getline(cin, path)) {
 
        i = 0;
        if (path[0] == 'C') vertex = 0;
        else if (path[0] == 'D') vertex = 1;
        else if (path[0] == 'E') vertex = 2;
        else if (path[0] == 'F') vertex = 3;
        else if (path[0] == 'G') vertex = 4;
        
        i = 3;
        path += '\\';
        while (i < path.size()) {
            start = i;
            for (; path[i] != '\\'; i++) {
                if (path[i] == '.') {
                    files[vertex]++;
                    break;
                }
            }
 
            if (path[i] == '\\') {
                string name = path.substr(start, i-start);
                if (graph[vertex] == NULL) graph[vertex] = createNode(++index, name);
                p = graph[vertex];
                while (p->next) {
                    if (p->name == name) break;
                    p = p->next;
                }
 
                if (p->name != name) {
                    p->next = createNode(++index, name);
                    vertex = index;
                }
                else vertex = p->key;
                i++;
            }
            else break;
        }
    }
 
    // recursively count files in directories
    dfs (graph, 0, files);
    dfs (graph, 1, files);
    dfs (graph, 2, files);
    dfs (graph, 3, files);
    dfs (graph, 4, files);
 
    // recursively count folders in directories
    dfs2 (graph, 0, folders);
    dfs2 (graph, 1, folders);
    dfs2 (graph, 2, folders);
    dfs2 (graph, 3, folders);
    dfs2 (graph, 4, folders);
 
    // iterate through arrays and find max other than 0,1,2,3,4 (DISK C, D, E, F, G)
    int max = 0;
    for (i=5; i<MAX; i++) {
        if (folders[i] > max) max = folders[i];
    }
    cout << max << " ";
    max = 0;
    for (i=5; i<MAX; i++) {
        if (files[i] > max) max = files[i];
    }
    cout << max << endl;
 
    // cout << paths.size() << endl;
    // for (int i=0; i<paths.size(); i++) {
    //     cout << paths[i] << endl;
    // }
 
    // for (i=0; i<10; i++) {
    //     p = graph[i];
    //     while (p) {
    //         cout << p->key << "|" << p->name << "|" << folders[p->key] << "    ";
    //         p = p->next;
    //     }
    //     cout << endl;
    // }
}   