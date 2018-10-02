#include<iostream>
using namespace std;
void matrixrow_add(int a[100][100],int n,int m)
{
    cout<<"\n   ________________________________________________________________________________\n";
    cout<<"\n";
    cout<<"\n\n\t => THE ROW WISE SUM OF MATRIX : \n";
    cout<<"\n";
    int sum=0,sum2=0;
   for(int i=0;i<n;i++)
  {
      cout<<"\t\t\t";
     for(int j=0;j<m;j++)
     {
        cout<<a[i][j]<<"   ";
        sum=sum+a[i][j];
     }
     cout<<"   =  "<<sum;
     cout<<"\n\n";
     sum=0;
  }

}
void matrixcol_add(int a[100][100],int n,int m)
{
    cout<<"\n\t => THE COLUMN WISE SUM OF MATRIX : \n";
    cout<<"\n";

    int sum=0;
   for(int i=0;i<m;i++)
  {
      cout<<"\t\t\t";
     for(int j=0;j<n;j++)
     {
        cout<<a[j][i]<<"   ";
        sum=sum+a[j][i];
     }
     cout<<"   =  "<<sum;
     cout<<"\n\n";
     sum=0;
  }

}
void matrixdiag1_add(int a[100][100],int n,int m)
{
    cout<<"\n   ________________________________________________________________________________\n";
    cout<<"\n";
    int sum=0,sum2=0,flag,flagi;
   for(int i=0;i<n;i++)
  {

     for(int j=0;j<m;j++)
     {
        if(i==j)
        {
            sum=sum+a[i][j];
            flag=1;
        }
        if((i+j)==n-1)
        {
            sum2=sum2+a[i][j];
            flagi=1;
        }
     }
  }
  if(n==m)
  {
    if(flag==1)
      {
        cout<<"\n\t => SUM OF THE MAJOR DIAGONAL OF MATRIX : "<<sum;
      }
     if(flagi==1)
      {
        cout<<"\n\t => SUM OF THE MINOR DIAGONAL OF MATRIX : "<<sum2;
      }
  }

  else
  {
     cout<<"\n\t => !! ERROR !! No. of rows and columns are not same, so sum of diagonal cannot be calculated. \n";
  }
   cout<<"\n";

}
void matrixlowtri_add(int a[100][100],int n,int m)
{
    cout<<"\n   ________________________________________________________________________________\n";
    cout<<"\n";

    cout<<"\n\t => THE LOWER TRIANGULAR ELEMENTS OF MATRIX IS SHOWN BELOW : \n";
    int sum=0;
   for(int i=0;i<n;i++)
  {
      cout<<"\n\t\t\t";
     for(int j=0;j<m;j++)
     {
        if(i>=j)
        {
            cout<<a[i][j]<<"   ";
            sum=sum+a[i][j];
        }
        if(i<j)
        {
            cout<<"_"<<"   ";
        }
     }
     cout<<"\n";
  }
  cout<<"\n\t => SUM OF LOWER TRIANGULAR ELEMENTS OF THE MATRIX IS : "<<sum;
}
void matrixupptri_add(int a[100][100],int n,int m)
{
    cout<<"\n\t => THE UPPER TRIANGULAR ELEMENTS OF MATRIX IS SHOWN BELOW : \n";
    int sum=0;
   for(int i=0;i<n;i++)
  {
      cout<<"\n\t\t\t";
     for(int j=0;j<m;j++)
     {
        if(i<=j)
        {
            cout<<a[i][j]<<"   ";
            sum=sum+a[i][j];
        }
        if(i>j)
        {
            cout<<"_"<<"   ";
        }
     }
     cout<<"\n";
  }
  cout<<"\n\t => SUM OF UPPER TRIANGULAR ELEMENTS OF THE MATRIX IS : "<<sum;
}
void matrixtranspose(int a[100][100],int n,int m)
{
    cout<<"\n   ________________________________________________________________________________\n";
    cout<<"\n";
    cout<<"\n\t => TRANSPOSE OF THE MATRIX IS : \n";
    cout<<"\n";
   for(int i=0;i<m;i++)
  {
      cout<<"\t\t\t";
     for(int j=0;j<n;j++)
     {
        cout<<a[j][i]<<"   ";
     }
     cout<<"\n\n";
  }

}
int main()
{
  int a[100][100],i,j,sum=0,n,m,x;
  cout<<"\n\t     ======================\n";
  cout<<"  \t       MATRIX OPERATIONS\n";
  cout<<"  \t     ======================\n";
  cout<<"\n\n\t Enter the number of rows(n) : ";
  cin>>n;
  cout<<"\n\t Enter the number of columns(m) : ";
  cin>>m;
  cout<<"\n\n\t Enter the elements of the matrix : ";
  for(i=0;i<n;i++)
  {
     for(j=0;j<m;j++)
     {
        cin>>a[i][j];
     }
  }
  cout<<"\n\t THE MATRIX YOU ENTERED IS : \n";
  for(i=0;i<n;i++)
  {
      cout<<"\n\t\t\t";
     for(j=0;j<m;j++)
     {
        cout<<a[i][j]<<"   ";
     }
  }
  cout<<"\n\n\t Enter the program you want to run : ";
  cout<<"\n\n\t       1. ROW WISE & COLUMN WISE SUM OF A MATRIX \n";
  cout<<"\t       2. SUM OF MAJOR & MINOR DIAGONAL OF A MATRIX\n";
  cout<<"\t       3. LOWER TRIANGULAR & UPPER TRIANGULAR ELEMENTS OF MATRIX\n";
  cout<<"\t       4. TRANSPOSE OF A MATRIX\n";
  cin>>x;
  switch(x)
  {
    case 1:
     matrixrow_add(a,n,m);
     matrixcol_add(a,n,m);
     break;

    case 2:
     matrixdiag1_add(a,n,m);
     break;

    case 3:
        if(n==m)
        {
          matrixlowtri_add(a,n,m);
          matrixupptri_add(a,n,m);
        }
        else
        {
            cout<<"    ______________________________________________________________________\n";
            cout<<"\n\n\t ERROR !! 'n' is not equal to 'm'. \n";
        }


     break;

    case 4:
      matrixtranspose(a,n,m);
      break;

    default:
        cout<<"\n\t INVALID INPUT !! ENTER AGAIN : ";
        break;

    }

}
