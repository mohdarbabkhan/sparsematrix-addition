#include<iostream>
using namespace std;

class element{
    public:
    int i;
    int j;
    int x;
};

class sparse{
    private:
    
    int m;
    int n;
    int num;
    element *e;

    public:
    sparse(int m,int n,int num){
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[this->num];
    }
    ~sparse(){
        delete[]e;
    }
    void create();
    void display();
    sparse add(sparse &s);
};

void sparse::create(){
    
    cout<<"Enter the elements "<<endl;
    for (int j = 0; j < num; j++)
    {
        cin>>e[j].i>>e[j].j>>e[j].x;
    }
    
};

void sparse::display(){
    int i,j,k=0;
    for ( i = 0; i < m; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if (i ==e[k].i && j==e[k].j)
            {
                cout<<e[k++].x<<" ";
            }else{
                cout<<"0"<<" ";
            }
            
        }
        cout<<endl;
    }
    
}

sparse sparse::add(sparse &s){
    int i,j,k;
    i=j=k=0;
    // if (m!=s.m || n!=s.n)
    // {
    //     return  0;
    // }
    sparse *sum = new sparse(m,n,num+s.num);
    while (i<num && j<s.num)
    {
        if (e[i].i < s.e[j].i)
        {
            sum->e[k++] = e[i++];
        }
       else if (e[i].i > s.e[j].i)
        {
            sum->e[k++] = s.e[j++];
        }
        else{
            if (e[i].j < s.e[j].j)
        {
            sum->e[k++] = e[i++];
        }
        else if (e[i].j > s.e[j].j)
        {
            sum->e[k++] = s.e[j++];
        }
        else{
            sum->e[k] = e[i++];
            sum->e[k++].x = s.e[j].x + e[i++].x;
        }
        }   
    }
    for ( ; i < num; i++)
    {
        sum->e[k++] = e[i];
    }
    for ( ; j < s.num; j++)
    {
        sum->e[k++] = s.e[i];
    };
    sum->num = k;
    cout<<"the value of k is "<<k;
    return *sum;
};

int main(){
    sparse s(3,3,3);
    s.create();
    cout<<"the 1st mat: "<<endl;
    s.display();
    sparse s1(3,3,3);
    s1.create();
    cout<<"The sec mat: "<<endl;
    s1.display();
    sparse m = s1.add(s);
    cout<<"the added mat: "<<endl;
    m.display();

    return 0;
}
