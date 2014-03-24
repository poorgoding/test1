#include <iostream>
#include <cstdlib>
#include <ctime>
	
using namespace std;

int main()
{
	int i,j,temp;
	int com[9];
	int user[9];
	int comc=0;
	int userc=0;
	srand((unsigned int)time(NULL));
	
	for(i=0;i<9;i++)
	{
		com[i]=i; //컴퓨터 패를 0부터 8까지 초기화시킴
	}

	for (i=0; i<20; i++)  //컴퓨터 패를 20번 섞음
	{
		j = rand()%9;              //j에 0~8사이의 임의의수 저장
		temp = com[0];             //임시값에 섞을 패의 값 저장
		com[0] = com[j];           //섞기로 한 패의 값에 임의의 패를 뽑아서 저장
		com[j] = temp;             //임의의 패를 뽑은곳에 섞기로 한 패의값을 저장해줌     
	}
	
	for(i=0;i<9;i++)
	{
		cout<<"Com : ";
		if(com[i]%2==0)
			cout<<"Even"<<endl;
		else
			cout<<"Odd"<<endl;			//컴퓨터가 제시한 숫자가 홀수인지 짝수인지 판별후 출력

		cout<<"User : ";
		cin>>user[i];
		for(j=i-1;j>=0;j--)
		{
			if(user[i]==user[j])
			{
				cout<<"같은숫자는 사용할수 없습니다.";
					return 0;
			}
		}
		if(user[i]<0 || user[i] >8)
		{
			cout<<"0에서 8까지의 숫자를 입력해주세요.";
			return 0;									//사용자가 숫자를 입력할 때 불가능한경우 예외처리
		}

		cout<<"-------------------------------------";

		if(com[i]>user[i])
		{
			comc++;
			userc--;
			cout<<"Winner is Com"<<endl<<endl;				
		}
		else if(com[i]<user[i])
		{								//컴퓨터와 사용자가 낸 수를 비교해 승리자 출력, 점수계산
			userc++;
			comc--;
			cout<<"Winner is User"<<endl<<endl;
		}
		
			
	}

	cout<<"Result"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<"        Com     User"<<endl;

	for(i=0;i<9;i++)
	{
		cout<<i+1<<"Round    "<<com[i]<<"      "<<user[i]<<endl;		//배열에 저장된 값을 이용 각 라운드 제시한 숫자 출력
	}
	cout<<"User Score : "<<userc<<endl;
	cout<<"Com Socre : "<<comc<<endl;				//점수 출력

	if(comc>userc)
		cout<<"Com Victory"<<endl;
	else if(userc>comc)
		cout<<"User Victory"<<endl;
	else
		cout<<"Draw"<<endl;				// 컴퓨터와 사용자의 점수를 비교해 승,패,무승부 표시
	
	

	return 0;

}