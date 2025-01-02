//easier w regex
#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream ifs("input.txt");
    if(!ifs.is_open()) return -1;

    string ss((istreambuf_iterator<char>(ifs)),istreambuf_iterator<char>());
    ifs.close();

    regex mul(R"(mul\((\d+),(\d+)\))");
    regex doo(R"(do\(\))");
    regex dont(R"(don't\(\))");

    bool enabled=false; 
    int total=0;

    auto it=ss.begin();
    while(it!=ss.end()){
        string remaining(it,ss.end());

        smatch match;
        if(regex_search(remaining,match,mul)){
            if (enabled) {
                int n1 = stoi(match[1].str());
                int n2 = stoi(match[2].str());
                total += n1 * n2;
            }
            it += match.position() + match.length();
        }
         else if (regex_search(remaining, match, doo)) {
            enabled = true;
            it += match.position() + match.length();
        } else if (regex_search(remaining, match, dont)) {
            enabled = false;
            it += match.position() + match.length();
        } else {
            break; // No more matches
        }
    }

    cout << total << endl;
    return 0;
}
