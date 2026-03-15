////////////////////////////////////////////////////////////////////////////
/// Final code of QUEUE using Generic Approach
//////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

#pragma pack(1)
template <class T>
class Queuenode
{
    public :
        T data;
        Queuenode<T> *next;

        Queuenode(T no)
        {
            this -> data = no;
            this -> next = NULL;
        }
};

template <class T>
class Queue
{
    private:
        Queuenode<T> *first;
        Queuenode<T> *last; 
        int iCount;

    public:
        Queue();

        void enqueue(T);
        T dequeue();             
        void Display();
        int Count();
};

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created Successfully....\n";
    this -> first = NULL;
    this -> last = NULL;
    this -> iCount = 0;
}

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T> *newn = NULL;

    newn = new Queuenode<T>(no);

    if(this -> first == NULL && this -> last == NULL)
    {
        this -> first = newn;
        this -> last = newn;
    }
    else
    {
        this -> last -> next = newn ;
        this -> last = this -> last -> next;
    }

    this -> iCount++;
} 

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T> *temp = this -> first;

    if(this -> first == NULL && this -> last == NULL)
    {
        cout<<"Queue is empty";
        return -1;
    }

    Value = this -> first -> data;

    this -> first = this -> first -> next;
    delete temp;

    this -> iCount--;

    return Value;
}   

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> *temp = this -> first;

    if(this -> first == NULL && this -> last == NULL)
    {
        cout<<"Queue is empty";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp -> data<<" | - ";
        temp = temp -> next;
    }

    cout<<"\n";
}

template <class T>
int Queue<T> :: Count()
{
    return this -> iCount;
}

int main()
{
    Queue<int> *qobj = new Queue<int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)
    {
        cout<<"-------------------------------------------------------------\n";
        cout<<"-------------------------PLease select the option------------------------------------\n";
        cout<<"1 : Insert the new element in Queue\n";
        cout<<"2 : Remove the new element from Queue\n";
        cout<<"3 : Display the elements in Queue\n";
        cout<<"2 : Count the number of elements in Queue\n";
        cout<<"0 : Exit the Application\n";

        cin>>iChoice;
        cout<<"-------------------------------------------------------------\n";

        switch(iChoice)
        {
            case 1: 
                cout<<"Enter the element that you want to insert: \n";
                cin>>Value;
                qobj -> enqueue(Value);
                cout<<"Element gets inserted Successfully\n";
                break;

            case 2:
                iRet = qobj -> dequeue();
                if(iRet != -1)
                {
                    cout<<"Element removed from Queue is "<<iRet<<"\n";
                }
                break;

            case 3: 
                cout<<"Elements of Queue are :\n";
                qobj -> Display();
                break;

            case 4:
                iRet = qobj -> Count();
                cout<<"Number of elements in queue are : "<<iRet<<"\n";
                break;
            
            case 0:
                cout<<"Thankyou for Using Application\n";
                delete qobj;
                return 0;

            default:
                cout<<"Please enter the valid input\n";
        }   //End of Switch
    }   //End of while

    return 0;
}