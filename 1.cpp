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
		com[i]=i; //��ǻ�� �и� 0���� 8���� �ʱ�ȭ��Ŵ
	}

	for (i=0; i<20; i++)  //��ǻ�� �и� 20�� ����
	{
		j = rand()%9;              //j�� 0~8������ �����Ǽ� ����
		temp = com[0];             //�ӽð��� ���� ���� �� ����
		com[0] = com[j];           //����� �� ���� ���� ������ �и� �̾Ƽ� ����
		com[j] = temp;             //������ �и� �������� ����� �� ���ǰ��� ��������     
	}
	
	for(i=0;i<9;i++)
	{
		cout<<"Com : ";
		if(com[i]%2==0)
			cout<<"Even"<<endl;
		else
			cout<<"Odd"<<endl;			//��ǻ�Ͱ� ������ ���ڰ� Ȧ������ ¦������ �Ǻ��� ���

		cout<<"User : ";
		cin>>user[i];
		for(j=i-1;j>=0;j--)
		{
			if(user[i]==user[j])
			{
				cout<<"�������ڴ� ����Ҽ� �����ϴ�.";
					return 0;
			}
		}
		if(user[i]<0 || user[i] >8)
		{
			cout<<"0���� 8������ ���ڸ� �Է����ּ���.";
			return 0;									//����ڰ� ���ڸ� �Է��� �� �Ұ����Ѱ�� ����ó��
		}

		cout<<"-------------------------------------";

		if(com[i]>user[i])
		{
			comc++;
			userc--;
			cout<<"Winner is Com"<<endl<<endl;				
		}
		else if(com[i]<user[i])
		{								//��ǻ�Ϳ� ����ڰ� �� ���� ���� �¸��� ���, �������
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
		cout<<i+1<<"Round    "<<com[i]<<"      "<<user[i]<<endl;		//�迭�� ����� ���� �̿� �� ���� ������ ���� ���
	}
	cout<<"User Score : "<<userc<<endl;
	cout<<"Com Socre : "<<comc<<endl;				//���� ���

	if(comc>userc)
		cout<<"Com Victory"<<endl;
	else if(userc>comc)
		cout<<"User Victory"<<endl;
	else
		cout<<"Draw"<<endl;				// ��ǻ�Ϳ� ������� ������ ���� ��,��,���º� ǥ��
	
	

	return 0;

}