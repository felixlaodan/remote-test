#include<bits/stdc++.h>
#define inf 110000
using namespace std;
map<string, int> mp;//string:��   int:���
int p[inf],cnt[inf],dx[inf],dy[inf],sex[inf]; 
string ming[inf], xing[inf];  //����ÿ���˵������� 

bool judge(int x, int y)
{
	memset(cnt,0,sizeof(cnt));
	memset(dx,0,sizeof(dx));
	memset(dy,0,sizeof(dy)); 
    cnt[x]=1,cnt[y]=1;
    while(p[x] != -1){  //���x�г���ʱ����ͣ������ѭ����ֱ��û�г���Ϊֹ 
        cnt[p[x]]++;
        dx[p[x]] = dx[x] + 1; //ͳ�ƶ��ٴ��� 
        if(p[x] == y) return false; //���x���ϱ�����y��ֱ�ӷ��أ����No 
        x = p[x];
    }
    while(p[y] != -1){
        cnt[p[y]]++;
        dy[p[y]] = dy[y] + 1;
        if(cnt[p[y]] > 1){ //>1˵��p[y]Ҳ��x�ĳ������ж϶��ٴ����Ƿ�ﵽ��� 
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
		mp[ming[i]]=i;  //������Ψһ�ģ����Խ�����Ϊ��ţ����㴦�� 
		int t=xing[i].size()-1;
		if(xing[i][t]=='m'||xing[i][t]=='n') sex[i]=1;//�У�m�ַ���β��sson��β�����֣� 
		else sex[i]=-1; //Ů	
		
		//���潫��׺ȥ�����գ������׵��� 
		string s="";
		if(xing[i][t]=='n'){
			for(int j=0; j<t-3; j++) s+=xing[i][j];
		}else if(xing[i][t]=='r'){
			for(int j=0; j<t-6; j++) s+=xing[i][j];
		}
		xing[i]=s;  
	}	
	memset(p,-1,sizeof(p));//��ʼΪ-1����ʾ�޳���
	for(int i=1; i<=n; i++){
		if(mp[xing[i]]>0) p[i]=mp[xing[i]];  //p[i]��ʾ��� i �����ױ�� 
	} 
	cin>>m;
	string s1,s2,s3,s4;
	while(m--){
		cin>>s1>>s2>>s3>>s4;
		int x=mp[s1],y=mp[s3];  
		if(!sex[x]||!sex[y]) cout<<"NA"<<endl;  //sex[i]Ϊ1���У�Ϊ-1��Ů��Ϊ0��ʾû�д��� 
		else if(sex[x]==sex[y])cout<<"Whatever"<<endl;//��Ҫ�ж��Ƿ���ڣ�Ȼ�����ж��Ƿ�ͬ�ԣ���Ȼ�в��Ե������  
		else{ //���ԵĻ����ж��Ƿ�Ϊ���� 
			if(judge(x, y)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;			
		}			
	} 
	return 0;
} 

