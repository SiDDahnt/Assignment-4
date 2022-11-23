#include<iostream>
using namespace std;

//CLASS IMPLEMENTATION
class parcel{
    protected: 
	    int weight;    
        int shipping_cost;
    public:
        //CONSTRUCTOR
        parcel(){
            cout<<"Enter the Weight of the Parcel: ";
			cin>>weight;
            shipping_cost = 0;
        }  
        //FRIEND FUNCTION
        friend void call_shipping(class parcel&);     
};
void call_shipping(class parcel &m){
    //EXECPTION HANDELLING
    try{
        if(m.weight<=0){
           throw m.weight;
       }
    }
    catch(int w){
       cout<<"EXCEPTION OCCURED...."<<endl;
       cout<<"EXCEPTION VALUE IS "<<m.weight<<endl;
    }
    float cost = m.weight/10;
    m.shipping_cost = m.shipping_cost+cost;
}
//VIRTUAL CLASS
class toll : virtual public parcel{
    public:
        void tol(){
            if(weight>100){
                shipping_cost += 10;
            }
        }      
};
class distance : virtual public parcel{
    private:
        int dist;
    public: 
        distance(){
            cout<<"Enter the Distance: ";
            cin>>dist;
        }
        void dis(){
            if (dist>2000){
                shipping_cost += 200;
            }
            else{
                shipping_cost += 100;
            }
        }
};
//INHERITANCE
class display : public toll, public distance{
    public:
    void diss(){
        cout<<"The weight of the parcel is: "<<weight<<endl;
        cout<<"The total shipping cost is: "<<shipping_cost<<endl;
    }
};
//TEMPLATE CLASS
template <class T>
class Box{
    private: 
        T height;
        T depth;
        T width;
        T volume;
        int box_no;
    public: 
        Box(){
            height = 0;
            depth = 0;
            width = 0;
            cout<<"Enter the Box Number: ";
            cin>>box_no;
        }    
        Box(T h, T d, T w){
            height = h;
            depth = d;
            width = w;
            cout<<"Enter the Box Number: ";
            cin>>box_no;
        }
        void volume1(){
            volume = height*depth*width;
            cout<<"Volume is "<<volume<<endl;
        }
        //OPERATOR OVERLOADING
        void operator == (class Box &b){
            if(volume>b.volume){
                cout<<"Box "<<box_no<<" has higher volume"<<endl;
            }
            else{
                 cout<<"Box "<<b.box_no<<" has higher volume"<<endl;
            }
        }
};
int main(){
    display a;
    call_shipping(a);
    a.tol();
    a.dis();
    a.diss();
	cout<<"To compare volume of two boxes"<<endl;
	Box <int>b(4, 5, 6);
    Box <int>c(3, 7, 4);
    b.volume1();
    c.volume1();
    b == c;
    return 0;
}