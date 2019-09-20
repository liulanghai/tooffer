
#include "common.h"
/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/
class Solution {
public:
	void replaceSpace(char *str,int length) {
        char *tmp = (char *)malloc(length);
        for(int i=0;i<length;i++){
            tmp[i] = str[i];
        }
        int j=0;
        for(int i=0;i<length;i++){
            if(tmp[i] == ' '){
                str[j++] = '%';
                str[j++] = '2';
                str[j++] = '0';
            }else{
                str[j++] = tmp[i];
            }
        }
        str[j] = 0;
	}
};

int main(){
   Solution s;
   char *a = (char *)malloc(3);
   a[0] = '1';
   a[1] = ' ';
   a[2] = '2';
   s.replaceSpace(a,3);
   printf("out func %s\n",a);
   return 0;
}
 
    