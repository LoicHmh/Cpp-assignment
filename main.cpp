#include <iostream>

using namespace std;


class Stack
{
private:
    int data[100];
    int hight;
public:
    Stack()
    {
        data[0]=0;
        hight=0;
    }
    int pop()
    {
        if (hight>0)
        {
            return (data[--hight]);
        }
        return 0;
    }
    void push (int a)
    {
        if (hight<100)
        {
            data[hight]=a;
            hight++;
        }
    }
    bool isright(int*a,int N);
};

bool Stack::isright(int*a,int N)
{
    int i=1,js=0,flag=1;
    while (i<=N)
    {
        if (*a==i)
        {
            a++;
            js++;
            i++;
        }
        else
        {
            int k=pop();
            if (k==*a)
            {
                a++;
                js++;
            }
            else
            {
                if (k!=0)
                {
                    push(k);
                }
                push(i);
                i++;
            }
        }

    }
    while (js<N)
    {
        if (pop()==*a)
        {
            a++;
            js++;
        }
        else
        {
            flag=0;
            break;
        }
    }

    if ((flag==1)&&(hight==0))
        return (1);
    else
        return (0);
}

int main()
{
    while (1)
    {
        int N;
        cin>>N;
        if (N==0)
            break;
        while (1)
        {
            int a[101];
            int i;
            Stack p;
            cin>>a[0];
            if (a[0]==0)
            {
                cout<<"---"<<endl;
                break;
            }
            for (i=1;i<N;i++)
            {
                cin>>a[i];
            }
            if (p.isright(a,N))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
    }
    return 0;
}
