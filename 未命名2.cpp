#include<bits/stdc++.h>
#define inf 110000
using namespace std;
map<string, int> mp;//string:名   int:编号
int p[inf],cnt[inf],dx[inf],dy[inf],sex[inf]; 
string ming[inf], xing[inf];  //保存每个人的名和姓 

bool judge(int x, int y)
{
	memset(cnt,0,sizeof(cnt));
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy)); 
    cnt[x]=1,cnt[y]=1;
    while(p[x] != -1){  //如果x有长辈时，不停的向上循环，直到没有长辈为止 
        cnt[p[x]]++;
        dx[p[x]] = dx[x] + 1; //统计多少代了 
        if(p[x] == y) return false; //如果x的上辈等于y，直接返回，输出No 
        x = p[x];
    }
    while(p[y] != -1){
        cnt[p[y]]++;
        dy[p[y]] = dy[y] + 1;
        if(cnt[p[y]] > 1){ //>1说明p[y]也是x的长辈，判断多少代，是否达到五代 
            if(dy[p[y]]>=4 && dx[p[y]] >= 4) return true;
            else return false;
        }
        y = p[y];
    }
    return true;
}

int main(){
	int n,m;
	cin>>n;
	getchar();
	for(int i=1; i<=n; i++){
		cin>>ming[i]>>xing[i];
		mp[ming[i]]=i;  //名字是唯一的，所以将名改为编号，方便处理 
		int t=xing[i].size()-1;
		if(xing[i][t]=='m'||xing[i][t]=='n') sex[i]=1;//男（m字符结尾或sson结尾的名字） 
		else sex[i]=-1; //女	
		
		//保存将后缀去掉的姓，即父亲的名 
		string s="";
		if(xing[i][t]=='n'){
			for(int j=0; j<t-3; j++) s+=xing[i][j];
		}else if(xing[i][t]=='r'){
			for(int j=0; j<t-6; j++) s+=xing[i][j];
		}
		xing[i]=s;  
	}	
	memset(p,-1,sizeof(p));//初始为-1，表示无长辈
	for(int i=1; i<=n; i++){
		if(mp[xing[i]]>0) p[i]=mp[xing[i]];  //p[i]表示编号 i 它父亲编号 
	} 
	cin>>m;
	string s1,s2,s3,s4;
	while(m--){
		cin>>s1>>s2>>s3>>s4;
		int x=mp[s1],y=mp[s3];  
		if(!sex[x]||!sex[y]) cout<<"NA"<<endl;  //sex[i]为1是男，为-1是女，为0表示没有此人 
		else if(sex[x]==sex[y])cout<<"Whatever"<<endl;//先要判断是否存在，然后在判断是否同性，不然有测试点过不了  
		else{ //异性的话，判断是否为近亲 
			if(judge(x, y)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}			
	} 
	return 0;
} 

