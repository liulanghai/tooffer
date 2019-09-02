#include "common.h"
/*
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/
vector<string> split(const string &str, const string &pattern)
{
    vector<string> res;
    if(str == "")
        return res;
    //在字符串末尾也加入分隔符，方便截取最后一段
    string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while(pos != strs.npos)
    {
        string temp = strs.substr(0, pos);
        res.push_back(temp);
        //去掉已分割的字符串,在剩下的字符串中进行分割
        strs = strs.substr(pos+1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}
class Solution {
public:
    string ReverseSentence(string str) {
        vector<string>  strs = split(str," ");
        string s;
        for(int i=strs.size()-1;i>-1;i--){
            if(i == 0){
                s = s + strs[i];
            }else{
                s = s + strs[i] + " ";
            }
           
        }
        return s;
    }
};
int main(){
    Solution s;
    
    cout<<s.ReverseSentence("student. a am I")<<endl;
}