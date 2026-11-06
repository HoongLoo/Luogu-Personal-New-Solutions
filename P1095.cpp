#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int m=0,s=0,t=0;
    cin>>m>>s>>t;
    vector<int> max_length(t+1,0);
    int j=0,jin=0;
    while(1){
        if(m<10){
            jin=j;
            break;
        }
        j++;
        max_length[j]=max_length[j-1]+60;
        if(j<=t&&max_length[j]>=s){
        	cout<<"Yes"<<endl<<j<<endl;;
        	return 0;
		}
		else if(j==t&&max_length[j]<s){
			cout<<"No"<<endl<<max_length[t]<<endl;
			return 0;
		}
        m-=10;
        //36 255 10 5 240
    }//  0 3 8      1 3 8    2  2 -9    3 2 -9
    if(m>=6){
    	if(t-jin<2){
    		max_length[t]=max_length[jin]+17;
		}
		else{
    		max_length[jin+2]=max_length[jin]+60;
    		jin+=2;
    		m=m+4-10;
    	}
	}
    while(1){
    	if(m<=5&&m>1){
    		if(jin+10<=t){
    			max_length[jin+10]=max_length[jin]+180;
    			jin+=10;
    			m=m-2;
			}
			else{
				if(t-jin<3){
					for(int i=jin+1;i<=t;i++){
						max_length[i]=max_length[i-1]+17;
					}
				}
				else{
					max_length[jin+3]=max_length[jin]+60;
					for(int i=jin+4;i<=t;i++){
						max_length[i]=max_length[i-1]+17;
					}
				}
				break;
			}
		}
		else{
			if(jin+7<=t){
				max_length[jin+7]=max_length[jin]+120;
				jin+=7;
			}
			else{
				for(int i=jin+1;i<=t;i++){
					max_length[i]=max_length[i-1]+17;
				}
				break;
			}
		}
	}
	for(int i=0;i<=t;i++){
		if(max_length[i]>=s){
			if(max_length[i-1]==0){
				int j=i-1;
				while(max_length[j]==0&&j>0){
					j--;
				}
				int sheng=s-max_length[j];
				int	xu=sheng/17;
				if(sheng%17!=0){
					xu++;
				}
				if(j+xu<i){
					cout<<"Yes"<<endl<<j+xu<<endl;
					return 0;
				}			
			}
			cout<<"Yes"<<endl<<i<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl<<max_length[t]<<endl;
	
}	