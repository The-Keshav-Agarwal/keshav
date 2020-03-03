#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,p,c=0,x,c1=0;
	cout<<"enter a even number : ";
	cin>>n;
	p = sqrt(n);
	for(int i=2;i<n;i++)
	{
		c=0;
		c1=0;
		for(int j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			{
				c = 1;
				break;
			}
		}
		if(c==0)
		{
			x = n-i;
			for(int j=2;j<=sqrt(x);j++)
			{
				if(x%j==0)
				{
					c1=1;
					break;
				}
			}
			if(c1==0)
			{
				cout<<"we can write the number "<<n<<" as a sum of two prime number such that \n"<< n<<" = "<<i<<" + "<<x<<endl;
				break;
			}
		}
	}
}