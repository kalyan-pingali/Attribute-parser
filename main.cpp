// File Description 	: Custom Markup Language, Attribute Parse (Contact for details)
// Version				: 1.0
// Author Name 			: Kalyan Pingali
// Contact Information  : pnglkalyan@gmail.com

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
//#include <sstream>
using namespace std;


int main() {

    map<string,string> map_ss;
    pair<string,string> pair_ss;
    map<string,string>::iterator iterator_ss=map_ss.begin();
    
    int N,Q; 
    char c;
    cin >> N >> Q;
    string blankline;
    getline(cin,blankline);     //Removing the incomplete end of line from the integer inputs
    vector<string> code;
    for(int i=0;i<N;i++)
    {
        string line;
        getline(cin,line);
        code.push_back(line);
    }
    
    vector<string> query;
    
    for(int i=0;i<Q;i++)
    {
        string temp;
        getline(cin,temp);
        //replace(temp.begin(),temp.end(),'~','.');
        query.push_back(temp);
    }
    
    vector<string> open_tags;
    for(int i=0;i<N;i++)
    {
        char a,b,c;
        vector<string> parsed;
        int number_of_spaces; 
        int number_of_assignments=0;
        string temp_string;
        
        // Parsing the line into space separated strings
        for(int itt=0;itt<=code[i].size();itt++)
        {
            if(itt==code[i].size())
            {
                //cout<<"Reached the end of line"<<endl;
                parsed.push_back(temp_string);
            }
            else if(code[i][itt]!=' ')
            {
                //cout<<"blah : "<<code[i][itt]<<endl;
                temp_string += code[i][itt]; 
            }
            else
            {
                number_of_spaces++;
                parsed.push_back(temp_string);
                temp_string = "";
            }
        }
        
        if(code[i][1]!='/')
        {
            if(parsed.size()==1)
            {
                open_tags.push_back(parsed[0].substr(1,parsed[0].size()-2));
            }
            else
            {open_tags.push_back(parsed[0].substr(1,parsed[0].size()-1));}
        }
        else if(code[i][1]=='/')
        {
            open_tags.pop_back();
        }
       
        //Creating the mapping!
        for(int iteer=0; iteer<parsed.size();iteer++)
        {
            
            if(parsed[iteer]=="=")
            {
                pair_ss.first = "";
                for(int iter_open_tags=0;iter_open_tags<open_tags.size();iter_open_tags++)
                {
                    pair_ss.first += open_tags[iter_open_tags]+'.';
                }
                //pair_ss.first = parsed[0].substr(1,parsed[0].size()-1)+'~'+parsed[iteer-1];
                pair_ss.first.pop_back();
                pair_ss.first += '~'+parsed[iteer-1];
                if(parsed[iteer+1][(parsed[iteer+1].size())-1]=='>')
                {
                    pair_ss.second = parsed[iteer+1].substr(1,parsed[iteer+1].size()-3);
                }
                else
                {
                    pair_ss.second = parsed[iteer+1].substr(1,parsed[iteer+1].size()-2);
                }
                
                
                map_ss.insert(pair_ss);
                number_of_assignments++;
                
            }
        }
        
    }
    /*for(iterator_ss=map_ss.begin();iterator_ss!=map_ss.end();iterator_ss++)
    {
        cout<<"Map output : "<<iterator_ss->first<<" = "<<iterator_ss->second<<endl;
    }*/
    
    /*for(int j=0;j<N;j++)
    {
        cout<<"Code : "<<code[j]<<endl;
    }*/
    
    for(int j=0;j<Q;j++)
    {
        iterator_ss = map_ss.find(query[j]);
        if(iterator_ss == map_ss.end())
        {
            cout<<"Not Found!"<<endl;
            continue;
        }
        
        cout<<iterator_ss->second<<endl;
    }
    
    return 0;
}
