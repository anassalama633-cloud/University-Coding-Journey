#include<iostream>
#include<string>
using namespace std;

// Structure to group student personal information
struct student 
 {
string firstname;
string lastname;
long id;
 };
 // Function to handle student details from user input
 
student input(student &c)
   {
cin>>c.firstname>>c.lastname>>c.id;
return c;
   }
   // Function to display student details in a formatted layout
void output(student c)
       {
cout<<"first name :"<<c.firstname<<endl;
cout<<"last name  :"<<c.lastname<<endl;
cout<<"id         :"<<c.id<<endl;
       }
       // Function to process and calculate the average of filtered grades
double sum(int a[], int b)
  {
 int sum=0;
 double avg=0.0;
 int n=b;// Dynamic counter representing total array size
 for(int i=0;i<b;i++)
 // Controlled traversal preventing out-of-bounds error
    {
    // Skip grades that are lower than the threshold of 60
  if(a[i]<60)
              {
      continue;
              } 
      else
          {
      sum+=a[i];     
      // Accumulate passing grades only
          }
     }
     // Explicit type casting to double for accurate floating-point division
  avg=(double)sum/n;
  return avg;
 }

int main()
{
   student v;
   input(v);
   output(v);
   // Sample dataset of student academic marks
   
   int arr[]={100,60,50,88,57,77};
   // Formulate total element count dynamically
   cout<<"his average:"<<sum(arr,6);
   // Output final parsed academic results
   return 0;
}
