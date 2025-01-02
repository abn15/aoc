#include <bits/stdc++.h>
using namespace std;

int main() {
    const string path="input.txt";

    ifstream stream(path);

    int x=0;
    int y=0;
    int section=0;

    unordered_map<int,unordered_set<int>>rules;
    vector<vector<int>>updates;

    string buffer;

    while(getline(stream,buffer)){
        if(buffer.empty()){
            ++section;
            continue;
        }

        if(section==0){
            size_t index=buffer.find('|');
            int k=stoi(buffer.substr(0,index));
            int v=stoi(buffer.substr(index+1));
            rules[k].insert(v);
        } else if(section==1){
            vector<int>update;
            stringstream string_stream(buffer);
            string item;

            while(getline(string_stream,item,',')){
                update.push_back(stoi(item));
            }

            updates.push_back(update);
        }
    }

    for(vector<int>& update : updates){
        bool valid=true;

        for(size_t j=0;j<update.size() && valid; ++j){
            for(size_t i = 0; i < j && valid; ++i){
                if(rules[update[j]].find(update[i])!=rules[update[j]].end()){
                    valid=false;
                }
            }
        }

        if(valid){
            x+=update[update.size()/2];
        } else{
            sort(update.begin(), update.end(), [&rules](const int a, const int b) -> bool {
                return rules[b].find(a) != rules[b].end();
            });

            y += update[update.size() / 2];
        }
    }

    cout << x << " " << y <<endl;
    return 0;
}
