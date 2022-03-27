#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
/*the following comment text is actualy presentation of two functions which gives random char to each person*/
//void givech(char *ch,int n)
//{
//	srand(time(0));
//	int a;
//	for(int i=0;i<6;i++)
//	{
//		a=rand()%n;
//		if(*(ch+a)!='\0')
//		{
//			i--;
//			continue;
//		}
//		else
//		*(ch+a)=char(97+i);
//	}
//	int m=(n-6);
//	for(int i=0;i<(m/4);i++)
//	{
//		a=rand()%n;
//		if(*(ch+a)!='\0')
//		{
//			i--;
//			continue;
//		}
//		else
//		*(ch+a)='g';
//	}
//	for(int i=0;i<(3*m/4);i++)
//	{
//		a=rand()%n;
//		if(*(ch+a)!='\0')
//		{
//			i--;
//			continue;
//		}
//		else
//		*(ch+a)='h';
//	}
//		
//}
//void givech(char *ch,int n)
//{
//	
//	char r[9]="abcdefgh";
//	int m=(n-6);
//	int e[8]={1,1,1,1,1,1,m/4,3*m/4};
//	int i=0;
//	while(i<6)
//	{
//		srand(time(0));
//		int y=rand()%6;
//		if(e[y]!=0)
//		{
//			*(ch+i)=r[y];
//			e[y]--;
//		}
//		else
//		i--;
//		i++;
//		
//	}
//	while(i<n)
//	{
//		srand(time(0));
//		int y=(rand()%2)+6;
//		if(e[y]!=0)
//		{
//			*(ch+i)=r[y];
//			e[y]--;
//		}
//		else
//		i--;
//		i++;
//		
//	}
//}
void swap(char *r)
{
	char t;
	t=*r;
	*r=*(r+1);
	*(r+1)=t;
}
void swapt(int *r)
{
	int t;
	t=*r;
	*r=*(r+1);
	*(r+1)=t;
}
void givech(char *ch,int n){
	srand(time(0));
	char r[9]="abcdefgh";
	int l=8;
	int m=(n-6);
	int e[8]={1,1,1,1,1,1,m/4,m-m/4};
	int i=0;
	while(i<n)
	{
		int y=rand()%l;
		*(ch+i)=r[y];
		e[y]--;	
		if(e[y]==0)
		{
			for(int j=y;j<7;j++)
			{
				swap(&r[j]);
				swapt(&e[j]);
			}
			l--;
		}
		i++;
	}
}
int findmax(int vote[],int n)
{
	int t=0,p;
	int h=0;
	for(int i=0;i<n;i++)
	if(vote[i]>t)
	{
		t=vote[i];
		p=i;
	}
	for(int i=0;i<n;i++)
	if((vote[i]==t)&&(p!=i))
	h++;
	if(h>0)
	return -1;
	return p;
		
}
int search(int n,string a,string name[])
{
	for(int i=0;i<n;i++)
	if(a==name[i])
	return i;
	return -1;
}

