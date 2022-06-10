#include<stdio.h>

int main(void)
{
    int n = 0;
    int num[1000000] = {0};
    int max = 0;
	int min = 0;
	int i = 0;

    scanf("%d",&n);
    
    for(i = 0; i < n;i++)
    {
		scanf("%d",&num[i]);
    }
	i = 0;
	max = num[i];
	min = num[i];
    for(i = 0 ;i<n;i++)
    {
		if(max < num[i])
			max = num[i];
		if(min > num[i])
			min = num[i];
    }
	printf("%d %d",min, max);
    return 0;
}
