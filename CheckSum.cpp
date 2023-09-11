#include <bits/stdc++.h>
using namespace std;

string ones_complement(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            s[i]='1';
        }
        else{
            s[i]='0';
        }
    }
    return s;
}
string check_sum(string data, int block_size){
    int n =  data.size();
    if(n%block_size!=0){
        int pad_size = block_size-(n%block_size);
        for(int i=0;i<pad_size;i++){
            data = '0' + data;
        }
    }
    string result = "";
    for(int i=0;i<block_size;i++){
        result+=data[i];
    }
    for(int i=block_size;i<n;i+=block_size){
        string next_block = "";
        for(int j=i;j<i+block_size;j++){
            next_block+=data[j];
        }
        string addition="";
        int sum=0;
        int carry=0;
        for(int k=block_size-1;k>=0;k--){
            sum+=(next_block[k]-'0')+(result[k]-'0');
            carry=sum/2;
            if(sum==0){
                addition='0'+addition;
                sum=carry;
            }
            else if(sum==1){
                addition = '1'+addition;
                sum=carry;
            }
            else if(sum==2){
                addition = '0'+addition;
                sum=carry;
            }
            else{
                addition = '1'+addition;
                sum=carry;
            }

        }
        string final="";
        if(carry == 1){
            for(int l = addition.size()-1;l>=0;l--){
                if(carry==0){
                    final=addition[l]+final;
                }
                else if(((addition[l]-'0')+carry)%2==0){
                    final = '0' + final;
                    carry=1;
                }
                else{
                    final = '1' + final;
                    carry=0;
                }
            }
            result=final;
        }
        else{
            result = addition;
        }
    }
    return ones_complement(result);

}
bool check(string sent_message,string rec_message,int block_size){
    string sender_checksum=check_sum(sent_message,block_size);
    string received_message = check_sum(rec_message+sender_checksum,block_size);
    if(count(received_message.begin(),received_message.end(),'0')==block_size){
        return true;
    }
    return false;

}
int main() {

    string sent_message;
    cout<<"Enter the senders message"<<endl;
    cin>>sent_message;
    string received_message;
    cout<<"Enter the receiver message"<<endl;
    cin>>received_message;
    int block_size;
    cout<<"Enter the block size"<<endl;
    cin>>block_size;
    if(check(sent_message,received_message,block_size)){
        cout<<"No error"<<endl;
    }
    else{
        cout<<"Error"<<endl;
    }

    return 0;
}
