//代码是错误的，把<=k条件笼统以为是分k段条件
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
    string stra,strb;
    int alen=0,blen=0,count=0;
    cin>>alen>>blen>>count;
    cin>>stra>>strb;
    map<char,vector<int>> locat;
    for(int i=0;i<blen;i++){
        char c=strb[i];
        locat[c].push_back(i);
    }
    for(auto it=locat.begin();it!=locat.end();it++){
        reverse(it->second.begin(),it->second.end());
    }
    vector<int> len_count(blen,0);
    vector<int> minline_count(blen,1);
    int can_to_strb=0;
    bool has_addline=false;
    for(int i=0;i<alen;i++){
        char c=stra[i];
        auto it=locat.find(c);
        if(it==locat.end()){
            continue;
        }
        bool is_enc=false;
        for(int j=0;j<it->second.size();j++){
            int e=it->second[j]; 
            if(e==can_to_strb){
                can_to_strb++;
                is_enc=true;
                has_addline=false;
            }
            else{
                is_enc=false;
            }
            if(e==0){
                len_count[0]++;
            }
            else{
                len_count[e]+=len_count[e-1];
            }
        }
        if(!is_enc&&!has_addline){
            minline_count[can_to_strb]=minline_count[can_to_strb-1]+1;
            has_addline=true;
        }
    }
    cout<<len_count[blen-1]<<endl;
}