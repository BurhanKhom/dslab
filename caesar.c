
#include <stdio.h>
int main(){
    int n; 
    scanf("%d",&n);
    char s[n];
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    
    for(int i=0; i<n; i++)
    {
        if(s[i]>='A' && s[i]<='z')
            printf("%c", s[i]+2);
        else
            printf("%c", s[i]);
        
            
    }
    
    
    
    
    
    
}
