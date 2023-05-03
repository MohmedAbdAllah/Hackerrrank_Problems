class BadLengthException :  public exception{
    private:
        string  char_num;
    public:
    BadLengthException(int n){
        char_num = to_string(n);
    }
    virtual const char* what() const throw(){
        return char_num.c_str();
    }
};