#include <iostream>
#include <string>
#include <unordered_map>
#include <map>
#include <typeinfo>
/**
 {

            "" : {
                "a" : "2",
                "b" : "3",
                "c" : {
                    "d" : "3",
                    "e" : "1"
                }
            }
        }

a : 2
b : 3
c.d:3
pk = "",new dict
pk = "", a:2 , b:3,
pk = "c", c.d:3,c:e:1
*/

using namespace std;

void addToHash(map<string, string> & hash1,string parentKey, const map<string, void*> &dict) {
    map<string, void*>::const_iterator it = dict.begin();

    for(; it!=dict.end(); it++) {
        //  cout<<typeid(int).name()<<endl;
                hash1.insert(make_pair(it->first,*static_cast<std::string*>(it->second)));

        if((typeid(it->second).name()!=typeid(int).name())&&(typeid(it->second).name()!=typeid(string).name())) {
          /*
            map<string, void*> map2 = *static_cast<map<string, void*>*>( it->second);
            if(it->first=="") {

                addToHash(hash1,parentKey,map2);
            }
            else if(parentKey=="") {
                addToHash(hash1,it->first,map2);
            }
            else {
                addToHash(hash1,parentKey+"."+it->first,map2);
            }
          */
  
  
        }
        else {
            if(parentKey=="") {
              //std::string *sp = static_cast<std::string*>(it->second);
              std::string s = "a";
          
              hash1.insert(make_pair(it->first,*static_cast<std::string*>(it->second)));
             // delete sp;
            }
            else {
               hash1.insert(make_pair(parentKey+"."+it->first,*static_cast<std::string*>(it->second)));
            }
        }
    }


}

map<string, string> flattenDictionary(const map<string, void*> &dict)
{
    // your code goes here
    map<string, string> hash1;
    map<string, void*> dict2 = dict;
    addToHash(hash1,"",dict);
    return hash1;

}




int main() {

    /* input:  dict = {
           "Key1" : "1",
           "Key2" : {
               "a" : "2",
               "b" : "3",
               "c" : {
                   "d" : "3",
                   "e" : "1"
               }
           }
       } */

//     int a =0;
    cout<<typeid(map<string,string>).name()<<endl;
    
    map<string, string> dict1;
    map<string, void*> dict2;
    map<string, string> dict3;
    /*
    dict1.insert(pair<string,string>("d","3"));
    dict1.insert(make_pair("e","3"));

    dict2.insert(make_pair("a","2"));
    dict2.insert(make_pair("b","3"));
    dict2.insert(make_pair("c",dict1));

    dict3.insert(make_pair("Key1","1"));
    dict3.insert(make_pair("Key2",dict2));
*/
    string a = "1";
    string k  = "Key1";
    dict3.insert(k,a );
    
    map<string, void*> flatDict = flattenDictionary(dict2);
//     */
    return 0;
}