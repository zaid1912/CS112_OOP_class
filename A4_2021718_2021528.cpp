//Assignment 4 - Zaid Bin Muzammil (2021718) - Raja Ata Ul Karim (2021528)
#include <iostream>
using namespace std;

//Class definition
class CMyString
{
private:
    
    //private attributes of the class
    char *a;
    int sizea;

public:
    // stores the characters(taken in as an argument from user) to the character array(a); 
    void getstring(CMyString &str){
        for(int i = 0; str.a[i] != '\0'; i++){
            cout<<str.a[i];
        }
        cout<<endl;
    }

    //default constructor
    CMyString(){
        a = new char[50];
    }

    //constructor which accepts char array
    CMyString(char *str){
        a = new char[50];
        int i;
        for(i = 0; str[i] != '\0'; i++){
            a[i] = str[i];
        }
        sizea = i;
    }

    //1 constructor yet to be made

    //overloading the + operator to perform concatination
    CMyString operator+(CMyString &str2)
    {
        int totalsize;
        totalsize = this->sizea + str2.sizea;
        //Temp object made.
        CMyString temp;
        temp.sizea = totalsize;
        int i;

        //loop is utilized to concatinate the string values
        for (i = 0; i < this->sizea; i++)
        {
            temp.a[i] = this->a[i];
        }
        for (int j = 0; j < str2.sizea; j++)
        {
            temp.a[i+j] = str2.a[j];
        }
        return temp;
    }

    //Secondary concatination, no temp used as it is being stored onto another pre-built variable/attribute
    void operator+=(CMyString &str2)
    {
        int i = 0;
        int totalsize = this->sizea + str2.sizea;
        for (i = 0; i < this->sizea; i++)
        {
        }
        for (int j=0; j < str2.sizea; j++)
        {
            this->a[i+j] = str2.a[j];
        }
    }

    //string size funciton, checks the size of the strings and answers accordingly.
    bool operator==(CMyString &str2)
    {
        if (this->sizea != str2.sizea)
        {
            return false;
        }
        else
        {
            for (int i = 0; i < str2.sizea; i++)
            {
                if (this->a[i] != str2.a[i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    //String inequality checker, checks if size is unequal between both strings and returns true if conditions
    //are met
    bool operator!=(CMyString &str2)
    {
        if (this->sizea != str2.sizea)
        {
            return true;
        }

        else
        {
            for (int i = 0; i < str2.sizea; i++)
            {
                if (this->a[i] != str2.a[i])
                {
                    return true;
                }
            }
        }
        return false;
    }

    //greater than comparison, uses while loop to go from start to end of either string and compares
    //if string A is greater than B then returns true
    bool operator>(CMyString &str2)
    {
        int i = 0;
        while(this->a[i] != '\0' || str2.a[i] != 0)  //ABC ABCD          SUKHS  KWdh
        {
           if(this->a[i] > str2.a[i]){
               return true;
           }
           i++;
        }
        return false;
    }

    //lesser than comparison, uses while loop to go from start to end of either string and compares
    //if string A is lesser than B then returns true
    bool operator<(CMyString &str2)
    {
       int i = 0;
        while(this->a[i] != '\0' || str2.a[i] != 0)  //ABC ABCD          SUKHS  KWdh
        {
           if(this->a[i] <= str2.a[i]){
               return false;
           }
           i++;
        }
        return true;
    }

    //outputs a string....ostream operator overloading

    friend ostream& operator<<(ostream& output, CMyString &str){
            output<<str.a<<endl;
       return output;

    }

    //input string, uses default input stream to show to user on console.
    //istream operator overloading to cin an object of a class directly
    friend istream &operator>>(istream &input, CMyString &str){
        
        int i = 0;
        cout<<"Enter the string: ";
        input>>str.a;
        
        return input;
    }

    //string assignment, assigns the string taken is as an argument to already existing string(this)

    void operator=(CMyString str2){
        int j;
        for(j = 0; j< str2.a[j] != '\0'; j++){
            this->a[j] = str2.a[j];
        }
        this->a[j]='\0';
    }

    //string left shift, used to store a certain value into a secondary object by shifting it a number
    //of places, user gives input of value n, which further shifts it "n" no. of places

    CMyString operator <<(int n){
        CMyString temp;
        int i;
        for(i = 0; i<n; i++){
            temp.a[i] = this->a[i];
        }
        int j;
        for(int k = 0; k<n; k++){
            for(j = 0; j<=this->sizea; j++){
                this->a[j] = this->a[j+1];
            }
            this->a[j] = '\0';
        }
        this->sizea = this->sizea - n;

        return temp;
    }

    //string right shift, used to store a certain value into a secondary/third object by shifting it a number
    //of places, user gives input of value n, which further shifts it "n" no. of places

    CMyString operator >>(int n){ 
        CMyString temp;
        int j=0;
        for(int i = this->sizea - n;i<this->sizea; i++){
            temp.a[j] = this->a[i];
            j++;
        }
        for(int k = this->sizea - n; k<this->sizea; k++){
            this->a[k] = '\0';
        }
        this->sizea = this->sizea - n;


        return temp;
    }

    //to access specific characters from with in the string(from lower bound to upper bound, upper bound being included)

    CMyString operator()(int lower, int upper){
        int j = 0; 
        CMyString temp;
        for(int i = lower; i<=upper; i++){
            temp.a[j] = this->a[i];
            j++;
        }
        return temp;

    }
    //get/set individual characters operator, the function would not work if both parameters are the same
    //hence one has been made a constant and the other has been passed by reference.
    char operator[](int n)const{
        return (this->a[n]);
    }

    char& operator[](int n){
        return (this->a[n]);
    }

    int getsize(CMyString &str){
        return (str.sizea);
    }
    //destructor
    ~CMyString(){}

    
};

int main()
{
    CMyString a("ABCDEFG");
    cout << "printing string A: " << endl;
    cout << endl << a;
    CMyString b("1234567");
    cout << "printing string B: " << endl;
    cout << endl << b << endl;
    cout<<"size of string a: "<<a.getsize(a)<<endl;
    
    CMyString d;

    d = a + b;
    cout << "Concatenating and outputting A and B: " << endl;
    cout << d << endl;

    a += b;

    cout << "Adding B to A through += operator" << endl;
    cout << a << endl;

    char e = a [ 1 ];

    cout << "Performing Get/Set e = a[1] " << endl; 
    cout << e << endl;

    bool p = ( a == a );
    cout << "Checking if a == a or not." << endl;

    if (p == true)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    cout << "Checking if a != b or not." << endl;
    if (a != b)
    {
        cout << "Not equal." << endl;
    }
    else
    {
        cout << "Equal" << endl;
    }

    cout << "Checking if a > b or not." << endl;
    if (a > b)
    {
        cout << "a > b - a is greater than b" << endl;
    }
    else
    {
        cout << "a > b - a is lesser than b" << endl;
    }

    cout << "Checking if a < b or not." << endl;
    if (a < b)
    {
        cout << "a < b = a is lesser than b" << endl;
    }
    else
    {
        cout << "a < b - a is greater than b" << endl;
    }

    CMyString c;
    c = a ( 0, 3 );
    cout << "The value of c = a(0,3) is " << c << endl;

    cout << a << b << endl;

    b = a;

    cout << "The value of b after b = a is " << b << endl;

    CMyString f;
    f = a << 1;
    cout << "The value of f = a << 1 is " << f << endl;

    CMyString g;
    g = a >> 1;
    cout << "The value of g = a >> 1 is " << g << endl;
    return 0;
}