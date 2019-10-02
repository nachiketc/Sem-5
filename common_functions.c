#include"common_functions.h"
#include<stdio.h>
#include<math.h>
//#define M_PI 3.14159265358979323846


void lpf(float fc,float fs, int N,float a[] )
{
  float wc;
  wc=2*M_PI*fc/fs;
  for(int i=0;i<(N-1)/2;i++)
  {
    a[i]=(sin(wc*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }
  a[(N+1)/2]=(wc/M_PI);
  for(int i=(N+3)/2;i<N;i++)
  {
    a[i]=(sin(wc*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }
}


void hpf(float fc,float fs, int N,float a[] )
{
  float wc;
  wc=2*M_PI*fc/fs;
  for(int i=0;i<(N-1)/2;i++)
  {
    a[i]=(sin(M_PI*(i+(N-1)/2))-sin(wc*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }
  a[(N+1)/2]=1-(wc/M_PI);
  for(int i=(N+3)/2;i<N;i++)
  {
    a[i]=(sin(M_PI*(i+(N-1)/2))-sin(wc*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }

}


void bpf(float fc1,float fc2,int fs, int N,float a[] )
{
  float wc1,wc2;
  wc1=2*M_PI*fc1/fs;
  wc2=2*M_PI*fc2/fs;
  for(int i=0;i<(N-1)/2;i++)
  {
    a[i]=(sin(wc2*(i+(N-1)/2))-sin(wc1*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }
  a[(N+1)/2]=((wc2-wc1)/M_PI);
  for(int i=(N+3)/2;i<N;i++)
  {
    a[i]=(sin(wc2*(i+(N-1)/2))-sin(wc1*(i+(N-1)/2)))/(M_PI*(i+(N-1)/2));
  }

}


void mavgf(float x[],int n,float y[])
{
  //float y[n];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<5;j++)  //L=5
    {
      if(i+j>=0)
      {
        y[i]+=x[i-j];
      }
    }
    y[i]/=5;
  }
}

void hamwindow( float x[],int n,float y[] )
{
  for(int i=0;i<n;i++)
  {
    y[i]=x[i]*(0.54-0.46*(cos(2*M_PI*i)/(n-1)));
  }
}


void rectwindow( float x[],int n,float y[] )
{
  for(int i=0;i<n;i++)
  {
    y[i]=x[i]*1;
  }
}

void disp(float a[],int n)
{
  for( int i=0;i<n;i++)
  {
    printf("%f\t",a[i] );
  }
  printf("\n" );
}
