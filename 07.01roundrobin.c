#include <stdio.h>

void main(){
	int i,j,n,temp,qt,sq=0,count,bt[20],tat[20],wt[20],rem_bt[20],ttat=0,twt=0;
	printf("enter the number of process");
	scanf("%d",&n);
	printf("enter the burst time");
	for(i=0;i<n;i++){
		scanf("%d",&bt[i]);
		rem_bt[i]=bt[i];
	}
	printf("enter the quantum time");
	scanf("%d",&qt);
	while(1){
		count =0;
		for(i=0;i<n;i++){
			temp=qt;
			if(rem_bt[i]==0){
				count++;
				continue;
			}
			if(rem_bt[i]>qt){
				rem_bt[i]-=qt;
				sq+=qt;
			}
			else{
				if(rem_bt[i]>=0){
					temp=rem_bt[i];
					rem_bt[i]=0;
					sq+=temp;
				}
				tat[i]=sq;
			}
		}
		if(count==n)
			break;
	}
	printf("\nprocess\t\tbrusttime\t\tturnaroundtime\t\twaitingtime");
	for(i=0;i<n;i++){
		wt[i]=tat[i]-bt[i];
		ttat+=tat[i];
		twt+=wt[i];
		printf("\np[%d]\t\t\t%d\t\t\t%d\t\t\t%d",i+1,bt[i],tat[i],wt[i]);
	}
}
