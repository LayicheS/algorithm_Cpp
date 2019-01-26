#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

vector<int> findindex(string s,string sub){
    //寻找子串
    vector<int> find;
    int j=0;
    for(int i=0;i<=s.size()-sub.size();i++){
        int temp=i;
        while(s[temp]==sub[j] and j<sub.size()){
            temp++;    j++;
        }
        if(j==sub.size()){
            find.push_back(i);
        }
        j=0;
    }
    return find;
}

bool same(vector<char> s1,vector<char> s2){
    map<char,int> alpha;
    for(int i=0;i<s1.size();i++){
        if(!alpha[s1[i]])
            alpha[s1[i]]=1;
        else alpha[s1[i]]+=1;
    }
    for(int i=0;i<s2.size();i++){
        if(!alpha[s2[i]])
            return false;
        else{
            alpha[s2[i]]--;
            if(alpha[s2[i]]<0)
                return false;
        }
    }
    return true;
}

bool same(vector<string> s1,vector<string> s2){
    map<string,int> alpha;
    for(int i=0;i<s1.size();i++){
        if(!alpha[s1[i]])
            alpha[s1[i]]=1;
        else alpha[s1[i]]+=1;
    }
    for(int i=0;i<s2.size();i++){
        if(!alpha[s2[i]])
            return false;
        else{
            alpha[s2[i]]--;
            if(alpha[s2[i]]<0)
                return false;
        }
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    //多个指针，筛选出有限的组合在进一步确认是否符合要求
    vector<int> rui;
    if(s.size()==0 or words.size()==0)
        return rui;
    int step=words[0].size();
    if(s.size()<words[0].size()*words.size())
        return rui;
    vector<char> rem;
    vector<vector<char>> ram(step,vector<char>(words.size(),' '));
    for(int i=0;i<step;i++){
        for(int j=0;j<words.size();j++){
            ram[i][j]=words[j][i];
        }
    }
    vector<int> hina;
    for(int i=0;i<words.size();i++){
        hina.push_back(i*step);
    }
    int index=0;
    while(hina.back()<s.size()){
        rem.clear();
        for(int i=0;i<hina.size();i++){
            rem.push_back(s[hina[i]]);
        }
//        cout<<"LOOP"<<endl;
        if(same(rem,ram[index])){
            index++;
            for(int k=0;k<hina.size();k++){
                hina[k]++;
//                cout<<"hina[k]"<<k<<"+"<<hina[k]<<endl;
            }
            if(index==step){
                rui.push_back((hina[0]-index));
                for(int k=0;k<hina.size();k++){
                    hina[k]=hina[k]+1-index;
//                    cout<<"hina[k]"<<k<<"+"<<hina[k]<<endl;
                }
                index=0;
            }
        }
        else{
            for(int k=0;k<hina.size();k++){
                hina[k]=hina[k]+1-index;
            }
            index=0;
        }
    }
    vector<int> toji;
    for(int i=0;i<rui.size();i++){
        vector<string> test;
        for(int j=0;j<words.size();j++){
            test.push_back(s.substr(rui[i]+step*j,step));
        }
        if(same(test,words))
            toji.push_back(rui[i]);
    }
    return toji;
}

vector<int> findSubstring1(string s, vector<string>& words) {
    //直接遍历 (慢)
    vector<int> toji;
    if(s.size()==0 or words.size()==0)
        return toji;
    int step=words[0].size();
    if(s.size()<step*words.size())
        return toji;
    for(int i=0;i<=s.size()-step*words.size();i++){
        vector<string> test;
        for(int j=0;j<words.size();j++){
            test.push_back(s.substr(i+step*j,step));
        }
        if(same(test,words))
            toji.push_back(i);
    }
    return toji;
}

vector<int> findSubstring2(string s, vector<string>& words) {
    vector<int> toji;
    map<int,int> rui;
    vector<int> temp;
    if(s.size()==0 or words.size()==0)
        return toji;
    int step=words[0].size();
    if(s.size()<step*words.size()){
        cout<<"?"<<endl;
        return toji;
    }
    for(int i=0;i<words.size();i++){
        temp=findindex(s,words[i]);
        for(int j=0;j<temp.size();j++){
            rui[temp[j]]++;
        }
    }
    map<int, int>::iterator iter;
    for(iter = rui.begin(); iter != rui.end(); iter++) {
        vector<string> test;
        for(int j=0;j<words.size() and iter->first+step*j<s.size();j++){
            test.push_back(s.substr(iter->first+step*j,step));
//            cout<<iter->first<<endl;
        }
        if(same(test,words))
            toji.push_back(iter->first);
    }
    return toji;
}

int main(){
    vector<string> words={"a"};
    string s="";
    vector<int> result=findSubstring2(s,words);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}