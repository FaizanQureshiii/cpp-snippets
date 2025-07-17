#include<iostream>
using namespace std;

class stack{
    public:
    int top;int * arr;
    int size;
    stack(){};
    stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int val){
        if(top>=size){
            cout<<"stack is overflow"<<endl;
        }
        else{
            top++;
            arr[top]=val;
        }
    }
    void pop(){
        if(top<=0){
            cout<<"stack is underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
        }
        else{
            return arr[top];
        }
    }
    bool isempty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool ismatch(char open ,char close){
        return (open=='('&&close==')')||
        (open=='{'&&close=='}')||
        (open=='['&&close==']');
    }
    bool isbracketmatch(string str){
       stack st;
       for(char ch:str){
        if(ch=='('||ch=='{'||ch=='['){
            st.push(ch);
        }
        else if(ch==')'||ch==']'||ch=='}'){
            if(st.isempty()){
                return false;
            }
            char lastopen=st.peek();
            if(ismatch(lastopen,ch)){
                st.pop();
            }
            else{
                return false;
            }

        }

       }
       st.isempty();
    }
    void bubblesort(){
        int n=size;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    int temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
            }
        }
    }
    int binarysearch(int target){
        int low=0;
        int high=size-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==target){
                return mid;
            }
            else if(arr[mid]<target){
                low = low +1;
            }
            else{
                high=high-1;
            }
        }
    }
};