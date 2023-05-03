
// Write your Student class here
class Student {
    private:
        vector<int> scores;
    public:
        Student(){}
        
        void input(){
            for(int i = 0;i < 5;i++){
                int input  = 0;
                std::cin>> input;
                scores.push_back(input);
            }
        }
        
        uint16_t calculateTotalScore(){
            int result_sum = 0;
            for(auto element : this->scores){
                result_sum += element;
            }
            return result_sum;
        }
};
