#include<stdio.h>
int n;
struct process
{

int p_no;

int arrival_time,burst_time,ctime,wait_time1,taround_time,p;

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
