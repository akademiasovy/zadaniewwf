#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int checkCode(int num);
void checkCode2(int *num);
void printArray(int field[8][8]);

main(){
	
	printf("Welcome in my aplication,author:Matus\n");
	
	int code1,code2,code3,code4;
	int i,j;
	int field[8][8];
	int position;
	int positionRow;
	int positionCol;
	int count=1;
	
 		printf("\nenter: code 1: ");
	scanf("%d",&code1);
		printf("\nenter: code 2: ");
	scanf("%d",&code2);
		printf("\nenter: code 3: ");
	scanf("%d",&code3);
		printf("\nenter: code 4: ");
	scanf("%d",&code4);
	
	code1=checkCode(code1);
	code2=checkCode(code2);
	
	checkCode2(&code3);
	checkCode2(&code4);
	
	//printf("%d,%d,%d,%d,",code1,code2,code3,code4);
	
	
	for(i=1;i>=0;i--){
	for(j=7;j>=0;j--){
			
		 if(code1 & 1 == 1)	{
		 
		 field[i][j]= -1;
		 code1=code1>>1;
	     }
		 else{
		 
		 field[i][j]= 0;
		 code1=code1>>1;
	    }
	    
}
}
	 for(i=3;i>=2;i--){
	for(j=7;j>=0;j--){
			
		 if(code2 & 1 == 1)	{
		 
		 field[i][j]= -1;
		 code2=code2>>1;
	     }
		 else{
		 
		 field[i][j]= 0;
		 code2=code2>>1;
	    }  
	    
	}
}
	for(i=5;i>=4;i--){
	for(j=7;j>=0;j--){
			
		 if(code3 & 1 == 1)	{
		 
		 field[i][j]= -1;
		 code3=code3>>1;
	     }
		 else{
		 
		 field[i][j]= 0;
		 code3=code3>>1;
	    }
	}
}
		for(i=7;i>=6;i--){
	for(j=7;j>=0;j--){
			
		 if(code4 & 1 == 1)	{
		 
		 field[i][j]= -1;
		 code4=code4>>1;
	     }
		 else{
		 
		 field[i][j]= 0;
		 code4=code4>>1;
	    }
	}
}
	
	
  printArray(field);
	
  printf("\nenter position of ship <0,63>\n");
  scanf("%d",&position);
  if(position<0 || position >63){
  	printf("\nerror wrong input:position=%d",position);
  	return 1;
  	
  }
  
  positionRow=position/8;
  positionCol=position%8;
  
  if(field[positionRow][positionCol]==-1)
  {
  	printf("\nWrong position: Island ");
  	return 2;
  	
  }
  else
  field[positionRow][positionCol]=-2;
  
  


		if(positionCol>0 && field[positionRow][positionCol-1]==0)
			field[positionRow][positionCol-1]=1;
		if(positionCol<7 && field[positionRow][positionCol+1]==0)
			field[positionRow][positionCol+1]=1;
		if(positionRow>0 && field[positionRow-1][positionCol]==0)
			field[positionRow-1][positionCol]=1;
		if(positionRow<7 && field[positionRow+1][positionCol]==0)
			field[positionRow+1][positionCol]=1;			
			
	
	while(count<39){
	
		for(i=0;i<=7;i++){
	     for(j=0;j<=7;j++){
	     	
	     if(field[i][j]==count){
		 	     
	     	if(j>0 && field[i][j-1]==0)
	 		field[i][j-1]=count+1;
	    	if(j<7 && field[i][j+1]==0)
			field[i][j+1]=count+1;
	    	if(i>0 && field[i-1][j]==0)
			field[i-1][j]=count+1;
	    	if(i<7 && field[i+1][j]==0)
			field[i+1][j]=count+1;	
	    }
	     	
		 }	
	   }
	count++;
   }
		
	printArray(field);	
	
    
}

void printArray(int field[8][8]){
	
	int i,j;
	
	printf("\n");
	for(i=0;i<=7;i++){
	for(j=0;j<=7;j++){
	
	
	 if(field[i][j]==0)
	  printf("   ");
	 else
	 if(field[i][j]==-1) 
	 printf(" - ");
	 else
	 if(field[i][j]==-2)
	 printf(" O ");
	 else
	 printf("%2d ",field[i][j]);
	 
	//printf("%2d ",field[i][j]);
		
	}
	printf("\n");
    }
    
    
	
}

int checkCode(int num){
	
	if(num>=0 && num <= pow(2,16)-1)
	return num;
	else
	return 0;

}

void checkCode2(int *num){
	
	if(*num<0|| *num > pow(2,16)-1)
	*num=0;
	
}
