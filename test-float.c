#include "stdio.h"
#include <math.h>


printfFloatBit(float f)
{ 
 int i,j;
 unsigned int byte=0;
 char ch,*p;
 p=(char *)(&f);
 printf(" %.3f: ",f);
 for(i=sizeof(float)-1;i>=0;i--)
 {
  ch=*(p+i);
  byte=ch;

  for(j=1;j <=8;j++)
  {
   if(byte>=128) printf("1");
   else printf("0");
   byte <<=1;
   byte&=255;
  }
 }
 printf("\n");
} 


void convert_binary2float(unsigned int interger)
{
	int fuhao;
	unsigned int interger_tmp=interger;
//	printf("interger=%#x, interger_tmp=%#x\n",interger,interger_tmp);
	if(interger_tmp >= 0x80000000)
	{
		fuhao=1;
		interger_tmp = interger_tmp - 0x80000000;
	}
	else
	{
		fuhao=0;
	}
//	printf("fuhao=%d, interger_tmp=%#x\n",fuhao,interger_tmp);
	
	int jieshu;
	jieshu = interger_tmp >> 23;
//	printf("jieshu=%d\n",jieshu);
	unsigned int weishu;
	weishu = interger_tmp & 0x007FFFFF;
//	printf("weishu=%#x\n",weishu);

	jieshu = jieshu -127;
//	printf("jieshu=%d\n",jieshu);
	weishu = weishu | 0x00800000;
//	printf("weishu=%#x\n",weishu);


	float value=0;
	int i;
	unsigned int weishu_interger=0;
	if(jieshu<0)
	{
		value=0;
//		printf("value=%f\n",value);
//		printf("xiao shu,jieshu=%d\n",jieshu);
		//only xiao shu

/*
		for(i=0;i<24;i++)
		{
			if(weishu>>i & 0x01)
			{
//				printf("i=%d,(i-23)+jieshu=%d\n",i,(i-23)+jieshu);
				value = value + powf(2,(i-23)+jieshu);
//				printf("value=%f\n",value);
			}
		}
*/	

		i=0;
		while(weishu)
		{
			if(weishu & 0x01)
			{
//				printf("i=%d,(i-23)+jieshu=%d\n",i,(i-23)+jieshu);
				value = value + powf(2,(i-23)+jieshu);
//				printf("value=%f\n",value);
//				printf("1111 weishu_xiaoshu=%#x\n",weishu_xiaoshu);
			}
			weishu = weishu >> 1;
			i++;
//			printf("2222 weishu=%#x,i=%d\n",weishu,i);
		}

//		printf("value=%f\n",value);
	}
	else
	{
		value=0;
//		printf("value=%f\n",value);
//		printf("da shu,jieshu=%d\n",jieshu);
		// int + xiao shu
		weishu_interger = weishu >>(23-jieshu);
//		printf("weishu_interger=%d\n",weishu_interger);

		/*
		i=0;
		while(weishu_interger)
		{
			if(weishu_interger & 0x01)
			{
				printf("i=%d,i=%d,value=%f\n",i,i,value);
				value = value + powf(2,i);
				printf("value=%f\n",value);
			
			}
			weishu_interger = weishu_interger >> 1;
			i++;
		}
		*/

		value = weishu_interger;
//		printf("value=%f\n",value);

		unsigned int weishu_xiaoshu=0;
		weishu_xiaoshu = weishu << (jieshu+1+8) >> (jieshu+1+8);
//		printf("weishu_xiaoshu=%#x\n",weishu_xiaoshu);

		i=0;
		while(weishu_xiaoshu)
		{
			if(weishu_xiaoshu & 0x01)
			{
//				printf("i=%d,(i-23)+jieshu=%d\n",i,(i-23)+jieshu);
				value = value + powf(2,(i-23)+jieshu);
//				printf("value=%f\n",value);
//				printf("1111 weishu_xiaoshu=%#x\n",weishu_xiaoshu);
			}
			weishu_xiaoshu = weishu_xiaoshu >> 1;
			i++;
//			printf("2222 weishu_xiaoshu=%#x,i=%d\n",weishu_xiaoshu,i);
		}

//		printf("3333 i=%d,i-18=%d,value=%f\n",i,i-18,value);
	
	}
	
	if(fuhao)
		value = -value;

	printf("total value=%f\n",value);


	return;
}


void main()
{
 float f1=178.125; 
 float f2=-0.15625;
 float f3=1.0;
 //printfFloatBit(f1);
 //printfFloatBit(f2);
 //printfFloatBit(f3);

/*
	float value=0;
	int x=2;
	printf("value=%f\n",value);
	value = powf(2,3);
	printf("value=%f\n",value);
	value = powf(2,-3);
	printf("value=%f\n",value);
	value = pow(10,3);
	printf("value=%f\n",value);

	value = powf(2,x);
	printf("value=%f\n",value);
	value = powf(2,-x);
	printf("value=%f\n",value);
*/

	int interger;
	interger=0x3d15312a;
 	convert_binary2float(interger);
	interger=0x4215312a;
	convert_binary2float(interger);
	interger=0xc215312a;
 	convert_binary2float(interger);
	interger=0xbd15312a;
 	convert_binary2float(interger);

	interger=0x44df2037;
 	convert_binary2float(interger);



}