int main() {
	system("Color 7C");
	int n,chance=2,chance2=1;
	cout<<"__________________________________________________Welcome To The MAFIA__________________________________________________\n\n";
	cout<<"enter the number of players\n";
	cin>>n;
	string name[n];
	char ch[n];
	for(int i=0;i<n;i++)
	{
	cout<<"enter the name of player number "<<i+1<<endl;
	cin>>name[i];
    }
	givech(&ch[0],n);
	string target,target1;
	int cte[n][4];
	int ncte[n][4];
	int vote[n];
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
		cte[i][j]=0;
	bool result2=0;
	while(result2!=1)
	{
		for(int i=0;i<n;i++)
			for(int j=0;j<4;j++)
			{
			ncte[i][j]=0;
		    vote[i]=0;
			}
		cout<<"its night\n_____________________________\n\n\n";
		for(int i=0;i<n;i++)
		{
			if(cte[i][3]==0)
			{
			cout<<'\n'<<'\n'<<name[i]<<" its your turn\n_____________________________\n";
			switch(ch[i])
			{
				case 'a':
					{
						cout<<"\n\nkill\nenter the target\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						ncte[q][2]=i+1;
						break;
					}
				case 'b':
					{
						int o;
						cout<<"1.oil\n2.burn\n\n\n";
						cin>>o;
						if(o==1)
						{
						cout<<"enter the target\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						cte[q][1]=1;	
						}
						else if(o==2)
						{
						for(int j=0;j<n;j++)
							if(cte[j][1]==1)
							ncte[j][3]=1;	
						}
						break;
					}
				case 'c':
					{
						cout<<"\n\nsave\nenter the target\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						ncte[q][0]=1;
						break;
					}
				case 'd':
					{
						if(chance2>0)
						{
						cout<<"\n\nlove\nenter two targets\n\n\n";
						cin>>target>>target1;
						int q=search(n,target,name);
						int w=search(n,target1,name);
						cte[q][0]=w+1;
						cte[w][0]=q+1;
					    chance2--;
						}
						else
						cout<<"sorry you have used your chance wait till the morning\n\n\n";
						break;
					}
				case 'e':
					{
						cout<<"\n\ncult\nenter the target\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						if(ch[q]!='f')
						cte[q][2]=1;
						break;
					}
				case 'f':
					{
					if(chance>0)
					{
						cout<<"\n\nshoot\nenter the target\nif you dont want to use your shot type ok\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						if(q!=-1)
						{
							if(cte[q][2]==1)
							ncte[q][1]=1;
							chance--;
						}
					}
					else
					cout<<"\n\nsorry you have taken your shot\n\n\n";
						break;
					}
				case 'g':
					{
						cout<<"\n\neat\nenter the target\n\n\n";
						cin>>target;
						int q=search(n,target,name);
						ncte[q][2]=i+1;
						break;
					}
				case 'h':
					{
						cout<<"\n\nsorry you should wait till the morning\ntype ok to continue\n\n\n";
						cin>>target;
						break;
					}
			}
			system("CLS");
		    }
		    else
		    {
		    cout<<"\n\nsorry your dead\ntype ok to continue\n\n\n";
	        cin>>target;
			}
		}
		for(int i=0;i<n;i++)
		{
			int fard=cte[i][0];
			if(ncte[i][0]==1||cte[i][3]==1)
			continue;
			else if(ncte[i][1]==1)
			cte[i][3]=1;
			else if(ncte[i][2]!=0)
			{
				int fard=ncte[i][2]-1;
				if(ch[i]=='b'&&ncte[fard][3]==1)
				cte[fard][3]=1;
				else if(ch[i]=='a'&&ncte[fard][2]==(i+1))
				cte[fard][3]=1;
				else if(ch[i]=='g'&&ch[fard]=='g'&&ncte[fard][2]==(i+1))
				{
					if(i>fard)
					cte[i][3]=1;
					else
					cte[fard][3]=1;
				}
				else
				cte[i][3]=1;
				
			}
			else if(ncte[i][3]==1)
			cte[i][3]=1;
			
			else if(fard!=0&&cte[fard-1][3]==1)
			cte[i][3]=1;
			
		}
		cout<<"\n\nits day\n\n\n";
		for(int i=0;i<n;i++)
		{
			if(cte[i][3]==0)
			{
				cout<<name[i]<<" its your turn\n_____________________________\n";
				cout<<"vote\nenter the target\n";
				cin>>target;
				int q=search(n,target,name);
				vote[q]+=1;
			}
			else
			{
				cout<<endl<<name[i]<<" sorry your dead\ntype ok to continue\n\n\n";
				cin>>target;
			}
		system("CLS");
		}
		int result=findmax(vote,n);
		if(result==-1)
		cout<<"\n\nits a tie\nnobody is dying today\n\n\n";
		else
		{
			cte[result][3]=1;
			cout<<'\n'<<'\n'<<name[result]<<" is dead\nmay GOD bless him or her\n\n\n";
		}
		bool result1=1;
		for(int i=0;i<n;i++)
		if(ch[i]!='h'&&cte[i][3]==0)
		result1=0;
		if(result1==1)
		{
		ofstream x("d:\\reasults.txt");
		cout<<"villagers won\nreasults have been saved in your D drive\n";
		x<<"villagers won\n";
		x.close();
		result2=1;
		}
		bool result3=1;
		for(int i=0;i<n;i++)
		if(ch[i]!='e'&&cte[i][3]==0)
		result3=0;
		if(result3==1)
		{
		ofstream x("d:\\reasults.txt");
		cout<<"culturals won\nreasults have been saved in your D drive\n";
		x<<"culturals won\n";
		x.close();
		result2=1;
		}
		int count=0,count1;
		for(int i=0;i<n;i++)
		if(cte[i][3]==0)
		{
		count++;
	    count1=i;
		}
		if(count==1)
		{
		cout<<name[count1]<<" won\nreasults have been saved in your D drive\n";
	    ofstream x("d:\\reasults.txt");
		x<<name[count1]<<" won\n";
		x.close();
		result2=1;
		}
		
	}
	
	return 0;
}



