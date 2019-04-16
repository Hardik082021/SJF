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
 
