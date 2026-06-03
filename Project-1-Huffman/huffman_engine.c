#include<stdio.h>
#include<string.h>
int main(){
    char text[] = "engineering is about execution";
    int freq[256] = {0};
    int i = 0;
    int count = 0;
    while(text[i]!='\0'){
        freq[text[i]]++;
        count++;
        i++;
    }

    printf("total count: %d\n",count);

    for(int i=0;i<256;i++){
        if(freq[i]>0){
            printf("count of '%c': %d\n",i,freq[i]);
        }
    }

    return 0;
}