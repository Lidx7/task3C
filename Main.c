#include <stdio.h>
#include <string.h>
#include "StrList.h"
#define MAX 500
#define TRUE 1
#define FALSE 0

int main()
{
    StrList* list = StrList_alloc();
    char act[MAX] = "";
    scanf("%s" , act);
    int cont_loop = TRUE;

    while (cont_loop)
    {
        if (strcmp(act , "0") == 0){
            cont_loop = FALSE;
        }
        
        if (strcmp(act , "1") == 0)
        {
            int n;
            scanf("%d" , &n);
            char str[MAX];
            
            for (int i = 0; i < n; i++)
            {
                scanf("%s" , str);
                StrList_insertLast(list, str);
            }
            
             
        }
        if (strcmp(act , "2") == 0)
        {
            int n;
            scanf("%d" , &n);
            char str[MAX];
            scanf("%s" , str);
            StrList_insertAt(list, str, n);
        }

        if(strcmp(act , "3") == 0)
        {
            if (list!= NULL)
            {
                StrList_print(list);
                
            }
            printf("\n");
        }

        if (strcmp(act , "4") == 0)
        {
            printf("%zu\n" , StrList_size(list));
        }
        
        if (strcmp(act , "5") == 0)
        {
            int n;
            scanf("%d" , &n);
            StrList_printAt(list, n);
        }

        if (strcmp(act , "6") == 0)
        {
            int len;
            len = StrList_printLen(list);
            printf("%d\n" , len);
        }

        if (strcmp(act , "7") == 0)
        {
            char str[MAX];
            scanf("%s" , str);
            printf("%d\n" , StrList_count(list, str));
        }
        
        if(strcmp(act , "8") == 0)
        {   
            char str[MAX];
            scanf("%s" , str);
            StrList_remove(list, str);
        }
        
        if (strcmp(act , "9") == 0)
        {
            int n;
            scanf("%d" , &n);
            StrList_removeAt(list, n);
        }
        
        if (strcmp(act , "10") == 0)
        {
            StrList_reverse(list);
        }
        
        if (strcmp(act , "11") == 0)
        {   
            StrList_free(list);
            list = NULL;
        }

        if(strcmp(act , "12") == 0)
        {
            StrList_sort(list);
        }
        
        if(strcmp(act , "13") == 0)
        {
            int check;
            check = StrList_isSorted(list);
            if(check == 1)
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
        }
        
        scanf("%s" , act);
    }
    
    
    return 0;
}