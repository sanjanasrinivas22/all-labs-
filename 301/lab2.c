#include <stdio.h>
#include <stdlib.h>

void sort(int pro_id[],int at[],int bt[],int n){
    int min=at[0],temp=0;
    for(int i=0;i<n;i++){
        min =at[i];
        for (int j= i; j<n; j++)
        {
            /* code */
            temp=at[i];
            at[i]=at[j];
            at[j]=temp;
            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;
            temp=pro_id[i];
            pro_id[i]=pro_id[j];
            pro_id[j]=temp;
            
        }
        
    }
}


int main() {
    int n,c=0;
    printf("enter the number of processes to be performed:\n");
    scanf("%d",&n);
    int pro_id[n],at[n],bt[n],ct[n],wt[n],tat[n];
    double avg_tat=0.0 ,avg_wt=0.0,ttat=0.0,twt=0.0;
    printf("enter the process id");
    for(int i=0;i<n;i++)
        pro_id[i]=i+1;


    printf("Enter arrival times:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);


    printf("Enter burst times:\n");
        for(int i=0;i<n;i++)
        scanf("%d",&bt[i]);

    sort(pro_id,at,bt,n);

    printf("enter the completion time");
    for(int i=0;i<n;i++){
        if(c>at[i]){
            c+=bt[i];}
        else{
            c+=at[i]-ct[i-1]+bt[i];}
        ct[i]=c;
        }
    

    printf("enter the turn around time");
    for(int i=0;i<n;i++)
        tat[i]=ct[i]-at[i];
    
    printf("enter the waiting time");
    for(int i=0;i<n;i++)
        wt[i]=tat[i]-bt[i];
    
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",pro_id[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    
    for(int i=0;i<n;i++)
        ttat+=tat[i];

    for(int i=0;i<n;i++)
        twt+=wt[i];
    avg_tat=ttat/(double)n ;
    avg_wt=twt/n;
    printf("%lf is average tat",avg_tat);
    printf("%lf is average waiting time",avg_wt);


 return 0;

}