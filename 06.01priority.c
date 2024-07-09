#include <stdio.h>
#define max 5
void main(){
	int i,j,n,bt[max],pri[max],wt[max],pos,t,tat[max],ttat,twt,p[max];
	printf("enter the no of process\n");
	scanf("%d",&n);
	printf("enter the burst time\n");
	for( i=0;i<n;i++){
		scanf("%d",&bt[i]);
	}
	printf("enter the priority of process\n");
	for( i=0;i<n;i++){
		printf("p[%d]:\t",i+1);
                scanf("%d",&pri[i]);
		p[i]=i+1;
        }
	for(i =0;i<n;i++){
		pos = i;
		for(j =i+1;j<n;j++){
			if(pri[j]<pri[pos]){
				pos = j;
			}
		}
		t= pri[i];
		pri[i] = pri[pos];
		pri[pos]=t;


		t=bt[i];
		bt[i]=bt[pos];
		bt[pos] =t;

		t=p[i];
		p[i]=p[pos];
		p[pos]=t;

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
