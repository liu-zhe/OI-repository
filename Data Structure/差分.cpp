#include <iostream>
using namespace std;
int a[1000],A[1000];
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		A[i]=a[i]-a[i-1];
	}
	char cmd;
	while (true)
	{
	    cin>>cmd;
	    switch(cmd)
	    {
        case 'p':
            int l,r,k; 
            cin>>l>>r>>k;
    	    A[l]+=k;
    	    A[r+1]-=k;
    	    break;
    	case 'v':
    	    for(int i=1;i<=n;i++)
    	    {
    	        a[i] = a[i-1] + A[i];
    	        cout<<a[i]<<" ";
    	    }
    	    cout<<endl;
    	    break;
        case 's':
            return 0;
	    }
	}
}
