#include<stdio.h>
 #include<conio.h>
 
 int Selected;
 int f1;
 int f2;
 int f3;
 int f4;
 int pages[] = {54,83,37,45,78,32,46,78,21,45,87,83,55,64,21};
 
 void Display()
 {
    printf("----------------------------------------------------------------------------\n");
    printf("---  Please Enter The Number of Your Choice(Page Replacement Algorithm)  ---\n");
    printf("1 --> OPT                                    		   	         ---\n");
    printf("2 --> MFU                           			                 ---\n");
    printf("----------------------------------------------------------------------------\n");
    scanf("%d", &Selected);
    
    if(Selected == 1) {
			OPTP1();
			OPTP2();
			BKGMFUP1();
			BKGMFUP2();
			
			printf("\n\n\nUsing algorithm: OPT");
			printf("\nFault rate: P1 = %d", f1);
			printf("\nFault rate: P2 = %d", f2);
			
			if (f1 > f3 && f2 > f4){
			    printf("\nBetter Performance: OPT");
			}else{
			    if (f1 < f3 && f2 < f4){
			        printf("\nBetter Performance: MFU");
			    }else{
			        printf("\nMutual Performance from both OPT and MFU");
			    }
			}
	}else {
		if(Selected == 2) {
			MFUP1();
			MFUP2();
			BKGOPTP1();
			BKGOPTP2();
			
			
			
			printf("\n\n\nUsing algorithm: MFU");
			printf("\nFault rate: P1 = %d", f1);
			printf("\nFault rate: P2 = %d", f2);
			
			if (f1 > f3 && f2 > f4){
			    printf("\nBetter Performance: OPT");
			}else{
			    if (f1 < f3 && f2 < f4){
			        printf("\nBetter Performance: MFU");
			    }else{
			        printf("\nMutual Performance from both OPT and MFU");
			    }
			}
		}
	}
 }
/*Using algorithm: XYZ
Illustrations of page-to-frame allocation, for both processes
Fault rate: P1 = 0.xxx P2 = 0.xxx
Second Algorithm Fault rate: P1 = 0.xxx P2 = 0.xxx
Better Performance: Name of algorithm 
 */
 
 //--------------------          MAIN          ---------------------
 int main()
 {
    Display();
    return 0;
 }
 
 // ----------------------      OPT       ---------------------------

int OPTP1()
{
    int no_of_frames = 5, no_of_pages = 15, frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
//    int pages[]={10,1,3,2,5,3,1,8,7,10};
    
    
    printf("\n\n\n-----------   Process 1: OPT - 5 Frames   -----------\n");
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    f1 = faults;
    return 0;
}




int OPTP2()
{
    int no_of_frames = 3, no_of_pages = 15, frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
//    int pages[]={10,1,3,2,5,3,1,8,7,10};
    
    
    
    printf("\n\n\n-----------   Process 2: OPT - 3 Frames   -----------\n");
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    printf("\n\nTotal Page Faults = %d", faults);
    f2 = faults;
    return 0;
}











// ----------------------      Back Ground OPT       ---------------------------

int BKGOPTP1()
{
    int no_of_frames = 5, no_of_pages = 15, frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
//    int pages[]={10,1,3,2,5,3,1,8,7,10};
    
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        
    }
    
    f3 = faults;
    return 0;
}




