#include <stdio.h>

float Sum(float*, int);
float Min(float*, int);
float Max(float*, int);
float Average(float*, int); 
float MathFunc(float (*ptr)(float*, int), float* , int );

int main()
{
	int size;
    scanf("%d",&size);
    float nums[size];

    for(int i=0;i<size;i++)
	{
        scanf("%f",&nums[i]);
    }
    
	printf("\n求和：  %.2f", MathFunc(Sum,nums,size));
    printf("\n最小值：%.2f", MathFunc(Min,nums,size));
    printf("\n平均值：%.2f", MathFunc(Average,nums,size));
    printf("\n最大值：%.2f", MathFunc(Max,nums,size)); 
	
}	
	
float MathFunc(float (*ptr)(float*, int), float* nums,int size)
{	
	float ans=ptr(nums,size);		
	return ans;
}

float Sum(float* nums, int size)
{
	int sum=0;
	for(int i=0;i<size;i++)
	{
		sum+=nums[i];
	}	
	return sum;
}

float Min(float* nums, int size)
{
	int min= nums[0];
	for(int i=0;i<size;i++)
	{
		if(min>nums[i])
		min=nums[i];
	}	
	return min;
}

float Max(float* nums, int size)
{
	int max= nums[0];
	for(int i=0;i<size;i++)
	{
		if(max<nums[i])
		max=nums[i];
	}	
	return max;
}

float Average(float* nums, int size)
{
	float sum=Sum(nums,size);
	
	return sum/size;
}



