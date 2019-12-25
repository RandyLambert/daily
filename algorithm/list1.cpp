#include <iostream>
using namespace std;

struct List{
    List* Next;
    int data;

    List(){
        Next = nullptr;
    }

    void Push_back(int x){
        List *p = this;
        while(p->Next != nullptr){
            p = p->Next;
        }
        p->Next = new List;
        p->Next->data = x;
        p->Next->Next = nullptr;
    }

    void Hebing(List * head2,List *head3){
        List *p1 = this;
        List *p2 = head2->Next;
        List *p3 = head3->Next;
        while(p2 != nullptr && p3 != nullptr)
            if(p2->data < p3->data){
                p1->Next = p2;
                p1 = p1->Next;
                p2 = p2->Next;
            }
            else{
                p1->Next = p3;
                p1 = p1->Next;
                p3 = p3->Next;
            }
        if(p2 == nullptr){
            while(p3 != nullptr){
                p1->Next = p3;
                p1 = p1->Next;
                p3 = p3->Next;
            }
        }
        else{
            while(p2 != nullptr){
                p1->Next = p2;
                p1 = p1->Next;
                p2 = p2->Next;
            }
        }
    }

    void Print(){
        List *p = this->Next;
        while(p!=nullptr){
            cout<<p->data<<endl;
            p = p->Next;
        }
    }

    ~List(){
        List *p = this;
        while(p->Next!=nullptr){
            List *q = p;
            p = p->Next;
            delete q;
        }
    }
};

void test01(){
    List *head1,*head2,*head3;
    head1 = new List;
    head2 = new List;
    head3 = new List;
    head1->Push_back(1);
    head1->Push_back(3);
    head1->Push_back(4);
    head1->Push_back(5);
    head1->Push_back(8);

    head2->Push_back(2);
    head2->Push_back(6);
    head2->Push_back(7);
    head2->Push_back(9);

    head3->Hebing(head1,head2);
    head3->Print();

}
int main(){
    test01();

    return 0;
}