int BKGOPTP2()
{
    int no_of_frames = 3, no_of_pages = 15, frames[10], temp[10], flag1, flag2, flag3, i, j, k, pos, max, faults = 0;
//    int pages[]={10,1,3,2,5,3,1,8,7,10};
    
    
    
    
    for(i = 0; i < no_of_frames; ++i){
        frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
        flag1 = flag2 = 0;
        
        for(j = 0; j < no_of_frames; ++j){
            if(frames[j] == pages[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        
        if(flag1 == 0){
            for(j = 0; j < no_of_frames; ++j){
                if(frames[j] == -1){
                    faults++;
                    frames[j] = pages[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        
        if(flag2 == 0){
        	flag3 =0;
        	
            for(j = 0; j < no_of_frames; ++j){
            	temp[j] = -1;
            	
            	for(k = i + 1; k < no_of_pages; ++k){
            		if(frames[j] == pages[k]){
            			temp[j] = k;
            			break;
            		}
            	}
            }
            
            for(j = 0; j < no_of_frames; ++j){
            	if(temp[j] == -1){
            		pos = j;
            		flag3 = 1;
            		break;
            	}
            }
            
            if(flag3 ==0){
            	max = temp[0];
            	pos = 0;
            	
            	for(j = 1; j < no_of_frames; ++j){
            		if(temp[j] > max){
            			max = temp[j];
            			pos = j;
            		}
            	}            	
            }
			
			frames[pos] = pages[i];
			faults++;
        }
        
        printf("\n");
        for(j = 0; j < no_of_frames; ++j){
            printf("%d\t", frames[j]);
        }
    }
    
    f4 = faults;
    return 0;
}























// -----------------------------------        MFU      ----------------------------------




struct node
{
  int pno,freq;
}frames[20];

int n;

int page_found(int pno)
{
  int fno;
  for(fno=0;fno<n;fno++)
    if(frames[fno].pno==pno)
       return fno;
    return -1;
}

int get_free_frame()
{  int fno;
  for (fno=0; fno<=n; fno++)
    if (frames[fno].pno==-1)
        return(fno);
   return(-1);
}

int get_mfu_frame()
{
  int fno;
  int selfno=0;
  for (fno=1; fno<n; fno++)
    if(frames[fno].freq>frames[selfno].freq)
    selfno=fno;
  return selfno;
}







int MFUP1()
{
   n = 5;
//   int pages[]={10,1,3,2,5,3,1,8,7,10};
   int size=15;
   int page_falts=0,i,j,fno;


   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }
   printf("\n\n\n-----------       Process 1: MFU - 5 Frames       -----------\n");
   printf("\nPageNo     Page Frames              Page Fault");
   printf("\n---------------------------------------------------");
   for(i=0;i<size;i++)
   {
     j=page_found(pages[i]);
     if(j==-1)  //page fault occurs
     {
       j=get_free_frame();
       if (j==-1) //no free frame - do page replacement
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=pages[i];
       frames[j].freq=1;
       printf("\n%4d\t ",pages[i]);
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : YES");
     }
    else //page found in frame j
    {
       printf("\n%4d\t ",pages[i]);
       frames[j].freq++;
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : NO");
    }
   }
  printf("\n-------------------------------------------------------");
  printf("\n Number of Page_Falts=%d",page_falts);


  f1 = page_falts;

  getch();
  return 0;
}











int MFUP2()
{
   n = 3;
  
  
//   int pages[]={10,1,3,2,5,3,1,8,7,10};
   int size=15;
   int page_falts=0,i,j,fno;


   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }

   printf("\n\n\n-----------       Process 2: MFU - 3 Frames       -----------\n");
   printf("\nPageNo     Page Frames              Page Fault");
   printf("\n---------------------------------------------------");
   for(i=0;i<size;i++)
   {
     j=page_found(pages[i]);
     if(j==-1)  //page fault occurs
     {
       j=get_free_frame();
       if (j==-1) //no free frame - do page replacement
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=pages[i];
       frames[j].freq=1;
       printf("\n%4d\t ",pages[i]);
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : YES");
     }
    else //page found in frame j
    {
       printf("\n%4d\t ",pages[i]);
       frames[j].freq++;
       for (fno=0; fno<n; fno++)
         printf("%4d:%2d",frames[fno].pno,frames[fno].freq);
       printf(" : NO");
    }
   }
  printf("\n-------------------------------------------------------");
  printf("\n Number of Page_Falts=%d",page_falts);
  
  f2 = page_falts;
  getch();
  return 0;
}






















// -----------------------------------        Background MFU      ----------------------------------



int BKGMFUP1()
{
   n = 5;
//   int pages[]={10,1,3,2,5,3,1,8,7,10};
   int size=15;
   int page_falts=0,i,j,fno;


   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }

   for(i=0;i<size;i++)
   {
        j=page_found(pages[i]);
        if(j==-1)  //page fault occurs
        {
           j=get_free_frame();
           if (j==-1) //no free frame - do page replacement
             j=get_mfu_frame();
           page_falts++;
           frames[j].pno=pages[i];
           frames[j].freq=1;
        }   
        else //page found in frame j
        {
        frames[j].freq++;
        }
   } 
    f3 = page_falts;
    
    getch();
    return 0;
}











int BKGMFUP2()
{
   n = 3;
  
  
//   int pages[]={10,1,3,2,5,3,1,8,7,10};
   int size=15;
   int page_falts=0,i,j,fno;


   //initialize frames
   for (i=0; i<n; i++)
   { frames[i].pno=-1;
     frames[i].freq=0;
   }


   for(i=0;i<size;i++)
   {
     j=page_found(pages[i]);
     if(j==-1)  //page fault occurs
     {
       j=get_free_frame();
       if (j==-1) //no free frame - do page replacement
         j=get_mfu_frame();
       page_falts++;
       frames[j].pno=pages[i];
       frames[j].freq=1;
       
     }
    else //page found in frame j
    {
       frames[j].freq++;
    }
   }
  
  f4 = page_falts;
  getch();
  return 0;
}
