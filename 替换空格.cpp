
#include "head.h"
/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        char *res  = (char *)malloc(length*3);
        int i = 0;
        int j = 0;
        for(i=0;i<length;i++){
            if(str[i] == ' '){
                printf("xxx\n");
                res[j++] = '%';
                res[j++] = '2';
                res[j++] = '0';
            }else{
                res[j++] = str[i];
            }
        }
        res[j] = 0;
        str = res;
        printf("%s\n",str);
	}
};

int main(){
   Solution s;
   char *a = (char *)malloc(3);
   a[0] = '1';
   a[1] = ' ';
   a[2] = '2';
   s.replaceSpace(a,3);
   printf("%s\n",a);
   return 0;
}
 
    