#include<stdio.h>
int n;
struct process
{

int p_no;

int arrival_time,burst_time,ctime,wait_time1,taround_time,p;
int priority;

int flag;
 }p1_list[100];
 void Sorting()//to sort the element so the element with the minimum arrival time comes first
 {
struct process p;

int q, r;

for(q=0;q<n-1;q++)

{

for(r=q+1;r<n;r++)

{

if(p1_list[q].arrival_time > p1_list[r].arrival_time)

{

p = p1_list[q];

p1_list[q] = p1_list[r];

p1_list[r] = p;

}

}

}
 } //to sort the process so the process with minimum arrival time 
 void Sorting2()//sort the process according to the priority
 {
struct process p;

int q, r;

for(q=0;q<n-1;q++)

{

for(r=q+1;r<n;r++)

{

if(p1_list[q].priority < p1_list[r].priority)

{

p = p1_list[q];

p1_list[q] = p1_list[r];

p1_list[r] = p;

}

}

}
 } 
 int main()
 {

int i,t=0,b_t=0,peak;

int a[10];

float wait_time = 0, taround_time = 0, avg_w_t1=0, avg_taround_time1=0;

printf("enter the no. of processes: ");

scanf("%d",&n);

for(i = 0; i < n; i++)

{

p1_list[i].p_no = i+1;

printf("\nEnter Details For P%d process:-\n", p1_list[i].p_no);
printf("Enter Arrival Time: ");
scanf("%d", &p1_list[i].arrival_time );
printf("Enter Burst Time: ");
scanf("%d", &p1_list[i].burst_time);
p1_list[i].flag = 0;
b_t = b_t + p1_list[i].burst_time;
}
Sorting();
for(i=0;i<n;i++)
{
a[i]=p1_list[i].burst_time;
}
p1_list[9].burst_time = 9999;
for(t = p1_list[0].arrival_time; t <= b_t+1;)
{
peak = 9;
for(i=0;i<n;i++)
{
if(p1_list[i].arrival_time <= t && p1_list[i].burst_time < p1_list[peak].burst_time && p1_list[i].flag != 1)
{
peak = i;
}
if(p1_list[peak].burst_time==0 && p1_list[i].flag != 1)
{
p1_list[i].flag = 1;
p1_list[peak].ctime=t;p1_list[peak].burst_time=9999;
printf("P%d completes in %d\n",p1_list[i].p_no,p1_list[peak].ctime);
}
}
t++;
(p1_list[peak].burst_time)--;
}
for(i=0;i<n;i++)
{
p1_list[i].taround_time=(p1_list[i].ctime)-(p1_list[i].arrival_time);
avg_taround_time1=avg_taround_time1+p1_list[i].taround_time;
p1_list[i].wait_time1=((p1_list[i].taround_time)-a[i]);
p1_list[i].priority=1+(p1_list[i].wait_time1%p1_list[i].burst_time);//taround_time);
avg_w_t1=avg_w_t1+p1_list[i].wait_time1;
}
printf("PNO\tAT\tCT\tTA\tWTt\t Priority\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p1_list[i].p_no,p1_list[i].arrival_time,p1_list[i].ctime,p1_list[i].taround_time
,p1_list[i].wait_time1,p1_list[i].priority);
 }
printf("Average Turn around Time: %f\t\n\n",avg_taround_time1);
printf("Average Waiting Time :\t %f\t\n",avg_w_t1);
Sorting2();
printf("\nPNO\tAT\tCT\tTA\tWTt\t Priority\n");
for(i=0;i<n;i++)
{
printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p1_list[i].p_no,p1_list[i].arrival_time,p1_list[i].ctime,p1_list[i].taround_time
,p1_list[i].wait_time1,p1_list[i].priority);

}
printf("\n\n thus the process are listed in terms of priority in descending order");
printf("\n thus the process with higher priority will be executed first than the process with lowest priority");
return 0;
}
