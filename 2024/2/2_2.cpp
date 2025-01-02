#include<bits/stdc++.h>
using namespace std;

int p=0; 

bool safe(vector<int>& vec){
    if(vec.empty())return false;

    bool inc=true,dec=true;
    bool vdiff=true;

    for(size_t i=1;i<vec.size();++i){
        int diff=vec[i]-vec[i-1];

        if(diff<0) inc=false;
        if(diff>0) dec=false;

        if(abs(diff)<1 || abs(diff)>3) {
            vdiff=false;
            break;
        }
    }

    return (vdiff && (inc || dec));
}

void solve(vector<int>& vec){
    if(safe(vec)){
        p++; 
        return;
    }

    for(size_t i=0;i<vec.size();++i){
        vector<int>temp=vec;
        temp.erase(temp.begin()+i); 
        if(safe(temp)){
            p++;
            return;
        }
    }
}


int main(){
    ifstream ifs("input.txt");
    if(!ifs.is_open()){
        cerr<<"Failed to open input file."<<endl;
        return -1;
    }

    string line;
    while(getline(ifs,line)) {
        if (line.empty()) continue; 

        istringstream iss(line);
        vector<int>vec((istream_iterator<int>(iss)),istream_iterator<int>());

        solve(vec);
    }

    cout <<p<< endl; 

    return 0;}
