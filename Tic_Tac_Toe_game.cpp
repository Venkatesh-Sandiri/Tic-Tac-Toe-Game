#include <iostream>
#include <limits>
using namespace std;
void printformat()
{
	cout<<"1 | 2 | 3"<<endl;
	cout<<"---------"<<endl;
	cout<<"4 | 5 | 6"<<endl;
	cout<<"---------"<<endl;
	cout<<"7 | 8 | 9"<<endl;
}
void printSelected(char** arr)
{
	int cnt=1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(arr[i][j]=='a')
			{
				cout<<cnt;
			}
			else if(arr[i][j]=='X')
			{
				cout<<"X";
			}
			else if(arr[i][j]=='O')
			{
				cout<<"O";
			}
			if(j!=2)
			{
				cout<<" | ";
			}
			cnt++;
		}
		cout<<endl<<"---------"<<endl;
	}
}
void init(char** arr, int n, int ele=1)
{
	if(n==1)
	{
		if(ele==1)
		{
			arr[0][0]='X';
		}
		else
		arr[0][0]='O';
	}
	else if(n==2)
	{
		if(ele==1)
		{
			arr[0][1]='X';
		}
		else
		arr[0][1]='O';
	}
	else if(n==3)
	{
		if(ele==1)
		{
			arr[0][2]='X';
		}
		else
		arr[0][2]='O';
	}
	else if(n==4)
	{
		if(ele==1)
		{
			arr[1][0]='X';
		}
		else
		arr[1][0]='O';
	}
	else if(n==5)
	{
		if(ele==1)
		{
			arr[1][1]='X';
		}
		else
		arr[1][1]='O';
	}
	else if(n==6)
	{
		if(ele==1)
		{
			arr[1][2]='X';
		}
		else
		arr[1][2]='O';
	}
	else if(n==7)
	{
		if(ele==1)
		{
			arr[2][0]='X';
		}
		else
		arr[2][0]='O';
	}
	else if(n==8)
	{
		if(ele==1)
		{
			arr[2][1]='X';
		}
		else
		arr[2][1]='O';
	}
	else if(n==9)
	{
		if(ele==1)
		{
			arr[2][2]='X';
		}
		else
		arr[2][2]='O';
	}
}
int chk(char** arr)
{
	//cout<<"came here"<<endl;
	if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[1][1]!='a')
	{
		return(1);
	}
	else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[1][1]!='a')
	{
		//cout<<"came here"<<endl;
		return(1);
	}
	else if(arr[0][1]==arr[1][1]&&arr[1][1]==arr[2][1]&&arr[1][1]!='a')
	{
		return(1);
	}
	else if(arr[1][0]==arr[1][1]&&arr[1][1]==arr[1][2]&&arr[1][1]!='a')
	{
		return(1);
	}
	else if(arr[0][0]==arr[0][1]&&arr[0][1]==arr[0][2]&&arr[0][1]!='a')
	{
		return(1);
	}
	else if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]&&arr[2][1]!='a')
	{
		return(1);
	}
	else if(arr[0][0]==arr[1][0]&&arr[1][0]==arr[2][0]&&arr[1][0]!='a')
	{
		return(1);
	}
	else if(arr[2][0]==arr[2][1]&&arr[2][1]==arr[2][2]&&arr[2][1]!='a')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
int main()
{
	char **arr;
	char c;
	arr=(char**)new char**[3];
	for(int i=0;i<3;i++)
	{
		*(arr+i)=(char*)new char*[3];
		std::fill_n(*(arr+i), 3, 'a');
	}
	
	int cnt[9]={0};
	int n,i=0;
	cout<<"Tic Tac Toe game"<<endl;
	//printformat();
	cout<<"rules to play game :"<<endl;
	cout<<"select only numbers displayed in the format ie(in between 1 to 9)"<<endl;
	cout<<"As you already know a number once selected cannot be selected again and it is final"<<endl;
	cout<<"The who starts the game will be first player and his letter will be X"<<endl;
	hh:
		printformat();
	for(i=0;i<9;)//i++)
	{
		/*int rese=0;
		for(int ii=0;ii<9ii++)
		{
			if(cnt[ii]==0)
			{
				rese++;
			}
		}
		if(rese==0)
		{
			cout<<"match has drawn"<<endl;
			break;
		}*/
		cout<<"please select the number player-1(X)"<<endl;
		hh1:
		cin.ignore();
		cin.clear();
		cin>>n;
		if(n<1||n>9)
		{
			cout<<"Player-1 please select a valid number"<<endl;
			goto hh1;
		}
		else if(cnt[n-1]!=0)
		{
			cout<<"Player-1 the no you entered is already selected please select another no"<<endl;
			goto hh1;
		}
		cnt[n-1]=1;
		init(arr,n);
		if(i>1)
		{
			if(chk(arr))
			{
				cout<<endl<<"\t"<<"\t"<<"Player-1 WIN!!!!!!!"<<endl;
				break;
			}	
		}
		i++;
		printSelected(arr);


		if(i<9)
		{
		
		cout<<"please select the number player-2(O)"<<endl;
		hh2:
		cin.ignore();
		cin.clear();
		cin>>n;
		if(!(n>0&&n<10))//(n<1||n>9)
		{
			cout<<"Player-2 please select a valid number"<<endl;
			cin.ignore();
			cin.clear();
			goto hh2;
		}
		else if(cnt[n-1]!=0)
		{
			cout<<"Player-2 the no you entered is already selected please select another no"<<endl;
			goto hh2;
		}
		cnt[n-1]=1;
		init(arr,n,2);
		if(i>1)
		{
			if(chk(arr))
			{
				cout<<endl<<"\t"<<"\t"<<"Player-2 WIN!!!!!!!"<<endl;
				break;
			}	
		}
		i++;
		printSelected(arr);
		}
		else
		break;
	}
	if(i>8)
	{
		cout<<endl<<"\t"<<"\t"<<"match tied"<<endl;
	}
	cout<<"do you want to play another game press any key to play another game or enter n to exit"<<endl;
	cin>>c;
	if(c!='n')
	{
		for(i=0;i<9;i++)
		{
			cnt[i]=0;
		}
		for(i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				arr[i][j]='a';
			}
		}
		cout<<endl<<endl<<endl;
		goto hh;
	}
	exit(1);
}
