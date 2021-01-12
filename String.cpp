#include <iostream>
using namespace std;
class String{
    protected:
        char *str;
        int size;
    public:
        String():str(NULL),size(0){}
        String(const char* str){
            //Getting length
            int len=0;
            while(str[len]!='\0')len++; //len count '\0' too
            //allocating memory
            this->size=len;
            this->str=new char[this->size+1];
            //Copying data
            for(int i=0;i<=len;i++){
                this->str[i]=str[i];
            }
        }
        String& operator=(const char *str){
              //Getting length
              int len=0;
              while(str[len]!='\0')len++;
              //Deleting left side string
              if(this->size!=0){
                  delete[] this->str;
                  this->size=0;
              }
              //allocating memory
              this->size=len;
              this->str=new char[this->size+1];
              //Copying data
              for(int i=0;i<len;i++){
                  this->str[i]=str[i];
              }
              return *this;
        } 
        String& operator+(String& other){
            //Creating result string
            String *Res;
            //Allocating memory to result
            //string
            Res->size=this->size+other.size;
            Res->str=new char[Res->size+1];//+1 for null pointer
            //Copying data to new string
            int k=0;
            for(int i=0;i<this->size;i++){
                Res->str[k]=this->str[i];
                k++;
            }
            for(int j=0;j<=other.size;j++){
                Res->str[k]=other.str[j];
                k++;
            }
            return *Res;
        }
        void display(){
            cout<<str;
        }
        int len(){return size;}
};
int main(){
    String a="Hi there! ";
    String b="What's up?";
    String r;
    r=a+b;
    r.display();
    cout<<"\nLength:-"<<r.len();
    return 0;
}

