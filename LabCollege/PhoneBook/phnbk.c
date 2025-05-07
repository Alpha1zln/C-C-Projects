//ver2.0 --- wrkng cds ---
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct phonebook
{
    char name[60];
    char email[60];
    long long int mobileno;
};


typedef struct phonebook phnbk;
phnbk p[60];
int ct=0;





void add();
void display();
void sort();
//void swap(phnbk ak[], phnbk bk[]);


void bubblesortName();
void selectionsortName(); 
void insertionsortName(); 


void bubblesortEmail(); 
void selectionsortEmail(); 
void insertionsortEmail(); 
                
                
void bubblesortMobileno(); 
void selectionsortMobileno();
void insertionsortMobileno(); 






int main()
{
    int choice;
    printf("*********************PHONEBOOK*************************\n");
    
    
    while(1)
    {
        printf("\nList of operations on 'contact details' in phonebook :: \n");
        printf("Type the operation 'No.' : \n");
        printf("1. Add :  \t2. Display  \t3. Sort   \t4.Exit\n");
        
        printf(" \nEnter choice-> \n");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1: add(); break;
            case 2: display(); break;
            case 3: sort(); break;
            case 4: printf("Exited"); exit(1);
            default : 
                        {
                            printf("Invalid choice, chooose correct no. : \n");
                        }
        }
        
        
    }
    
}





void add()
{
    
    printf("Enter name : \n");
    scanf("%s", p[ct].name);
    
    printf("Enter email id : \n");
    scanf("%s", p[ct].email);
    
    printf("Enter mobile no. : \n");
    scanf("%lld", &p[ct].mobileno);
    
    printf("Name : %s", p[ct].name);
    printf(" is added in contact list \n");
    printf("\n");
    
    ct++;
    
}



void display()
{
    int j=0;
    
    if(ct==0) printf("Empty contact list");
    printf("\n");
    
    for(j=0; j<ct; j++)
    {
        printf("Contact details : %d\n", (j+1) );
        printf("Entered name : %s\n", p[j].name);
        printf("Entered email id : %s\n", p[j].email);
        printf("Entered mobile no : %lld\n", p[j].mobileno);
        printf("\n");
    }
    
    printf("\n");
}



/*void swap(phnbk ak[], phnbk bk[])
{
    phnbk temp;
    phnbk ak, phnbk bk;
    temp=ak; 
    ak=bk;
    bk=temp;
    
}*/


void sort()
{
    int choice, choice1, choice2, choice3;
    printf("Select the field to be sorted :: \n");
    printf("1. Name :  \t2. Email   \t3. Mobileno :     \n");
    scanf("%d", &choice);
    
    
    switch(choice)
    {
        case 1:
        {   
            printf("Field selected : Name \n");
            printf("Select Method of Sorting :: \n");
            printf("1. Bubble sort  \t2. Selection sort \t3. Insertion sort \n");
            scanf("%d", &choice1);
            
            switch(choice1)
            {
                case 1: bubblesortName(); display(); break;
                case 2: selectionsortName(); display(); break;
                case 3: insertionsortName(); display(); break;
                
            }
        
            break;
        }
        
        
        case 2:
        {
            printf("Field selected : Email \n");
            printf("Select Method of Sorting :: \n");
            printf("1. Bubble sort  \t2. Selection sort \t3. Insertion sort \n");
            scanf("%d", &choice2);
            
            switch(choice2)
            {
                case 1: bubblesortEmail(); display(); break;
                case 2: selectionsortEmail(); display(); break;
                case 3: insertionsortEmail(); display(); break;
                
            }
            
            break;
        }
        
        case 3:
        {
            printf("Field selected : Mobileno \n");
            printf("Select Method of Sorting :: \n");
            printf("1. Bubble sort  \t2. Selection sort \t3. Insertion sort \n");
            scanf("%d", &choice3);
            
            switch(choice3)
            {
                case 1: bubblesortMobileno(); display(); break;
                case 2: selectionsortMobileno(); display(); break;
                case 3: insertionsortMobileno(); display(); break;
                
            }
            
            break;
        } // case 3 end - field
        
    } // switch field
    
} // sort - end 




void bubblesortName()
{
    int i,j; 
    phnbk temp ;
    
    for(i=0; i<(ct-1); i++)
    {
        for(j=0; j<(ct-1-i); j++)
        {
            if(strcmp( p[j].name ,  p[j+1].name ) > 0)
            {
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        } // for j
    } // for i
} // bsrt - Nm



void selectionsortName() 
{
    int i,j; 
    phnbk temp;
    
    for(i=0; i<(ct-1); i++ )
    {
        int min = i;
        for(j=i+1 ; j<ct; j++)
        {
            if( strcmp (p[j].name , p[min].name )  < 0 )
            {
                min = j ;
            }
        }
        
        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp ;
            
        }
        
    } // for 1st
    
}



void insertionsortName() 
{
    int i,j;
    phnbk temp;
    
    for(i=1; i<ct; i++)
        {
            temp = p[i];
            j=i-1;
            
            while( (j>=0) && (strcmp(p[j].name , temp.name) > 0 ) )
            {
                p[j+1] = p[j];
                j--;
            }
            
            p[j+1]=temp;
        }
}




void bubblesortEmail() 
{
    int i,j; 
    phnbk temp ;
    for(i=0; i<(ct-1); i++)
    {
        for(j=0; j<(ct-1-i); j++)
        {
            if(strcmp(p[j].email ,  p[j+1].email) > 0)
            {
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        } // for j
    } // for i
}



void selectionsortEmail() 
{
    int i,j; 
    phnbk temp;
    
    for(i=0; i<(ct-1); i++ )
    {
        int min = i;
        for(j=i+1 ; j<ct; j++)
        {
            if( strcmp (p[j].email , p[min].email )  < 0 )
            {
                min = j ;
            }
        }
        
        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp ;
            
        }
        
    } // for 1st
}


void insertionsortEmail() 
{
    int i,j;
    phnbk temp;
    
    for(i=1; i<ct; i++)
        {
            temp = p[i];
            j=i-1;
            
            while( (j>=0) && (strcmp(p[j].email , temp.email) > 0 ) )
            {
                p[j+1] = p[j];
                j--;
            }
            
            p[j+1]=temp;
        }
}




                 
void bubblesortMobileno() 
{
    int i, j; 
    phnbk temp ;
    
    for(i=0; i<(ct-1); i++)
    {
        for(j=0; j<(ct-1-i); j++)
        {
            if( (p[j].mobileno > p[j+1].mobileno ) )
            {
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        } // for j
    } // for i
}


void selectionsortMobileno()
{
    int i,j; 
    phnbk temp ;
    
    for(i=0; i<(ct-1); i++ )
    {
        int min = i;
        for(j=i+1 ; j<ct; j++)
        {
            if( p[j].mobileno < p[min].mobileno )
            {
                min = j ;
            }
        }
        
        if(min != i)
        {
            temp = p[i];
            p[i] = p[min];
            p[min] = temp ;
            
        }
        
    } // for 1st
    
}


void insertionsortMobileno()
{
    int i,j;
    phnbk temp;
    
    for(i=1; i<ct; i++)
        {
            temp = p[i];
            j=i-1;
            
            while( (j>=0) && ( p[j].mobileno > temp.mobileno ) )
            {
                p[j+1] = p[j];
                j--;
            }
            
            p[j+1]=temp;
        }
        
}
