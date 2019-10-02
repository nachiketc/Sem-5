#include"common_functions.c"
#include"common_functions.h"

void main()
{
  FILE * fp;
  fp = fopen("/home/nachiketc/Documents/IDP/A3/filter_coefficients3.txt","w");//enter your locartion of file
  float fclpf,fchpf,fc1,fc2,fslpf,fshpf,fsbpf;
  float x[]={-0.7145, 1.3514, -0.2248, -0.5890, -0.2938, -0.8479, -1.1201,
2.5260, 1.6555, 0.3075, -1.2571, -0.8655, -0.1765 ,0.7914, -1.3320, -2.3299,
-1.4491, 0.3335, 0.3914, 0.4517, -0.1303, 0.1837, -0.4762, 0.8620, -1.3617,
0.4550, -0.8487, -0.3349, 0.5528 ,1.0391};
  int nlpf,nhpf,nbpf;
  int nmf=sizeof(x)/sizeof(x[0]);

//Band pass filter
  printf("Low Pass Filter\n" );
  fclpf=300;
  fslpf=1200;
  nlpf=39;
  float Hlpf[nlpf];
  lpf(fclpf,fslpf,nlpf,Hlpf);
  disp(Hlpf,nlpf);
  printf("Low Pass Filter rect window\n" );
  float hlpfrect[nlpf];
  rectwindow(Hlpf,nlpf,hlpfrect);
  disp(hlpfrect,nlpf);
  float hlpfham[nlpf];
  hamwindow(Hlpf,nlpf,hlpfham);
  printf("Low Pass Filter hamming window\n" );
  disp(hlpfham,nlpf);

  //High pass filter
    printf("High Pass Filter\n" );
    fchpf=1200;
    fshpf=4800;
    nhpf=39;
    float Hhpf[nhpf];
    hpf(fchpf,fshpf,nhpf,Hhpf);
    disp(Hhpf,nhpf);
    printf("High Pass Filter rect window\n" );
    float hhpfrect[nhpf];
    rectwindow(Hhpf,nhpf,hhpfrect);
    disp(hhpfrect,nhpf);
    float hhpfham[nhpf];
    hamwindow(Hhpf,nhpf,hhpfham);
    printf("High Pass Filter hamming window\n" );
    disp(hhpfham,nhpf);

    //Band pass filter
      printf("Band Pass Filter\n" );
      fc1=500;
      fc2=1200;
      fsbpf=6000;
      nbpf=39;
      float Hbpf[nbpf];
      bpf(fc1,fc2,fsbpf,nbpf,Hbpf);
      disp(Hbpf,nbpf);
      printf("Band Pass Filter rect window\n" );
      float hbpfrect[nbpf];
      rectwindow(Hbpf,nbpf,hbpfrect);
      disp(hbpfrect,nbpf);
      float hbpfham[nbpf];
      hamwindow(Hbpf,nbpf,hbpfham);
      printf("Band Pass Filter hamming window\n" );
      disp(hbpfham,nbpf);

      //Moving Avg filter
      printf("Moving Average Filter input" );
      disp(x,nmf);
      float y[nmf];
      mavgf(x,nmf,y);
      printf("Moving Average Filter output" );
      disp(y,nmf);

      for( int i=0;i<nmf;i++)
      {
        fprintf(fp,"%f\n",y[i] );
      }
      fclose(fp);



}
