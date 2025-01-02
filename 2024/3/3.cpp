#include<bits/stdc++.h>
using namespace std;
int main() {
	ifstream ifs{ "input.txt" };
	if (!ifs.is_open()) return -1; 

   string ss((istreambuf_iterator<char>(ifs)),istreambuf_iterator<char>()); //conv the input.txt to a string ss
   ifs.close();
    int total=0;
//     for(size_t i=0;i<ss.size();++i){
//         if(ss[i] == 'm' && ss[i + 1] == 'u' && ss[i + 2] == 'l' && ss[i + 3] == '(')
// {
//             size_t start=i+4; // Start after "mul("
//             size_t comma=ss.find(',',start); 
//             size_t end=ss.find(')',start);
        
//        if(comma!=string::npos&& end!=string::npos && comma<end) {
//                 string ch1=ss.substr(start,comma-start);
//                 string ch2=ss.substr(comma+1,end-comma-1);

//                 if(all_of(ch1.begin(),ch1.end(),::isdigit) && 
//                     all_of(ch2.begin(),ch2.end(),::isdigit)){
//                     int n1=stoi(ch1);
//                     int n2=stoi(ch2);

//                     total+=n1*n2;
//                 }
//             }

//             i = end; }
        
//     }

//REGEX WAYY
    regex pattern(R"(\bmul\((\d+),(\d+)\))");//define the pattern
    auto it=ss.cbegin();
    smatch num;

    while(regex_search(it,ss.cend(),num,pattern)) {
        int n1=stoi(num[1].str());
        int n2=stoi(num[2].str());
        total += n1 * n2;
        it = num[0].second;
    }
    cout<<total<<endl;
    return 0;}
