
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)
class Box{
    private:
        int l,b,h;
    public:
       Box(){
           this->l = 0;
           this->b = 0;
           this->h = 0;
       }
       Box(int length,int breadth,int height):l(length),b(breadth),h(height){
           
       }
       Box(Box& B){
           this->b =B.b;
           this->l = B.l;
           this->h = B.h;
       }
       int getLength(){
           return this->l;
       }
       int getBreadth (){
           return this->b;
       }
       int getHeight (){
           return this->h;
       }
       long long CalculateVolume(){
           
           return (long long)(l) * h * b;
       }
       bool operator<(Box& b){
           if(this->l < b.l) return true;
           else if((this->b < b.b)&&(this->l == b.l)) return true;
           else if((this->b == b.b)&&(this->l == b.l)&&(this->h < b.h)) return true;
           else return false;
       }
       friend ostream& operator<<(ostream& out, Box& B){
           cout<<B.l<<" "<<B.b<<" "<<B.h;
           return out;
       }
};
