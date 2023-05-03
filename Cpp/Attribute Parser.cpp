#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<map>
using namespace std;

//split string function
vector<string> SplitStr(string str,char deli)
{
    string s = "";
    vector<string> str_words(0);

    //cout<<"The split string is:"
    for (auto x : str)
    {
        if (x == deli)
        {
            //cout << s << endl;
            str_words.push_back(s);
            s = "";
        }
        else {
            s = s + x;
        }
    }
    str_words.push_back(s);
    //cout << s << endl;
    return str_words;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //get the numbers of HRML lines and queries lines
    int HRML , queries;
    cin>> HRML >> queries;
    //create the vectors that will hold the HRML and queries lines
    vector<string> HRML_lines(HRML),queries_lines(queries);
    //get HRML lines
    string space;
    getline(cin, space);
    for(auto& line : HRML_lines){
       getline(cin, line);
       
    }
    //get the queries lines
    for(auto& line : queries_lines){
       getline(cin, line);
       //cout<<line <<endl; 
    }
    //map <data_type_of_key, data_type_of_value> variable_name;
    //bakery["Choclatecake"] = 585.5;
    
    //initialize the map that will hold the attributes with its values
    map <string, string> attributes_dic;
    // HRML tags
    string HRML_tags = "",copy = "";
    int inc = 0;
    vector<string> tags_name {""};
    //get the attributes and its value from HRML lines
    for(auto line : HRML_lines){
        //split line to words
        
        vector<string>line_words = SplitStr(line,' ');
        //for(auto word :line_words ) cout<<word<<ends;
        //cout<<endl;
        //search for attributes
        if(line_words[0][1] == '/'){
            tags_name.pop_back();
            continue;
        }
        
        vector<string> words = SplitStr(line_words[0],'>');
        //cout<<words[0]<<endl;
        string attribute = words[0];
        
        HRML_tags = tags_name[tags_name.size()-1] + words[0].substr(1);
        for(int word = 0; word < line_words.size(); word++){
            if(line_words[word] == "="){
                //get values
                vector<string> words = SplitStr(line_words[word+1],'\"');
                string value = words[words.size()-2];
                
                //cout<<HRML_tags + "~" +line_words[word-1]<<endl;
                attributes_dic[HRML_tags + "~" +line_words[word-1]] = value ;
            }
        }
        tags_name.push_back(HRML_tags+".");
        //copy = HRML_tags+".";
        inc++;
        if(inc == HRML/2) break;
    }
/*
    //initialize vector that will hold the attributes asked in queries
    vector<string> attributes_keys(0);
    //get the attributes from lines
    for(auto line : queries_lines){
        //split line to words
        vector<string> line_words = SplitStr(line,'~');
        //get attributes
        //cout<<line_words[line_words.size() - 1]<<endl;
        attributes_keys.push_back(line_words[line_words.size() - 1]);
        queries_tags.push_back(line_words[0]);
    }
 */   
    //display the value of attributes
    
    for(auto queries : queries_lines){
        // declaring iterators
        //cout<<attribute<<endl;
        auto it = attributes_dic.find(queries);    
         
        if(it == attributes_dic.end())
            cout << "Not Found!" <<endl;
        else
            cout << it->second <<endl;
    }
     
    return 0;
}
