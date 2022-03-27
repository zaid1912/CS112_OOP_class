#include<iostream>

using namespace std;


char *Mystrcpy(char *s1, const char *s2){
    int k;
    for(k = 0; (s2[k] != '\0'); k++){
        *(s1+k) = *(s2+k);
    }
    *(s1+k) = '\0';
     return s1;
}



char *Mystrncpy(char *s1, const char *s2, size_t count){
    int k;
    for(k = 0; k<count; k++){
        *(s1 + k) = *(s2 + k);
    }
    *(s1+k) = '\0';
return s1;

}



char *Mystrcat(char *s1, const char *s2){
    int k;
    int i=0;
    while((s1[i]) != '\0'){
        i++;
    }
    //cout<<endl<<i<<endl;
    int j;
    for(j = 0;(s2[j] != '\0'); j++ ){
        *(s1+i+j) = *(s2+j);
    }

       
    *(s1+i+j) = '\0';
    return s1;

}


char *Mystrncat(char *s1, const char *s2, size_t n){
    int k;
    int i=0;
    while((s1[i]) != '\0'){
        i++;
    }
    //cout<<endl<<i<<endl;
    int j;
    for(j = 0;j<n; j++ ){
        *(s1+i+j) = *(s2+j);
    }

       
    *(s1+i+j) = '\0';
    return s1;

}

int Mystrcmp(char *s1, char *s2){
    int i = 0, j = 0, temp;
    for(i = 0; s1[i]!= '\0'; i++){
        // for(j = 0; j<=i; j++){
            if((s1[i]) == (s2[i]))
                temp = 0;
            else if((s1[i]) > (s2[i]))
                return 1;
            else
                return -1;
        }
    // }
    return temp;
}

int Mystrncmp(char *s1, char *s2, size_t n){
    int i = 0, j = 0, temp;
    for(i = 0; n; i++){
            if((s1[i]) == (s2[i]))
                temp = 0;
            else if((s1[i]) > (s2[i]))
                //temp = 1;
                return 1;
            else{
                //temp = -1;
                return -1;
        }
    return temp;
}


// size_t Mystrlen(const char *s){
//     int i=0;
//      while((s[i]) != '\0'){
//          i++;
//     }
//     return i;

// }

size_t Mystrlen(const char *s){
    int i = 0;
    while((s[i] != '\0')){
        i++;
    }
    return i;
}

//not working multiple times

char *Mystrtok(char *s1, const char *s2){
    static int i = 0;
    while(s1[i] != s2[0]){
        i++;
    }
    *(s1 + i) = '\0';
    return s1;
    
}



int main(){
    char s1[] = "Hello world, my name is Zaid";
    //char s1[] = "probramming";
    char s2[] = "programming";
    //char s2[] = " ";
    // Mystrcpy(s1, s2);
    // cout << s1<<endl;
    // Mystrncpy(s1, s2, 7);
    // cout<<s1<<endl;
    // cout<<Mystrcat(s1, s2);
    //cout<<s1<<endl;
    // cout<<Mystrncat(s1, s2, 7);
    //cout<<Mystrcmp(s1, s2);
    //cout<<Mystrncmp(s1, s2, 4);
    //cout<<Mystrlen(s1);
    //cout<<Mystrtok(s1, s2);

    return 0;
}