#include <stdio.h>
#include <unistd.h>
#define max 5
void main(){
	int i,p[20],j,bt[max],wt[max],tat[max],t,ttat,twt,n;
	printf("enter the number of process");
	scanf("%d",&n);
	printf("enter the burst time of process");
	for(i=0;i<n;i++){
		printf("p[%d]",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n-1-i;j++){
			if(bt[j]>bt[j+1]){
				t=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=t;

				 t=p[j];
				  p[j]=p[j+1];
				  p[j+1]=t;
				}
		}
	}
	wt[0] = 0;
	ttat=twt=0;
	for(i=0;i<n;i++){
		tat[i]=wt[i+1]=wt[i]+bt[i];
		 ttat+=tat[i];
		  twt+=wt[i];
	}
	printf("\nProcess\t\tBursttime\t\twaitingtime\t\tTurnaroundtime\n");
        for(i=0;i<n;i++){
                printf("\np[%d]\t\t\t%d\t\t\t%d\t\t\t%d\n",p[i],bt[i],wt[i],tat[i]);
        }
        printf("Average waiting time:%f\n",(float)twt/n);
        printf("Average turnaround time:%f\n",(float)ttat/n);
}
