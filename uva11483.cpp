#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main (){
    int i,n,len,ca=0;
    char s[100000];
    while(1){
        scanf("%d",&n);
        if(n == 0)break;
        ca++;
        printf("Case %d:\n",ca);
        printf("#include<string.h>\n");
        printf("#include<stdio.h>\n");
        printf("int main()\n");
        printf("{\n");
        while(n > 0){
            gets(s);
            if(strcmp(s,"") == 0)continue;
            len = strlen(s);
            printf("printf(\"");
            for(i=0;i<len;i++){
                if(s[i] == '\\' || s[i] == '\"')
                    printf("\\%c",s[i]);
                else
                    printf("%c",s[i]);
            }
            printf("\\n\");\n");
            n--;
        }
        printf("printf(\"\\n\");\n");
        printf("return 0;\n");
        printf("}\n");
    }
    return 0;
}
